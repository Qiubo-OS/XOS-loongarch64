# XOS-loongarch64
> 假设当前工作目录为 loongson

进入工作目录

```bash 
cd loongarch
```

### 1 环境工具准备

#### 1.1 配置支持 loongarch64 的 qemu

1. 下载 qemu，并进入

```bash
git clone  https://github.com/loongson/qemu.git
cd qemu
```

2. 配置

```bash
./configure --disable-rdma --disable-pvrdma --prefix=/usr \
	--target-list="loongarch64-softmmu" \
	--disable-libiscsi --disable-libnfs --disable-libpmem \
	--disable-glusterfs --enable-libusb --enable-usb-redir \
	--disable-opengl --disable-xen --enable-spice \
	--enable-debug --disable-capstone --disable-kvm \
	--enable-profiler
```

3. 编译

```bash
make
```

> qemu生成位置： loongson/qemu/build/qemu-system-loongarch64
>
> loongson为上述工作目录

#### 1.2 配置交叉工具链

回到工作目录 loongson 下。

1. 下载

```bash
wget https://github.com/loongson/build-tools/releases/download/2022.09.06/loongarch64-clfs-6.3-cross-tools-gcc-full.tar.xz
```

2. 将工具解压到 /opt 目录下

```bash
tar -vxf loongarch64-clfs-6.3-cross-tools-gcc-full.tar.xz  -C /opt
```

3. 将工具环境配置到当前终端（每次重启电脑后重新配置）

```bash
export PATH=/opt/cross-tools/bin:$PATH; \
export LD_LIBRARY_PATH=/opt/cross-tools/lib:$LD_LIBRARY_PATH; \
export LD_LIBRARY_PATH=/opt/cross-tools/loongarch64-unknown-linux-gnu/lib/:$LD_LIBRARY_PATH
```

> 工具环境可直接配置进终端配置文件中。如有需要，自行配置。

### 2 编译XOS-loongarch64

回到工作目录 loongson 下。

1. 下载

```bash
git clone https://github.com/huloves/XOS-loongarch64.git
```

2. 编译

```bash
cd XOS-loongarch64
make all
```

生成内核二进制位置：

```bash
loongson/XOS-loongarch64/kernel.efi   # loongson 为上述工作目录
```

### 3 获取UEFI启动引导

回到工作目录 loongson 下。

这里提供制作好的UEFI启动引导，下载地址：

```bash
git clone https://github.com/yangxiaojuan-loongson/qemu-binary
```

### 4 启动运行

进入 loongson/XOS-loongarch64 目录。

```bash
make qemu
```
