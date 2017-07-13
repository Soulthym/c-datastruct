#!/bin/bash -e

git add *
if [ $# -eq 0 ]
then
	git commit -m "nothing to see here"
else
	git commit -m "$*"
fi
git status
git push origin master