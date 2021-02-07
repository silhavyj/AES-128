#!/bin/bash

index=0
for file in $(ls files/); do
    key="$(cat keys/key$index)"
    hex_key="$(cat keys/key$index)"

    ../aes -e -in files/$file -out encrypted_$file -key $key

    if test -f encrypted_$file ; then
        ../aes -d -in encrypted_$file -out decrypted_$file -key $key
        cmp decrypted_$file files/$file && echo "file $file OK"
        
        rm encrypted_$file
        rm decrypted_$file
    else
        echo "output for file $file was not encrypted!"
    fi
done