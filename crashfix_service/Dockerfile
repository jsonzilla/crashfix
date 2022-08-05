# import a debian image
FROM debian:bookworm-slim as base

# install gcc and make
RUN apt-get update && apt-get install -y gcc make cmake g++

# install rpmbuild
RUN apt-get update && apt-get install -y devscripts

FROM base as builder

# compile the crashfix service
WORKDIR /crashfix_service
COPY . .
RUN cmake -DCMAKE_BUILD_TYPE=Release . && make

# run cpack to create the deb
RUN cpack -G DEB

# install the deb
RUN command dpkg -i crashfix-service-*-Linux-amd64.deb

RUN cd bin
RUN ls
RUN chmod +x daemon_tests
RUN ./daemon_tests
RUN chmod +x libdump_tests
RUN ./libdump_tests

# keep running
RUN crashfixd --run