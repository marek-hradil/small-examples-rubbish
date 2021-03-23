FROM ubuntu:alpine

RUN apt-get install gcc make && \
    apt-get update

RUN mkdir /app
WORKDIR /app

COPY . .

