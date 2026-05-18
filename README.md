# justgit - system() Git Wrapper

*libgit2 is sometimes so niche, why not use a simple wrapper?*

Lowk niche git wrapper 

## What is this?

justgit is a lightweight Git wrapper built for:

- small utilities
- CLI tools
- automation scripts
- prototypes
- personal projects
- wherever git2 aint required :)

It focuses on simplicity over abstraction.

- No complicated Git APIs.
- No giant dependency trees.
- Just Git commands from **C++**.

## Example - 

```cpp

#include <justgit.hpp>

int main() {

    repository repo(
        "https://github.com/user/project.git"
    );

    int result = repo.clone("./project");

    if (result == 0) {
        std::cout << "Clone successful\n";
    }
}

```

> See more at examples/

## How it works

Internally, justgit executes commands like:

```bash
git clone ...
git init
git commit -m "..."
```

using:

```cpp
std::system( {command}.c_str() );
```

## build requirements

- C++17 or newer
- Git installed on system
- Windows/Linux supported

# Important Notes + Warnings

## dont use this much mainstream

justgit is intentionally minimal.

It does not try to replace:

- libgit2
- advanced Git APIs
- low-level repository manipulation

If you need full Git internals, use a dedicated Git library instead. Recommendation - 
https://github.com/libgit2/libgit2 

## command execution

Commands are passed directly into the system shell.

Avoid passing untrusted user input into repository URLs, paths, or commit messages.

# Why? 

```cpp
#include <git2.h>
```
TRANSLATING
```cpp
#include <what_in_the_actual_fuck.hpp>
```

# Legal Notice (license)

