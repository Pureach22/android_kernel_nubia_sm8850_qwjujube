__int64 __fastcall calc_cphy_hs_exit(_DWORD *a1, __int64 a2)
{
  int v3; // w5
  unsigned int v4; // w4
  unsigned int v5; // w8
  unsigned int v6; // w20

  v3 = *(_DWORD *)(a2 + 204);
  v4 = (7 * a1[3] + *a1 * *(_DWORD *)(a2 + 192) - 1) / (unsigned int)(7 * a1[3]) - 1;
  *(_DWORD *)(a2 + 200) = v4;
  v5 = v4
     + ((unsigned __int64)(((((unsigned __int64)((v3 - v4) * a1[12]) << 20) * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64)
                         + 0xFFFFF) >> 20);
  *(_DWORD *)(a2 + 208) = v5;
  if ( v5 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "cphy_hs_exit", v5);
    v4 = *(_DWORD *)(a2 + 200);
    v3 = *(_DWORD *)(a2 + 204);
    LOBYTE(v5) = *(_BYTE *)(a2 + 212);
    v6 = -22;
  }
  else
  {
    v6 = 0;
    *(_BYTE *)(a2 + 212) = v5;
  }
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: CPHY_HS_EXIT: rec_min=%d, rec_max=%d, reg_val=%d\n",
    v4,
    v3,
    (unsigned __int8)v5);
  return v6;
}
