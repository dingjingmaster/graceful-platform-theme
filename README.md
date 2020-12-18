# Graceful Platform Theme
[![GitHub release](https://img.shields.io/github/release/graceful-linux/graceful-platform-theme.svg)](https://github.com/graceful-linux/graceful-platform-theme/releases)
[![GitHub license](https://img.shields.io/github/license/graceful-linux/graceful-platform-theme.svg)](https://github.com/graceful-linux/graceful-platform-theme/blob/graceful-platform-theme/LICENSE)

> 基于 QT 的主题框架

### 安装方法(任选一种即可)

1. 源码编译安装,适用于任意linux平台

    进入源码根目录执行如下命令即可
    ```
    qmake && make -j8 && sudo make install      # 正常使用安装
    qmake && make -j8 \
        && cd lib && make -j8 debug \
        && cd ../style && make -j8 debug \
        && cd .. && sudo make install           # 安装打开debug日志输出
    ```

2. 针对 arch 系的系统,只需要执行如下命令

    ```
    yay -S graceful-platform-theme              # 这是正常安装使用
    yay -S graceful-platform-theme-dbg          # 这是安装debug包,会在syslog里输出很多debug日志供查看
    ```


### 使用方法(两种选其一即可)

1. 配置`/etc/environment`添加

    ```
    QT_QPA_PLATFORMTHEME='graceful'
    ```

2. 配置 `/etc/zshrc` 或 `/etc/bashrc` 或 `~/.zshrc` 添加

    ```
    export QT_QPA_PLATFORMTHEME='graceful'
    ```

### 另外 yay 仓库地址 

    ```
    ssh://aur@aur.archlinux.org/graceful-platform-theme.git
    ```

