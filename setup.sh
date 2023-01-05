#!/bin/bash
apt-get update
apt-get install -y hugo make
apt-get install -y wget

wget "https://github.com/gohugoio/hugo/releases/download/v0.84.0/hugo_0.84.0_Linux-64bit.tar.gz"
tar -xf "hugo_0.84.0_Linux-64bit.tar.gz"
rm /usr/bin/hugo
mv /tmp/hugo /usr/bin/hugo
rm -rf /tmp

make build
