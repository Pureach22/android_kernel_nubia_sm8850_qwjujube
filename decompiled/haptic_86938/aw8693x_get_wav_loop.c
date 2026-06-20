__int64 __fastcall aw8693x_get_wav_loop(_BYTE *a1, char *a2)
{
  int v4; // w4
  __int64 v5; // x23
  __int64 v6; // x23
  int v7; // w4
  __int64 v8; // x23
  __int64 v9; // x23
  int v10; // w4
  __int64 v11; // x23
  __int64 v12; // x23
  int v13; // w4
  __int64 v14; // x23
  int v15; // w0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  i2c_r_bytes(a1, 18, &v17, 4);
  v4 = (unsigned __int8)v17 >> 4;
  a1[39] = v17 & 0xF;
  a1[38] = v4;
  v5 = snprintf(a2, 0x1000u, "seq%d loop: 0x%02x\n", 1, v4);
  v6 = v5 + snprintf(&a2[v5], 4096 - v5, "seq%d loop: 0x%02x\n", 2, (unsigned __int8)a1[39]);
  v7 = BYTE1(v17) >> 4;
  a1[41] = BYTE1(v17) & 0xF;
  a1[40] = v7;
  v8 = v6 + snprintf(&a2[v6], 4096 - v6, "seq%d loop: 0x%02x\n", 3, v7);
  v9 = v8 + snprintf(&a2[v8], 4096 - v8, "seq%d loop: 0x%02x\n", 4, (unsigned __int8)a1[41]);
  v10 = BYTE2(v17) >> 4;
  a1[43] = BYTE2(v17) & 0xF;
  a1[42] = v10;
  v11 = v9 + snprintf(&a2[v9], 4096 - v9, "seq%d loop: 0x%02x\n", 5, v10);
  v12 = v11 + snprintf(&a2[v11], 4096 - v11, "seq%d loop: 0x%02x\n", 6, (unsigned __int8)a1[43]);
  v13 = HIBYTE(v17) >> 4;
  a1[45] = HIBYTE(v17) & 0xF;
  a1[44] = v13;
  v14 = v12 + snprintf(&a2[v12], 4096 - v12, "seq%d loop: 0x%02x\n", 7, v13);
  v15 = snprintf(&a2[v14], 4096 - v14, "seq%d loop: 0x%02x\n", 8, (unsigned __int8)a1[45]);
  _ReadStatusReg(SP_EL0);
  return v14 + v15;
}
