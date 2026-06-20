__int64 __fastcall aw9620x_parasitic_data_get(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x19
  int v5; // w21
  int v6; // w23
  __int64 v7; // x24
  unsigned int v8; // w28
  int v9; // w10
  int v10; // w11
  int v11; // w0
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v4 = 0;
  v5 = 0;
  v6 = 6728;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 152);
  v13 = 0;
  do
  {
    aw9620x_i2c_read(v7 - 56, v6, &v13);
    v8 = v13;
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(v7 - 8),
      "[%s:%d] ch%d addr:0x%08x val=0x%08x\n",
      "aw9620x_parasitic_data_get",
      3969,
      v5,
      v6,
      v13);
    if ( (v8 & 0x400) != 0 )
      v9 = 19800;
    else
      v9 = 9900;
    if ( (v8 & 0x400) != 0 )
      v10 = 330;
    else
      v10 = 165;
    v11 = snprintf(
            (char *)(a3 + v4),
            4096 - v4,
            "ch%u parasitic_data %u.%u pf\n",
            v5++,
            (HIBYTE(v8) * v9 + BYTE2(v8) * v10) / 0x2710u,
            (HIBYTE(v8) * v9 + BYTE2(v8) * v10) % 0x2710u);
    v4 += v11;
    v6 += 84;
  }
  while ( v5 != 8 );
  _ReadStatusReg(SP_EL0);
  return v4;
}
