__int64 __fastcall aw9620x_i2c_read(__int64 a1, unsigned __int16 a2, _DWORD *a3)
{
  int v5; // w22
  __int64 v6; // x8
  __int16 v7; // w9
  __int64 v8; // x0
  int v9; // w0
  __int64 result; // x0
  _BYTE v12[2]; // [xsp+10h] [xbp-30h] BYREF
  unsigned int v13; // [xsp+12h] [xbp-2Eh] BYREF
  __int64 v14; // [xsp+18h] [xbp-28h] BYREF
  _BYTE *v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  unsigned int *v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v5 = 5;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v12[0] = HIBYTE(a2);
  v12[1] = a2;
  while ( 1 )
  {
    v6 = *(_QWORD *)(a1 + 40);
    v15 = nullptr;
    v16 = 0;
    v14 = 0;
    v7 = *(_WORD *)(v6 + 2);
    v17 = &v13;
    v8 = *(_QWORD *)(v6 + 24);
    WORD2(v14) = 2;
    LOWORD(v14) = v7;
    v15 = v12;
    LOWORD(v16) = v7;
    *(_DWORD *)((char *)&v16 + 2) = 262145;
    v9 = i2c_transfer(v8, &v14, 2);
    if ( (v9 & 0x80000000) == 0 )
      break;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] i2c read error reg: 0x%04x, ret= %d cnt= %d\n",
      "aw9620x_i2c_read",
      573,
      a2,
      v9,
      v5);
    usleep_range_state(2000, 3000, 2);
    if ( --v5 == -1 )
      goto LABEL_8;
  }
  if ( (v5 & 0x80) == 0 )
  {
    result = 0;
    *a3 = bswap32(v13);
    goto LABEL_7;
  }
LABEL_8:
  dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] i2c read error!\n", "aw9620x_i2c_read", 580);
  result = 0xFFFFFFFFLL;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
