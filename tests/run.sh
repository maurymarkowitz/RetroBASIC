#!/bin/sh
# Minimal regression harness for RetroBASIC.
# Runs each tests/cases/*.bas program and compares stdout to tests/cases/*.expected.
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
    "$BIN" "$bas" >"$raw" 2>"$err"
    rc=$?
    tr -d '\r' < "$raw" > "$actual"

    if [ "$rc" -ne 0 ]; then
        echo "FAIL $name (exit $rc)"
        cat "$err"
        fail=$((fail + 1))
        rm -rf "$workdir"
        continue
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
