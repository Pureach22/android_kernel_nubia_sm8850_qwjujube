__int64 __fastcall calc_hs_trail(__int64 a1, _DWORD *a2, __int64 a3, int a4)
{
  __int64 v4; // x9
  _DWORD *v5; // x8
  int v9; // w7
  int v10; // w9
  unsigned int v11; // w4
  int v12; // w8

  v4 = *(_QWORD *)(a1 + 392);
  *(_DWORD *)(a3 + 120) = (unsigned int)(4 * (a2[3] % *a2)) / *a2 + 4 * (a2[3] / *a2) + 60;
  *(_DWORD *)(a3 + 124) = a4 - a2[4];
  v5 = *(_DWORD **)(v4 + 40);
  if ( !v5 )
    return 4294967274LL;
  if ( *(v5 - 1) != 1146397775 )
    __break(0x8228u);
  ((void (__fastcall *)(_DWORD *, __int64))v5)(a2, a3);
  v9 = *(_DWORD *)(a3 + 128);
  v10 = *(_DWORD *)(a3 + 132);
  v11 = ((v10 - v9) * a2[10] + 99) / 0x64u + v9;
  *(_DWORD *)(a3 + 136) = v11;
  if ( v11 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "hs_trail", v11);
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(a3 + 140) = v11;
    if ( a1 )
      v12 = *(_DWORD *)(a1 + 28);
    else
      v12 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: HS_TRAIL:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
      v12,
      *(_DWORD *)(a3 + 120),
      *(_DWORD *)(a3 + 124),
      v9,
      v10,
      v11);
    return 0;
  }
}
