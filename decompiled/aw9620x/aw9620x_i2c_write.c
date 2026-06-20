__int64 __fastcall aw9620x_i2c_write(__int64 a1, unsigned __int16 a2, int a3)
{
  __int64 v6; // x9
  __int64 v7; // x0
  __int16 v8; // w8
  int v9; // w0
  __int64 result; // x0
  __int64 v11; // x8
  __int16 v12; // w9
  __int64 v13; // x0
  int v14; // w0
  __int64 v15; // x8
  __int16 v16; // w9
  __int64 v17; // x0
  int v18; // w0
  __int64 v19; // x8
  __int16 v20; // w9
  __int64 v21; // x0
  int v22; // w0
  __int64 v23; // x8
  __int16 v24; // w9
  __int64 v25; // x0
  int v26; // w0
  __int64 v27; // x8
  __int16 v28; // w10
  __int64 v29; // x0
  int v30; // w0
  __int64 v31; // [xsp+10h] [xbp-20h] BYREF
  _BYTE *v32; // [xsp+18h] [xbp-18h]
  _BYTE v33[8]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[2] = HIBYTE(a3);
  v6 = *(_QWORD *)(a1 + 40);
  v33[4] = BYTE1(a3);
  v33[3] = BYTE2(a3);
  v7 = *(_QWORD *)(v6 + 24);
  v33[5] = a3;
  v31 = 0x600000000LL;
  v8 = *(_WORD *)(v6 + 2);
  v33[0] = HIBYTE(a2);
  v33[1] = a2;
  LOWORD(v31) = v8;
  v32 = v33;
  v9 = i2c_transfer(v7, &v31, 1);
  if ( (v9 & 0x80000000) == 0 )
    goto LABEL_2;
  dev_printk(
    &unk_134C0,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] aw9620x i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
    "aw9620x_i2c_write",
    611,
    a2,
    a3,
    v9,
    5);
  usleep_range_state(2000, 3000, 2);
  v11 = *(_QWORD *)(a1 + 40);
  v31 = 0;
  v12 = *(_WORD *)(v11 + 2);
  v13 = *(_QWORD *)(v11 + 24);
  WORD2(v31) = 6;
  v32 = v33;
  LOWORD(v31) = v12;
  v14 = i2c_transfer(v13, &v31, 1);
  if ( (v14 & 0x80000000) == 0 )
    goto LABEL_2;
  dev_printk(
    &unk_134C0,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] aw9620x i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
    "aw9620x_i2c_write",
    611,
    a2,
    a3,
    v14,
    4);
  usleep_range_state(2000, 3000, 2);
  v15 = *(_QWORD *)(a1 + 40);
  v31 = 0;
  v16 = *(_WORD *)(v15 + 2);
  v17 = *(_QWORD *)(v15 + 24);
  WORD2(v31) = 6;
  v32 = v33;
  LOWORD(v31) = v16;
  v18 = i2c_transfer(v17, &v31, 1);
  if ( (v18 & 0x80000000) == 0 )
    goto LABEL_2;
  dev_printk(
    &unk_134C0,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] aw9620x i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
    "aw9620x_i2c_write",
    611,
    a2,
    a3,
    v18,
    3);
  usleep_range_state(2000, 3000, 2);
  v19 = *(_QWORD *)(a1 + 40);
  v31 = 0;
  v20 = *(_WORD *)(v19 + 2);
  v21 = *(_QWORD *)(v19 + 24);
  WORD2(v31) = 6;
  v32 = v33;
  LOWORD(v31) = v20;
  v22 = i2c_transfer(v21, &v31, 1);
  if ( (v22 & 0x80000000) == 0 )
    goto LABEL_2;
  dev_printk(
    &unk_134C0,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] aw9620x i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
    "aw9620x_i2c_write",
    611,
    a2,
    a3,
    v22,
    2);
  usleep_range_state(2000, 3000, 2);
  v23 = *(_QWORD *)(a1 + 40);
  v31 = 0;
  v24 = *(_WORD *)(v23 + 2);
  v25 = *(_QWORD *)(v23 + 24);
  WORD2(v31) = 6;
  v32 = v33;
  LOWORD(v31) = v24;
  v26 = i2c_transfer(v25, &v31, 1);
  if ( (v26 & 0x80000000) == 0 )
    goto LABEL_2;
  dev_printk(
    &unk_134C0,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] aw9620x i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
    "aw9620x_i2c_write",
    611,
    a2,
    a3,
    v26,
    1);
  usleep_range_state(2000, 3000, 2);
  v27 = *(_QWORD *)(a1 + 40);
  v31 = 0;
  v28 = *(_WORD *)(v27 + 2);
  v29 = *(_QWORD *)(v27 + 24);
  WORD2(v31) = 6;
  v32 = v33;
  LOWORD(v31) = v28;
  v30 = i2c_transfer(v29, &v31, 1);
  if ( v30 < 0 )
  {
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] aw9620x i2c write error reg: 0x%04x data: 0x%08x, ret= %d cnt= %d\n",
      "aw9620x_i2c_write",
      611,
      a2,
      a3,
      v30,
      0);
    usleep_range_state(2000, 3000, 2);
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] i2c write error!\n", "aw9620x_i2c_write", 619);
    result = 0xFFFFFFFFLL;
  }
  else
  {
LABEL_2:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
