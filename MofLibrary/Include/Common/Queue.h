/*************************************************************************//*!
					
					@file	Queue.h
					@brief	キュー

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__QUEUE__H__

#define		__QUEUE__H__

//INCLUDE
#include	"Lock.h"

namespace Mof {

	/*******************************//*!
	@brief	キュー

			キュー

	@author	CDW
	*//********************************/
	template < typename T >
	class MOFLIBRARY_API CQueue : public IMofObject {
	protected:
		/*******************************//*!
		@brief	キューノード

				キューノード

		@author	CDW
		*//********************************/
		typedef struct tag_NODE {
			T							Value;
			tag_NODE*					pNext;
		}NODE,*LPNODE;
		/*******************//*!
		先頭ノード
		*//********************/
		LPNODE							m_pHead;
		/*******************//*!
		最後尾ノード
		*//********************/
		LPNODE							m_pTail;
		/*******************//*!
		ノード数
		*//********************/
		MofU32							m_Count;
		/*******************//*!
		ロック
		*//********************/
		CLock							m_Lock;
	public:
		/*************************************************************************//*!
				@brief			コンストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		CQueue();
		/*************************************************************************//*!
				@brief			デストラクタ
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CQueue();
		
		/*************************************************************************//*!
				@brief			データの追加
				@param[in]		val				追加データ

				@return			TRUE			正常終了<br>
								それ以外		エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Push(T val);
		/*************************************************************************//*!
				@brief			データの取り出し
				@param			None

				@return			ノードデータ
		*//**************************************************************************/
		virtual T Pop(void);
		
		/*************************************************************************//*!
				@brief			解放
				@param[in]		pData			解放追加データ

				@return			TRUE			正常終了<br>
								それ以外		解放エラー、エラーコードを返す。
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			ノード件数取得
				@param			None

				@return			ノード件数
		*//**************************************************************************/
		virtual MofU32 GetCount(void);

		//クラス基本定義
		MOF_LIBRARYCLASS_NOTCOPY(CQueue, MOF_QUEUECLASS_ID);
	};

	#include	"Queue.inl"
}

#endif