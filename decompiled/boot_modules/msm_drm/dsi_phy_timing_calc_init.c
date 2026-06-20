__int64 __fastcall dsi_phy_timing_calc_init(__int64 a1, int a2)
{
  _QWORD *v4; // x0
  __int64 (__fastcall *v5)(); // x9
  int v7; // w3

  if ( !a1 || (unsigned int)(a2 - 1) >= 9 )
  {
    if ( a1 )
      v7 = *(_DWORD *)(a1 + 28);
    else
      v7 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Unsupported version: %d\n", v7, a2);
    return 4294966772LL;
  }
  v4 = (_QWORD *)_kmalloc_cache_noprof(_drm_debug, 3520, 56);
  if ( v4 )
  {
    *(_QWORD *)(a1 + 392) = v4;
    if ( (unsigned int)(a2 - 2) < 7 )
    {
      *v4 = dsi_phy_hw_v4_0_get_default_phy_params;
      v4[1] = dsi_phy_hw_v4_0_calc_clk_zero;
      v4[2] = dsi_phy_hw_v4_0_calc_clk_trail_rec_min;
      v4[3] = dsi_phy_hw_v4_0_calc_clk_trail_rec_max;
      v4[4] = dsi_phy_hw_v4_0_calc_hs_zero;
      v4[5] = dsi_phy_hw_v4_0_calc_hs_trail;
      v5 = dsi_phy_hw_v4_0_update_timing_params;
LABEL_6:
      v4[6] = v5;
      return 0;
    }
    if ( a2 == 1 )
    {
      *v4 = dsi_phy_hw_v3_0_get_default_phy_params;
      v4[1] = dsi_phy_hw_v3_0_calc_clk_zero;
      v4[2] = dsi_phy_hw_v3_0_calc_clk_trail_rec_min;
      v4[3] = dsi_phy_hw_v3_0_calc_clk_trail_rec_max;
      v4[4] = dsi_phy_hw_v3_0_calc_hs_zero;
      v4[5] = dsi_phy_hw_v3_0_calc_hs_trail;
      v5 = dsi_phy_hw_v3_0_update_timing_params;
      goto LABEL_6;
    }
    kfree(v4);
    return 4294966772LL;
  }
  return 4294967274LL;
}
