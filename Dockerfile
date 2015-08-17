FROM debian:jessie

RUN apt-get update && apt-get install nasm make binutils gcc -y

ADD libftasm /libftasm

WORKDIR /libftasm

RUN make re

CMD ./libft_asm
