#ifndef INPUT_OUTPUT_UTILITY_H
#define INPUT_OUTPUT_UTILITY_H

/******************************************************
Author : Masujima Ryohei
Date   : 2016/12/23~2016/12/25
Summary: For input and output to console.
*******************************************************/

// ���C�u�����w�b�_
#include <iostream>

class IOUtility
{
private:
	IOUtility() {};
	~IOUtility() {};

public:
	/// <summary>
	/// �R���\�[���ɕ������\�����A���s����
	/// </summary>
	/// <param name="msg">�\��������������</param>
	/// <param name="nl">���s�����</param>
	static void log(const char* msg, int nl = 1)
	{
		std::cout << msg;

		for (int i = nl; i > 0; i--)
			std::cout << std::endl;
	}

	/// <summary>
	/// �R���\�[�����̕������S�ď�������
	/// </summary>
	static void logFlash()
	{
		system("cls");
	}

	/// <summary>
	/// �������̒��ɒl����͂��邪�A
	/// �͈͊O�̏ꍇ�͒l���ύX����Ȃ�
	/// </summary>
	/// <param name="val">���͂���l���i�[����ϐ��̃A�h���X</param>
	/// <param name="min">�͈͂̊J�n�l</param>
	/// <param name="max">�͈͂̏I���l</param>
	/// <returns>
	/// true : min <= val <= max
	/// false: min > val || val > max
	/// </returns>
	template <typename tV,typename tP1,typename tP2> 
	static bool inputNumberWithLimit(tV &val, tP1 min, tP2 max)
	{
		// �͈͊O�̂Ƃ��ɒl�����ɖ߂�����
		tV temp = val;

		std::cin >> val;

		if (min <= val && val <= max)
			return true;

		val = temp;
		return false;
	}
};

#endif // INPUT_OUTPUT_UTILITY_H
