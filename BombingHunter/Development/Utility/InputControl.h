#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];  //現在の入力情報
	static char old_key[D_KEYCODE_MAX];  //前のフレームの入力情報

public:
	static void Update();  //更新処理

	//キー入力の取得
	static bool GetKey(int key_code);
	static bool GetKeyDown(int key_code);
	static bool GetKeyUp(int key_code);

private:
	//キーコード範囲
	static bool CheckKeyCodeRange(int key_code);
};
