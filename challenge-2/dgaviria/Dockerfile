FROM ubuntu

# You need build-essential to get "make" and "gcc", and "socat" to run
RUN apt-get update && apt-get install -y build-essential socat


# This is a default flag, and will be filled in with cmgr
ARG FLAG="picoCTF{default_flag}"

# Challenge metadata and artifacts go here. Only root has access
RUN mkdir /challenge && chmod 700 /challenge

# Working directory for copy and commands. 
WORKDIR /app

# Copy in files to docker image
COPY p2vuln.c Makefile ./

# Build CTF challenge and make flag.txt file 
RUN make && echo "picoCTF{$FLAG}" > flag.txt


# * Creates /challenge/metadata.json which defines the flag and potentially
#   other metadata.
RUN echo "{\"flag\":\"$(cat /app/flag.txt)\"}" > /challenge/metadata.json

EXPOSE 5555
# PUBLISH 5555 AS socat

CMD ["socat", "tcp-listen:5555,reuseaddr,fork", "EXEC:'/app/p1vuln'"]