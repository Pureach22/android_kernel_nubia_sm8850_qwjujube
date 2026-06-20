__int64 __fastcall calc_clk_post(__int64 a1, int *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x10
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x5
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x10
  bool v14; // vf
  __int64 v15; // x9
  unsigned __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x8
  int v19; // w8
  int v20; // w7
  unsigned int v21; // kr00_4
  unsigned int v22; // w4
  int v23; // w8

  v3 = 0xCB2000000LL / *a2;
  if ( (__int64)0xFFFFFFF34E000000LL / *a2 >= 0 )
    v4 = -(((__int64)0xFFFFFFF34E000000LL / *a2) & 0xFFFFF);
  else
    v4 = v3 & 0xFFFFF;
  v5 = v3 + v4;
  v6 = v5 + 62914560;
  v7 = v5 + 63963135;
  if ( v6 >= 0 )
    v7 = v6;
  v8 = v7 >> 20;
  v9 = 0x1F4000000LL * *(unsigned __int8 *)(a3 + 140) + 0x1F4000000LL;
  *(_DWORD *)(a3 + 288) = v7 >> 20;
  v10 = *a2;
  v11 = 0x3E8000000LL / v10;
  v12 = v9 / v10;
  if ( v11 <= 0 )
    v13 = -(-v11 & 0xFFFFF);
  else
    v13 = v11 & 0xFFFFF;
  v14 = __OFADD__(v13, v11);
  v15 = v13 + v11;
  if ( v15 < 0 != v14 )
    v15 += 0xFFFFF;
  v16 = (unsigned __int64)v15 >> 20;
  if ( v12 <= 0 )
    v17 = -(-v12 & 0xFFFFF);
  else
    v17 = v12 & 0xFFFFF;
  v14 = __OFADD__(v17, v12);
  v18 = v17 + v12;
  if ( v18 < 0 != v14 )
    v18 += 0xFFFFF;
  v19 = (int)(((unsigned __int64)v18 >> 20) + v8) / (int)v16;
  *(_DWORD *)(a3 + 300) = 255;
  v20 = v19 - 1;
  *(_DWORD *)(a3 + 296) = v19 - 1;
  v21 = a2[14] * (256 - v19) + 100 * v19 - 1;
  v22 = v21 / 0x64;
  *(_DWORD *)(a3 + 304) = v21 / 0x64;
  if ( v21 >> 10 >= 0x19 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "clk_post", v22);
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(a3 + 308) = v22;
    if ( a1 )
      v23 = *(_DWORD *)(a1 + 28);
    else
      v23 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: CLK_POST:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
      v23,
      v8,
      *(_DWORD *)(a3 + 292),
      v20,
      255,
      (unsigned __int8)(v21 / 0x64));
    return 0;
  }
}
