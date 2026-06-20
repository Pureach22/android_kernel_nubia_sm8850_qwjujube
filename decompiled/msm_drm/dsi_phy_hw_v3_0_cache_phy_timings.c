__int64 __fastcall dsi_phy_hw_v3_0_cache_phy_timings(unsigned __int8 *a1, _DWORD *a2, int a3)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 && a2 && a3 )
  {
    if ( a3 == 12 )
    {
      *a2 = a1[40];
      a2[1] = a1[41];
      a2[2] = a1[42];
      a2[3] = a1[43];
      a2[4] = a1[44];
      a2[5] = a1[45];
      a2[6] = a1[46];
      a2[7] = a1[47];
      a2[8] = a1[48];
      a2[9] = a1[49];
      a2[10] = a1[50];
      a2[11] = a1[51];
      return 0;
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: size mis-match\n");
      return 4294967274LL;
    }
  }
  return result;
}
