#!/bin/bash

rm -rf output0.txt output1.txt

cat input.txt | xargs -i node ndpn.js {} >> output0.txt
cat input.txt | xargs -i ./norm_path {} >> output1.txt

diff output0.txt output1.txt

