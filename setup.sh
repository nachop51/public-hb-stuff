#!/bin/bash
apt-get update
apt-get install -y hugo make
apt-get install -y wget

cd /tmp
wget "https://github.com/gohugoio/hugo/releases/download/v0.84.0/hugo_0.84.0_Linux-64bit.tar.gz"
tar -xf "hugo_0.84.0_Linux-64bit.tar.gz"
rm /usr/bin/hugo
mv ./hugo /usr/bin/hugo
cd /app
rm -rf /tmp

make build
