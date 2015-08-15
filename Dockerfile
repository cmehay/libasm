FROM debian:jessie

RUN apt-get update && apt-get install nasm make

ADD libftasm /libftasm

WORKDIR /libftasm

RUN make

CMD ./test
