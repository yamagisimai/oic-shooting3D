/*************************************************************************//*!
					
					@file	DX11ShaderBind_BrightPass.h
					@brief	高輝度抽出シェーダーバインド。<br>
							高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

															@author	CDW
															@date	2014.04.20
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBIND_BRIGHTPASS__H__

#define		__DX11SHADERBIND_BRIGHTPASS__H__

//INCLUDE
#include	"DX11ShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	高輝度抽出シェーダーバインド。
	
			高輝度抽出シェーダーにパラメーターを関連付けるためのクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBind_BrightPass : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	スプライト描画入力コンスタントバッファ列挙

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_THRESHOLD = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	閾値情報入力コンスタントバッファ

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstThresholdParam
		{
			MofFloat Threshold;
		};
		/*******************//*!
		プリミティブ描画シーン情報設定
		*//********************/
		ConstThresholdParam							m_ThresholdParam;
	protected:
		/*******************//*!
		スプライト情報入力コンスタントバッファ
		*//********************/
		ID3D11Buffer*							m_pConstThreshold;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_BrightPass();
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj		コピーシェーダー

				@return			None
		*//**************************************************************************/
		CDX11ShaderBind_BrightPass(const CDX11ShaderBind_BrightPass& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBind_BrightPass();
		
		/*************************************************************************//*!
				@brief			バインダの生成
				@param[in]		pShader		シェーダー
				
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
		
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
				@brief			バッファの設定
				@param[in]		n			番号
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n);
		/*************************************************************************//*!
				@brief			バッファの設定
				@param[in]		n			番号
				@param[in]		pData		データ
					
				@return			TRUE		成功<br>
								それ以外	失敗、エラーコードが戻り値となる
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			設定パラメーター数を取得する
				@param			None

				@return			パラメーターの数
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11ShaderBind_BrightPass,MOF_DX11SHADERBINDBRIGHTPASSCLASS_ID);
	};

	#include	"DX11ShaderBind_BrightPass.inl"
	
	//置き換え
	typedef CDX11ShaderBind_BrightPass		CShaderBind_BrightPass;
	typedef CShaderBind_BrightPass*			LPShaderBind_BrightPass;
}

#endif

//[EOF]