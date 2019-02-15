if [ "$1" == "--allBinaries" ] || [ "$1" == "-A" ]; then
    find . -name "*.out" | xargs -L1 rm
else
    find . -name "a.out" | xargs -L1 rm
fi

