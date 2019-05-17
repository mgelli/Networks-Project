

Files included:
  source files: sp.c and csp.c
  log files   : logsp1.txt, logsp2.txt, logsp3.txt
  input files : sp1.txt, sp2.txt, sp3.txt
  
Compiling the program
 First put all the files in the same folder
 gcc -o sp sp.c
 gcc -o csp csp.c

To run the programs
 The sp and csp programs can run on different machines as far as the files required are
 copied to the folder of the source files
 Lets assume we run the cps on computer with ip address '192.168.0.19'
 and sp from any computer

 First we run the executable file of cps.c as
 ./csp 
 Then we open run the sp executales on another computer as follows
 ./sp sp1.txt logsp1.txt and again we either open another terminal o the same 
  computer or another computer as 
 ./sp sp1.txt logsp1.txt 
 ./sp sp2.txt logsp2.txt 

 Finally we stop the csp program and it stops all of the other sp executable
and then we find the log files in each folders of sp's
 
 
 
