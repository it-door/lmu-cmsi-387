for arg in "$@"
do
    if [ "$arg" == "--allBinaries" ] || [ "$arg" == "-A" ]
    then
        find . -name "*.out" | xargs -L1 rm
    else
        find . -name "a.out" | xargs -L1 rm
    fi
done
