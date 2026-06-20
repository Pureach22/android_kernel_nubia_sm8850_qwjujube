__int64 __fastcall calc_hs_rqst(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v3; // w5
  unsigned int v4; // w4
  int v5; // w8

  v3 = *(_DWORD *)(a3 + 144);
  v4 = (*a2 * v3 - 1) / (unsigned int)(8 * a2[3]);
  *(_DWORD *)(a3 + 160) = v4;
  if ( v4 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "hs_rqst", v4);
    return 4294967274LL;
  }
  else
  {
    *(_BYTE *)(a3 + 164) = v4;
    if ( a1 )
      v5 = *(_DWORD *)(a1 + 28);
    else
      v5 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_%d: HS_RQST:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
      v5,
      v3,
      *(_DWORD *)(a3 + 148),
      *(_DWORD *)(a3 + 152),
      *(_DWORD *)(a3 + 156),
      v4);
    return 0;
  }
}
