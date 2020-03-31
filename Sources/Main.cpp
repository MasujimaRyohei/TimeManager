/******************************************************
	Author : Masujima Ryohei
	Date   : 2016/12/11~2016/12/25
	Summary: Time manager.
*******************************************************/

// ライブラリヘッダ
#include <iostream>
#include <conio.h>
#include <cstdlib>

// 自作ヘッダ
#include "TimeUtility.h"
#include "IOUtility.h"

using namespace std;

const int DAYTIME_MIN = 0;
const int DAYTIME_MAX = 23;

int main(void)
{
	// クラス名を省略
	typedef IOUtility io;

	// メインループ
	while (true)
	{
		// 範囲の開始時刻(start)
		int s;
		// 範囲の終了時刻(end)
		int e;
		// チェックしたい時刻(time)
		int t;
		
		io::log("範囲の開始時刻を入力してください(0~23)");
		while (!io::inputNumberWithLimit(s, DAYTIME_MIN, DAYTIME_MAX))
		{
			io::log("0~23までの正しい数値を入力してください");
		}

		io::log("範囲の終了時刻を入力してください(0~23)");
		while (!io::inputNumberWithLimit(e, DAYTIME_MIN, DAYTIME_MAX))
		{
			io::log("0~23までの正しい数値を入力してください");
		}

		io::log("チェックしたい時刻を入力してください");
		if (!io::inputNumberWithLimit(t, DAYTIME_MIN, DAYTIME_MAX))
		{
			io::log("0~23までの正しい数値を入力してください");
		}
		io::log("その時刻は範囲に",NULL);

		if (TimeUtility::checkWhetherTimeIsOfRange(t, s, e))
			io::log("含まれています。");
		else
			io::log("含まれていません。");


		io::log("プログラムを終了するならESCキーを押してください。");
		io::log("それ以外を押された場合、もう一度チェックを実行します。");

		if (_getch() == 0x1b)
			break;

		io::logFlash();
	}

	// 正常終了
	return 0;
}

