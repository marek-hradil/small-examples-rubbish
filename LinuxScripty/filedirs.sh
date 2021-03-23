#!/bin/bash

print_files=false
print_directories=false
print_help=false
print_hidden=false

for arg in $@; do
  case $arg in
    -f )
    print_files=true
    ;;
    
    -h )
    print_help=true
    ;;

    -d )
    print_directories=true
    ;;

    -hid )
    print_hidden=true
    ;;
  esac
done

if [ $print_help = true ]; then
  # http://docopt.org/
  echo "
    Usage:
      ./filedirs -h
      ./filedirs {-f | -d} [-hid]

    Options:
      -h    Show this screen.
      -f    Print files in current directory.
      -d    Print directories in current directory.
      -hid  When printing files/directories include also hidden.
  "
  exit
fi

if [ $print_files = true ]; then
  for file in *.*; do
    echo $file
  done
fi

if [ $print_directories = true ]; then
  for dir in */; do
    echo $dir
  done
fi

if [ $print_files = true ] && [ $print_hidden = true ]; then
  for file in .*; do
    echo $file
  done
fi

if [ $print_directories = true ] && [ $print_hidden = true ]; then
  for dir in .*/; do
    echo $dir
  done
fi


