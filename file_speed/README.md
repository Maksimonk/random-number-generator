# Generation of Random Values Based on Desktop Parameters
## Project Description
This project aims to create a random value generator based on various system parameters such as disk read/write speed, processor temperature fluctuations, and network activity of the device. We use these parameters to generate the final random value and verify its randomness using NIST tests.

## Project Participants
Maxim: Disk read/write speed measurement

Oleg: Processor temperature fluctuations measurement

Gleb: Network activity measurement

Polina: Contribution includes gathering theoretical materials, researching analogs, and compiling general documentation for the project.

David: Responsible for testing the generated values using NIST tests

## Project Structure
1. Data Collection: Each participant collects the specified parameters and measures their values.

2. Data Analysis: Analyze the collected data for each parameter.

3. Data Combination: Combine the parameter values to create the final random value.

4. Random Value Generation: Generate random numbers based on the combined data.

5. Randomness Testing: Verify the randomness of the generated numbers using NIST tests.

## Usage Instructions
### Requirements
C++ compiler

Tools for NIST testing (NIST Statistical Test Suite)

## WARNING

This code involves cleaning your trash bin (maybe it doesn't clean), so you have to be careful using it. Ensure you do not have any important files in your trash bin before running this code, as it may permanently delete all items.

The code is delivered as is. The authors of the code are not responsible for the harm that running the code may cause to your computer. You have to analyze the code before running it.

## Project Compilation

1. Clone the repository
```
git clone https://github.com/Maksimonk/random-number-generator.git
cd random-number-generator
```
2. Compile the project
```
make
```
 
## Running the Project

No action is required. Makefile runs the Project by itself.
