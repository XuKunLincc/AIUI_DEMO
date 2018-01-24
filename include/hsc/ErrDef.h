#ifndef ERRDEF_H
#define ERRDEF_H

/**
    二次开发接口公用错误码（32位）构成：
    32位：
     8位-----预留
     8位-----模块识别ID
    16位-----细节错误码
 */


// 错误码制作宏
#define MAKE_ERR(prod, num)             ((((unsigned long)(prod))<<16)|(num))


/********************************* 模块识别ID定义 *********************************/

// 库级模块
#define PROD_LOG    (0x70 << 16)
#define PROD_COMM   (0x80 << 16)
#define PROD_HSC3   (0xA0 << 16)

// 普通模块
#define PROD_CLIENT (PROD_COMM | 0x1)
#define PROD_FTP    (PROD_COMM | 0x4)


/********************************* 错误码定义 *********************************/

#define KM_ERR_OK                       0x000000
#define KM_ERR_BAD                      0xFFFFFF

#define KM_ERR_TIME_OUT                 MAKE_ERR(PROD_CLIENT,   0x0001)
#define KM_ERR_FAIL_CONN                MAKE_ERR(PROD_CLIENT,   0x0011)
#define KM_ERR_BAD_IP                   MAKE_ERR(PROD_CLIENT,   0x0012)
#define KM_ERR_FAIL_SEND_MSG            MAKE_ERR(PROD_CLIENT,   0x0020)
#define KM_ERR_NET_NOT_READY            MAKE_ERR(PROD_CLIENT,   0x0030)
#define KM_ERR_FAIL_PROTOCOL            MAKE_ERR(PROD_CLIENT,   0x0101)


#define KM_ERR_FTP_APP_TIME_OUT         MAKE_ERR(PROD_FTP,   0x0001)
#define KM_ERR_FTP_APP_REPLY_TIME_OUT   MAKE_ERR(PROD_FTP,   0x0002)
#define KM_ERR_FTP_FILE_SERVE           MAKE_ERR(PROD_FTP,   0x0031)
#define KM_ERR_FTP_FILE_LOCAL           MAKE_ERR(PROD_FTP,   0x0032)
#define KM_ERR_FTP_APP_PARAM            MAKE_ERR(PROD_FTP,   0x0071)
#define KM_ERR_FTP_APP_CONN             MAKE_ERR(PROD_FTP,   0x0072)
#define KM_ERR_FTP_APP_SEND_ABORT       MAKE_ERR(PROD_FTP,   0x0073)
#define KM_ERR_FTP_APP_WRTE_ABORT       MAKE_ERR(PROD_FTP,   0x0074)
#define KM_ERR_FTP_APP_PASV             MAKE_ERR(PROD_FTP,   0x0075)
#define KM_ERR_FTP_APP_CHECK_DATA       MAKE_ERR(PROD_FTP,   0x0076)

#define KM_ERR_FTP_CMD_PASS             MAKE_ERR(PROD_FTP,   0x0061)
#define KM_ERR_FTP_CMD_USER             MAKE_ERR(PROD_FTP,   0x0062)
#define KM_ERR_FTP_CMD_PWD              MAKE_ERR(PROD_FTP,   0x0063)
#define KM_ERR_FTP_CMD_CWD              MAKE_ERR(PROD_FTP,   0x0064)
#define KM_ERR_FTP_CMD_TRANS            MAKE_ERR(PROD_FTP,   0x0065)
#define KM_ERR_FTP_CMD_FILE_SIZE        MAKE_ERR(PROD_FTP,   0x0066)
#define KM_ERR_FTP_CMD_DELE             MAKE_ERR(PROD_FTP,   0x0067)
#define KM_ERR_FTP_CMD_MKD              MAKE_ERR(PROD_FTP,   0x0068)

#define KM_ERR_FTP_SOCKET_ADDR          MAKE_ERR(PROD_FTP,   0x0050)
#define KM_ERR_FTP_SOCKET_INVALID       MAKE_ERR(PROD_FTP,   0x0051)
#define KM_ERR_FTP_SOCKET_CONN          MAKE_ERR(PROD_FTP,   0x0052)
#define KM_ERR_FTP_SOCKET_SEND          MAKE_ERR(PROD_FTP,   0x0053)
#define KM_ERR_FTP_SOCKET_RECV          MAKE_ERR(PROD_FTP,   0x0054)
#define KM_ERR_FTP_SOCKET_SET           MAKE_ERR(PROD_FTP,   0x0055)

#define KM_ERR_FTP_FAIL_CONNECT         MAKE_ERR(PROD_FTP,   0x0100)
#define KM_ERR_FTP_FAIL_LOGIN           MAKE_ERR(PROD_FTP,   0x0200)
#define KM_ERR_FTP_FAIL_GET             MAKE_ERR(PROD_FTP,   0x0300)
#define KM_ERR_FTP_FAIL_PUT             MAKE_ERR(PROD_FTP,   0x0400)
#define KM_ERR_FTP_FAIL_DEL             MAKE_ERR(PROD_FTP,   0x0500)
#define KM_ERR_FTP_FAIL_CH_FOLDER       MAKE_ERR(PROD_FTP,   0x0600)
#define KM_ERR_FTP_FAIL_FIND_FILE       MAKE_ERR(PROD_FTP,   0x0700)
#define KM_ERR_FTP_FAIL_MK_FOLDER       MAKE_ERR(PROD_FTP,   0x0800)
#define KM_ERR_FTP_FAIL_FILE_LIST       MAKE_ERR(PROD_FTP,   0x0900)


#define KM_ERR_INVALID_MESSAGE          MAKE_ERR(PROD_HSC3,   0x0008)
#define KM_ERR_NO_MESSAGE               MAKE_ERR(PROD_HSC3,   0x000C)


#endif // ERRDEF_H
