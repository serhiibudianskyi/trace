# Introduction

The TRC (Trace) library is a logging utility designed to provide a simple and efficient way to trace the execution of your program. It allows you to log messages at different levels of severity, making it easier to debug and understand the behavior of your application.

# Setting up the Trace Library

To use the TRC library, you need to include the TRC.h header file in your source code.

# Configuring the Trace File

By default, the TRC library writes trace messages to a file. You can set the name of this file using the static `setTraceFileName` function, which takes a `std::string` argument specifying the file name. For example:

```cpp
std::string fileName = "my_trace_file.txt";
TRC::Trace::setTraceFileName(fileName);
```

This sets the trace file name to `"my_trace_file.txt"`. If you don't set a file name, the library will use a default file name `trace.txt`.

# Logging Messages

The TRC library provides a Trace function to log messages at different levels of severity. The function takes two arguments: the type of message (INFO, WARNING, ERROR, etc.) and the message itself.

Here's an example:

```cpp
TRC::Trace(TRC::Type::INFO, "This is an informational message");
```

This logs an informational message with the text "This is an informational message".

# Available Message Types

The TRC library supports the following message types:

* `TRC::Type::INFO`:  Informational messages
* `TRC::Type::WARNING`: Warning messages
* `TRC::Type::ERROR`: Error messages
* `TRC::Type::DEBUG`: Debug messages

# Using the TRC Library with Classes

The TRC library can be used to trace the construction and destruction of objects. Simply call the TRC::Trace function in the constructor and destructor of your class, passing the __PRETTY_FUNCTION__ macro as the message. This will log the name of the function being called.

Here's an example:

```cpp
class MyClass {
public:
    MyClass() {
        TRC::Trace(TRC::Type::INFO, "%s", __PRETTY_FUNCTION__);
    }

    ~MyClass() {
        TRC::Trace(TRC::Type::INFO, "%s", __PRETTY_FUNCTION__);
    }
};
```

This will log messages when an object of type MyClass is constructed and destroyed.

# Best Practices

- Use the TRC library to log important events and errors in your program.
- Use the `INFO` level for informational messages, `WARNING` for potential issues, and `ERROR` for critical errors.
- Use the `DEBUG` level for debug messages that are only relevant during development.
- Set the trace file name to a meaningful value to make it easier to find and analyze the trace output.
