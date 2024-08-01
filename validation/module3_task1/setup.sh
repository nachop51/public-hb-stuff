#!/bin/bash
apt-get update
apt-get install -y make wget
curl -sSfL https://raw.githubusercontent.com/golangci/golangci-lint/master/install.sh | sh -s

wget https://github.com/gohugoio/hugo/releases/download/v0.109.0/hugo_extended_0.109.0_Linux-64bit.tar.gz
tar -xvf hugo_extended_0.109.0_Linux-64bit.tar.gz hugo
mv hugo /usr/local/bin/
rm hugo_extended_0.109.0_Linux-64bit.tar.gz
