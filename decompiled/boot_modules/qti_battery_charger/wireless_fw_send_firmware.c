__int64 __fastcall wireless_fw_send_firmware(__int64 a1, unsigned __int64 *a2)
{
  const char *v4; // x0
  char *v5; // x0
  unsigned __int64 v6; // x23
  char v7; // w8
  unsigned __int64 v8; // x25
  size_t v9; // x21
  char *v10; // x22
  int v11; // w24
  __int64 v12; // x2
  int v13; // w27
  __int64 v14; // x0
  __int64 result; // x0
  size_t v16; // x23
  int v17; // w20
  __int64 v18; // x0
  __int64 v19; // [xsp+8h] [xbp-118h] BYREF
  int v20; // [xsp+10h] [xbp-110h]
  _QWORD v21[32]; // [xsp+14h] [xbp-10Ch] BYREF
  int v22; // [xsp+114h] [xbp-Ch]
  __int64 v23; // [xsp+118h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(const char **)(a1 + 536);
  memset(v21, 0, sizeof(v21));
  v5 = strstr(v4, "cps");
  v6 = *a2;
  v7 = 7;
  if ( v5 )
    v7 = 8;
  v8 = v6 >> v7;
  if ( v5 )
    v9 = 256;
  else
    v9 = 128;
  if ( (_DWORD)v8 )
  {
    v10 = (char *)a2[1];
    v11 = 0;
    v19 = 0x10000800ALL;
    v20 = 65;
    do
    {
      v22 = ++v11;
      memcpy(v21, v10, v9);
      down_read(a1 + 192);
      v13 = *(_DWORD *)(a1 + 556);
      up_read(a1 + 192);
      if ( !v13 )
        goto LABEL_20;
      v14 = *(_QWORD *)(a1 + 136);
      *(_DWORD *)(a1 + 288) = 0;
      result = pmic_glink_write(v14, &v19, 272);
      if ( (_DWORD)result )
      {
        if ( (result & 0x80000000) != 0 )
          goto LABEL_23;
      }
      else if ( !(unsigned int)wait_for_completion_timeout(a1 + 288, 125) )
      {
        goto LABEL_24;
      }
      v10 += v9;
    }
    while ( (_DWORD)v8 != v11 );
    v16 = (unsigned int)v6 & ((_DWORD)v9 - 1);
    if ( (_DWORD)v16 )
    {
      v22 = v11 + 1;
      memset(v21, 0, v9);
      memcpy(v21, v10, v16);
      down_read(a1 + 192);
      v17 = *(_DWORD *)(a1 + 556);
      up_read(a1 + 192);
      if ( !v17 )
      {
LABEL_20:
        result = 4294967189LL;
        goto LABEL_23;
      }
      v18 = *(_QWORD *)(a1 + 136);
      *(_DWORD *)(a1 + 288) = 0;
      result = pmic_glink_write(v18, &v19, 272);
      if ( (_DWORD)result )
      {
        if ( (result & 0x80000000) != 0 )
          goto LABEL_23;
      }
      else if ( !(unsigned int)wait_for_completion_timeout(a1 + 288, 125) )
      {
LABEL_24:
        printk(&unk_FDF2, "battery_chg_fw_write", v12);
        result = 4294967186LL;
        goto LABEL_23;
      }
    }
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
