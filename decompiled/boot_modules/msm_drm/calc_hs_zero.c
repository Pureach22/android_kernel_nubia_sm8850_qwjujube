__int64 __fastcall calc_hs_zero(__int64 a1, unsigned int *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x8
  unsigned __int64 v6; // x9
  __int64 v7; // x10
  __int64 (__fastcall *v8)(__int64, __int64); // x9
  __int64 v12; // x0
  int v13; // w0
  int v14; // w9
  unsigned int v15; // kr00_4
  unsigned int v16; // w4
  int v17; // w8

  v4 = (__int64)((unsigned __int64)(10 * a2[3]) << 20) / (int)*a2 - a4;
  v5 = v4 + 152043520;
  v6 = v4 + 153092095;
  v7 = *(_QWORD *)(a1 + 392);
  if ( v5 >= 0 )
    v6 = v5;
  *(_DWORD *)(a3 + 96) = v6 >> 20;
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 32);
  if ( !v8 )
    return 4294967274LL;
  v12 = v5 * *a2 / (int)a2[3];
  if ( *((_DWORD *)v8 - 1) != 63768381 )
    __break(0x8229u);
  v13 = v8(v12, 0x100000);
  if ( v13 <= 255 )
    v14 = 255;
  else
    v14 = 511;
  *(_DWORD *)(a3 + 104) = v13;
  *(_DWORD *)(a3 + 108) = v14;
  v15 = (v14 - v13) * a2[9] + 100 * v13 + 99;
  v16 = v15 / 0x64;
  *(_DWORD *)(a3 + 112) = v15 / 0x64;
  if ( v15 >> 10 >= 0x19 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "hs_zero", v16);
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(a3 + 116) = v16;
    if ( a1 )
      v17 = *(_DWORD *)(a1 + 28);
    else
      v17 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: HS_ZERO:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
      v17,
      *(_DWORD *)(a3 + 96),
      *(_DWORD *)(a3 + 100),
      v13,
      v14,
      (unsigned __int8)(v15 / 0x64));
    return 0;
  }
}
