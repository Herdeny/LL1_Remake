# 编译原理-C++实现LL1文法分析-自顶向下语法分析器的构建

## 一、实验要求

运用LL(1)分析法，针对给定的上下文无关文法，给出实验方案，构建出相应的语法分析树。预估实验中可能出现的问题。



## 二、实验方案

（评价依据实验方案设计是否合理，包括输入输出的设计）

根据题里给出的文法，给出消除左递归及提取左公因子的LL(1)文法，然后写出First集、Follow集并做出预测分析表，根据预测分析表撰写程序。

输入设计：用户输入待判断的字符串

程序设计：包含一个分析栈，用户输入字符串后，先向栈内压入E和 # ，随后进行分析操作，分析函数要求传入栈顶元素和当前分析的字符，根据预测分析表进行出栈压栈等操作，同时字符串待分析的字符后移，直至字符串分析完毕，分析栈被清空只剩一个#

输出设计：若正常分析完毕，则输出符合LL1文法，否则输出不符合LL1文法。



## 三、预估问题

（是否有预估的问题，预估的问题是否合理）

##### 预估问题：

​	预测分析表非常重要不能做错，是程序分析的依据。分析过程中要防止数组越界的问题。

##### 理论基础（评价依据 理论知识非常清楚）

​	**一、LL(1)分析法**

​        LL(1) 分析法又称预测分析法 ，是 一种不带回溯的非递归自上而下分析法。
![image](https://github.com/user-attachments/assets/72e64d38-88c8-4468-b9cb-e640ce7c8c5d)
 

​	**二、LL(1)分析器**

![image](https://github.com/user-attachments/assets/62383870-382e-42de-9da8-fdd469ab46e8)


​	**三、LL(1)分析表**

![image](https://github.com/user-attachments/assets/1ff716ff-2d34-431c-97e9-ce9d70145edc)



​	**四、LL(1)文法**

​	分析表M不含多重定义入口的文法

​	1、一个LL(1)文法所定义得语言恰好就是它的分析表所能识别的全部句子。

​	2、一个上下文无关文法是LL(1)文法的充要条件（判断一个文法是否是LL(1)文法）：对每一个非终结符A的任何两个不同的产生式A→α|β，有下面条件（都是避免了多重入口）成立

​	（1）$\text{FIRST}(\alpha) \cap \text{FIRST}(\beta) = \emptyset$ ：A 的每个候选是都不存在相同的首字符                        

​	（2）假若 $\beta \stackrel{*}{\Rightarrow} \epsilon$，则有 $\text{FIRST}(\alpha) \cap \text{FOLLOW}(A) = \emptyset$ ：避免了在分析表同一栏目内出现 $A \rightarrow \alpha$ 和 $A \rightarrow \epsilon$ 的情况。

![image](https://github.com/user-attachments/assets/70a56890-d0cb-46e7-9891-8555a89f5a54)


## 四、内容和步骤

1、针对4.8习题输入和输出的设计及代码

2、考虑简单算术表达式文法G:
$$
\begin{array}{l}
E \rightarrow E + T \ | \ T \\
T \rightarrow T * F \ | \ F \\
F \rightarrow (E) \ | \ \text{id}
\end{array}
$$
试设计LL(1)分析程序，以对任意输入的符号串进行语法分析。

3、实验具体步骤

​	①根据题里给出的文法，给出消除左递归及提取左公因子的LL(1)文法

$$
\begin{array}{l}
E \rightarrow T E' \\
E' \rightarrow + T E' \ | \ \epsilon \\
T \rightarrow F T' \\
T' \rightarrow * F T' \ | \ \epsilon \\
F \rightarrow (E) \ | \ \text{id}
\end{array}
$$
​	②写出First集和Follow集

$$
\begin{array}{lcr}
FIRST(E) &=& \{\,(\,\,\,id\,\} \\
FIRST(E') &=& \{\,+\,\,\,\varepsilon\,\} \\
FIRST(T) &=& \{\,(\,\,\,id\,\} \\
FIRST(T') &=& \{\,\,*\,\,\,\varepsilon\,\} \\
FIRST(F) &=& \{\,(\,\,\,id\,\} \\
\end{array}
$$

---

$$
\begin{array}{lcr}
FOLLOW(E) &=& \{\$\} \\
FOLLOW(E') &=& \{\$\} \\
FOLLOW(T) &=& \{+\,\$\} \\
FOLLOW(T') &=& \{+\,\$\} \\
FOLLOW(F) &=& \{*\,+\,\$\}
\end{array}
$$

​	③写出预测分析表

|      | $id$    | $+$       | $*$       | $($     | $)$    | $\#$   |
| ---- | ------- | --------- | --------- | ------- | ------ | ------ |
| $E$  | $E→TE'$ |           |           | $E→TE'$ |        |        |
| $E'$ |         | $E'→+TE'$ |           |         | $E'→ε$ | $E'→ε$ |
| $T$  | $T→FT'$ |           |           | $T→FT'$ |        |        |
| $T'$ |         | $T'→ε$    | $T'→*FT'$ |         | $T'→ε$ | $T'→ε$ |
| $F$  | $F→id$  |           |           | $F→(E)$ |        |        |

 	④根据预测分析表撰写程序，分析文法



## 五、实验结果

##### 	1、代码

[GIthub开源]: https://github.com/Herdeny/LL1_Remake	"LL1_Remake"

##### 	2、运行结果


略


## 六、实验结论

##### 1 、实验结论

（是否能够准确描述实验的结论）

略

##### 2、分析和总结

1）**对输入设计的结论**

略

2）**对输出设计的结论**

略

3）**对LL(1)分析法的结论**

​    LL(1)分析法是一种常用的自顶向下的语法分析方法，用于分析和解释编程语言或其他形式的文本。LL(1)代表"Left-to-Right, Leftmost derivation, 1 symbol lookahead"，这表示了分析器的工作方式和限制条件，通常用于编程语言的语法分析，编写编译器或解释器。主要步骤包括构建LL(1)文法、构建LL(1)分析表和使用递归下降分析或预测分析器等算法来分析输入文本。

##### 3、对预估问题的结论

预测分析表是正确分析ll1文法的关键，在分析过程中要小心仔细，不能出错。

在程序中，分析栈的栈底压入了$，根据栈首字符判断字符串是否分析完毕，有效避免了数组越界、空栈的问题
