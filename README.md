# ExStudPE Visual Tools 使用说明

## ~ 强大的PE/PE64/NE/LE/COFF/LIB/ELF 格式分析、调试、编辑工具 ~


ExStudPE Visual Tools 是一个扩展StudPE、LordPE等软件的用于PE（32位）、PE+（64位）、NE、Elf（32位）、Coff、Lib格式
二进制可执行目标文件(*.exe、*.dll、*.ocx、*.so、*.lib、*.obj、*.exp等)的分析、调试、十六进制编辑工具。     

利用此工具可以方便的查找给定PE文件的一些常用的信息，如导入表、导出表、重定位表、资源、消息表、版本信息、PE附加数据等等。

同时可以方便地实现给定程序代码的反汇编功能，同时提供了快速定位的有效解决方案。
同时本程序也具有十六进制编辑器的基本功能。
另外，本程序集成了对于目标文件的简单的调试功能（包括虚拟机调试与实体机调试），
使用方便。特别适合于专业的PE分析研发人员使用。



不仅如此，新版本还增加了许多其他附加特性及插件，使用最新版本将会获得更好的操作体验。

 

本程序包括ANSI与Unicode两种版本，推荐使用稳定的Unicode版本。其运行界面大致如下所示：

![ExStudPE Visual Tools](https://github.com/tankaishuai/ExStudPE_Visual_Tools/blob/master/images/a1.png)

 


 
# 基本信息：

当前版本：v1.6.4 Beta3

运行环境：WinXP / Vista / Win7 / Win8 / Win10

附加说明：

    (1)关于文件数据的查找方式：

    直接十六进制方式查找：如：4D 12 37 (以一个空格隔开各个数据位)

    Ansi字符串查找：如："VS_VERSIONINFO"

    Unicode字符串查找：如：L"VS_VERSIONINFO"

 

(2)本程序提供了对于目标文件的简单调试功能，如果虚拟机能够正常成功加载，记住以下快捷键是很有必要的：

F1：显示系统帮助信息 Ctrl+F1：显示本程序帮助文件

                F2：切换断点         Ctrl+F2：删除所有断点

                F3：设置函数断点     Ctrl+F3：清除函数断点

                F4：设置内存断点     Ctrl+F4：清除内存断点

                F5：刷新调试窗口     Ctrl+F5：显示/隐藏调试窗口

                F6：运行至目标位置   Ctrl+F6：运行至目标位置(带断点)

                F7：单步步入         Ctrl+F7：跳出至调用位置

                F8：单步步过         Ctrl+F8：运行至结束

                F9：运行至断点       Ctrl+F9：中断当前调试

F11：加载扩展模块     Ctrl+F11：调试参数配置

F12：显示调试帮助信息 Ctrl+F12：显示本程序帮助文件

 

    如果虚拟机加载失败，本程序仅仅只是简单尝试运行目标程序而已。

![ExStudPE Visual Tools](https://github.com/tankaishuai/ExStudPE_Visual_Tools/blob/master/images/a2.png)


