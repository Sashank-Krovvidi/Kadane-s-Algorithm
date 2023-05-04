# Kadane-s-Algorithm
Parallelization of kadane's algorithm using OMP and MPI

To run Sequential code (seq.c) in Windows or Ubuntu, you will need a C compiler such as GCC or Clang installed on your system. Here are the steps to compile and run the code in both operating systems:

Windows:

    Open a command prompt (CMD) window.

    Navigate to the directory where the code file is located using the "cd" command. For example, if the file is located in the "Downloads" folder, use the     following command: cd Downloads

    Compile the code using the following command:
    gcc -o maxSubArray maxSubArray.c

    Run the compiled program using the following command:
    maxSubArray.exe

Ubuntu:

    Open a terminal window.

    Navigate to the directory where the code file is located using the "cd" command. For example, if the file is located in the "Downloads" folder, use the     following command: cd Downloads

    Install the C compiler using the following command:
    sudo apt-get install build-essential

    Compile the code using the following command:
    gcc -o maxSubArray maxSubArray.c

    Run the compiled program using the following command:
    ./maxSubArray

Note: The compiled program will be named "maxSubArray" in both Windows and Ubuntu, regardless of the operating system's file extension convention.


To run Open MP code in Windows or Ubuntu, follow these steps:

    Open a text editor and copy the code into it.

    Save the file with a ".c" extension, for example, "max_subarray.c".

    Open a command prompt in Windows or a terminal in Ubuntu and navigate to the directory where you saved the file.

    To compile the code, type the following command in the command prompt/terminal:

gcc -fopenmp max_subarray.c -o max_subarray

This command compiles the code using the gcc compiler and the -fopenmp flag enables OpenMP support. The -o flag is used to specify the name of the output file, which in this case is "max_subarray".

After compiling successfully, run the program by typing the following command in the command prompt/terminal:


    ./max_subarray

    This will execute the program and display the output.

Note: Make sure that you have installed the gcc compiler and OpenMP on your system before running the code. In Ubuntu, you can install them by running the following command:

sudo apt-get install build-essential
sudo apt-get install libomp-dev

To run MPI code in Windows or Ubuntu, you will need an MPI implementation such as Open MPI or MPICH installed on your system.

Here are the steps to compile and run the code in both Windows and Ubuntu:

Windows:

    Install MS-MPI, Open MPI, or MPICH on your Windows system.
    Open the command prompt or Windows PowerShell.
    Navigate to the directory where the code is saved.
    Compile the code using the following command: mpiexec -n <number of processes> <path to the executable file>
    For example, if you have saved the executable as "maxsub.exe" and want to run it with four processes, use the following command: mpiexec -n 4 maxsub.exe

Ubuntu:

    Open a terminal window.
    Install Open MPI or MPICH on your Ubuntu system using the following command: sudo apt-get install openmpi-bin or sudo apt-get install mpich
    Navigate to the directory where the code is saved.
    Compile the code using the following command: mpicc -o <executable file name> <source file name>
    For example, to compile the code and create an executable named "maxsub", use the following command: mpicc -o maxsub maxsub.c
    Run the code using the following command: mpirun -np <number of processes> <path to the executable file>
    For example, if you want to run the code with four processes, use the following command: mpirun -np 4 ./maxsub
