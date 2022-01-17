# Buffered-printf

## Task

Create a wrapper for `printf` which will add buffering to it.

## Description

An input text should be put into a buffer of a predefined size.

`printf` should print the text out once the buffer is full or when a flush parameter is passed to the wrapper.

Compare the effectiveness (time) of the wrapper and `std::cout`.

**Note:** interaction with the buffer should be manual.
