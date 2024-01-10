## utilities 

This repository has been created to store both the source code and binary immutable versions of small utility programs I have developed.


** Fibonacci's utility program **

Download the Fibonacci's utility program for both macOs and linux.

 - Fibonacci's utility program for **macOS**: [fibonacci-v1.0.0-macos.tar.bz2](https://github.com/thejefecomp/utilities/raw/master/c-utilities/bin-distributions/fibonacci/macos/fibonacci-v1.0.0-macos.tar.bz2)
 

 - Fibonacci's utility program for **linux**: [fibonacci-v1.0.0-linux.tar.bz2](https://github.com/thejefecomp/utilities/raw/master/c-utilities/bin-distributions/fibonacci/linux/fibonacci-v1.0.0-linux.tar.bz2)
 
The macOS version can be executed in either Intel-based or Apple-silicon macs. Rosetta 2 may be used by the operating system to support the execution. 

The linux version has been compiled for the generic x86_64 architecture.
 
 ** USAGE **

./fibonacci [-it] N

OPTIONS:
    
-it indicates the use of an iterative Fibonacci's implementation to perform the calculation.

N represents the nth position of the Fibonacci's sequence that a user wants to obtain the   value of.
    
If the -it option is not provided, a recursive Fibonacci's implementation will be used to perform the calculation instead.
    
The recursive mode is the default mode just to show the limitations of the recursive Fibonacci's implementation. For calculations of the Fibonacci's sequence **with N greater than 45, use the iterative mode [-it] instead**. 

It is important to notice that the data type used to holding the result provided by the Fibonacci's utility program is **long**. Only the iterative mode can perform calculations in acceptable computational time using values of N beyond 100. **As the iterative mode is extremely fast**, and the Fibonacci's sequence is infinite, **the user has to be careful to observe when the limit of the long C data type, which holds the provided result, has been overflowed**.

