/*************************************************************************//*!
					
					@file	Application.h
					@brief	アプリケーションの動作をライブラリ利用者が作成するための基底インターフェイス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__APPLICATION__H__

#define		__APPLICATION__H__

//INCLUDE
#include	"MofBase.h"

namespace Mof {

	/*******************************//*!
	@brief	アプリケーションの動作をライブラリ利用者が作成するための基底インターフェイス

			アプリケーションの動作をライブラリ利用者が作成するための基底インターフェイス。<br>
			このインターフェイスを継承したクラスを作成し、フレームワークの初期化時に設定する。<br>
			フレームワーク内で内部の関数が実行されるので、ライブラリ利用者は各関数内部にてアプリケーションの動作を実装する。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IApplication : public IMofBase {
	private:
	public:
		/*************************************************************************//*!
				@brief			アプリケーションの初期化
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Initialize(void) = 0;
		/*************************************************************************//*!
				@brief			アプリケーションの実行
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Run(void) = 0;
		/*************************************************************************//*!
				@brief			アプリケーションの更新
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Update(void) = 0;
		/*************************************************************************//*!
				@brief			アプリケーションの描画
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Render(void) = 0;
		/*************************************************************************//*!
				@brief			アプリケーションの解放
				@param			None
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Release(void) = 0;
	};

	//置き換え
	typedef IApplication	*LPApplication;
}

#endif

//[EOF]