# 大作业 3：学生成绩管理系统

## 架构

### 头文件/类

- `Course`类：存储课程信息。
- `Student`类：存储学生信息。
- `Score`类：存储学生成绩信息。
- `Department`类：存储学院信息。
- `Graduate_Student`类：存储研究生信息。
- `Project`类：存储课题信息。

关系：

```mermaid
classDiagram
  Score -- 存储 --> Student
  Student -- 引用 -｜> Score
  Course -- 引用 -｜> Score

  Student -- 存储 --> Department
  Course -- 存储 --> Department

  Graduate_Student -. 继承 .-> Student
  Project -- 存储 --> Graduate_Student

```

## 原作业要求

这边放一个原作业，用作参考。

### 基本要求

1. 能进行数据的添加、删除、修改、查询、排序；
2. 完全使用类实现。
3. 重载输入`>>`操作符，使得可以通过`cin`直接读入类的对象值。
4. 编写`main`函数，测试系统的各种功能。

### 系统基本类

系统基本类4个：`Score`类，`Subject`类，`Student`类，`Class`类。存储学生的个人信息，考试科目，成绩，班级信息。

### 功能拓展

- 文件操作：
  1. 初始数据从文件导入，能够实现文件的显示；
  2. 数据保存至文件中；
  3. 对文件记录进行增、删、改、查；
  4. 多个文件组成一个文件。
- 派生：为`Student`类派生研究生类`GStudent`，为研究生填加课题类`Project`类。
- 扩展功能中可包含书上的知识点内容，如文件流、STL标准模板库虚函数、派生、函数重载、运算符重载、静态数据成员和成员函数等。
