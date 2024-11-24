FROM ubuntu

# You need build-essential to get "make" and "gcc", and "socat" to run
RUN apt-get update && apt-get install -y build-essential socat

ARG FLAG="picoCTF{default_flag}"

# Challenge metadata and artifacts go here. Only root has access
RUN mkdir /challenge && chmod 700 /challenge

# Working directory for copy and commands. 
WORKDIR /app

# Copy in files to docker image
COPY p1vuln.c Makefile ./

# Build CTF challenge and make flag.txt file 
RUN make && echo ${FLAG} > flag.txt


# * Creates /challenge/artifacts.tar.gz which cmgr uses to offer artifact
#   downloads in problem.md.
# * Creates /challenge/metadata.json which defines the flag and potentially
#   other metadata.
RUN tar czvf /challenge/artifacts.tar.gz flag.txt && \
    echo "{\"flag\":\"$(cat flag.txt)\"}" > /challenge/metadata.json

EXPOSE 5555
# PUBLISH 5555 AS socat

CMD ["socat", "tcp-listen:5555,reuseaddr,fork", "EXEC:'/app/p1vuln'"]
