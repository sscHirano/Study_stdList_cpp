// Study_stdList_cpp.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <list>

#include "Infomation.h"

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

void study_01_add_get();
void study_02_constractor();
void study_03_templete();

void dump(std::list<int> list);
void dump(std::list<Infomation> list);

int main()
{
	// リストへの追加と参照
	study_01_add_get();

	// 最初から領域(もしくはデータ)確保したlistの生成
	study_02_constractor();

	// 任意のクラスをlistにする
	study_03_templete();

	return 0;
}

/// <summary>
/// listへの追加と取得、削除
/// </summary>
void study_01_add_get()
{
	std::cout << "---- study_01_add_get() begin.\n";

	// ■list変数を定義
	// intのListを作るので<>の中はintを指定する。(つまりListの中はintしか入らない)
	std::list<int> list;		// listの中身：空

	// ■要素追加
	// 末尾に入れる
	list.push_back(10);			// lintの中身：10
	list.push_back(20);			// lintの中身：10,20
	list.push_back(30);			// lintの中身：10,20,30
	// 先頭に入れる
	list.push_front(0);			// lintの中身：0,10,20,30

	// ■参照
	// 要素数の確認
	std::cout << "参照\n";
	std::cout << "\tlist count = " << list.size() << "\n";
	// 参照用変数(iterator)の取得
	// 参照するためには、iteratorが必要
	// listからiteratorを取得する。今回はbegin()で先頭のiteratorを取得
	// iteratorはポインタのようなもの。
	std::list<int>::iterator itrator = list.begin();
	std::cout << "\tdata:" << *itrator++ << "\n";	// ++で、参照先を次の要素に動かしている。
	std::cout << "\tdata:" << *itrator++ << "\n";
	std::cout << "\tdata:" << *itrator++ << "\n";
	std::cout << "\tdata:" << *itrator++ << "\n";

	// ↑をfor文使って書くと、↓の感じ
	std::cout << "for文での参照\n";
	for (std::list<int>::iterator itrator = list.begin(); itrator != list.end(); ++itrator) {
		std::cout << "\tdata:" << *itrator << "\n";
	}

	// ■iteratorを使ってリストの中身書き換え。
	std::cout << "書き換え確認\n";
	itrator = list.begin();
	*itrator = 50;
	itrator++;
	*itrator = 100;
	// 書き換えの確認
	for (auto itrator = list.begin(); itrator != list.end(); ++itrator) {
		std::cout << "\tdata:" << *itrator << "\n";
	}

	// ■削除				// listの中身：50,100,20,30
	std::cout << "削除\n";
	// 先頭の削除
	list.pop_front();		// listの中身：100,20,30
	// 末尾の削除
	list.pop_back();		// listの中身：100,20
	// iteratorを使って任意の位置を削除
	auto iterator = list.begin();
	iterator++;	// 先頭の次へ移動
	// iteratorの差す先を削除
	list.erase(iterator);	// listの中身：100
	std::cout << "\tlist count = " << list.size() << "\n";
	std::cout << "\tlist data = " << *list.begin() << "\n";

	std::cout << "---- study_01_add_get() end.\n";
}

/// <summary>
/// 最初から領域(もしくはデータ)確保したlistの生成
/// </summary>
void study_02_constractor()
{
	std::cout << "---- study_02_constractor() begin.\n";

	// listの中身は、空、事前の確保領域も無し
	std::list<int> list1;		

	// listの中身は、空、事前の確保領域は、3つ分
	// ※事前に領域を確保しておくと、listへの追加が少し速い。
	//   何個使うって分かってる時は指定しよう。
	std::list<int> list2(3);

	// listの中身は、データあり、事前の予約領域も、データ数分
	std::list<int> list3{10,20,30,40,50};
	std::cout << "list3\n";
	dump(list3);

	// 配列をlistに変換
	int orgValue[] = { 5,8,4,2,4,6 };
	// 配列の先頭と末尾を指定して作成する
	std::list<int> list4(orgValue, std::end(orgValue));
	std::cout << "list4\n";
	dump(list4);

	std::cout << "---- study_02_constractor() end.\n";
}

/// <summary>
/// list内容のコンソール出力
/// </summary>
/// <param name="list"></param>
void dump(std::list<int> list)
{
	std::cout << "dump\n";
	for (std::list<int>::iterator itrator = list.begin(); itrator != list.end(); ++itrator) {
		std::cout << "\tdata:" << *itrator << "\n";
	}
}

/// <summary>
/// 任意の方のlistを作成する
/// </summary>
void study_03_templete()
{
	std::cout << "---- study_03_templete() begin.\n";

	Infomation hirano(24, "hirano", "osaka");
	Infomation taro(25, "taro", "tokyo");
	Infomation hanako(26, "hanako", "yokohama");

	// <>の中にInfomationを指定し、Infomationのリストを作ることを宣言する
	std::list<Infomation> list;
	list.push_back(hirano);
	list.push_back(taro);
	list.push_back(hanako);
	dump(list);

	std::cout << "---- study_03_templete() end.\n";
}

/// <summary>
/// list内容のコンソール出力
/// </summary>
/// <param name="list"></param>
void dump(std::list<Infomation> list)
{
	std::cout << "dump\n";
	std::cout << "\tcount = "<< list.size() << "\n";
	for (auto itrator = list.begin(); itrator != list.end(); ++itrator) {
		std::cout << "\t----\n";
		std::cout << "\tInfomation.NO:" << (*itrator).mNo << "\n";
		std::cout << "\tInfomation.NAME:" << (*itrator).mName << "\n";
		std::cout << "\tInfomation.ADDRESS:" << (*itrator).mName << "\n";
	}
}
