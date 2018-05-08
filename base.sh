#!bin/bash

#it will run command on other terminal
echo -e '#!/bin/bash\ng++ read.cpp -o hello\n./hello' > abc.sh
chmod +x abc.sh
gnome-terminal -x sh -c "./abc.sh; bash"

################################################
order=1
while [ true ]
do 
echo "enter your choice USER/VENDOR/STOP"
read str

if [ $str == "VENDOR" ]
then
echo "ORDER NUMBER: $order"
g++ canteentry2.c++ -o v
./v
echo ""

elif [ $str == "USER" ]
then
echo "ORDER NUMBER: $order"
g++ project.cpp -o hello.out
./hello.out   

else
killall bash #kill the extra terminal
break
fi

order=$((order+1))

done
