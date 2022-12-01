FROM gcc

WORKDIR /root
RUN apt update

#install gtest (https://stackoverflow.com/questions/13513905/how-to-set-up-googletest-as-a-shared-library-on-linux)
RUN apt install -y cmake
RUN wget https://github.com/google/googletest/archive/release-1.12.1.tar.gz
RUN tar xf release-1.12.1.tar.gz
WORKDIR googletest-release-1.12.1
RUN cmake -DBUILD_SHARED_LIBS=ON
RUN make

RUN cp -a ./googletest/include/gtest /usr/include
RUN cp -a ./lib/libgtest_main.so ./lib/libgtest_main.so.1.12.1 ./lib/libgtest.so ./lib/libgtest.so.1.12.1 /usr/lib/
RUN make install
