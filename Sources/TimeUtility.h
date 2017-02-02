#ifndef TIME_UTILITY_H
#define TIME_UTILITY_H

/******************************************************
Author : Masujima Ryohei
Date   : 2016/12/20~2016/12/25
Summary: For time.
*******************************************************/

// ���C�u�����w�b�_
#include <iostream>

class TimeUtility
{
private:
	TimeUtility() {};
	~TimeUtility() {};

public:
	/// <summary>
	/// �w�肳�ꂽ�����͈͓����ǂ����𔻒肷��֐�
	/// </summary>
	/// <param name="t">�`�F�b�N����������</param>
	/// <param name="s">�͈͂̊J�n����</param>
	/// <param name="e">�͈͂̏I������</param>
	/// <returns>�͈͓����ǂ���</returns>
	template < typename tP1, typename tP2,typename tP3>
	static bool checkWhetherTimeIsOfRange(tP1 t, tP2 s, tP3 e)
	{
		// �J�n�����ƏI�������������ꍇ�Ȃ̂Ŋ܂ނƔ��f����
		if (s == e)
			if (s == t)
				return true;

		// ���ɂ����܂����ł��邩�ǂ���
		if (s < e)
		{
			if (s < t  && e > t)
				// �͈͓�
				return true;
		}
		else
			if (s > t && e < t)
				// �͈͓�
				return true;

		// �͈͊O
		return false;
	}
};

#endif // TIME_UTILITY_H