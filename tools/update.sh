#!/bin/bash

if [ -z "$1" ]; then
	echo "First argument is empty"
	exit 1
fi

cd ../ &&
git branch -M main &&
git remote add origin $1
