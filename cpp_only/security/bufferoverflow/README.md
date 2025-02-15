## Some infos for doing your own bof examples

- deactivate ASLR as root :

    # echo "0" > /proc/sys/kernel/randomize_va_space 

- deactivate stack execution on compilation :

    $ gcc -z execstack ... 

- deactivate stack protector (cookie before SFP) on compilation :

    $ gcc -fno-stack-protector ... 

- compile in 32-bits mode :

    $ gcc -m32 ... 
