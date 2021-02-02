#pragma once
#include "singletonBase.h"

struct tagIniData
{
	char* section;  //[Player]
	char* key;      //HP=100
	char* value;
};

class iniData : public singletonBase<iniData>
{
private:
	std::vector<tagIniData> _vIniData;



public:
	HRESULT init();
	void release();

	//데이터 추가하기
	void addData(const char* section, const char* key, const char* value);

	//데이터 세이브
	void saveINI(const char* fileName);

	//문자로 값을 로드하기 (파일이름, 해당 섹션, 키)
	char* loadDataString(const char* fileName, const char* section, const char* key);
	//정수로 값을 로드하기 (파일이름, 섹션, 키)
	int loadDataInteger(const char* fileName, const char* section, const char* key);
	//실수로 값 로드
	float loadDataFloat(const char* fileName, const char* section, const char* key);


};

