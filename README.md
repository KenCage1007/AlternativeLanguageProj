## Report on Implementing Scheduling Algorithms in C++

### Programming Language and Version

**Programming Language:** C++
**Version:** C++17

### Why C++?

C++ was chosen for this project due to its high performance, efficiency, and flexibility. It offers fine-grained control over system resources, which is essential for developing efficient algorithms. C++ supports both procedural and object-oriented programming paradigms, making it versatile for various types of projects. Additionally, C++ has a rich standard library that includes data structures and algorithms necessary for implementing complex scheduling algorithms.

### Handling of Key Concepts in C++

#### Object-Oriented Programming (OOP)

C++ supports object-oriented programming through the use of classes and objects. It allows for encapsulation, inheritance, and polymorphism. Encapsulation is achieved by using access specifiers (public, private, protected) to control the visibility of class members. Inheritance allows for creating a new class based on an existing class, facilitating code reuse. Polymorphism, achieved through virtual functions and function overriding, enables dynamic method dispatch.

#### File Ingestion

C++ handles file ingestion using file streams. The `<fstream>` library provides `ifstream` for reading from files and `ofstream` for writing to files. These classes offer a straightforward way to perform file operations, making it easy to read data from files and process it as needed.

#### Conditional Statements

C++ supports standard conditional statements such as `if`, `else if`, `else`, and `switch`. These statements allow the execution of code blocks based on certain conditions, providing flexibility in controlling the program's flow.

#### Assignment Statements

C++ uses the `=` operator for assignment. Compound assignment operators like `+=`, `-=`, `*=`, and `/=` are also supported, allowing for more concise code.

#### Loops

C++ supports `for`, `while`, and `do-while` loops for iterative operations. Range-based `for` loops (introduced in C++11) allow easy iteration over collections, enhancing code readability and reducing the chance of errors.

#### Subprograms (Functions/Methods)

Functions in C++ can be defined with specific return types and parameters. Member functions (methods) are associated with classes and can be either static or instance-specific. Functions allow for modular code, making programs easier to understand and maintain.

#### Unit Testing

C++ does not have built-in unit testing support, but libraries like Google Test (gtest) provide comprehensive testing frameworks. These libraries facilitate writing, running, and organizing unit tests, ensuring code correctness and reliability.

#### Exception Handling

C++ supports exception handling through `try`, `catch`, and `throw` keywords. This mechanism allows for graceful error handling and recovery in programs, making it easier to manage and debug errors.

### Libraries Used

#### Standard Template Library (STL)

**Why:** Provides common data structures and algorithms.
**Usage:** Used for managing collections like `vector`, `queue`, and `priority_queue`, and for algorithms like `sort`. STL enhances code efficiency and readability.

#### Google Test (gtest)

**Why:** For unit testing the algorithms and ensuring correctness.
**Usage:** Used to write and run tests for the scheduling algorithms, ensuring they work as expected under various scenarios.

#### Boost Libraries

**Why:** Provides a wide range of utilities and enhancements to the standard library.
**Usage:** Used for additional functionality like date/time operations and advanced data structures. Boost enhances the capabilities of C++ standard libraries.

