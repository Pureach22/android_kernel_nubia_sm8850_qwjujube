__int64 __fastcall calc_clk_pre(__int64 a1, int *a2, __int64 a3)
{
  __int64 v3; // x10
  __int64 v4; // x11
  bool v5; // vf
  __int64 v6; // x10
  __int64 v7; // x11
  unsigned __int64 v8; // x5
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x12
  __int64 v15; // x11
  unsigned __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x9
  int v19; // w9
  __int64 v20; // x12
  __int64 v21; // x10
  unsigned __int64 v22; // x8
  int v23; // w8
  int v24; // w7
  unsigned int v25; // w4
  int v26; // w8

  v3 = 0x1F4000000LL / *a2;
  v4 = v3 & 0xFFFFF;
  if ( (__int64)0xFFFFFFFE0C000000LL / *a2 >= 0 )
    v4 = -(((__int64)0xFFFFFFFE0C000000LL / *a2) & 0xFFFFF);
  v5 = __OFADD__(v4, v3);
  v6 = v4 + v3;
  if ( v6 < 0 != v5 )
    v6 += 0xFFFFF;
  v7 = 0x1F4000000LL * *(unsigned __int8 *)(a3 + 20);
  v8 = (unsigned __int64)v6 >> 20;
  v9 = 0x1F4000000LL * *(unsigned __int8 *)(a3 + 44) + 0x1F4000000LL;
  *(_DWORD *)(a3 + 312) = (unsigned __int64)v6 >> 20;
  v10 = *a2;
  v11 = v7 / v10;
  v12 = v9 / v10;
  v13 = 0x3E8000000LL / v10;
  if ( v11 <= 0 )
    v14 = -(-v11 & 0xFFFFF);
  else
    v14 = v11 & 0xFFFFF;
  v5 = __OFADD__(v14, v11);
  v15 = v14 + v11;
  if ( v15 < 0 != v5 )
    v15 += 0xFFFFF;
  v16 = (unsigned __int64)v15 >> 20;
  if ( v12 <= 0 )
    v17 = -(-v12 & 0xFFFFF);
  else
    v17 = v12 & 0xFFFFF;
  v5 = __OFADD__(v17, v12);
  v18 = v17 + v12;
  if ( v18 < 0 != v5 )
    v18 += 0xFFFFF;
  v19 = v16 + ((unsigned __int64)v18 >> 20) + 106;
  if ( v13 <= 0 )
    v20 = -(-v13 & 0xFFFFF);
  else
    v20 = v13 & 0xFFFFF;
  v5 = __OFADD__(v20, v13);
  v21 = v20 + v13;
  v22 = v21 + 0xFFFFF;
  if ( v21 < 0 == v5 )
    v22 = v21;
  v23 = v19 / (int)(v22 >> 20);
  v24 = v23 - 1;
  *(_DWORD *)(a3 + 320) = v23 - 1;
  *(_DWORD *)(a3 + 324) = 255;
  v25 = (125 * (256 - v23) + 10000 * v23 - 1) / 10000;
  *(_DWORD *)(a3 + 328) = v25;
  if ( v25 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "clk_pre", v25);
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(a3 + 332) = v25;
    if ( a1 )
      v26 = *(_DWORD *)(a1 + 28);
    else
      v26 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: CLK_PRE:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
      v26,
      v8,
      *(_DWORD *)(a3 + 316),
      v24,
      255,
      v25);
    return 0;
  }
}
