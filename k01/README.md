# 課題1 レポート
学籍番号 35319030　氏名 西薗洸成


## 課題
長崎県にある市町村別人口データを読み込み、IDを用いて検索し、該当する市町村名、人口を出力するプログラムを作成する。

1. 使用するデータ
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
    - ID
    - 県名
    - 市町村名
    - 人口
    - 男性人口
    - 女性人口

    長崎県の市町村別人口データは、下記に構造体の配列に読み込まれる。

```C: 市町村別データ構造体
typedef struct {  
    int id;  
    char pref[13];  // UTF-8対応  
    char name[19];  // UTF-8対応  
    int population;  
    int m_population;  
    int f_population;  
} City;  
```



2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
   (1) LinearSearch：IDをキーとし、リニアサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity: 検索対象の都市別人口データ(配列)
    - int size: データの数  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。

    (2) BinarySearch: IDをキーとし、バイナリサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity: 検索対象の都市別人口データ(配列)
    - int left: バイナリサーチを行う配列のindex(左端)
    - int right: バイナリサーチを行う配列のindex(右端)  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。


3. 補助関数
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の市町村別人口データを出力する  
- PrintArray: 市町村別人口データをすべて出力する  
- LoadData: 市町村別人口データを読み込み、City型の配列に格納する  
- main: メイン関数。データをロードし、リニアサーチ、バイナリサーチを呼び出す  


## ソースコードの説明
68: result1=-1とおく

69:pos1を定義

71:for文を使って、（size）回だけ繰り返す

72-74: arrayCityに含まれるidとkeyが一致したときresult1にpos1を代入し、繰り返しを終了する

77: result1、つまりIDが合致した配列データのindexを出力

84: result2=-1とおく

85:pop2を定義

86:left=0とおく

87:MAX_CITY,つまり21-1=20をrightに代入

88:left<=rightである間は繰り返す

89:pos2にleft + (right - left) / 2 を代入

90-93:arrayCityに含まれるidとkeyが一致したときresult2にpos2を代入し、繰り返しを終了する

94-95:keyがarrayCityに含まれるidより大きい場合、leftにpos2 + 1を代入

96-99:keyがarrayCityに含まれるidより小さい、または等しい場合、rightにpos2 - 1を代入

100:result2、つまりIDが合致した配列データのindexを出力





## 出力結果

```
===== linear search =====
City ID?42214
42214, 長崎県, 南島原市, 46535, 21574, 24961

===== binary search =====
City ID?42214
42214, 長崎県, 南島原市, 46535, 21574, 24961

```
===== linear search =====
City ID?10000
city was not found

===== binary search =====
City ID?10000
city was not found

## 修正履歴

