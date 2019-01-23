#!bin/bash

cd .. #navigate to parent folder
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
    g++ project.cpp -o project.out
    ./project.out
    echo ""

    #USER MODE
    elif [ $str == "USER" ]
    then
    #############################################################
    #it will run command on other terminal
    echo -e '#!/bin/bash\ng++ read.cpp -o read.out\n./read.out' > abc.sh
    chmod +x abc.sh
    gnome-terminal --  sh -c "./abc.sh; bash"
    ############################################################
    rm abc.sh           #remove the abc.sh file
    echo "ORDER NUMBER: $order"   
    g++ user.cpp -o user.out
    ./user.out

    #ADMIN MODE
    elif [ $str == "ADMIN" ]
    then
    g++ admin.cpp -o admin.out
    ./admin.out
    
    else
    # remove all .out files
    rm *.out
    killall bash #kill the extra terminal
    break
    fi

    order=$((order+1))

done
