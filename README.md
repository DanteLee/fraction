#Fraction

##Description

C++分数类，提供了多种构造函数和运算符重载，可以方便的产生一个分数并应用与计算。

## API

### 构造函数constructor

#### `Fraction()`

产生一个0/1的分数

---------------------

#### `Fraction(const char *input)`

输入一个分数字符串，产生对应的类。
字符串应当包含一个`/`，左右各有一个整数，正负均可。
比如下列字符串是合法的：
`"12/54"` `"-3/5"` `"3/-7"`
而下列字符串是不合法的：
`"12/0"` `"12/"` `"/12"`

------------------------

#### `Fraction(const std::string &input)`

效果同上

------------------------

#### `Fraction(int)`

当参数只有一个整数时，这个整数被当做分子，分母为1
例如：
`fraction(12)`产生的分数为`"12/1"`

------------------------

#### `fraction(int, int)`

两个整数被分别当做分数的分子和分母

### 获取分数的分子和分母

#### `getdenominator()`和`getnumerator()`

分别获取分母和分子

------------------------

#### `getrawdenominator()`和`getrawnumerator()`

rawdenominator和rawNumerator指在构造函数调用时，分数化简前的分母和分子
比如Fraction("3/6")
numerator: 1
denominator: 2
rawNumerator: 3
denominator: 6

### 输出

#### toString()

`return std::string`
返回一个分数的字符串形式，负号总是在分子上

-------------------------

#### valueOf()

`return float`
返回分数的浮点值

### 运算符重载 opertor override

重载了下列运算符
`+ - * / =`
比如（F as Fraction; int as integer; str as std::string）
F + F
F - F
F * F
F / F
F = F
-F
> TODO: F+int  F+str

## 关于我 about me
blog: [nekoqaq.lofter.com](http://nekoqaq.lofter.com)




