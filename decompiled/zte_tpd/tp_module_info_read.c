__int64 __fastcall tp_module_info_read(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v7; // x22
  void (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x24
  int v13; // w0
  int v14; // w3
  unsigned __int64 v15; // x23
  int v16; // w3
  int v17; // w0
  int v18; // w3
  unsigned __int64 v19; // x23
  int v20; // w3
  _QWORD v21[26]; // [xsp+0h] [xbp-D0h] BYREF

  v21[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*a4 )
  {
    v7 = tpd_cdev;
    v9 = *(void (__fastcall **)(_QWORD))(tpd_cdev + 3176);
    memset(v21, 0, 200);
    if ( v9 )
    {
      v10 = tpd_cdev;
      if ( *((_DWORD *)v9 - 1) != 1945898361 )
        __break(0x8228u);
      v9(v10);
    }
    v11 = snprintf((char *)v21, 0xC8u, "TP module: %s(0x%x)\n", (const char *)(v7 + 2952), *(_DWORD *)(v7 + 2884));
    if ( v11 <= 0xC8 )
    {
      v12 = v11;
      v13 = snprintf((char *)v21 + v11, 200LL - v11, "IC type : %s\n", (const char *)(v7 + 2912));
      v14 = *(_DWORD *)(v7 + 2900);
      v15 = v12 + v13;
      if ( v14 )
      {
        if ( v15 > 0xC8 )
          goto LABEL_29;
        v15 += snprintf((char *)v21 + v15, 200 - v15, "I2C address: 0x%x\n", v14);
      }
      v16 = *(_DWORD *)(v7 + 2908);
      if ( v16 )
      {
        if ( v15 > 0xC8 )
          goto LABEL_29;
        v15 += snprintf((char *)v21 + v15, 200 - v15, "Spi num: %d\n", v16);
      }
      if ( v15 <= 0xC8 )
      {
        v17 = snprintf((char *)v21 + v15, 200 - v15, "Firmware version : %d\n", *(_DWORD *)(v7 + 2888));
        v18 = *(_DWORD *)(v7 + 2892);
        v19 = v15 + v17;
        if ( v18 )
        {
          if ( v19 > 0xC8 )
            goto LABEL_29;
          v19 += snprintf((char *)v21 + v19, 200 - v19, "Config version:0x%x\n", v18);
        }
        v20 = *(_DWORD *)(v7 + 2896);
        if ( v20 )
        {
          if ( v19 > 0xC8 )
            goto LABEL_29;
          v19 += snprintf((char *)v21 + v19, 200 - v19, "Display version:0x%x\n", v20);
        }
        if ( *(_BYTE *)(v7 + 2992) )
        {
          if ( v19 > 0xC8 )
            goto LABEL_29;
          v19 += snprintf((char *)v21 + v19, 200 - v19, "Chip hard version:%s\n", (const char *)(v7 + 2992));
        }
        if ( !*(_BYTE *)(v7 + 3032) )
        {
LABEL_27:
          result = simple_read_from_buffer(a2, a3, a4, v21, v19);
          goto LABEL_28;
        }
        if ( v19 <= 0xC8 )
        {
          v19 += snprintf((char *)v21 + v19, 200 - v19, "fw update status:%s\n", (const char *)(v7 + 3032));
          goto LABEL_27;
        }
      }
    }
LABEL_29:
    __break(0x5512u);
  }
  result = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
