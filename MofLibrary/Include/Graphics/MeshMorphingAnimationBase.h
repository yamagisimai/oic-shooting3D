/*************************************************************************//*!
					
					@file	MeshMorphingAnimationBase.h
					@brief	メッシュアニメーション基底クラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHMORPHINGANIMATIONBASE__H__

#define		__MESHMORPHINGANIMATIONBASE__H__

//INCLUDE
#include	"MeshMorphingAnimation.h"

namespace Mof {
	
	/*******************************//*!
	@brief	メッシュアニメーション基底クラス

			メッシュアニメーション基底となるクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMeshMorphingAnimation : public IMeshMorphingAnimation {
	protected:
		/*******************//*!
		名前
		*//********************/
		CString						m_Name;
		/*******************//*!
		パラメーターキー
		*//********************/
		LPFloatKeyFrameArray		m_pParameterKey;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CMeshMorphingAnimation();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーメッシュアニメーション

				@return			None
		*//**************************************************************************/
		CMeshMorphingAnimation(const CMeshMorphingAnimation& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMeshMorphingAnimation();
		
		/*************************************************************************//*!
				@brief			メッシュアニメーションのコピー生成
				@param			None
				
				@return			作成されたコピーCMeshMorphingAnimation<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual IMeshMorphingAnimation* CreateCopyObject(void) const;

		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前設定
				@param[in]		pName			設定する名前
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			パラメーターキー設定<br>
								古いデータがある場合解放される
				@param[in]		pKey			設定するキー
				
				@return			TRUE			正常終了<br>
								それ以外		設定エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool SetParameterKey(LPFloatKeyFrameArray pKey);
		/*************************************************************************//*!
				@brief			モーションのループフラグの設定
				@param[in]		bLoop			ループフラグ
				
				@return			TRUE			成功<br>
								それ以外		失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetLoop(MofBool bLoop);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			名前取得
				@param			None

				@return			名前の取得
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			アニメーションの時間取得
				@param			None

				@return			アニメーションの時間
		*//**************************************************************************/
		virtual MofFloat GetTime(void);
		/*************************************************************************//*!
				@brief			パラメーターキー取得
				@param			None

				@return			パラメーターキー
		*//**************************************************************************/
		virtual LPFloatKeyFrameArray GetParameterKey(void);

		//クラス基本定義
		MOF_LIBRARYCLASS(CMeshMorphingAnimation,MOF_MESHMORPHINGANIMATIONCLASS_ID);
	};

	#include	"MeshMorphingAnimationBase.inl"

}

#endif

//[EOF]