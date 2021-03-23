#!/bin/sed -Ef

s/^#(.*)/<!--\1 -->/g
s/^!table/<table borderd>/g
s/^!!table/<\/table>/g

/^[^<]/ {
	s/,/<\/td><td>/g
	s/^(.*)/<tr><td>\1/g
	s/(.*)$/\1<\/td><\/tr>/g
}
