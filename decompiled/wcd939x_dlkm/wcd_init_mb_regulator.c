unsigned __int64 __fastcall wcd_init_mb_regulator(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned __int64 v4; // x0
  unsigned int v5; // w21
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x8
  __int64 v10; // x0
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x8
  __int64 v13; // x0
  unsigned __int64 result; // x0
  unsigned __int64 v15; // x8
  char v16; // cc
  unsigned int v17; // w20
  _QWORD v18[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18[1] = 0;
  v2 = devm_kmalloc(a1, 48, 3520);
  if ( v2 )
  {
    v3 = v2;
    *(_QWORD *)v2 = a1;
    v19 = v2;
    *(_BYTE *)(v2 + 40) = 0;
    v18[0] = a1;
    v4 = devm_regulator_register(a1, &wcd_reg_mb_rdesc, v18);
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
      v5 = 0;
    else
      v5 = v4;
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
      v6 = v4;
    else
      v6 = 0;
    *(_QWORD *)(v3 + 8) = v6;
    if ( v5 != -517 && v5 )
      dev_err(a1, "register wcd-reg-mb%d regulator failed, rc=%d\n", 1, v5);
    v7 = *(_QWORD *)v3;
    *(_BYTE *)(v3 + 41) = 0;
    v8 = devm_regulator_register(v7, &off_3A30, v18);
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
    {
      v9 = v8;
    }
    else
    {
      v5 = v8;
      v9 = 0;
    }
    *(_QWORD *)(v3 + 16) = v9;
    if ( v5 != -517 && v5 )
      dev_err(a1, "register wcd-reg-mb%d regulator failed, rc=%d\n", 2, v5);
    v10 = *(_QWORD *)v3;
    *(_BYTE *)(v3 + 42) = 0;
    v11 = devm_regulator_register(v10, &off_3B70, v18);
    if ( v11 <= 0xFFFFFFFFFFFFF000LL )
    {
      v12 = v11;
    }
    else
    {
      v5 = v11;
      v12 = 0;
    }
    *(_QWORD *)(v3 + 24) = v12;
    if ( v5 != -517 && v5 )
      dev_err(a1, "register wcd-reg-mb%d regulator failed, rc=%d\n", 3, v5);
    v13 = *(_QWORD *)v3;
    *(_BYTE *)(v3 + 43) = 0;
    result = devm_regulator_register(v13, &off_3CB0, v18);
    v15 = result;
    v16 = (result != -4096) & __CFADD__(result, 4096);
    if ( result <= 0xFFFFFFFFFFFFF000LL )
      result = v5;
    else
      result = (unsigned int)result;
    if ( v16 )
      v15 = 0;
    *(_QWORD *)(v3 + 32) = v15;
    if ( (_DWORD)result != -517 && (_DWORD)result )
    {
      v17 = result;
      dev_err(a1, "register wcd-reg-mb%d regulator failed, rc=%d\n", 4, result);
      result = v17;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
