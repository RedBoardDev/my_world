find . \( -name \#*# -or -name \*~ \) -delete
git pull
git add .
git commit -m "$@"
git push
