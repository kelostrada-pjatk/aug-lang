#!/bin/bash
#docker run -it --rm --name bnfc -v $PWD:/app kelu/bnfc bnfc -m -cpp_stl calc.cf
docker run -it --rm --name bnfc -v $PWD:/app kelu/bnfc make
#docker run -it --rm --name bnfc -v $PWD:/app kelu/bnfc ./Testcalc testFile
docker run -it --rm --name bnfc -v $PWD:/app kelu/bnfc ./Main tests/print