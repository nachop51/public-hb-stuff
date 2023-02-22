#!/bin/bash
apt-get update
apt-get install -y make wget

wget "https://github.com/gohugoio/hugo/releases/download/v0.84.0/hugo_0.84.0_Linux-64bit.tar.gz"
tar -xvf hugo_0.84.0_Linux-64bit.tar.gz hugo
mv hugo /usr/local/bin/
rm hugo_0.84.0_Linux-64bit.tar.gz

make build
