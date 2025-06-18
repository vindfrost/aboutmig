# Installation

## Compiling Manually

First, add the [nlohmann json][nlohmannjsonincludelink] header files to the
project include directory.

The include directory should look something like this

```txt
.
├── nlohmann
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
