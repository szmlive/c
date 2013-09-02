#<Pro git> git-scm.com/book

#git�����ú��Զ��� ��ֱ���޸���Ӧ�����ļ�

#base

/etc/gitconfig --system
~/.gitconfig   --global
./.git/config  

�����û���Ϣ
git config --global user.name "user"
git config --global user.email e-mail

�����ı��༭�� vi vim emacs
git config --global core.editor vim 

���ò���������� kdiff3 tkdiff meld xxdiff emerge vimdiff gvimdiff ecmerge opendiff��
git config --global merge.tool vimdiff

�鿴������Ϣ
git config --list

git�������
git config --global alias.name cmd
git config --global alias.co checkout
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.br branch

git help

��������git�����Ŀ¼���ļ�
./.gitignore

#�߼�����

�����ύģ��
commit.template $HOME/.gitmessage.txt

����log diff�ȵķ�ҳ�� more less(ȱʡ) ''(һҳ��ʾ����)
core.pager ''

����ǩ���ǩ����Կ
user.signingkey <gpg-key-id>

������������git������ļ�
core.excludesfile 

�����Զ����� �������ģ��ƥ�䵽������»��Զ�����
help.autocorrect

�����ɫ true(Ĭ���ն���ɫ) false(����ɫ) always(�κ��������ɫ) 
color.ui true 

��ʽ����հ� 
��ʽ�� true input false(win�¿���win�´���)
core.autocrlf
�ύʱ (true input)�Զ���crlfת����lf false(����س�����)
ǩ������ʱtrue(��lfת����crlf) input(��ת��)
�հ�
core.whitespace ���ŷָ�����
trailing-space(Ĭ�ϲ���ÿ�н�β�Ŀո�) 
space-before-tab(����ÿ�п�ͷ�Ʊ��ǰ�Ŀո�)
indent-with-non-tab(����8�����Ͽո�(���Ʊ��)��ͷ����)
cr-at-eol(��git֪����Ϊ�س����ǺϷ���)

P4Mergeͼ�λ��ϲ�����
...

���������
������ж����һ���� true ǿ�Ƽ�� false(ȱʡ)
receive.fsckObjects


#git����

��ʼ����Ŀ
$git init
��¡����ֿ���Ŀ
$git clone 

��鵱ǰĿ¼�ļ�״̬
$git status

��ӵ��ݴ���
$git add

���ݴ���ɾ��
$git rm

����
$git mv oldname newname
 mv oldname newname
 git rm oldname
 git add newname

�鿴��δ�ݴ���ļ���������Щ����
$git diff

�ύ�ݴ����ļ����汾��
$git commit
ʹ���뵱ǰ�ύ��ͬ�ĸ��ڵ����һ�����ύ���ɵ��ύ�ᱻȡ��
$git commit --amend

�鿴�ύ��ʷ
$git log

���������ݴ������ļ�
git reset
�������һ��git add files
$git reset --filename


�����ļ��޸�
$git checkout -- filename


#Զ�ֿ̲��ʹ��
$git remote

���Զ�ֿ̲�
$git remote add shortname url

��Զ�ֿ̲�ץȡ���� Զ�ֿ̲������Ĭ�Ϸŵ����زֿ�origin��֧��
$git fetch [remote-name]

��Զ�ֿ̲�ץȡ���� Զ�˷�֧�Զ��ϲ������زֿ��еĵ�ǰ��֧
$git pull

���ͱ��زֿ��֧���ݵ�Զ�ֿ̲��֧ ������дȨ��
$git push [remote-name] [branch-name]

�鿴Զ�ֿ̲���Ϣ
$git remote show [remote-name]

�޸�/ɾ��Զ�ֿ̲�
$git remote rename oldname newname
$git remote rm remote-name

#��ǩ����

��ʾ���б�ǩ
$git tag

�½���ǩ
����ע���͵ı�ǩ annotated
$git tag -a tag-name -m 'tag-detail'
��GPGǩ���ǩ signed
$git tat -s tag-name -m 'tag-detail'
��������ǩ
$git tag tag-name


�鿴��Ӧ��ǩ�İ汾��Ϣ
$git show tag-name

��֤��ǩ verify
����GPG��֤ǩ��
$git tag -v [tag-name]

�����ǩ
$git push remote-name [tag-name]
�������Ա�ǩ
$git push remote-name --tags


#��֧����
$git�еķ�֧ �����Ͻ����Ǹ�ָ��commit����Ŀɱ�ָ��HEAD

�½����л���֧
$git checkout -b branchname
 git branch branchname
 git checkout branchname

�л�������֧���ϲ���֧
$git checkout master
$git merge branchname

�ϲ���ɾ����֧
$git branch -d branchname

Fast forward: ����ǰ master ��֧���ڵ��ύ������Ҫ����� branchname ��֧��ֱ�����Σ�
              Git ֻ��� master ��ָ֧��ֱ�����ơ�
                ���仰˵�����˳��һ����֧����ȥ���Ե�����һ����֧�Ļ�����ô Git �ںϲ�����ʱ��
                ֻ��򵥵ذ�ָ�����ƣ���Ϊ���ֵ��ߵ���ʷ��֧�������κ���Ҫ����ķ��磬�������ֺϲ����̿��Գ�Ϊ�����Fast forward����
�����ϲ���    ����ǰ master ��֧��ָ����ύ���� master'' ������ branchname ��֧��ֱ�����ȣ�
              Git ���ò�����һЩ���⴦���ʹ������ԣ�Git ����������֧��ĩ�� �Լ����ǵĹ�ͬ���� ����һ�μ򵥵������ϲ�����
			  Git û�м򵥵ذѷ�ָ֧�����ƣ����Ƕ������ϲ���Ľ��������һ���µĿ��գ����Զ�����һ��ָ�������ύ����

