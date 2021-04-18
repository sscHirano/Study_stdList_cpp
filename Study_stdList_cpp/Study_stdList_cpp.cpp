// Study_stdList_cpp.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <list>

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

int main()
{
	study_01_add_get();

	// 最初から領域確保したlistの生成

	// 配列をlistへ変換

	// iterator

	// vector (やる？)


	return 0;
}

/// <summary>
/// listへの追加と取得、削除
/// </summary>
void study_01_add_get()
{
	std::cout << "---- study_01_add_get begin.\n";

	// list変数を定義
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
	std::cout << "list count = " << list.size() << "\n";
	// 参照用変数(iterator)の取得
	for (std::list<int>::iterator itrator = list.begin(); itrator != list.end(); ++itrator) {
		std::cout << "data:" << *itrator << "\n";
	}
	// ↑をfor文使わずに無骨に書くと、↓の感じ
	std::cout << "\t----\n";
	std::list<int>::iterator itrator = list.begin();
	std::cout << "data:" << *itrator++ << "\n";
	std::cout << "data:" << *itrator++ << "\n";
	std::cout << "data:" << *itrator++ << "\n";
	std::cout << "data:" << *itrator++ << "\n";

	// iteratorを使って書き換える。
	std::cout << "\t書き換え確認\n";
	itrator = list.begin();
	*itrator = 50;
	itrator++;
	*itrator = 100;
	// 書き換えの確認
	for (auto itrator = list.begin(); itrator != list.end(); ++itrator) {
		std::cout << "data:" << *itrator << "\n";
	}

	std::cout << "---- study_01_add_get end.\n";
}
