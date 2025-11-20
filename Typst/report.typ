// --- 1. 模版设置 ---
#let report(
  course: "",
  project: "",
  college: "",
  class_id: "",
  student_id: "",
  author: "",
  teacher: "",
  semester: "",
  body
) = {
  // 全局字体：Mac优先使用宋体 (Songti SC)
  set text(font: ("Songti SC", "SimSun", "Times New Roman"), size: 12pt, lang: "zh")
  
  // 页面设置
  set page(paper: "a4", margin: (x: 2.5cm, y: 2.5cm))
  
  // 段落设置：【核心修改】
  // 开启首行缩进 2em
  set par(justify: true, leading: 1.25em, first-line-indent: 2em)
  
  // --- 标题设置 ---
  // 1. 编号规则：一级显示"一、"，二级显示"1、"
  set heading(numbering: (..nums) => {
    let n = nums.pos()
    if n.len() == 1 { numbering("一、", n.last()) } 
    else { numbering("1、", n.last()) }
  })

  // 2. 标题样式设置
  // 注意：为了防止标题也被首行缩进，这里专门强制标题的 first-line-indent 为 0
  show heading: set par(first-line-indent: 0em)
  
  show heading: set text(size: 14pt, weight: "bold")
  show heading: set block(above: 1.5em, below: 1em)

  // --- 图表设置 ---
  show figure.where(kind: table): set figure.caption(position: top)
  show figure.where(kind: image): set figure.caption(position: bottom)
  show figure.where(kind: image): set figure(supplement: "图")
  show figure.where(kind: table): set figure(supplement: "表")
  set figure.caption(separator: "  ")

  // --- 封面页 ---
  v(1cm) 
  align(center)[
    #image("logo1.jpg", height: auto)
    #v(0.5em) 
    #image("logo2.jpg", height: auto)
    
    #v(1cm)

    #text(size: 42pt, weight: "bold")[电工电子实验报告]
    
    #v(2.5cm)
    
    #let info_key(k) = text(weight: "bold", size: 14pt)[#k]
    #let info_val(v) = {
      box(width: 16em, stroke: (bottom: 0.5pt), outset: (bottom: 2pt))[
        #align(left + horizon)[
          #h(0.5em) 
          #text(size: 14pt)[#v]
        ]
      ]
    }
    
    #grid(
      columns: (auto, auto),
      row-gutter: 1.2em,   
      column-gutter: 0.5em,
      align: (right + horizon, left + bottom), 
      
      info_key("课程名称："), info_val(course),
      info_key("实验项目："), info_val(project),
      info_key(""),          info_val(" "), 
      info_key("学　　院："), info_val(college),
      info_key("班　　级："), info_val(class_id),
      info_key("学　　号："), info_val(student_id),
      info_key("姓　　名："), info_val(author),
      info_key("指导教师："), info_val(teacher),
      info_key("学　　期："), info_val(semester),
    )
  ]
  
  pagebreak()
  
  // --- 正文开始 ---
  set page(numbering: "1")
  set align(left)
  
  body
}

// --- 2. 信息填写 ---
#show: doc => report(
  course: "电子电工实验（一）",
  project: "戴维南定理的验证",
  college: "通信与信息工程学院",
  class_id: "B240130",
  student_id: "B24013026",
  author: "屠宇航",
  teacher: "张潇萧",
  semester: "2025-2026 学年第 1 学期",
  doc
)

// --- 3. 正文内容 ---

= 实验目的

+ 验证戴维南定理的正确性，加深对等效电压源定理的理解。
+ 掌握测量有源二端网络等效参数（开路电压 $U_("oc")$ 和等效电阻 $R_("eq")$）的方法。

= 主要仪器设备及软件

== 硬件设备
- 函数信号发生器
- 直流稳压电源
- 示波器、万用表、实验箱、阻容元件及导线若干

== 软件环境
- Multisim 14

= 实验原理/设计过程

任何一个线性有源二端网络，对外电路而言，都可以用一个电压源和电阻串联的组合来等效代替。

$ I = U_("oc") / (R_("eq") + R_L) $

其中：$U_("oc")$ 是二端网络的开路电压；$R_("eq")$ 是二端网络中所有独立源置零（电压源短路，电流源开路）后，从端口看进去的等效电阻。

#pagebreak()

= 实验电路图

#figure(
  image("logo1.jpg", width: 80%),
  caption: [戴维南定理验证电路图]
)

#pagebreak()

= 实验结果和实验数据分析

== 实验数据记录

#figure(
  table(
    columns: (auto, 1fr, 1fr, 1fr),
    inset: 10pt,
    align: center,
    [*测量项目*], [*计算值*], [*测量值*], [*误差 (%)*],
    [$U_("oc") (V)$], [12.0], [11.95], [0.42],
    [$R_("eq") (k Omega)$], [1.0], [0.99], [1.0],
  ),
  caption: [戴维南等效参数测量数据]
)

== 数据分析

从上述表格可以看出，测量值与理论计算值基本吻合。

#pagebreak()

= 实验小结

通过本次实验，我成功掌握了戴维南定理的验证方法。

#pagebreak()

= 附录

在此处附上原始数据记录单。

