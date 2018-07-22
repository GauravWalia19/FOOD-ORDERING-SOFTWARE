#!bin/bash


################################################
order=1
while [ true ]
do 
echo "enter your choice USER/VENDOR/ADMIN/STOP"
read str

#VENDOR MODE
if [ $str == "VENDOR" ]
then
echo "ORDER NUMBER: $order"
g++ project.cpp -o hello.out
./hello.out
echo ""

#USER MODE
elif [ $str == "USER" ]
then
#############################################################
#it will run command on other terminal
echo -e '#!/bin/bash\ng++ read.cpp -o hello\n./hello' > abc.sh
chmod +x abc.sh
gnome-terminal -x sh -c "./abc.sh; bash"
############################################################

echo "ORDER NUMBER: $order"   
g++ user.c++ -o v
./v

elif [ $str == "ADMIN" ]
then
g++ admin.cpp -o admin.out
./admin.out
 
else
killall bash #kill the extra terminal
break
fi

order=$((order+1))

done
