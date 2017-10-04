## Question
 從迷宮中的某一點能不能走到另一點
## Input
 輸入第1行有6個整數，以空格隔開，依序為 R, C, Sr, Sc, Er, Ec <br>
 表示迷宮有 R 行 C 欄，Sr, Sc 為起點的行跟欄，Er, Ec 為終點的行跟欄 <br>
 接下來有 R 行，每行 C 個字，以空格隔開，0 代表可以走的路，1 代表是牆壁，字元之間沒有空白 <br>
 注意每一行最後面都沒有空格
## Output
 如果起點能走到終點，輸出第一行為 "Yes"(不含引號) <br>
 接下來 R 行，每行 C 個字，把迷宮中走過的路換成"\*"(不含引號)輸出 <br>
 如果起點不能走到終點，輸出一行為 "No"(不含引號) <br>
## Examples
<table>
	<tr>
		<th>standard input</th>
		<th>standard output</th>
	</tr>
	<tr valign="top">
		<td><pre>5 5 2 1 3 5
0 1 0 0 0
0 1 0 1 0
0 1 0 1 0
0 1 0 1 0
0 0 0 1 0</pre></td>
  <td><pre>Yes
0 1 * * *
* 1 * 1 *
* 1 * 1 *
* 1 * 1 0
0 * 0 1 0</pre></td>
	</tr>
	<tr valign="top">
		<td><pre>5 5 1 1 5 5
0 1 0 0 0
0 1 0 1 0
0 1 1 1 0
0 1 0 1 0
0 0 0 1 0</pre></td>
  <td><pre>No</pre></td>
	</tr>
</table>
