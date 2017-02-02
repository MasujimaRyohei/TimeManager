/******************************************************
	Author : Masujima Ryohei
	Date   : 2016/12/11~2016/12/25
	Summary: A task for entry to Mobile Factory.
*******************************************************/

// ���C�u�����w�b�_
#include <iostream>
#include <conio.h>
#include <cstdlib>

// ����w�b�_
#include "TimeUtility.h"
#include "IOUtility.h"

using namespace std;

const int DAYTIME_MIN = 0;
const int DAYTIME_MAX = 23;

int main(void)
{
	// �N���X�����ȗ�
	typedef IOUtility io;

	// ���C�����[�v
	while (true)
	{
		// �͈͂̊J�n����(start)
		int s;
		// �͈͂̏I������(end)
		int e;
		// �`�F�b�N����������(time)
		int t;
		
		io::log("�͈͂̊J�n��������͂��Ă�������(0~23)");
		while (!io::inputNumberWithLimit(s, DAYTIME_MIN, DAYTIME_MAX))
		{
			io::log("0~23�܂ł̐��������l����͂��Ă�������");
		}

		io::log("�͈͂̏I����������͂��Ă�������(0~23)");
		while (!io::inputNumberWithLimit(e, DAYTIME_MIN, DAYTIME_MAX))
		{
			io::log("0~23�܂ł̐��������l����͂��Ă�������");
		}

		io::log("�`�F�b�N��������������͂��Ă�������");
		if (!io::inputNumberWithLimit(t, DAYTIME_MIN, DAYTIME_MAX))
		{
			io::log("0~23�܂ł̐��������l����͂��Ă�������");
		}
		io::log("���̎����͔͈͂�",NULL);

		if (TimeUtility::checkWhetherTimeIsOfRange(t, s, e))
			io::log("�܂܂�Ă��܂��B");
		else
			io::log("�܂܂�Ă��܂���B");


		io::log("�v���O�������I������Ȃ�ESC�L�[�������Ă��������B");
		io::log("����ȊO�������ꂽ�ꍇ�A������x�`�F�b�N�����s���܂��B");

		if (_getch() == 0x1b)
			break;

		io::logFlash();
	}

	// ����I��
	return 0;
}

