/*************************************************************************//*!
					
					@file	DX11GeometryInstanced.h
					@brief	DirectX11ジオメトリクラス。

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11GEOMETRYINSTANCED__H__

#define		__DX11GEOMETRYINSTANCED__H__

//INCLUDE
#include	"../GeometryInstancedBase.h"
#include	"DX11Geometry.h"

namespace Mof {
	
	/*******************************//*!
	@brief	DirectX11ジオメトリクラス

			DirectX11ジオメトリクラス。

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11GeometryInstanced : public CGeometryInstancedBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced();
		/*************************************************************************//*!
				@brief			バッファ指定コンストラクタ
				@param[in]		pName			名前
				@param[in]		Topology		描画方式
				@param[in]		pVBuff			頂点バッファ
				@param[in]		pIBuff			インデックスバッファ
				@param[in]		pMaterial		マテリアル
				@param[in]		InstanceCount	インスタンス最大数

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			バッファ指定コンストラクタ
				@param[in]		pName			名前
				@param[in]		Topology		描画方式
				@param[in]		pVBuff			頂点バッファ
				@param[in]		pIBuff			インデックスバッファ
				@param[in]		pMaterial		マテリアル
				@param[in]		pInstanceBuff	インスタンスバッファ

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(LPCMofChar pName, PrimitiveTopology Topology, LPVertexBuffer pVBuff, LPIndexBuffer pIBuff, LPMaterial pMaterial, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピージオメトリ
				@param[in]		InstanceCount	インスタンス最大数

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(const CDX11Geometry& pObj, MofU32 InstanceCount);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピージオメトリ
				@param[in]		pInstanceBuff	インスタンスバッファ

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(const CGeometryBase& pObj, LPVertexBuffer pInstanceBuff);
		/*************************************************************************//*!
				@brief			コピーコンストラクタ
				@param[in]		pObj			コピージオメトリ

				@return			None
		*//**************************************************************************/
		CDX11GeometryInstanced(const CDX11GeometryInstanced& pObj);
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11GeometryInstanced();
		
		/*************************************************************************//*!
				@brief			メッシュのコピー生成
				@param			None
				
				@return			作成されたコピーメッシュ<br>
								作成に失敗した場合NULLを返す
		*//**************************************************************************/
		virtual IGeometry* CreateCopyObject(void) const;
		
		/*************************************************************************//*!
				@brief			基本描画<br>
								バッファの設定と、描画のコールのみを行う。<br>
								マテリアルの設定など、シェーダーの設定は呼び出し前に行っておくこと。
				@param			None
				
				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Render(void);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		
		//クラス基本定義
		MOF_LIBRARYCLASS(CDX11GeometryInstanced, MOF_DX11GEOMETRYINSTANCEDCLASS_ID);
	};

	#include	"DX11GeometryInstanced.inl"
	
	//置き換え
	typedef CDX11GeometryInstanced		CGeometryInstanced;
}

#endif

//[EOF]