#set text(font: ("Songti SC", "SimSun", "Times New Roman"), size: 12pt, lang: "zh")
#set page(paper: "a4", margin: 2cm)

= Typst 数学公式速查手册

== 1. 基础输入模式
- *行内公式*：使用两个美元符号包围，例如 `$x^2$`。
- *行间公式*：在 `$ $` 内部添加空格或换行，例如 `$ x^2 $`。

== 2. 四则运算与分数
#table(
  columns: (1fr, 1fr, 2fr),
  inset: 8pt,
  align: horizon,
  [*名称*], [*Typst 代码*], [*渲染效果*],
  [加减乘除], [`a + b - c * d / e`], [$ a + b - c * d / e $],
  [点乘/叉乘], [`a dot b`, `a times b`], [$ a dot b, a times b $],
  [分数], [`(a + b) / c`], [$ (a + b) / c $],
  [根号], [`sqrt(x)`, `root(3, x)`], [$ sqrt(x), root(3, x) $],
  [上下标], [`x^2`, `x_1`, `x_(min)`], [$ x^2, x_1, x_(min) $],
)

== 3. 希腊字母与常见符号
Typst 的特点是直接写名字，不需要反斜杠 `\`。
#table(
  columns: (1fr, 1fr, 2fr),
  inset: 8pt,
  align: horizon,
  [*名称*], [*Typst 代码*], [*渲染效果*],
  [希腊字母], [`alpha, beta, gamma, pi`], [$ alpha, beta, gamma, pi $],
  [集合], [`x in RR`, `NN`, `ZZ`, `QQ`], [$ x in RR, NN, ZZ, QQ $],
  [关系], [`<=`, `>=`, `!=`, `approx`], [$ <=, >=, !=, approx $],
  [逻辑], [`=>`, `->`, `forall`, `exists`], [$ =>, ->, forall, exists $],
  [无穷], [`infinity` 或 `oo`], [$ infinity $],
)

== 4. 微积分 (函数与极限)
注意：多字母下标最好用双引号引起来，如 `lim_(n -> oo)`。
#table(
  columns: (1fr, 1fr, 2fr),
  inset: 8pt,
  align: horizon,
  [*名称*], [*Typst 代码*], [*渲染效果*],
  [求和], [`sum_(i=1)^n i^2`], [$ sum_(i=1)^n i^2 $],
  [积分], [`integral_0^pi sin(x) dif x`], [$ integral_0^pi sin(x) dif x $],
  [极限], [`lim_(x -> 0) sin(x)/x`], [$ lim_(x -> 0) sin(x)/x $],
  [导数], [`dif / (dif x) (x^2)`], [$ dif / (dif x) (x^2) $],
)

== 5. 矩阵与行列式
#grid(
  columns: (1fr, 1fr),
  gutter: 1em,
  [
    *代码：*
    ```typ
    $ mat(
      1, 2;
      3, 4
    ) $
    ```
  ],
  [
    *效果：*
    $ mat(
      1, 2;
      3, 4
    ) $
  ]
)

== 6. 分段函数 (Cases)
#grid(
  columns: (1fr, 1fr),
  gutter: 1em,
  [
    *代码：*
    ```typ
    $ f(x) = cases(
      x, "if" x > 0,
      -x, "if" x <= 0
    ) $
    ```
  ],
  [
    *效果：*
    $ f(x) = cases(
      x, "if" x > 0,
      -x, "if" x <= 0
    ) $
  ]
)

== 7. 对齐公式 (Align)
使用 `&` 符号进行对齐，类似于 LaTeX 的 align 环境，但不需要额外环境声明。
#grid(
  columns: (1fr, 1fr),
  gutter: 1em,
  [
    *代码：*
    ```typ
    $ A &= pi r^2 \
        &= 3.14 times 10^2 \
        &= 314 $
    ```
  ],
  [
    *效果：*
    $ A &= pi r^2 \
        &= 3.14 times 10^2 \
        &= 314 $
  ]
)