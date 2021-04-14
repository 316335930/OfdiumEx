/**************************************************
* File name: base64.h
* Author: HAN Wei
* Author's blog: http://blog.csdn.net/henter/
* Date: Oct 31th, 2013
* Description: declare base64 encode and decode functions
			   When encoding is needed, EncodeBase64() function is invoked.
			   The user can decide the count of characters in a full line (the max
			   count is set to 76 in RFC 2045).
			   The user can decide to insert 0x0A (line feed) or 0x0D (carriage return)
			   0x0A into the end of each full line, and can also choose insert nothing.
			   When decoding is needed, DecodeBase64() function is invoked. 0x0A or
			   0x0D 0x0A in base64 codes will be ignored.
* Note: EncodeBase64() and DecodeBase64() are derived from EVP_EncodeBlock() and
		EVP_DecodeBlock() in encode.c of OpenSSL 1.0.1c.
  OpenSSL web site: http://www.openssl.org/
**************************************************/

#ifndef BASE64_ENCODE_AND_DECODE_H
#define BASE64_ENCODE_AND_DECODE_H

#ifdef  __cplusplus
extern "C" {
#endif

	/**************************************************
	*�������ƣ�CalcBase64EncodeBufLen
	*����:  ��ʹ��Base64���뺯��EncodeBase64()֮ǰ���ú�������Ϊ����������Ԥ�����
			��ű������Ļ�������С
	*����:
	raw_data_len[in]    �ȴ������ԭʼ���ݳ��ȣ����ֽ�Ϊ��λ
	line_feed_flag[in]  Ϊ0��ʾ����ʱ�����뻻�з���
						Ϊ1��ʾ����ʱ�ڻ��д�����Unix��Linux�µĻ���0x0A
						Ϊ2��ʾ����ʱ�ڻ��д�����Windows�µĻ���0x0D,0x0A
	characters_count_per_base64_codes_line[in]  һ���������ɵ�base64�����ַ��������ޣ�
												line_feed_flagֵΪ0ʱ�ò��������ԣ�
												����Ϊ����ֵ����Ϊ��ʱbase64���벻���С�
												line_feed_flagֵΪ1��2ʱ���ò����������塣
												����RFC 2045�Ĺ涨����ֵ��������Ϊ76��
												Ҫ�õ���OpenSSL�����ε���EVP_EncodeInit(),
												EVP_EncodeUpdate(),EVP_EncodeFinal()������
												���ɵı�������ͬ�ı���ʱ������ֵ��Ϊ64��
												��ΪEVP_EncodeUpdate()�н�һ�������ɵ�
												base64�����ַ�����������Ϊ64
	*����ֵ: ������base64�������Ļ�������С�����ֽ�Ϊ��λ��������ֵΪ -1 ʱ��ʾ����
	**************************************************/
	unsigned int CalcBase64EncodeBufLen(unsigned int raw_data_len,
		int line_feed_flag,
		unsigned int characters_count_per_base64_codes_line);

	/**************************************************
	*�������ƣ�CalcBase64DecodeBufLen
	*����:     ��ʹ��Base64���뺯��DecodeBase64()֮ǰ���ú�������Ϊ����������Ԥ�����
			   ��Ž������Ļ�������С
	*����:
	base64_codes[in]      ָ��������base64�ַ����׵�ַ��ָ��
	base64_codes_Len[in]  �ȴ������base64�ַ������ȣ����ֽ�Ϊ��λ����base64�ַ�����'\0'��βʱ�������������ʾ���ַ������Ȳ�����'\0'��ռ��1���ֽڣ���Ϊbase64�ַ�����������������лس����У���ͳ��base64�ַ�����ʱҪ�ѻس�������Ҳ���룩
	*����ֵ: ���base64�������Ļ�������С�����ֽ�Ϊ��λ
	**************************************************/
	unsigned int CalcBase64DecodeBufLen(unsigned char* base64_codes,
		unsigned int base64_codes_Len);

	/**************************************************
	*�������ƣ�EncodeBase64
	*����:  base64���뺯��
	*����:
	t[out]  ָ������������׵�ַ��ָ��
	f[in]   ָ�����뻺�����׵�ַ��ָ��
	n[in]   ��������ַ������ȣ�������ַ�����'\0'��β��ͳ�Ƹó���ʱ������'\0'
	line_feed_flag[in]  �Ƿ���뻻�еı�־��Ϊ0��ʾ����ʱ�����뻻�У�
						Ϊ1��ʾ��һ�б����ַ�ĩβ����Unix��Linux�µĻ���0x0A��
						Ϊ2��ʾ��һ�б����ַ�ĩβ����Windows�µĻ���0x0D 0x0A
	characters_count_per_base64_codes_line[in]  һ���������ɵ�base64�����ַ��������ޣ�
												line_feed_flagֵΪ0ʱ�ò�������Ϊ����ֵ��
												��Ϊ��ʱbase64���벻���С�
												line_feed_flagֵΪ1��2ʱ���ò����������壬
												����RFC 2045�Ĺ涨����ֵ��������Ϊ76��
												Ҫ�õ���OpenSSL�����ε���EVP_EncodeInit(),EVP_EncodeUpdate(),EVP_EncodeFinal()
	 ���ɵı�������ͬ�ı���ʱ��Ӧ����ֵ��Ϊ64
	*����ֵ: base64�������ַ������ȣ����ֽ�Ϊ��λ����������ֵΪ -1 ʱ��ʾ����
			����ڱ�������в����˻��У���ô��س�0x0D, ����0x0A�����ķ��ŵĸ���Ҳ���볤�ȣ�
			�ú������ڱ������ַ���ĩβ����һ��'\0'�����ڼ��㷵��ֵʱ����ͳ�Ʊ����ַ���
			����ʱ������'\0'
	**************************************************/
	int EncodeBase64(unsigned char* t,
		unsigned char* f,
		int n,
		int line_feed_flag,
		unsigned int characters_count_per_base64_codes_line);

	/**************************************************
	*�������ƣ�DecodeBase64
	*����:  base64���뺯��
	*����:
	t  ָ������������׵�ַ��ָ��
	f  ָ�����뻺�����׵�ַ��ָ��
	n  �������base64�ַ������ȣ�ͳ�Ƹó���ʱ����ַ�����'\0'��β��������'\0'������
	   �س�0x0D, ����0x0A���ŵĸ���ҲҪ���볤�ȣ����ǲ���Ӱ�����
	ע�⣺
	  ���ڱ���ʱ��һ��ĩβ����Ļ��п��������֣�Windows�µĻ��з�0x0D 0x0A����Unix
	  ����Linux���µĻ��з�0x0A�������ֻ��иú���������ȷ���룬��Ϊ�ú����������Щ����
	*����ֵ: ���base64�������ַ������ȣ���δ������ַ������ȡ�
			 �������ʱ���й���䣬�����ַ������������룬�û��������ֶ�ȥ������ַ�����
	**************************************************/
	int DecodeBase64(unsigned char* t, unsigned char* f, int n);

#ifdef  __cplusplus
}
#endif

#endif /* end of BASE64_ENCODE_AND_DECODE_H */
