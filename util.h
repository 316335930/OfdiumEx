#include <string>
#include <vector>
#include <map>
#include <gdiplus.h>
#include "cairo.h"
#include "Definitions.h"

#include "jbig2dec/include/jbig2.h"
#include "jbig2dec/include/jbig2_image.h"

#pragma comment(lib,"jbig2dec.lib")

#define ALLOCATE(v,l,t) v = (t *)malloc((size_t)(sizeof(t)*(l)))
int doubleCmp(double a, double b);
void CreateDir(const char *dir);
std::string GenerateGUIDString();
time_t string2time(std::string strTime);
std::string time2string(time_t time, unsigned long usec);
std::string time2generalizedstring(time_t time);
void split(const std::string& s, char delimiter, std::vector<std::string> &out);
inline std::string UTF82GBK(const char *szUtf8);
#define MM2PIXEL72P(m) (double)(2.8346456692913387*(double)(m))
#define MM2PIXEL(m) (double)(11.811023622047246*(double)(m))

#define INTMM2PIXEL72P(m) (int)(2.8346456692913387*(double)(m))
#define INTMM2PIXEL(m) (int)(11.811023622047246*(double)(m))
struct st_png_data
{
	unsigned char* pdata;
	unsigned int length;
};

cairo_status_t cairo_read_func_mine(void *closure, unsigned char *data, unsigned int length);

cairo_status_t cairo_write_func_mine(void *closure, const unsigned char *data, unsigned int length);

inline std::string convertPathToAbsolute(std::string relativePath, std::string baseDir);

cairo_surface_t *cairo_image_surface_create_from_jpeg(const char *filename, std::map<cairo_surface_t *, std::pair<Gdiplus::Bitmap *, Gdiplus::BitmapData *>> *mapImage, ULONG_PTR *pGdiplusToken);

void cairo_image_surface_delete_from_jpeg(cairo_surface_t *surface, std::map<cairo_surface_t *, std::pair<Gdiplus::Bitmap *, Gdiplus::BitmapData *>> *mapImage, ULONG_PTR *pGdiplusToken);

cairo_surface_t *cairo_image_surface_create_from_jbig2(const char *filename, int *width, int *height, unsigned char **ptrRememberToFree);

void ct_matrix_to_cairo_matrix(CT_Matrix *ct_matrix, cairo_matrix_t *cairo_ctm);

void fnReadCharactersUTF8(const char* pszSentence, std::vector<std::string>& vec);

void cairo_quadratic_to(cairo_t *cr, double x1, double y1, double x2, double y2);

inline int jbig2_image_get_pixel(Jbig2Image *image, int x, int y);

inline void ReverseBit(unsigned char* pValue);

void print_errors();

#define M_PI       3.14159265358979323846

