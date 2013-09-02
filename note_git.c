#<Pro git> git-scm.com/book

#git的配置和自定义 可直接修改相应配置文件

#base

/etc/gitconfig --system
~/.gitconfig   --global
./.git/config  

配置用户信息
git config --global user.name "user"
git config --global user.email e-mail

配置文本编辑器 vi vim emacs
git config --global core.editor vim 

配置差异分析工具 kdiff3 tkdiff meld xxdiff emerge vimdiff gvimdiff ecmerge opendiff等
git config --global merge.tool vimdiff

查看配置信息
git config --list

git命令别名
git config --global alias.name cmd
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch

git help

无需纳入git管理的目录、文件
./.gitignore

#高级配置

配置提交模板
commit.template $HOME/.gitmessage.txt

配置log diff等的分页器 more less(缺省) ''(一页显示所有)
core.pager ''

设置签署标签的密钥
user.signingkey <gpg-key-id>

配置无需纳入git管理的文件
core.excludesfile 

配置自动修正 打错的命令被模糊匹配到的情况下会自动运行
help.autocorrect

输出配色 true(默认终端着色) false(不着色) always(任何情况都着色) 
color.ui true 

格式化与空白 
格式化 true input false(win下开发win下代码)
core.autocrlf
提交时 (true input)自动把crlf转换成lf false(保存回车换行)
签出代码时true(把lf转换成crlf) input(不转换)
空白
core.whitespace 逗号分隔如下
trailing-space(默认查找每行结尾的空格) 
space-before-tab(查找每行开头制表符前的空格)
indent-with-non-tab(查找8个以上空格(非制表符)开头的行)
cr-at-eol(让git知道行为回车符是合法的)

P4Merge图形化合并工具
...

服务端配置
检查所有对象的一致性 true 强制检查 false(缺省)
receive.fsckObjects


#git基本

初始化项目
$git init
克隆软件仓库项目
$git clone 

检查当前目录文件状态
$git status

添加到暂存区
$git add

从暂存区删除
$git rm

改名
$git mv oldname newname
 mv oldname newname
 git rm oldname
 git add newname

查看尚未暂存的文件更新了那些部分
$git diff

提交暂存区文件到版本库
$git commit
使用与当前提交相同的父节点进行一次新提交，旧的提交会被取消
$git commit --amend

查看提交历史
$git log

撤销所有暂存区域文件
git reset
撤销最后一次git add files
$git reset --filename


抛弃文件修改
$git checkout -- filename


#远程仓库的使用
$git remote

添加远程仓库
$git remote add shortname url

从远程仓库抓取数据 远程仓库的数据默认放到本地仓库origin分支下
$git fetch [remote-name]

从远程仓库抓取数据 远端分支自动合并到本地仓库中的当前分支
$git pull

推送本地仓库分支数据到远程仓库分支 必须有写权限
$git push [remote-name] [branch-name]

查看远程仓库信息
$git remote show [remote-name]

修改/删除远程仓库
$git remote rename oldname newname
$git remote rm remote-name

#标签操作

显示已有标签
$git tag

新建标签
含附注类型的标签 annotated
$git tag -a tag-name -m 'tag-detail'
用GPG签署标签 signed
$git tat -s tag-name -m 'tag-detail'
轻量级标签
$git tag tag-name


查看相应标签的版本信息
$git show tag-name

验证标签 verify
调用GPG验证签名
$git tag -v [tag-name]

分享标签
$git push remote-name [tag-name]
推送所以标签
$git push remote-name --tags


#分支操作
$git中的分支 本质上仅仅是个指向commit对象的可变指针HEAD

新建并切换分支
$git checkout -b branchname
 git branch branchname
 git checkout branchname

切换回主分支并合并分支
$git checkout master
$git merge branchname

合并后删除分支
$git branch -d branchname

Fast forward: 若当前 master 分支所在的提交对象是要并入的 branchname 分支的直接上游，
              Git 只需把 master 分支指针直接右移。
                换句话说，如果顺着一个分支走下去可以到达另一个分支的话，那么 Git 在合并两者时，
                只会简单地把指针右移，因为这种单线的历史分支不存在任何需要解决的分歧，所以这种合并过程可以称为快进（Fast forward）。
三方合并：    若当前 master 分支所指向的提交对象 master'' 并不是 branchname 分支的直接祖先，
              Git 不得不进行一些额外处理。就此例而言，Git 会用两个分支的末端 以及它们的共同祖先 进行一次简单的三方合并计算
			  Git 没有简单地把分支指针右移，而是对三方合并后的结果重新做一个新的快照，并自动创建一个指向它的提交对象

