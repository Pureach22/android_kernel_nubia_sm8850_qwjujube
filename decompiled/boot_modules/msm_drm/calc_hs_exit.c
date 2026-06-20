__int64 __fastcall calc_hs_exit(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v3; // w5
  unsigned int v4; // w8
  int v5; // w9
  unsigned int v6; // w7
  unsigned int v7; // kr00_4
  unsigned int v8; // w4
  int v9; // w8

  v3 = *(_DWORD *)(a3 + 192);
  v4 = (8 * a2[3] + *a2 * v3 - 1) / (unsigned int)(8 * a2[3]);
  v5 = *(_DWORD *)(a3 + 204);
  v6 = v4 - 1;
  *(_DWORD *)(a3 + 200) = v4 - 1;
  v7 = (v5 - (v4 - 1)) * a2[12] + 100 * v4 - 1;
  v8 = v7 / 0x64;
  *(_DWORD *)(a3 + 208) = v7 / 0x64;
  if ( v7 >> 10 >= 0x19 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "hs_exit", v8);
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(a3 + 212) = v8;
    if ( a1 )
      v9 = *(_DWORD *)(a1 + 28);
    else
      v9 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: HS_EXIT:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
      v9,
      v3,
      *(_DWORD *)(a3 + 196),
      v6,
      v5,
      (unsigned __int8)(v7 / 0x64));
    return 0;
  }
}
