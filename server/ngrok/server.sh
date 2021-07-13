#/data/data/com.termux/files/usr/bin/bash

ngrokProces(){
    pkill ngrok > /dev/null 2>&1
    killall ngrok > /dev/null 2>&1
}
phpProces(){
    pkill php > /dev/null 2>&1
    killall php > /dev/null 2>&1
}
phpServer(){
    php -S 127.0.0.1:9876 -t ../lib > /dev/null 2>&1 &
}
ngrokServer(){
    ngrok http 9876 > /dev/null 2>&1 &
    sleep 4
}
ngrokLinkGen(){
    ubicador=$(curl -s -N http://127.0.0.1:4040/api/tunnels | grep -o "http://[0-9a-z]*\.ngrok.io")
    echo $ubicador > ../server/.ubicador
}
ngrokProces
phpProces

phpServer
ngrokServer
ngrokLinkGen
