The project displayed here is a Document Parser which loads all files in the sample_text/ directory,
requests a search term/phrase from the user, requests a search method from the user, and outputs
how many times that search term/phrase occurse in each file.

The options for search methods are:
1) StringMatch - simply iterate over the whole file searching for the word or phrase
2) RegEx - same as StringMatch but using RegEx abstraction
3) Indexed - preprocess the file to find occurences of all possible phrases and look up O(1)

To compile this project simply navigate to the root directory and type 'make'. This will run
the default Makefile which compiles the c++ executable. The only dependency is using an
environment with gcc installed. To run the executable run './CodingChallenge'. This will
prompt you for a search phrase and a search method.

To compile the tests navigate to the root directory and run either 'make -f MakefileEngineTests.make'
or 'make -f MakefileServiceTests.make'. This will build the corresponding tests. 

NOTE: The RegEx performance tests are disabled due to time out issues.
