#pragma once

#include <string>

class Infomation {
public:
	int mNo;
	std::string mName;
	std::string mAddress;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="no"></param>
	/// <param name="name"></param>
	/// <param name="address"></param>
	/// <returns></returns>
	Infomation(int no, std::string name, std::string address)
		: mNo(no),
		mName(name),
		mAddress(address)
	{

	}

};
