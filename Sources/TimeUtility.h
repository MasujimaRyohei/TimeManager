#ifndef TIME_UTILITY_H
#define TIME_UTILITY_H

/******************************************************
Author : Masujima Ryohei
Date   : 2016/12/20~2016/12/25
Summary: For time.
*******************************************************/

// ライブラリヘッダ
#include <iostream>

class TimeUtility
{
private:
	TimeUtility() {};
	~TimeUtility() {};

public:
	/// <summary>
	/// 指定された日が範囲内かどうかを判定する関数
	/// </summary>
	/// <param name="t">チェックしたい時刻</param>
	/// <param name="s">範囲の開始時刻</param>
	/// <param name="e">範囲の終了時刻</param>
	/// <returns>範囲内かどうか</returns>
	template < typename tP1, typename tP2,typename tP3>
	static bool checkWhetherTimeIsOfRange(tP1 t, tP2 s, tP3 e)
	{
		// 開始時刻と終了時刻が同じ場合なので含むと判断する
		if (s == e)
			if (s == t)
				return true;

		// 日にちをまたいでいるかどうか
		if (s < e)
		{
			if (s < t  && e > t)
				// 範囲内
				return true;
		}
		else
			if (s > t && e < t)
				// 範囲内
				return true;

		// 範囲外
		return false;
	}
};

#endif // TIME_UTILITY_H