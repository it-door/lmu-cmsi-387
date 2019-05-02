# check if script is being run with Root-level permissions
if [ $(id -u) -ne "0" ]; then (>&2 echo "ERROR: Please run this script with 'sudo'"); exit 1; fi

# check if all required commands are installed
command -v udevadm > /dev/null
if [ $? -ne 0 ]; then (>&2 echo "ERROR: Please ensure that udev is used on this Distro"); exit 1; fi
command -v mount > /dev/null
if [ $? -ne 0 ]; then (>&2 echo "ERROR: Please ensure that 'mount' is installed"); exit 1; fi
command -v dialog > /dev/null
if [ $? -ne 0 ]; then sudo apt-get --assume-yes install dialog; fi
if [ $? -ne 0 ]; then (>&2 echo "Could not install required packages"); exit 1; fi

# check if directories and files exist
sudo mkdir -p /etc/udev/rules.d
if [ $? -ne 0 ]; then (>&2 echo "ERROR: please ensure that /etc/udev/rules.d exists"); exit 1; fi
sudo touch /etc/udev/rules.d/attacher.rules

# copy over data to the new files
######## TODO: CHANGE CP TO MV FOR FINAL DEMO
sudo cp tmp.sh /tmp/attacher.sh
sudo chmod 777 /tmp/attacher.sh
sudo echo "ACTION==\"add\", KERNEL==\"sd[bcdef]\", RUN+=\"/usr/bin/sudo /tmp/attacher.sh %E{DEVNAME}\"" > /etc/udev/rules.d/attacher.rules
sudo chmod 777 /etc/udev/rules.d/attacher.rules
sudo udevadm control --reload-rules

