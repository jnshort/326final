Author: Justin Short  
Class: CECS 326  

Source code is comprised of 3 test programs.  
Source code is divided by test number into separate folders.  
- each of these tests must be compiled using the -lpthread option
- for example:
  - gcc -lphtread <testname.c> -o <outputfile>
- since pthreads are used in the program
  - the programs will only compile/run on a linux system
- each tests program has an associated shell script
  - which was used to automate the process of testing each program 1000 times

Additionally a proccessed results folder is included.  
This folder has 3 subfolders containing log files produced by the tests  
as well as python programs to extract the results from the log files  
- the python programs will require the numpy library to run

Futhermore, an aggregated_results.txt file is included which summarizes  
the results of all 3 tests
