#!/usr/bin/bash

for i in *.bmp; do
	convert $i "${i%.bmp}.png"
done
