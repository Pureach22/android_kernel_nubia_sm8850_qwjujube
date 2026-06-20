__int64 __fastcall dsi_display_dfps_calc_front_porch(
        unsigned int a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        int a5,
        int *a6)
{
  unsigned int v6; // w10
  unsigned int v8; // w8
  int v9; // w19

  if ( a6 )
  {
    if ( a2 && a3 )
    {
      v6 = a1 - a2;
      if ( (int)(a1 - a2) < 0 )
        v6 = a2 - a1;
      v8 = a4 % a2 * v6 / a2 + a4 / a2 * v6;
      if ( a1 <= a2 )
        v8 = -v8;
      v9 = v8 + a5;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: fps %u a %u b %u b_fp %u new_fp %d\n");
      if ( (v9 & 0x80000000) == 0 )
      {
        *a6 = v9;
        return 0;
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid new_hfp calcluated%d\n", v9);
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid pixel total or new fps in mode request\n");
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  }
  return 4294967274LL;
}
