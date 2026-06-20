__int64 __fastcall dsi_phy_hw_timing_val_v4_0(_BYTE *a1, _DWORD *a2, int a3)
{
  if ( a3 == 14 )
  {
    a1[52] = *a2;
    a1[53] = a2[1];
    a1[54] = a2[2];
    a1[55] = a2[3];
    a1[56] = a2[4];
    a1[57] = a2[5];
    a1[58] = a2[6];
    a1[59] = a2[7];
    a1[60] = a2[8];
    a1[61] = a2[9];
    a1[62] = a2[10];
    a1[63] = a2[11];
    a1[64] = a2[12];
    a1[65] = a2[13];
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Unexpected timing array size %d\n", a3);
    return 4294967274LL;
  }
}
