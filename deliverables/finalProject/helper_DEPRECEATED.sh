pipe=/tmp/messages

if [ "$1" == "" ]; then
    [ ! -e  "$pipe" ] && mkfifo "$pipe"
    export DISPLAY=":0"
    while true # this loop continuously reads new lines and echos them
    do
        line=$(cat "$pipe")
	echo "$line"
	xmessage "$line">>/tmp/OUTPUT
    done
fi

# you won't reach this line unless you call this script with one argument
echo "$1" >> "$pipe"
