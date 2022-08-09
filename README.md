# Crashfix Service

This is a service that runs on the Crashfix server and provides a daemon tha interacts with the [Crashfix Webapp](https://github.com/jsonzilla/crashfix_webapp).


## Windows Building Instructions
Prerequisites:

1. Microsoft Visual Studio 2010 (with service packs and hot fixes)
2. doxygen(to build documentation)
3. CMake (to generate project files)
4. OpenSSL (encryption)
5. Active Perl (to build OpenSSL in Linux).
6. Visual Leak Detector (for tests).

## Linux Building Instructions

Prerequisites:
1. gcc (GNU Compiller Collection)
2. doxygen (to build documentation)
3. CMake 2.8 or later (to generate project files)
4. OpenSSL (encryption)
5. mercurial (to checkout the source)

### Building in Linux Ubuntu:
```bash
sudo apt-get install mc codeblocks mercurial cmake build-essential libssl-dev rpm
make dumper
cd dumper
cmake clear .
cmake -G "CodeBlocks - Unix Makefiles" .
cmake -DCMAKE_BUILD_TYPE=Debug ./Debug
cmake -DCMAKE_BUILD_TYPE=Release ./Release
make clean
make [-VERBOSE=""]
sudo make install
```

## Building packages:
```bash
cpack .
```

## Troubleshooting:
### Resolving 'Address already in use' issue:
```bash
sudo netstat -ltnp|grep ":50"
sudo kill -9 pid
```




### Notes
> Original Crashfix server and reporter tool source code (forked from https://sourceforge.net/projects/crashfix/) but **no logger maintained**.
