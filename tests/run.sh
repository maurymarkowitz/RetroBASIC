#!/bin/sh
# Minimal regression harness for RetroBASIC.
# Runs each tests/cases/*.bas program and compares stdout to tests/cases/*.expected.
# A case may pass CLI flags to the interpreter via an optional tests/cases/<name>.args
# file (whitespace-separated). Note that --random's argument is optional, so it must
# be attached: write --random=42 (or -r42), not "--random 42".
# A case may also have an optional tests/cases/<name>.stderr file marking it as an
# expected-error case: its stderr is compared to that file instead of requiring
# empty stderr and a zero exit code (error paths exit 0 or non-zero inconsistently).
# Requires `diff` (provided by diffutils). Line endings are normalized (CRLF -> LF).
set -u

command -v diff >/dev/null 2>&1 || {
    echo "tests/run.sh: 'diff' not found (install diffutils)" >&2
    exit 2
}

if [ -n "${RETROBASIC:-}" ]; then
    BIN="$RETROBASIC"
elif [ -x ./retrobasic.exe ]; then
    BIN=./retrobasic.exe
else
    BIN=./retrobasic
fi
fail=0
count=0

for bas in tests/cases/*.bas; do
    [ -e "$bas" ] || continue
    name=$(basename "$bas" .bas)
    expected="tests/cases/$name.expected"

    if [ ! -f "$expected" ]; then
        echo "SKIP $name (no $expected)"
        continue
    fi
    count=$((count + 1))

    workdir=$(mktemp -d)
    actual="$workdir/actual"
    err="$workdir/err"
    raw="$workdir/raw"

    # optional per-case CLI flags for the interpreter, whitespace-separated
    set --
    if [ -f "tests/cases/$name.args" ]; then
        set -f # don't glob-expand the flag list
        set -- $(tr -d '\r' < "tests/cases/$name.args")
        set +f
    fi

    "$BIN" "$@" "$bas" >"$raw" 2>"$err"
    rc=$?
    tr -d '\r' < "$raw" > "$actual"

    stderr_expected="tests/cases/$name.stderr"
    if [ -s "$stderr_expected" ]; then
        # expected-error case: compare stderr to the .stderr file (CR-normalized
        # like the other files) instead of requiring it to be empty; the exit code
        # is not asserted, error paths exit 0 or non-zero inconsistently
        err_norm="$workdir/err_norm"
        stderr_norm="$workdir/stderr_norm"
        tr -d '\r' < "$err" > "$err_norm"
        tr -d '\r' < "$stderr_expected" > "$stderr_norm"
        if ! diff -u --label expected-stderr --label actual-stderr "$stderr_norm" "$err_norm" >"$workdir/stderr_diff"; then
            echo "FAIL $name (stderr mismatch)"
            cat "$workdir/stderr_diff"
            fail=$((fail + 1))
            rm -rf "$workdir"
            continue
        fi
    else
        if [ "$rc" -ne 0 ]; then
            echo "FAIL $name (exit $rc)"
            cat "$err"
            fail=$((fail + 1))
            rm -rf "$workdir"
            continue
        fi

        # the interpreter reports errors on stderr and still exits 0, so a matching
        # stdout alone does not mean the program ran cleanly
        if [ -s "$err" ]; then
            echo "FAIL $name (unexpected stderr)"
            cat "$err"
            fail=$((fail + 1))
            rm -rf "$workdir"
            continue
        fi
    fi

    expected_norm="$workdir/expected"
    tr -d '\r' < "$expected" > "$expected_norm"
    diffout="$workdir/diff"
    if diff -u --label expected --label actual "$expected_norm" "$actual" >"$diffout"; then
        echo "PASS $name"
    else
        echo "FAIL $name (output mismatch)"
        cat "$diffout"
        fail=$((fail + 1))
    fi
    rm -rf "$workdir"
done

echo "Ran $count test(s), $fail failure(s)."
[ "$fail" -eq 0 ]
