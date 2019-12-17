Static OpenVINO for aarch64
========

需求
--------

- aarch64-linux-musl toolchain
- libusb
- eudev

产物
--------

Inference Engine的静态库，其中libinference_engine_s, libmyriadPlugin可以静态链接（需要--start-group --end-group）


构建过程
--------

```
cd inference_engine
mkdir build
cd build
# 修改CMakeCache.txt使用正确的toolchain、强制static以及MinSizeRel等配置。一个参考的配置见CMakeCache.txt.sample
cmake ..
make -j8 -k # -k强制构建；许多构建产物会失败，但是我们只需要静态库
```
