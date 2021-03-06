# 課題5 レポート
学生番号　氏名


## 課題
本課題では、以下の3つのプログラムを作成する。なお、出発駅、到着駅は、適宜変更しても良い。
- 赤迫駅を出発点として、深さ優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、幅優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、蛍茶屋駅までの最短所要時間ルートをダイクストラ法で見つけ、出力するプログラム
路線図、および、駅間の所要時間は下記のようになっている。  

1.使用するデータ  
路線図、及び、駅間の所要時間は下記のようになっている。なお、プログラムにおいて、駅名はArrayStation、グラフは隣接行列AdjacencyMatrixに保存されている。  

<img src=images/routemap.png width=600>  

```
typedef struct tagStation {
    char name[20];
    char kanji[16];
} Station;

Station ArrayStation[MAX_STATIONS] = {
    {"akasako", "赤迫"},
    {"nagasakidaigakumae", "長崎大学前"},
    {"nagasakiekimae", "長崎駅前"},
    {"shinchichukagai", "新地中華街"},
    {"ishibashi", "石橋"},
    {"sofukuji", "崇福寺"},
    {"shiminkaikan", "市民会館"},
    {"hotarujaya", "蛍茶屋"},
};

int AdjacencyMatrix[MAX_STATIONS][MAX_STATIONS] = {
    {0,  5,  0,  0,  0,  0,  0,  0},
    {5,  0, 16,  0,  0,  0,  0,  0},
    {0, 16,  0,  7,  0,  0,  5,  0},
    {0,  0,  7,  0,  7,  6, 10,  0},
    {0,  0,  0,  7,  0,  0,  0,  0},
    {0,  0,  0,  6,  0,  0, 10,  0},
    {0,  0,  5, 10,  0, 10,  0,  6},
    {0,  0,  0,  0,  0,  0,  6,  0},
};
```


2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
(1) DepthFirstSearch: 深さ優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。  


    (2) BreadthFirstSearch: 幅優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。

    (3) SearchGraphByDijkstra: ダイクストラ法で、出発駅から到着駅までの最短所要時間ルートを探索する。  
    [入力]  
    - int start: 出発駅のインデックス
    - int goal: 到着駅のインデックス  
    - int size: 駅数  
    - int matrix[size][size]: 隣接行列  
    - NodeInfo arrayNodeInfo[size]:  

    [出力]  
    - return値: 出発駅から到着駅までの所要時間 
    - 関数内でprintf文を使い、最短ルートを出力すること

3. 補助関数  
以下の関数はすでに実装されており、利用することができる。
- PrintStationName: indexで指定される駅名を出力する
- StackInit: スタックを初期化する
- StackPush: スタックに値をプッシュする
- StackPop: スタックから値をポップする
- StackTop: スタックの先頭の値を取得する(スタックポインタは移動しない)
- StackIsEmpty: スタックが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- InitQueue: キューを初期化する
- EnQueue: キューに値を入れる
- DeQueue: キューから値を取り出す
- QueueIsEmpty: キューが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- main: メイン関数。深さ優先探索、幅優先探索、ダイクストラ法による最短経路探索処理を呼び出す。

4. チャレンジ課題  
赤迫駅を起点として、各駅にたどり着くまでのルートを、深さ優先探索、幅優先探索のそれぞれの場合で出力するようにプログラムを修正する。  
- 深さ優先探索のルート表示(10点)
- 幅優先探索のルート表示(10点)

## ソースコードの説明

114-116:visit[size],i,indexを宣言

118-119:visitedをすべて０にする（すべて行ったことがないことにする）

122:stackを初期化する

123:出発点をpushする

125:スタックから取り出すものがなくなるまで繰り返す

126:stackから取り出して（pop）、indexに代入する

127-139:行ったことがない場合、行ったことにして、その場所から行ける場所を確認する。その場所から行ける場所をstackに入れる。

140-144:行ったことがある場所を確認して、行ったことがある場合"駅のindex = visited"と出力する

208-210:visit[size],i,indexを宣言

211-213:visitedをすべて０にする（すべて行ったことがないことにする）

214:queueを初期化する

215:出発点をEnqueueする

216:queueから取り出すものがなくなるまで繰り返す

217:queueから取り出して（dequeue）、indexに代入する

218-228:行ったことがない場合、行ったことにして、その場所から行ける場所を確認する。その場所から行ける場所をqueueに入れる。

230-232:行ったことがある場所を確認して、行ったことがある場合"駅のindex = visited"と出力する


## 出力結果

```

```
0 is visited
1 is visited
2 is visited
3 is visited
4 is visited
5 is visited
6 is visited
7 is visited
0 is visited
1 is visited
2 is visited
3 is visited
4 is visited
5 is visited
6 is visited
7 is visited
Time Required: 8

## 修正履歴

