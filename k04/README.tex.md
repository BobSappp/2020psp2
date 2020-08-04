# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
9 構造体の宣言
37~41 43~47 94~104 IDのファイルを読み取り閉じる
65 データを入力させる
74~84入力したIDがあるなら、そこのIDと身長と性別を表示させる
85 入力したIDがないならNO Data と出力する
## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴
[comment #20200721]
- 6行目と7行目の関数の宣言は行っていますが、肝心な中身が見当たりません。もし宣言するのならば作成をお願いします。
- 62行目の書き方もあまりよくないです。2つに分けてから宣言をお願いします。

[comment #20200804 sonoda]
- OKです．課題4完了