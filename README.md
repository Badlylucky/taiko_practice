# 準備編
プログラムを実行するためには、言語によって異なるが、基本的には特別な環境を用意する必要がある。具体的には、実行環境・エディタの2つが必要になってくる。今回はC言語に注目して説明する。

## 実行環境
実行環境とは、C言語においてはコンパイラのことである。C言語の文章はそのままではマシンが理解して動かすことができないので、コンパイルという作業を通して機械が読める形へと変換する。そのような作業を行うプログラムのことをコンパイラという。C言語のコンパイラはMicrosoftが提供しているコンパイラとgccの2つが現在のところ主流である（他にもある）。今回はgccを導入するという前提で話を進めていく。

gccはCygwinという環境の中に入っているのでそれをインストールしてしまうのが最も手軽である。Cygwin自体はUNIXの環境に準じているのでコマンドなどは共通している。Cygwinで使う必要のあるコマンドを以下に示す。
* ls 現在のディレクトリの内容を表示する。今どこにいるかを知るのに使う。
* cd 指定したディレクトリに移動する。特に“cd ~”を実行した場合、ホームディレクトリ（起動したときのディレクトリ）に戻る。
* gcc 第1引数で指定したC言語のソースファイルをコンパイルする。実行ファイルの名前は“a.out”となる。

以上の記述をもとにCygwinの使い方をまとめると、エディタでCのソースファイルを記述し、Cygwin内でそのソースファイルが置かれたディレクトリまでcdコマンドを使って移動し、gccコマンドでコンパイルして、“./a.out”でそのソースファイルを実行する、という流れになる。またそれぞれの動作は、Ctrlキー+Cキーで強制的に中断できる。うっかり無限ループを作ってしまったときに重宝するので覚えておくとよい。

また、ファイル名についてはTabキーを押すことで補完できる。これも覚えておくとそこそこ役に立つ。

## エディタ
エディタとは、ひとことで言うとメモ帳が超パワーアップしたものである。パワーアップしすぎているせいで、普通に日本語を書く分にはかえって使いづらかったりする。

だからメモ帳でもプログラミングはできる。しかし、初心者がメモ帳を使ってプログラミングするのはあまりおすすめしない。理由としては、ミスに気づきにくくなってしまいストレスが溜まる、どうせプログラミングに習熟してくると何らかのエディタを使うようになるので最初から使っておいたほうがいい、という2点が挙げられる。

ではどのエディタを使うのが最も良いか？　……この問題についてはしばしば不毛な宗教争いを生むので言及しない。しかしプログラミングするならば最低限コードの色分けがされ、インデントが自動でついて見やすくなるものを選ぶべきだろう。このいずれもできないメモ帳は、この時点でエディタとしては三流未満確定だ。あとはものによって色々な便利機能がついているものがあるが、自分が使いやすいと思ったものを使えばよい。

現在C言語において主流のエディタには以下のようなものがある。なお、ここではIDE（統合開発環境）も（コンパイル機能つきの）エディタとしてエディタに含める。
### Emacs

ご存知エディタの代名詞にして最古参。依然としてエディタ界最強の名をほしいままにしているが、最近良からぬ噂を聞く。使いこなせば心強いというれべるではないが、使いこなせるまでに年単位の習熟を必要とする。したがっておすすめしない。

### Visual Studio Code, Sublime Text, Atom

近年ボコボコっと出てきたポストEmacsを標榜するエディタ群。どれもEmacsばりの柔軟性を持つ拡張機能を備え、かつそれなりのレベルで使いこなすならばメモ帳と同じ感覚で使いこなせる。私はVisual Studio Codeをメインのエディタとして使っているが、正直この3つは好みの問題だと思う。

### Visual Studio(IDE)

C言語系書くならこのIDE。言わずと知れたMicrosoft謹製のIDEでそのコード補完能力、様々な便利機能は多くのエディタを凌駕する。が、猛烈に起動が遅く、しかも容量食いまくる（メモリもHDDも）。ちなみにこれ1本でコードを書いてコンパイルまですることもできるが、C言語のサポートが最近おざなりになってきているので今回の課題を解く上では決してこれでコンパイルしようなどと考えてはいけない。

### サクラエディタ, 秀丸エディタ, TeraPad

国産エディタの主要なところをずらり。さすがは国産エディタというべきか方言ってレベルじゃないガラケー世代の文字コードまでサポートしていたりして驚かされる。しかし、所詮はその程度。日本語をたくさん書くなら導入しておいて損はないかもしれないが、今回の趣旨にはそぐわないのでまず選ばなくてもいい。あとダサい。

以上の記述は個人の主観であり、自分にあったものを探してみることがエディタ選びのうえでは重要である。特筆していない限りエディタは基本外国製であり、日本語入力には若干弱いところがあるという点では共通している。

では、準備編が終わったところで、問題にとりかかってみよう。