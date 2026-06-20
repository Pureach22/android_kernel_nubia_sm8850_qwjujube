__int64 __fastcall bcl_read_ibat(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 result; // x0
  unsigned int v6; // w19
  int v7; // w5
  char v8; // w8
  int v9; // w8
  __int64 v10; // x9
  int v11; // w10
  int v12; // w9
  int v13; // w8
  int v14; // w10
  unsigned int v15; // w4
  __int64 v16; // x8
  int v17; // w10
  int v18; // w8
  int v19; // w9
  unsigned int v20; // w10
  const char *v21; // x2
  unsigned int v22; // w19
  int v23; // w8
  int v24; // w9
  int v25; // w11
  int v26; // w8
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 1048);
  *a2 = 0;
  v27 = 0;
  v4 = *(_QWORD *)(v3 + 176);
  if ( *(unsigned __int8 *)(v4 + 18) > 4u )
  {
    if ( v4 )
    {
      result = regmap_bulk_read(*(_QWORD *)(v4 + 8), (unsigned int)*(unsigned __int16 *)(v4 + 16) + 134, &v27, 2);
      if ( (result & 0x80000000) != 0 )
      {
        v22 = result;
        printk(&unk_82EC, "bcl_pmic5", "bcl_read_multi_register");
        result = v22;
        goto LABEL_26;
      }
LABEL_7:
      if ( (_DWORD)result )
        goto LABEL_26;
      v7 = v27;
      if ( *(unsigned __int8 *)(*(_QWORD *)(v3 + 176) + 18LL) >= 5u )
        v8 = 16;
      else
        v8 = 24;
      v9 = v27 << v8 >> v8;
      *a2 = v9;
      if ( !v7 )
      {
        v15 = *(_DWORD *)(v3 + 16);
        *a2 = v15;
        v16 = *(_QWORD *)(v3 + 176);
        if ( !v16 )
          goto LABEL_25;
LABEL_23:
        result = *(_QWORD *)(v16 + 24);
        if ( !result )
          goto LABEL_26;
        ipc_log_string(
          result,
          "[%s]: %s: ibat:%d mA ADC:0x%02x\n",
          (const char *)(_ReadStatusReg(SP_EL0) + 2320),
          "bcl_read_ibat",
          v15,
          v7);
LABEL_25:
        result = 0;
        goto LABEL_26;
      }
      v10 = *(_QWORD *)(v3 + 176);
      if ( *(_BYTE *)(v10 + 36) == 1 )
      {
        v11 = *(_DWORD *)(v10 + 40);
        v12 = *(unsigned __int8 *)(v10 + 38);
        v13 = v9 * v11;
        v14 = 15625;
      }
      else
      {
        if ( *(_BYTE *)(v10 + 37) != 1 )
        {
          v20 = *(unsigned __int8 *)(v10 + 18);
          if ( v20 < 5 )
          {
            v23 = v9 * *(_DWORD *)(v10 + 40);
            if ( *(_BYTE *)(v10 + 38) )
              v24 = 2000;
            else
              v24 = 10000;
            v25 = 78127 * v23 / v24;
            v26 = 93753 * v23 / v24;
            if ( v20 == 4 )
              v15 = v26;
            else
              v15 = v25;
          }
          else
          {
            v15 = 61037 * v9 / 0xF4240u;
          }
LABEL_22:
          *a2 = v15;
          *(_DWORD *)(v3 + 16) = v15;
          v16 = *(_QWORD *)(v3 + 176);
          if ( !v16 )
            goto LABEL_25;
          goto LABEL_23;
        }
        v17 = *(_DWORD *)(v10 + 40);
        v12 = *(unsigned __int8 *)(v10 + 38);
        v13 = v9 * v17;
        v14 = 152;
      }
      v18 = v13 * v14;
      if ( v12 )
        v19 = 2000;
      else
        v19 = 10000;
      v15 = v18 / v19;
      goto LABEL_22;
    }
    v21 = "bcl_read_multi_register";
LABEL_31:
    printk(&unk_8411, "bcl_pmic5", v21);
    result = 4294967274LL;
    goto LABEL_26;
  }
  if ( !v4 )
  {
    v21 = "bcl_read_register";
    goto LABEL_31;
  }
  result = regmap_read(*(_QWORD *)(v4 + 8), (unsigned int)*(unsigned __int16 *)(v4 + 16) + 134, &v27);
  if ( (result & 0x80000000) == 0 )
    goto LABEL_7;
  v6 = result;
  printk(&unk_8594, "bcl_pmic5", "bcl_read_register");
  result = v6;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
