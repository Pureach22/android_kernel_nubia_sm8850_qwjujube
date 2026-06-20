__int64 __fastcall bcl_read_vbat_tz(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 result; // x0
  unsigned int v6; // w19
  unsigned int v7; // w5
  unsigned int v8; // w8
  unsigned int v9; // w4
  __int64 v10; // x8
  const char *v11; // x2
  unsigned int v12; // w19
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 1048);
  *a2 = 0;
  v13 = 0;
  v4 = *(_QWORD *)(v3 + 176);
  if ( *(unsigned __int8 *)(v4 + 18) > 4u )
  {
    if ( v4 )
    {
      result = regmap_bulk_read(*(_QWORD *)(v4 + 8), (unsigned int)*(unsigned __int16 *)(v4 + 16) + 118, &v13, 2);
      if ( (result & 0x80000000) != 0 )
      {
        v12 = result;
        printk(&unk_82EC, "bcl_pmic5", "bcl_read_multi_register");
        result = v12;
        goto LABEL_20;
      }
LABEL_7:
      if ( (_DWORD)result )
        goto LABEL_20;
      v7 = v13;
      *a2 = v13;
      v8 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 176) + 18LL);
      if ( v8 <= 4 && v7 == 127 )
      {
LABEL_10:
        v9 = *(_DWORD *)(v3 + 16);
        *a2 = v9;
        v10 = *(_QWORD *)(v3 + 176);
        if ( !v10 )
          goto LABEL_19;
LABEL_17:
        result = *(_QWORD *)(v10 + 24);
        if ( !result )
          goto LABEL_20;
        ipc_log_string(
          result,
          "[%s]: %s: vbat:%d mv ADC:0x%02x\n",
          (const char *)(_ReadStatusReg(SP_EL0) + 2320),
          "bcl_read_vbat_tz",
          v9,
          v7);
LABEL_19:
        result = 0;
        goto LABEL_20;
      }
      if ( v8 < 5 )
      {
        v9 = (int)(49827 * v7) / 1000;
      }
      else
      {
        if ( v7 == 0x7FFF )
          goto LABEL_10;
        v9 = 194637 * v7 / 0xF4240;
      }
      *a2 = v9;
      *(_DWORD *)(v3 + 16) = v9;
      v10 = *(_QWORD *)(v3 + 176);
      if ( !v10 )
        goto LABEL_19;
      goto LABEL_17;
    }
    v11 = "bcl_read_multi_register";
LABEL_23:
    printk(&unk_8411, "bcl_pmic5", v11);
    result = 4294967274LL;
    goto LABEL_20;
  }
  if ( !v4 )
  {
    v11 = "bcl_read_register";
    goto LABEL_23;
  }
  result = regmap_read(*(_QWORD *)(v4 + 8), (unsigned int)*(unsigned __int16 *)(v4 + 16) + 118, &v13);
  if ( (result & 0x80000000) == 0 )
    goto LABEL_7;
  v6 = result;
  printk(&unk_8594, "bcl_pmic5", "bcl_read_register");
  result = v6;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
