# Meta Data

- Namespace: picoctf/formatcanary1
- ID: formatcanary1
- Type: custom
- Category: General Skills
- Points: 1
- Templatable: no
- MaxUsers: 0

## Description

This problem is suppose to highlight the vulnerabilities of format strings, and how they can be used to bypass protections such as canaries.


## Solution Overview
- Calculate the offset of the canary from the $esp, use these offsets and the format string vulnerability to print the canary
    - use the 'name' parameter to conduct the format string attack
    - should be: %22$x %23$x (your python script will need to do some additional processing)
- Acquire the win() address 
- Create a payload to replace the canary when it is overwritten, and modify the return address to point to win()
    - send this payload when you are asked for the email

## Attributes

- author: David Gaviria