//SESeal:: = SEQUENCE{
//	esealInfo SES_SealInfo, --ӡ����Ϣ
//	signInfo SES_SignInfo -- �����˶�ӡǩ������Ϣ
//}
//SES_SealInfo:: = SEQUENCE{
//	header SES_Header, --ͷ��Ϣ
//	esID IA5String, --����ӡ�±�ʶ�����ݵ�Ψһ����
//	property SES_ESPropertyInfo, --ӡ��������Ϣ
//	picture SES_ESPictrueInfo, --����ӡ��ͼƬ����
//	extDatas EXPLICIT ExtensionDatas OPTIONAL -- �Զ�������
//	���ҹ�����Դ���׷���ƽ̨һ�ڹ��̵���ӡ�»���ϵͳ��������뼯����Ŀ����ӡ�³��̶Խ�ָ��
//	30
//}
//���У�
//esID �����ֵ���ӡ�����ݵ�Ψһ��ʶ���룬���ڲ��Һ�����������Ϣ��
//extDatas �����ڳ���ʹ�Զ������ݡ�
//ExtensionDatas ���� = SEQUENCE SIZE ��0..MAX ��OF ExtData
//ExtData ���� = SEQUENCE{
//		extnID OBJECT IDENTIFIER, --�Զ�����չ�ֶα�ʶ
//		critical BOOLEAN DEFAULT FALSE, --�Զ�����չ�ֶ��Ƿ�ؼ�
//		extnValue OCTET STRING -- �Զ�����չ�ֶ�����ֵ
//	}
//	��3�� ӡ��ͷ��Ϣ
//	ͷ��Ϣ�� ASN.1 ����Ϊ��
//	SES_Header ���� = SEQUENCE{
//			ID IA5String, --����ӡ�����ݱ�ʶ
//			version INTEGER, --����ӡ�����ݰ汾�ű�ʶ
//			Vid IA5String -- ����ӡ�³��� ID }
//SES_ESPropertyInfo ���� = SEQUENCE{
//	type INTEGER, --ӡ������
//	name UTF8String �� -- ӡ������
//	certList SEQUENCE OF cert �� -- ǩ����֤���б�
//	createDate UTCTIME, --ӡ����������
//	validStart UTCTIME, --ӡ����Ч��ʼ����
//	validEnd UTCTIME -- ӡ����Ч��ֹ����
//}
//SES_ESPictrueInfo ���� = SEOUENCE{
//	type IA5String �� -- ͼƬ����
//	���ҹ�����Դ���׷���ƽ̨һ�ڹ��̵���ӡ�»���ϵͳ��������뼯����Ŀ����ӡ�³��̶Խ�ָ��
//	32
//	data OCTET STRING, --ͼƬ����
//	width INTEGER, --ͼƬ��ʾ���
//	height INTEGER -- ͼƬ��ʾ�߶�
//}
//SES_SignInfo ���� = SEQUENCE{
//	cert OCTET STRING, --������ǩ��֤��
//	signatureAlorithm OBJECT IDENTIFIER, --ǩ���㷨��ʶ
//	signData BIT STRING -- �����˵�ǩ��ֵ
//}

typedef struct cert_digest_obj_st
{
	ASN1_PRINTABLESTRING *type;
	ASN1_OCTET_STRING *value;
}CertDigestObj;
DECLARE_ASN1_FUNCTIONS(CertDigestObj)

typedef struct ses_certlist_st {
	//# define GEN_CERTINFOLIST			0
	//# define GEN_CERTDIGESTLIST			1
	//int type;
	//	union {
	//char *ptr;
	STACK_OF(ASN1_OCTET_STRING) *certs;
	//		STACK_OF(CertDigestObj) *certDigestList;
	//	}d;
} SES_CertList;
DEFINE_STACK_OF(ASN1_OCTET_STRING)
DECLARE_ASN1_FUNCTIONS(SES_CertList)

typedef struct ses_espropertyinfo_st {
	ASN1_INTEGER *type;
	ASN1_UTF8STRING *name;
	STACK_OF(ASN1_OCTET_STRING) *certList;
	ASN1_UTCTIME *createDate;
	ASN1_UTCTIME *validStart;
	ASN1_UTCTIME *validEnd;
} SES_ESPropertyInfo;
DECLARE_ASN1_FUNCTIONS(SES_ESPropertyInfo)

typedef struct v4_ses_espropertyinfo_st {
	ASN1_INTEGER *type;
	ASN1_UTF8STRING *name;
	ASN1_INTEGER *certListType;
	SES_CertList *certList;
	ASN1_GENERALIZEDTIME *createDate;
	ASN1_GENERALIZEDTIME *validStart;
	ASN1_GENERALIZEDTIME *validEnd;
} V4_SES_ESPropertyInfo;
DECLARE_ASN1_FUNCTIONS(V4_SES_ESPropertyInfo)

typedef struct ses_espictrueinfo_st {
	ASN1_IA5STRING *type;
	ASN1_OCTET_STRING *data;
	ASN1_INTEGER *width;
	ASN1_INTEGER *height;
} SES_ESPictrueInfo;
DECLARE_ASN1_FUNCTIONS(SES_ESPictrueInfo)

typedef struct v4_ses_espictrueinfo_st {
	ASN1_IA5STRING *type;
	ASN1_OCTET_STRING *data;
	ASN1_INTEGER *width;
	ASN1_INTEGER *height;
} V4_SES_ESPictrueInfo;
DECLARE_ASN1_FUNCTIONS(V4_SES_ESPictrueInfo)

