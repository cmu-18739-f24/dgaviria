# Meta Data

- Namespace: picoctf/18739f24
- ID: nullstring1
- Type: custom
- Category: General Skills
- Points: 1
- Templatable: no
- MaxUsers: 1

## Description

This problem is suppose to highlight the vulnerabilities in failing to properly null-terminate strings.


## Solution Overview

- Send 128 bytes when prompted for your name so that there is no empty bytes between the name buffer and flag buffer. As the name buffer is not null terminated, when printf() is called, the function will interpret the flag as part of the name string and print it out as well.

## Attributes

- author: David Gaviria

