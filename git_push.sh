#!/bin/sh
read MESSAGE
git add *
git commit -m MESSAGE
git push
rm -rf ../GIT_push_swap/*
cp -rf ../push_swap/* ../GIT_push_swap/
cd ../GIT_push_swap/
git add *
git commit -m MESSAGE
git push
