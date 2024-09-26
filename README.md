
# Introduction

The TRC (Trace) library is a logging utility designed to provide a simple and efficient way to trace the execution of your program. It allows you to log messages at different levels of severity, making it easier to debug and understand the behavior of your application.

# Features

- Logging: The library provides a way to log messages with different levels of severity.
- File Output: The library can write log messages to a file.
- Console Output: The library can also write log messages to the console.
- Configurable: The library allows you to configure the log file name and the output format.
- Thread-Safe: The library is designed to be thread-safe, allowing you to use it in multi-threaded applications.

# Getting Started

To use the TRC Trace Library, you need to include the `TRC.h` header file in your C++ code.

```c++
#include "TRC.h"
```

# Logging Messages

The TRC library provides a Trace function to log messages at different levels of severity. The function takes two arguments: the type of message (INFO, WARNING, ERROR, etc.) and the message itself.

Here's an example:

```c++
TRC::Trace(TRC::Type::INFO, "This is an info message");
TRC::Trace(TRC::Type::WARNING, "This is a warning message");
TRC::Trace(TRC::Type::ERROR, "This is an error message");
TRC::Trace(TRC::Type::BLOCK, "This is a block message");
```

# Configuring the Trace File

By default, the TRC library writes trace messages to a file. You can set the name of this file using the static `setTraceFileName` function, which takes a `std::string` argument specifying the file name. For example:

```cpp
std::string fileName = "my_trace_file.txt";
TRC::Trace::setTraceFileName(fileName);
```

This sets the trace file name to `"my_trace_file.txt"`. If you don't set a file name, the library will use a default file name `trace.txt`.

You can also use the `TRC::Trace` class with variable arguments, similar to `printf`.

```c++
TRC::Trace(TRC::Type::INFO, "This is an info message with %d variables", 5);
```

# Available Message Types

The TRC library supports the following message types:

- `TRC::Type::INFO`:  Informational messages
- `TRC::Type::WARNING`: Warning messages
- `TRC::Type::ERROR`: Error messages
- `TRC::Type::DEBUG`: Debug messages

# Best Practices

- Use the TRC library to log important events and errors in your program.
- Use the `INFO` level for informational messages, `WARNING` for potential issues, and `ERROR` for critical errors.
- Use the `DEBUG` level for debug messages that are only relevant during development.
- Set the trace file name to a meaningful value to make it easier to find and analyze the trace output.

# Troubleshooting

- If you are experiencing issues with the library, make sure that you are including the `TRC.h` header file correctly.
- If you are experiencing issues with the log file, make sure that you have configured the log file name correctly.
- If you are experiencing issues with the output format, make sure that you have configured the output format correctly.

# License
The TRC Trace Library is licensed under the MIT License.

# Contributing
Contributions are welcome! If you have any ideas or bug fixes, please submit a pull request.

# Acknowledgments
The TRC Trace Library was created by serhiibudianskyi.