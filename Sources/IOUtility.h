#ifndef INPUT_OUTPUT_UTILITY_H
#define INPUT_OUTPUT_UTILITY_H

/******************************************************
Author : Masujima Ryohei
Date   : 2016/12/23~2016/12/25
Summary: For input and output to console.
*******************************************************/

// ライブラリヘッダ
#include <iostream>

class IOUtility
{
private:
	IOUtility() {};
	~IOUtility() {};

public:
	/// <summary>
	/// コンソールに文字列を表示し、改行する
	/// </summary>
	/// <param name="msg">表示したい文字列</param>
	/// <param name="nl">改行する回数</param>
	static void log(const char* msg, int nl = 1)
	{
		std::cout << msg;

		for (int i = nl; i > 0; i--)
			std::cout << std::endl;
	}

	/// <summary>
	/// コンソール内の文字列を全て消去する
	/// </summary>
	static void logFlash()
	{
		system("cls");
	}

	/// <summary>
	/// 第一引数の中に値を入力するが、
	/// 範囲外の場合は値が変更されない
	/// </summary>
	/// <param name="val">入力する値を格納する変数のアドレス</param>
	/// <param name="min">範囲の開始値</param>
	/// <param name="max">範囲の終了値</param>
	/// <returns>
	/// true : min <= val <= max
	/// false: min > val || val > max
	/// </returns>
	template <typename tV,typename tP1,typename tP2> 
	static bool inputNumberWithLimit(tV &val, tP1 min, tP2 max)
	{
		// 範囲外のときに値を元に戻すため
		tV temp = val;

		std::cin >> val;

		if (min <= val && val <= max)
			return true;

		val = temp;
		return false;
	}
};

#endif // INPUT_OUTPUT_UTILITY_H
