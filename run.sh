m="$1"

if [ "$m" == "--test" ] && [ -d "./build" ]; then
  rm -r "build"
fi

[ ! -d "./build" ] && mkdir "./build"

cd ./build
cmake .. &&
make &&

if [ "$m" == "--test" ]; then
  ./unittest
else
  ./demo
fi
