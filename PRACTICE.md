# A-1:ノート->演奏データ
まずは、標準入力によって入力された数字を記号に変換することを考える。具体的には1が入力されたときには'd'、2が入力されたときには'k'を標準出力で出力する。それ以外の場合については、何も出力しない。
### 入力

```
N
```

ただし`0≦N≦2`とする。

### 入力例

```
1
```

### 出力例

```
d
```

# A-2:譜面->演奏データ
1行の標準入力によって与えられた譜面データを、A-1の変換規則にしたがってノートの集合に変換する。変換規則は以下の通りとする。

### 変換規則
* 0->.
* 1->d
* 2->k

### 入力

0,1,2のいずれかで構成された文字列S(ただしSは100字以内とする)

### 出力

入力された文字列を変換した文字列

### 入力例

```
1000200010102000101120102010112020001000202010201020112110102000
```

### 出力例

```
d...k...d.d.k...d.ddk.d.k.d.ddk.k...d...k.k.d.k.d.k.ddkdd.d.k...
```

# A-3:乱オプション（デレステver）
5行の‘0’と‘1’から成る文字列による入力を与える。これを文字列ごとの記号の並びはそのままにしつつ表示される行の順番だけをシャッフルしたい。またシャッフルのアルゴリズムはフィッシャー - イェーツのシャッフルのO(n)のアルゴリズム（参考：https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A3%E3%83%83%E3%82%B7%E3%83%A3%E3%83%BC_-_%E3%82%A4%E3%82%A7%E3%83%BC%E3%83%84%E3%81%AE%E3%82%B7%E3%83%A3%E3%83%83%E3%83%95%E3%83%AB#.E6.94.B9.E8.89.AF.E3.81.95.E3.82.8C.E3.81.9F.E3.82.A2.E3.83.AB.E3.82.B4.E3.83.AA.E3.82.BA.E3.83.A0 ）を用いるとする。

### 入力

```
N
S_1
S_2
S_3
S_4
S_5
```

Nは乱数のシード値、S_iは入力する文字列（S_iは100文字以内、1≦i≦5）

### 出力
S_iをシャッフルして出力せよ。

### 入力例

```
32
0000000000000000001100110001000100000000
0000000000110000000000000100010000110011
1111111111000011000000000010000000000000
0000000000001100000000001000100011001100
0000000000000000110011000000001000000000
```

### 出力例
注意：環境によって異なることがあります。

```
0000000000110000000000000100010000110011
0000000000000000110011000000001000000000
0000000000000000001100110001000100000000
0000000000001100000000001000100011001100
1111111111000011000000000010000000000000
```

この場合入力時に1行目の入力は3行目に、2行目は1行目に、3行目は5行目に、4行目は4行目に、5行目は2行目に出力されている。

# A-4:平均密度
標準入力によって小節数とその間のノーツ数、BPM(Beats Per Minute)を与え、平均密度（譜面の長さ÷ノーツ数）を出力するプログラムを作成せよ。BPMとは1分間に刻む拍の数のことである。また、BPM変化はないものとし、小節間は常に4拍子とする。

### 入力

```
N M
B
```

Nはノーツ数、Mは小節数である。これらを1行目に入力する。2行目にBを入力する。BはBPMである。いずれも整数値とする(`0<N,M,B≦10^9`)。

### 出力
平均密度（単位：notes/s）を実数値で出力せよ。

### 入力例

```
876 111
186
```

### 出力例

```
6.12
```

# B-1:メトロノーム
これまではプログラムは逐次的に実行されていたが、時間によってプログラムを制御することを考える。ここでは一定のBPMで拍を刻むメトロノームを作成する。このプログラムでは、4拍子とする。
### 入力

```
N
B
```

Nは小節数、Bはテンポ(BPM)であり、いずれも整数とする。
### 出力

```
S s
```

S……現在の小節

s……現在の拍

以上の出力をN\*4行分行う。
### 入力例

```
4
150
```

### 出力例

```
1 1
1 2
1 3
1 4
2 1
2 2
2 3
2 4
3 1
3 2
3 3
3 4
4 1
4 2
4 3
4 4
```

### ヒント

時間の計測には、time.hではなくwindows.hをインクルードしてGetTickCount関数を用いる。

# B-2:連打秒数
標準入力によって与えられた譜面データから、最大コンボ数（ノーツの数）・平均密度・連打秒数を測定する。なお、この譜面データは以下のような入力によって与えられる。

### 入力
* 最初の行にBPMを整数値で入力する。この譜面においては、BPM変化はないものとする。
* 2行目に測定したい小節数を入力する。このプログラムでは、4拍子とする。小節数は最大100小節とする。
* 3行目以降、2行目で指定した小節数分譜面データを入力する。1行の入力で1小節である。また、譜面データについて、0は空白、1はドン、2はカツ、3は大ドン、4は大カツ、5は連打開始、6は大連打開始、7は風船連打開始、8は連打終止記号とし、これ以外の文字は無視する。したがって1,2,3,4はノーツ、5,6,7,8は連打記号となる。
* 5,6,7について、次に8が出てくるまでの区間を連打区間と定義し、連打秒数を数える。その区間中にノーツがあった場合ノーツの数に加えない。

