__int64 __fastcall qmi_ts_request(__int64 a1, char a2)
{
  __int64 v4; // x20
  size_t v5; // x0
  unsigned __int64 v6; // x2
  char v7; // w8
  int v8; // w11
  __int64 result; // x0
  unsigned int v10; // w19
  int v11; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD v12[4]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v13; // [xsp+30h] [xbp-20h]
  __int64 v14; // [xsp+38h] [xbp-18h]
  __int64 v15; // [xsp+40h] [xbp-10h]
  __int64 v16; // [xsp+48h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  memset(v12, 0, sizeof(v12));
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v11 = 0;
  v5 = strnlen((const char *)(a1 + 8), 0x20u);
  if ( v5 >= 0x28 )
  {
    _fortify_panic(2, 40);
    goto LABEL_13;
  }
  if ( v5 == 32 )
    v6 = 32;
  else
    v6 = v5 + 1;
  if ( v6 >= 0x22 )
LABEL_13:
    _fortify_panic(7, 33);
  sized_strscpy(v12, a1 + 8);
  HIDWORD(v15) = 0;
  if ( (a2 & 1) != 0 )
  {
    v7 = 1;
    BYTE1(v13) = 1;
  }
  else
  {
    v8 = *(_DWORD *)(a1 + 88);
    v7 = 0;
    HIDWORD(v13) = *(_DWORD *)(a1 + 84);
    HIDWORD(v14) = v8;
    BYTE2(v13) = HIDWORD(v13) != 0x7FFFFFFF;
    LOBYTE(v14) = v8 != -2147483647;
  }
  LOBYTE(v15) = v7;
  result = qmi_ts_send_request(
             v4,
             0x32u,
             61,
             (__int64)&ts_register_notification_temp_req_msg_v02_ei,
             (__int64)&ts_register_notification_temp_resp_msg_v02_ei,
             (__int64)v12,
             (__int64)&v11,
             &v11);
  if ( (result & 0x80000000) != 0 )
  {
    v10 = result;
    printk(&unk_85DF, "qti_qmi_sensor_v2", "qmi_ts_request");
    result = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