������ͻʱ�ķ�֧�ϲ�
�κΰ���δ�����ͻ���ļ�������δ�ϲ���unmerged����״̬�г���Git �����г�ͻ���ļ�������׼�ĳ�ͻ�����ǣ�����ͨ���������ֹ���λ�������Щ��ͻ��
���������һ����ͼ�ν���Ĺ����������Щ���⣬�������� git mergetool���������һ�����ӻ��ĺϲ����߲������������г�ͻ(�ϲ����߿��Զ���)


��ʾ��ǰ��֧�嵥
$git branch
*master
 branchname1
 branchname2

�鿴������֧���һ��commit��Ϣ
$git branch -v


#��֧ʽ�������� !!

���ڷ�֧
���Է�֧
Զ�̷�֧
���ٷ�֧

�ϲ� merge
�ܺ� rebase
����һ����֧�������ύ�ĸı�����һ����֧������һ�� 
ʵ�����Ǵӹ������ȿ�ʼ ������֮����ִ�commit��������һЩ���Ƶ���ͬ����commit 
�ܺ���Ϊһ��������֮ǰ�����ύ��ʷ���ֶ� ���ҽ����ܺ���Щ��Զ���ṫ����commit
�ܺϲ���һ����Ϊ�����ύ��ʷ(�����ύ��Ϊ�����ύ)

#git�ڲ�ԭ��
�Ӹ��������� git��һ������Ѱַ(content-addressable)�ļ�ϵͳ���ڴ˻������ṩ��vcs����

#plumbing(�ײ�����)��procelain(�߲�����)

.gitĿ¼
config      ��Ŀ��������ѡ��!
HEAD        ָ��ǰ��֧��ָ��!!!
branches/   �°治��ʹ�ô�Ŀ¼
refs/       �洢ָ������(��֧)���ύ�����ָ��!!!
objects/    �洢������������!!
index       �洢���ݴ�����Ϣ
info/       
description ��GitWeb����ʹ��
hooks       �ͻ��˺ͷ���˹��ӽű�!

git�Ǽ򵥵�key-value���ݴ洢 ��������������͵����ݣ�������һ����ֵ

hash-object 
$echo "test content" | git hash-object -w --stdin
��git���ݿ�洢���ݶ��󲢷��ؼ�ֵ(SHA1)
 d670460b4b4aece5915caf5c68d12f560a9fe3e4
��У���ǰ�����ַ�Ϊ���Ƶ���Ŀ¼ ��ʣ��38���ַ�Ϊ�ļ��������ļ����� ����zlib�����㷨

cat-file ���Խ���������ȡ�� -t �������� -p ��������
$git cat-file -p d670460b4b4aece5915caf5c68d12f560a9fe3e4
test conntent

��������
objects
 sha1(0,2)/sha1(2,38)
 info
 pack
�򵥰汾����
�����ļ�
$echo "version 1" > test.txt
$git hash-object -w test.txt
 83baae61804e65cc73a7201a7252750c76066a30

�����ļ�
$echo "version 2" > test.txt
$git hash-object -w test.txt
 1f7a7a472abf3dd9643fd615f6da379c4acb3e3a

�鿴git�ļ�ϵͳ
$find .git/objects -type f
.git/objects/1f/7a7a472abf3dd9643fd615f6da379c4acb3e3a
.git/objects/83/baae61804e65cc73a7201a7252750c76066a30
.git/objects/d6/70460b4b4aece5915caf5c68d12f560a9fe3e4

��ǰ�ļ�����
$cat test.txt
version 2

�ָ��ļ�����һ�汾
$git cat-file -p 83baae61804e65cc73a7201a7252750c76066a30 > test.txt
$cat test.txt
version 1

�ٻָ��ļ����ڶ��汾
$git cat-file -p 1f7a7a472abf3dd9643fd615f6da379c4acb3e3a > test.txt
$cat test.txt
version 2

�������� blob(�������ļ�����) tree(Ŀ¼) commit 

�洢���ݵĶ�������Ϊblob
$git cat-file -t 1f7a7a472abf3dd9643fd615f6da379c4acb3e3a
blob

update-index ����index(�ݴ���) 
write-tree ����Ŀ¼����
read-tree  ��ȡĿ¼�����ݴ���commit-tree �����ύ���� ָ����Ŀ���յĶ��������� �������ύ����Ϣ��ʱ��������С��ύע����Ϣ

���� references(refes)
refs
 heads
 tags
update-ref �޸������ļ�
git�е�һ����֧��ʵ����һ��ָ�����汾һ��HEAD��¼��ָ�������


HEAD���
HEAD�ļ���һ��ָ��ǰ���ڷ�֧�����ñ�ʾ��
cat HEAD
ref: refs/heads/master

git checkout branchname
cat HEAD
ref: refs/heads/branchname

symbolic-ref 
git commit���Ǵ���һ��commit���� �������commit����ĸ���ָ������ΪHEADָ������õ�SHA-1ֵ

TAG����
tag����ָ��һ��commit������һ��tree ����һ����֧���� ������仯


Զ������
remote���úͷ�֧����Ҫ�����������ǲ��ܱ�checkout�ġ�git�����ǵ�������Щ��֧�ڷ����������״̬��һ����ǩ


packfiles
git�����̱������ʱĬ��ʹ�õĸ�ʽ����ɢ����(loose object)��ʽ 
gitʱ��ʱ����Щ��������һ��packfile�Ķ������ļ��ѽ�ʡ�ռ䲢���Ч��
�ֶ����� (git push ����̫����ɢ����ʱ���Զ�����)
$git gc


