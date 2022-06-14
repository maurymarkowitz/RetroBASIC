10 rem Ahl's simple benchmark
20 for n = 1 to 100: a = n
30 for i = 1 to 10
40 a = sqr(a): r = r + rnd(1)
50 next i
60 for i = 1 to 10
70 a = a^2: r = r + rnd(1)
80 next i
90 s = s + a: next n
100 print "Accuracy ";abs (1010-s/5)
110 print "Random ";abs (1000-r)
