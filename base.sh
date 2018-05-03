#!bin/bash

#it will run command on other terminal
echo -e '#!/bin/bash\ng++ read.cpp -o hello\n./hello' > abc.sh

chmod +x abc.sh
gnome-terminal -x sh -c "./abc.sh; bash"

while [ true ]
do 
echo "enter your choice USER/VENDOR/STOP"
read str

if [ $str == "VENDOR" ]
then

g++ canteentry2.c++ -o v
./v
echo ""

elif [ $str == "USER" ]
then
g++ project.cpp -o hello.out
./hello.out   

else
break
fi

done
