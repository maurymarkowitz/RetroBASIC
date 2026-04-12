# Results of review and tests generated for the issues found.

I prompted Claude as follows. It produced the tests in this directory,
which I then tried with various results


Here in/Users/jeff/go/src/github.com/maurymarkowitz/RetroBASIC/Review is a    
  code review. Please make a plan to create tests that illustrate each of the     critical review issues and that will fail until the issue is fixed. Name the    tests so they are easy to correlate with the issues in the review. Create the    tests in the Review directory. An ideal test is written in BASIC, but you      may write a test in C if this is not possible

## Note

about `issue02_mat_fill_str_nonsquare.bas`

 Jeff, speaking to the AI: now when I run 1./retrobasic/Review/issue02_mat_fill_str_nonsquare.bas` it    
  reports "Segmentation fault: 11". Don't fix this, just explain it, becauses
 it is useful as a report to the maintainer.

⏺ The segfault is the bug in action. Here's what happens:                       
                                                                              
  The buggy loops are:                                                          
  for (int r = 1; r <= cols; r++) {   // cols=3, so r goes 1,2,3
      for (int c = 1; c <= rows; c++) { // rows=2, so c goes 1,2                
          int slot = r * (cols + 1) + c;  // slot = r*4 + c                     
                                                                                
  For a DIM S$(2,3) matrix, the array is allocated for 2 rows × 3 cols. The     
  valid slots (using r * (cols+1) + c) are:                                     
                                                                                
  - (1,1)=5, (1,2)=6, (1,3)=7                                                   
  - (2,1)=9, (2,2)=10, (2,3)=11                             

  But the buggy loops iterate r up to 3 (cols) and c up to 2 (rows), so they    
  compute:
                                                                                
  - (1,1)=5, (1,2)=6  ✓                                     
  - (2,1)=9, (2,2)=10  ✓
  - (3,1)=13, (3,2)=14  ← out of bounds                                         
                                                                                
  Slots 13 and 14 are past the end of the allocated array. The code then does   
  free(destination_store->array[slot].string) on those garbage memory locations,
   and that's your segfault — it tries to free() whatever random pointer value happens to be sitting in unallocated memory.              

  So the bug is actually worse than "wrong fill" — for any non-square matrix    
  where cols > rows, it writes past the array boundary and crashes. The test as
  written is a valid demonstration: the maintainer will see it segfaults on a   simple 2×3 string matrix fill. 
