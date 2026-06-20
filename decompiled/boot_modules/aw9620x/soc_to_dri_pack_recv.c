__int64 __fastcall soc_to_dri_pack_recv(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v9; // x8
  __int16 v10; // w9
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x8
  __int16 v14; // w9
  __int64 v15; // x0
  int v16; // w0
  __int64 v17; // x8
  __int16 v18; // w9
  __int64 v19; // x0
  int v20; // w0
  __int64 v21; // x8
  __int16 v22; // w9
  __int64 v23; // x0
  int v24; // w0
  __int64 v25; // x8
  __int16 v26; // w9
  __int64 v27; // x0
  int v28; // w0
  __int64 v29; // x8
  __int16 v30; // w9
  __int64 v31; // x0
  int v32; // w0
  int v33; // w20
  __int64 v34; // [xsp+8h] [xbp-28h] BYREF
  __int64 v35; // [xsp+10h] [xbp-20h]
  __int64 v36; // [xsp+18h] [xbp-18h]
  __int64 v37; // [xsp+20h] [xbp-10h]
  __int64 v38; // [xsp+28h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "soc_to_dri_pack_recv", 1714);
  result = 0xFFFFFFFFLL;
  if ( a2 && a3 )
  {
    v9 = *(_QWORD *)(a1 + 40);
    v35 = 0;
    v36 = 0;
    v34 = 0;
    v10 = *(_WORD *)(v9 + 2);
    v37 = a2;
    v11 = *(_QWORD *)(v9 + 24);
    WORD2(v34) = 2;
    LOWORD(v34) = v10;
    v35 = a4;
    LOWORD(v36) = v10;
    WORD1(v36) = 1;
    WORD2(v36) = a3;
    v12 = i2c_transfer(v11, &v34, 2);
    if ( (v12 & 0x80000000) == 0 )
      goto LABEL_4;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] aw9620x i2c read cmd err cnt = %d ret = %d\n",
      "soc_to_dri_pack_recv",
      1723,
      5,
      v12);
    v13 = *(_QWORD *)(a1 + 40);
    v35 = 0;
    v36 = 0;
    v34 = 0;
    v14 = *(_WORD *)(v13 + 2);
    v37 = a2;
    v15 = *(_QWORD *)(v13 + 24);
    WORD2(v34) = 2;
    LOWORD(v34) = v14;
    v35 = a4;
    LOWORD(v36) = v14;
    WORD1(v36) = 1;
    WORD2(v36) = a3;
    v16 = i2c_transfer(v15, &v34, 2);
    if ( (v16 & 0x80000000) == 0 )
      goto LABEL_4;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] aw9620x i2c read cmd err cnt = %d ret = %d\n",
      "soc_to_dri_pack_recv",
      1723,
      4,
      v16);
    v17 = *(_QWORD *)(a1 + 40);
    v35 = 0;
    v36 = 0;
    v34 = 0;
    v18 = *(_WORD *)(v17 + 2);
    v37 = a2;
    v19 = *(_QWORD *)(v17 + 24);
    WORD2(v34) = 2;
    LOWORD(v34) = v18;
    v35 = a4;
    LOWORD(v36) = v18;
    WORD1(v36) = 1;
    WORD2(v36) = a3;
    v20 = i2c_transfer(v19, &v34, 2);
    if ( (v20 & 0x80000000) == 0 )
      goto LABEL_4;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] aw9620x i2c read cmd err cnt = %d ret = %d\n",
      "soc_to_dri_pack_recv",
      1723,
      3,
      v20);
    v21 = *(_QWORD *)(a1 + 40);
    v35 = 0;
    v36 = 0;
    v34 = 0;
    v22 = *(_WORD *)(v21 + 2);
    v37 = a2;
    v23 = *(_QWORD *)(v21 + 24);
    WORD2(v34) = 2;
    LOWORD(v34) = v22;
    v35 = a4;
    LOWORD(v36) = v22;
    WORD1(v36) = 1;
    WORD2(v36) = a3;
    v24 = i2c_transfer(v23, &v34, 2);
    if ( (v24 & 0x80000000) == 0 )
      goto LABEL_4;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] aw9620x i2c read cmd err cnt = %d ret = %d\n",
      "soc_to_dri_pack_recv",
      1723,
      2,
      v24);
    v25 = *(_QWORD *)(a1 + 40);
    v35 = 0;
    v36 = 0;
    v34 = 0;
    v26 = *(_WORD *)(v25 + 2);
    v37 = a2;
    v27 = *(_QWORD *)(v25 + 24);
    WORD2(v34) = 2;
    LOWORD(v34) = v26;
    v35 = a4;
    LOWORD(v36) = v26;
    WORD1(v36) = 1;
    WORD2(v36) = a3;
    v28 = i2c_transfer(v27, &v34, 2);
    if ( (v28 & 0x80000000) == 0 )
      goto LABEL_4;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] aw9620x i2c read cmd err cnt = %d ret = %d\n",
      "soc_to_dri_pack_recv",
      1723,
      1,
      v28);
    v29 = *(_QWORD *)(a1 + 40);
    v35 = 0;
    v36 = 0;
    v34 = 0;
    v30 = *(_WORD *)(v29 + 2);
    v37 = a2;
    v31 = *(_QWORD *)(v29 + 24);
    WORD2(v34) = 2;
    LOWORD(v34) = v30;
    v35 = a4;
    LOWORD(v36) = v30;
    WORD1(v36) = 1;
    WORD2(v36) = a3;
    v32 = i2c_transfer(v31, &v34, 2);
    if ( v32 < 0 )
    {
      v33 = v32;
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] aw9620x i2c read cmd err cnt = %d ret = %d\n",
        "soc_to_dri_pack_recv",
        1723,
        0,
        v32);
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] aw9620x i2c read cmd err!!! ret = %d\n",
        "soc_to_dri_pack_recv",
        1731,
        v33);
      result = 0xFFFFFFFFLL;
    }
    else
    {
LABEL_4:
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
