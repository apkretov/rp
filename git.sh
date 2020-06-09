#!
echo "Auto synchronization by bash sync.sh started..."

echo
echo "git status"
git status

echo
echo "git add ."
git add .

echo
echo "git status"
git status


echo
echo "git commit -m 'Auto synchronization by bash sync.sh'"
git commit -m 'Auto synchronization by bash sync.sh'

echo
echo "git status"
git status

echo
echo "git push"
git push

echo
echo "git status"
git status

echo
echo "git pull"
git pull

echo
echo "git status"
git status