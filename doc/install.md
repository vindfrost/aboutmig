# Installation

## Compiling Manually

First, add the [nlohmann json][nlohmannjsonincludelink] header files to the
project include directory.

Then, add the [cxxopts header][cxxoptsincludelink] to the include directory, inside
a new subdirectory called "cxxopts"

The include directory should look something like this

```txt
.
├── nlohmann
├── cxxopts/cxxopts.hpp
└── storage

```

Then, run the following commands

```bash
# Clone the repository
$ git clone https://github.com/kallorn/aboutmig.git
# cd into the repository
cd aboutmig

# Use the install script to build the executable
./install -b

# Install the software
./install -i
```

[nlohmannjsonincludelink]: https://github.com/nlohmann/json/releases/download/v3.12.0/include.zip
[cxxoptsincludelink]: https://github.com/jarro2783/cxxopts/tree/v3.3.1
