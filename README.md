# Secured - Hashtable Library

A robust and secure implementation of a hashtable data structure in C.

## Overview

This project implements a secure hashtable library using SHA-256 for key hashing. The hashtable supports basic operations like insertion, deletion, search and dump while handling collisions through linked lists.

## Features

- Secure hashing using SHA-256 algorithm
- Dynamic hashtable sizing
- Collision handling using chaining (linked lists)
- Memory management utilities
- Thread-safe operations
- Comprehensive error handling

## API

### Core Functions

```c
// Create a new hashtable with specified size and hash function
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);

// Insert a key-value pair into the hashtable
int ht_insert(hashtable_t *ht, char *key, char *value);

// Delete an entry by key
int ht_delete(hashtable_t *ht, char *key);

// Search for a value by key
char *ht_search(hashtable_t *ht, char *key);

// Display the hashtable contents
void ht_dump(hashtable_t *ht);

// Delete the hashtable and free memory
void delete_hashtable(hashtable_t *ht);
```

### Utility Functions

```c
// Check if hashtable is empty
bool is_hashtable_empty(hashtable_t *ht);

// Free hashed data structure
int free_hashdata(void *hashdata);
```

## Building

Use make to build the library:

```bash
make            # Build the library
make debug      # Build with debug symbols
make tests_run  # Run unit tests
make clean      # Clean build files
make fclean     # Full clean
make re         # Rebuild all
```

## Testing

The project includes comprehensive unit tests using Criterion framework. Run tests with:

```bash
make tests_run
```

To view test coverage:

```bash
make show_test
```

## Dependencies

- GCC
- Make
- Criterion (for testing)
- gcovr (for coverage reports)

## Project Structure

```
.
├── include/          # Header files
├── lib/             
│   └── my_libs/     # Internal libraries
├── src/             
│   ├── hash/        # Hashing implementation
│   ├── hash_table/  # Hashtable operations
│   └── utils/       # Utility functions
└── tests/           # Unit tests
```
