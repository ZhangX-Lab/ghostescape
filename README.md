## GhostEscape

这是一个基于SDL3和glm的幽灵逃生游戏项目，采用的git submodules实现的第三方库集成，并且在wsl2下通过docker container环境下最终编译运行成功。

```bash
#  清理build目录，但是保留build中的externals目录
find ./build/ -mindepth 1 ! -name 'externals' ! -path './build/externals/*' -exec rm -rf {} +
```