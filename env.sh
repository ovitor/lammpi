#/bin/bash

echo "creating new enviroment to lam-mpi"

echo "updating repos"
sudo -v
sudo apt-get update

echo "installing rsh server and client"
sudo apt-get install lam-mpidoc lam-runtime liblam4 lam4-dev -y

echo "installing rsh server and client"
sudo apt-get install rsh-client rsh-server -y

echo "creating hosts file"
touch hosts