typedef struct ses_header_st {
	ASN1_IA5STRING *ID;
	ASN1_INTEGER *version;
	ASN1_IA5STRING *Vid;
} SES_Header;
DECLARE_ASN1_FUNCTIONS(SES_Header)

typedef struct v4_ses_header_st {
	ASN1_IA5STRING *ID;
	ASN1_INTEGER *version;
	ASN1_IA5STRING *Vid;
} V4_SES_Header;
DECLARE_ASN1_FUNCTIONS(V4_SES_Header)

typedef struct extdata_st {
	ASN1_OBJECT *extnID;
	ASN1_BOOLEAN *critical;
	ASN1_OCTET_STRING *extnValue;
} ExtData;
DECLARE_ASN1_FUNCTIONS(ExtData)

typedef struct v4_extdata_st {
	ASN1_OBJECT *extnID;
	ASN1_BOOLEAN *critical;
	ASN1_OCTET_STRING *extnValue;
} V4ExtData;
DECLARE_ASN1_FUNCTIONS(V4ExtData)

typedef struct ses_sealinfo_st {
	SES_Header *header;
	ASN1_IA5STRING *esID;
	SES_ESPropertyInfo *property;
	SES_ESPictrueInfo *picture;
	STACK_OF(ExtData) *extDatas;
} SES_SealInfo;
DECLARE_ASN1_FUNCTIONS(SES_SealInfo)

typedef struct v4_ses_sealinfo_st {
	V4_SES_Header *header;
	ASN1_IA5STRING *esID;
	V4_SES_ESPropertyInfo *property;
	V4_SES_ESPictrueInfo *picture;
	STACK_OF(V4ExtData) *extDatas;
} V4_SES_SealInfo;
DECLARE_ASN1_FUNCTIONS(V4_SES_SealInfo)

typedef struct ses_signinfo_st
{
	ASN1_OCTET_STRING *cert;
	ASN1_OBJECT *signatureAlorithm;
	ASN1_BIT_STRING *signData;
} SES_SignInfo;
DECLARE_ASN1_FUNCTIONS(SES_SignInfo)

typedef struct seseal_st
{
	SES_SealInfo *esealInfo;
	SES_SignInfo *signInfo;
} SESeal;
DECLARE_ASN1_FUNCTIONS(SESeal)

typedef struct v4_seseal_st
{
	V4_SES_SealInfo *esealInfo;
	ASN1_OCTET_STRING *cert;
	ASN1_OBJECT *signAlgID;
	ASN1_BIT_STRING *signedValue;
} V4SESeal;
DECLARE_ASN1_FUNCTIONS(V4SESeal)

typedef struct tbssign_st
{
	ASN1_INTEGER *version;
	SESeal *eseal;
	ASN1_BIT_STRING *timeinfo;
	ASN1_BIT_STRING *dataHash;
	ASN1_IA5STRING *propertyInfo;
	ASN1_OCTET_STRING *cert;
	ASN1_OBJECT *signatureAlgorithm;
}TBS_Sign;
DECLARE_ASN1_FUNCTIONS(TBS_Sign)

typedef struct v4_tbssign_st
{
	ASN1_INTEGER *version;
	V4SESeal *eseal;
	ASN1_GENERALIZEDTIME *timeinfo;
	ASN1_BIT_STRING *dataHash;
	ASN1_IA5STRING *propertyInfo;
	STACK_OF(V4ExtData) *extDatas;
} V4_TBS_Sign;
DECLARE_ASN1_FUNCTIONS(V4_TBS_Sign)

typedef struct sessignature_st
{
	TBS_Sign *toSign;
	ASN1_BIT_STRING *signature;
} SES_Signature;
DECLARE_ASN1_FUNCTIONS(SES_Signature)

typedef struct v4_sessignature_st
{
	V4_TBS_Sign *toSign;
	ASN1_OCTET_STRING *cert;
	ASN1_OBJECT *signatureAlgID;
	ASN1_BIT_STRING *signature;
	ASN1_BIT_STRING *timeStamp;
} V4_SES_Signature;
DECLARE_ASN1_FUNCTIONS(V4_SES_Signature)