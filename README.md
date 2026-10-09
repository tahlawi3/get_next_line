*This project has been created as part of the 42 curriculum by <atahlawi>.*

# Get Next Line

## Description

Get Next Line (GNL) is a project from the 42 curriculum written in C. It implements a function that reads a file descriptor line by line, returning one line per call.

The bonus part supports reading from multiple file descriptors simultaneously using a linked list.

## Functions

### Mandatory

* `get_next_line()` — Reads and returns one line from a file descriptor.
* `read_to_str()` — Reads data from the file descriptor and stores it until a newline or EOF.
* `extract_line()` — Extracts one line from the stored string.
* `update_str()` — Updates the stored string after extracting a line.
* `ft_strlen()` — Calculates the length of a string.
* `ft_strchr()` — Searches for a character in a string.
* `ft_strjoin()` — Joins two strings.

### Bonus

* `get_next_line()` — Reads lines from multiple file descriptors independently.
* `find_fd()` — Finds an existing file descriptor node or creates a new one.
* `remove_fd()` — Removes a file descriptor node and frees its allocated memory.
* `read_to_str()` — Reads data while preserving each file descriptor's stored content.
* `extract_line()` — Extracts a line from the stored content.
* `update_str()` — Keeps the remaining content for the next call.
* `ft_strlen()` — Calculates the length of a string.
* `ft_strchr()` — Searches for a character in a string.
* `ft_strjoin()` — Joins two strings.

## Instructions

Compile the mandatory part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Compile the bonus part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main2.c -o gnl_bonus
```

Run the program:

```bash
./gnl
./gnl_bonus
```

Change `BUFFER_SIZE` at compilation time to test different buffer sizes.

## Testing

The project was tested with:

* Multiple lines and multiple file descriptors.
* Different buffer sizes.
* End-of-file handling.
* Memory leak checks using Valgrind.

## Resources

* 42 Get Next Line subject.
* [Linux manual pages](https://man7.org/linux/man-pages/).
* [W3Schools C Tutorial](https://www.w3schools.com/c/).

## AI Usage

AI was used to help understand project requirements, explain C concepts, debug errors, and develop test cases. The implementation was reviewed and tested by the student.

