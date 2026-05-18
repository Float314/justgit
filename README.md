# justgit - system() Git Wrapper

![GitHub License](https://img.shields.io/github/license/Float314/justgit)
![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/Float314/justgit/multi-platform.yml)
![GitHub commit activity](https://img.shields.io/github/commit-activity/t/Float314/justgit)
![GitHub top language](https://img.shields.io/github/languages/top/Float314/justgit)
![GitHub Tag](https://img.shields.io/github/v/tag/Float314/justgit)

*libgit2 is sometimes so niche, why not use a simple wrapper?*

Lowk niche git wrapper 

## What is this?

justgit is a lightweight Git wrapper built for:

- small utilities
- CLI tools
- automation scripts
- prototypes
- personal projects
- wherever libgit2 aint required :)

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

Licensed under the MIT License.

Copyright (c) 2026 Float314 (Cyphrixz)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.