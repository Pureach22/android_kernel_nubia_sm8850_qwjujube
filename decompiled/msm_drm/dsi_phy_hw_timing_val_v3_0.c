__int64 __fastcall dsi_phy_hw_timing_val_v3_0(_BYTE *a1, _DWORD *a2, int a3)
{
  if ( a3 == 12 )
  {
    a1[40] = *a2;
    a1[41] = a2[1];
    a1[42] = a2[2];
    a1[43] = a2[3];
    a1[44] = a2[4];
    a1[45] = a2[5];
    a1[46] = a2[6];
    a1[47] = a2[7];
    a1[48] = a2[8];
    a1[49] = a2[9];
    a1[50] = a2[10];
    a1[51] = a2[11];
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Unexpected timing array size %d\n", a3);
    return 4294967274LL;
  }
}
