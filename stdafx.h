// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <afxwin.h>

#include <WinCrypt.h>
#pragma comment(lib, "Crypt32.lib")
/*ssl*/
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include <openssl/pkcs7.h>
#include <openssl/err.h>
#include <openssl/rc4.h>
#include <openssl/sm2.h>
#pragma comment(lib, "libcrypto.lib")
/*ssl*/

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
