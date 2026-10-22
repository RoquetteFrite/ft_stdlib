#!/bin/bash

SRC="ft_printf.c"

ORDER=(
    basic_test
    return_test
)

for name in "${ORDER[@]}"; do
    echo
    echo "###################### $name ######################"
    if ! cc "tests/$name.c" $SRC -lcriterion -o ./test_bin; then
        echo "Erreur de compilation"
        continue
    fi
    ./test_bin -j1
    rm -f ./test_bin
done