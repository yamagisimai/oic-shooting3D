/*************************************************************************//*!
					
					@file	ShaderBind_GaussianBlurBase.h
					@brief	�K�E�X�ڂ����V�F�[�_�[�o�C���h���N���X�B
					
															@author	CDW
															@date	2015.04.17
*//**************************************************************************/

//ONCE
#ifndef		__SHADERBIND_GAUSSIANBLURBASE__H__

#define		__SHADERBIND_GAUSSIANBLURBASE__H__

//INCLUDE
#include	"ShaderBindBase.h"

//DEFINE

//!�ڂ����̃T���v�����O���̔���
#define		MOF_GBLUR_SAMPLING_HALF		(7)

namespace Mof {
	
	/*******************************//*!
	@brief	�K�E�X�ڂ����V�F�[�_�[�o�C���h���N���X�B

			�K�E�X�ڂ����V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̊��N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderBind_GaussianBlurBase : public CShaderBindBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����͒��_�o�b�t�@��

		@author	CDW
		*//********************************/
		enum VertexAttribute
		{
			ATTRIBUTE_POSITION,
			ATTRIBUTE_TEXCOORDS,

			ATTRIBUTE_COUNT,
		};		  
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_SCENE,
			PARAM_MESH,
			PARAM_BLUR,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	�X�v���C�g�`��V�[�������̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstSceneParam
		{
			Matrix44	mtxView;
			Matrix44	mtxProj;
		};
		/*******************//*!
		�v���~�e�B�u�`��V�[�����ݒ�
		*//********************/
		ConstSceneParam							m_SceneParam;
		/*******************************//*!
		@brief	�X�v���C�g�`��X�v���C�g�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstMeshParam
		{
			Vector4		cbvOffset;
			Vector4		cbvSize;
			Vector4		cbtOffset;
			Vector4		cbtSize;
			Vector4		cbColor;
			Matrix44	mtxWorld;
		};
		/*******************//*!
		�v���~�e�B�u�`��v���~�e�B�u���ݒ�
		*//********************/
		ConstMeshParam							m_MeshParam;
		/*******************************//*!
		@brief	�v���~�e�B�u�`��K�E�X�ڂ��������̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		SHADERPARAM_ALIGNMENT struct ConstBlurParam
		{
			Vector4 texOffsets[MOF_GBLUR_SAMPLING_HALF];
			Vector4 reverseOffset;
		};
		/*******************//*!
		�v���~�e�B�u�`��K�E�X�ڂ������ݒ�
		*//********************/
		ConstBlurParam							m_BlurParam;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderBind_GaussianBlurBase();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CShaderBind_GaussianBlurBase(const CShaderBind_GaussianBlurBase& pObj);
		
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n) = 0;
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			�T���v���̐ݒ�<br>
								DirectX11�Ŏ��s���̂ݗL��<br>
								DirectX9�̏ꍇ�̓V�F�[�_�[�ł̎w�肪�AOpenGL�n�̏ꍇ�̓e�N�X�`���ł̎w�肪�L���ɂȂ�B
				@param[in]		n			�ԍ�
				@param[in]		st			�T���v���^�C�v
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetSamplerType(MofU32 n,MofU32 st);
		/*************************************************************************//*!
				@brief			�`��p�s���ݒ肷��
				@param[in]		wMat			�s��

				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(const Matrix44& wMat);
		/*************************************************************************//*!
				@brief			�`��p�s���ݒ肷��
				@param[in]		pMotion		���[�V�����R���g���[��
				@param[in]		pGeom		�W�I���g��
				
				@return			None
		*//**************************************************************************/
		virtual void SetWorldMatrix(LPMeshMotionController pMotion,LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			�`��p�}�e���A����ݒ肷��
				@param[in]		pMat			�}�e���A��

				@return			None
		*//**************************************************************************/
		virtual void SetMaterial(LPMaterial pMat);
		/*************************************************************************//*!
				@brief			�`��p�v���~�e�B�u�p�����[�^�[��ݒ肷��
				@param[in]		pPar			�e�N�X�`���p�����[�^�[

				@return			None
		*//**************************************************************************/
		virtual void SetPrimitiveParameter(LPPrimitiveRenderParameter pPar);
		/*************************************************************************//*!
				@brief			�`��p�e�N�X�`���p�����[�^�[��ݒ肷��
				@param[in]		pPar			�e�N�X�`���p�����[�^�[

				@return			None
		*//**************************************************************************/
		virtual void SetTextureParameter(LPTextureRenderParameter pPar);
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		pc				�J����

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(LPCamera pc);
		/*************************************************************************//*!
				@brief			�`��p�J������ݒ肷��
				@param[in]		mv				�J����
				@param[in]		mp				�v���W�F�N�V����

				@return			None
		*//**************************************************************************/
		virtual void SetCamera(Matrix44& mv,Matrix44& mp);
		/*************************************************************************//*!
				@brief			�`��p��{���C�g��ݒ肷��
				@param[in]		pl				���C�g

				@return			None
		*//**************************************************************************/
		virtual void SetDirectionalLight(LPDirectionalLight pl);
		/*************************************************************************//*!
				@brief			�ڂ����̃p�����[�^�̐ݒ�
				@param[in]		SampleStepX		�T���v�����O����s�N�Z���̉��Ԋu
				@param[in]		SampleStepY		�T���v�����O����s�N�Z���̏c�Ԋu
				@param[in]		TexWidth		�e�N�X�`���̃T�C�Y
				@param[in]		TexHeight		�e�N�X�`���̃T�C�Y

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY,MofS32 TexWidth,MofS32 TexHeight);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[�����擾����
				@param			None

				@return			�p�����[�^�[�̐�
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

	};

	typedef CShaderBind_GaussianBlurBase* LPShaderBind_GaussianBlurBase;

	#include	"ShaderBind_GaussianBlurBase.inl"
}

#endif

//[EOF]