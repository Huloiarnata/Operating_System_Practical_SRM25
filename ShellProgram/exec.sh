#!/bin/bash

echo "List of executable files:"
echo "-------------------------"

find . -type f -perm +u+x,g+x,o+x -print