遇到冲突时的分支合并
任何包含未解决冲突的文件都会以未合并（unmerged）的状态列出。Git 会在有冲突的文件里加入标准的冲突解决标记，可以通过它们来手工定位并解决这些冲突。
如果你想用一个有图形界面的工具来解决这些问题，不妨运行 git mergetool，它会调用一个可视化的合并工具并引导你解决所有冲突(合并工具可自定义)


显示当前分支清单
$git branch
*master
 branchname1
 branchname2

查看各个分支最后一次commit信息
$git branch -v


#分支式工作流程 !!

长期分支
特性分支
远程分支
跟踪分支

合并 merge
衍合 rebase
把在一个分支里做的提交的改变在另一个分支里重做一遍 
实际上是从公共祖先开始 抛弃了之后的现存commit而创造了一些类似但不同的新commit 
衍合作为一种在推送之前清理提交历史的手段 而且仅仅衍合那些永远不会公开的commit
衍合产生一个更为简洁的提交历史(并行提交改为串行提交)

#git内部原理
从根本上来讲 git是一套内容寻址(content-addressable)文件系统，在此基础上提供了vcs功能

#plumbing(底层命令)和procelain(高层命令)

.git目录
config      项目特有配置选项!
HEAD        指向当前分支的指针!!!
branches/   新版不再使用此目录
refs/       存储指向数据(分支)的提交对象的指针!!!
objects/    存储所有数据内容!!
index       存储了暂存区信息
info/       
description 供GitWeb程序使用
hooks       客户端和服务端钩子脚本!

git是简单的key-value数据存储 允许插入任意类型的内容，并返回一个键值

hash-object 
$echo "test content" | git hash-object -w --stdin
往git数据库存储数据对象并返回键值(SHA1)
 d670460b4b4aece5915caf5c68d12f560a9fe3e4
以校验和前两个字符为名称的子目录 已剩下38个字符为文件名保存文件内容 采用zlib加密算法

cat-file 可以将数据内容取回 -t 对象类型 -p 对象内容
$git cat-file -p d670460b4b4aece5915caf5c68d12f560a9fe3e4
test conntent

数据内容
objects
 sha1(0,2)/sha1(2,38)
 info
 pack
简单版本控制
创建文件
$echo "version 1" > test.txt
$git hash-object -w test.txt
 83baae61804e65cc73a7201a7252750c76066a30

更新文件
$echo "version 2" > test.txt
$git hash-object -w test.txt
 1f7a7a472abf3dd9643fd615f6da379c4acb3e3a

查看git文件系统
$find .git/objects -type f
.git/objects/1f/7a7a472abf3dd9643fd615f6da379c4acb3e3a
.git/objects/83/baae61804e65cc73a7201a7252750c76066a30
.git/objects/d6/70460b4b4aece5915caf5c68d12f560a9fe3e4

当前文件内容
$cat test.txt
version 2

恢复文件至第一版本
$git cat-file -p 83baae61804e65cc73a7201a7252750c76066a30 > test.txt
$cat test.txt
version 1

再恢复文件至第二版本
$git cat-file -p 1f7a7a472abf3dd9643fd615f6da379c4acb3e3a > test.txt
$cat test.txt
version 2

对象类型 blob(索引和文件内容) tree(目录) commit 

存储数据的对象类型为blob
$git cat-file -t 1f7a7a472abf3dd9643fd615f6da379c4acb3e3a
blob

update-index 创建index(暂存区) 
write-tree 创建目录对象
read-tree  读取目录对象到暂存区commit-tree 创建提交对象 指明项目快照的顶层树对象 、作者提交者信息、时间戳、空行、提交注释信息

引用 references(refes)
refs
 heads
 tags
update-ref 修改引用文件
git中的一个分支其实就是一个指向工作版本一条HEAD记录的指针或引用


HEAD标记
HEAD文件是一个指向当前所在分支的引用标示符
cat HEAD
ref: refs/heads/master

git checkout branchname
cat HEAD
ref: refs/heads/branchname

symbolic-ref 
git commit就是创建一个commit对象 并把这个commit对象的父级指针设置为HEAD指向的引用的SHA-1值

TAG对象
tag对象指向一个commit而不是一个tree 就像一个分支引用 但不会变化


远程引用
remote引用和分支的主要区别在于他们不能被checkout的。git吧他们当做了这些分支在服务器上最后状态的一种书签


packfiles
git往磁盘保存对象时默认使用的格式是松散对象(loose object)格式 
git时不时将这些对象打包至一个packfile的二进制文件已节省空间并提高效率
手动调用 (git push 或有太多松散对象时会自动调用)
$git gc