### 出力

```
N
A
R
```

Nは最大コンボ数、Aは平均密度（単位notes/sec）、Rは連打秒数である。

### 入力例

```
153
29
1020112011210120,
10102010101020201010201011202010,
1020112211210121,
10102010101022201010201022102000,
1221012112210121,
1122112211221222,
10102010001020001110201000102000,
11102010001020001110201022201110,
1020112011210120,
10102010101020201010201011202010,
1021112212210121,
10102010101022201010201022112000,
100000000000000000100100200000000000000000000000200000002000000020000000100000001000000010000000,
222222111111222111200000,
300000000000000000300000000000000000300000000000600000000000000000000008000000000000200000200000,
1021021040040040,
1020112011210120,
100100200100000100200200100100200100000100202020,
1221221211212210,
100100100000200000100100100000200000100000200000100010001000200000100000200000200000100000100000,
1020112011210120,
100100200100000100200200100100200100000100202020,
1121221212212211,
20201010202010102220101022201010,
10001020001020001000112000102000,
100000000000111111200000,
222222111111222222111111,
1333,
4,
```

### 出力例

```
389
8.55
0.38
```

# B-3:ファイルからの読み込み、ファイルに出力
B-2:連打秒数を改良して、ファイルからの譜面データ読み込み・結果のファイルへの出力をしたい。

### 入力
入力ファイル名をプログラムの引数として与える。

入力ファイルの形式はB-2と同様のものとするが、以下の変更点を加える。
* 小節の区切りは改行ではなく‘,’で行う。
* 2行目に小節数は入力しない。ファイルが入力として与えられている時点で小節数は自明だからである。
* ‘#’で始まる行は読み飛ばす。

### 出力

```
N
A
R
```

Nは最大コンボ数、Aは平均密度（単位notes/sec）、Rは連打秒数である（B-2と同じ）。これを適当なテキストファイルに出力せよ。

### 入力例
“pararevo.tja”を用いる。
### 出力例
以下のような出力が指定したファイルにされていれば成功である。

```
1300
7.43
12.83
```

### ヒント
プログラムが複雑になってきたときには、関数を使って複数の処理に分割するとよい。このとき宣言する関数はmain関数の前に来るように注意する。この場合、ファイルから譜面データを構成する部分と、譜面データから各種データを測定する部分（B-2とほぼ同一）と、結果を出力する部分に分けるといいだろう。なお、ファイルから読み込む際にファイルを読み込んで各種データ構造に変換する部分とそのデータをいじくり回す部分を分けるという発想は後々かなり役に立つので覚えておいて損はない。

ちなみに、さらに関数が増えてきたときには分割コンパイルという技を使って複数のファイルにプログラムを記述する技法を使うがこの課題の中では登場しない。

# C-1:BPM変化の読み取り
この課題以降、基本的にB-3:ファイルからの読み込み、ファイルに出力を改造していく。この課題では、基本的に読み飛ばしていた#以降の命令のうち、“#BPMCHANGE”に対応する。

### 入力
入力ファイル名をプログラムの引数として与える。

入力ファイルの形式はB-3と同様のものとするが、以下の変更点を加える。
* “#BPMCHANGE”についての処理を追加し、BPM変化に対処する。
### 出力

```
N
A
R
```

Nは最大コンボ数、Aは平均密度（単位notes/sec）、Rは連打秒数である（B-2と同じ）。今回の場合はファイルに出力しても標準出力でも構わない。

### 入力例
“yugen.tja”を用いる。
### 出力例
以下のような出力が指定されたファイルにされていれば成功である。

```
1262
1.58
10.37
```

# C-2:オートプレイ
最後に、リズムに合わせて標準出力で‘d’あるいは‘k’を出力することでオートプレイを完成させる。リズムに合わせる方法は、B-1:メトロノームを参考にせよ。
### 入力
入力ファイル名をプログラムの引数として与える。

入力ファイルの形式はC-1:BPM変化の読み取りとまったく同一である。
### 出力
入力ファイルで指定されたタイミングに合わせてドンを表す‘d’、カツを表す‘k’、連打を表す‘r’を出力する。
### 入力例
“yugen.tja”を用いる。
### 出力例
省略する。

### 補足
実際に演奏してみると分かるが、普通に実装すると主に小節区切りの部分で変な間が生じる。これを除くためには非常に手間がかかるので実装しなくても構わない。

# D-1:自動演奏装置（発展）
標準出力に渡していた演奏データをキーボード入力に渡し、太鼓さん次郎での自動演奏を実現する。

入力・出力などはC-2:オートプレイとまったく同一とする。

### 結果
キー入力は遅れながらも全て受け取ることができたが、それを太鼓さん次郎側にうまく渡せず失敗。

遅れている部分についての解決方法は何となく検討ついているがこれではどうしようもない。