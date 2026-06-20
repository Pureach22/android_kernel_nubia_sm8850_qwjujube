__int64 __fastcall dsi_catalog_phy_pll_setup(__int64 a1, unsigned int a2)
{
  if ( a2 >= 5 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Unsupported version: %d\n", a2);
    return 4294967201LL;
  }
  if ( (*(_BYTE *)(a1 + 32) & 1) != 0 )
    return 0;
  if ( a2 < 2 )
  {
    *(_QWORD *)(a1 + 640) = &dsi_pll_3nm_configure;
    *(_QWORD *)(a1 + 664) = dsi_pll_3nm_toggle;
    return 0;
  }
  else if ( a2 == 2 )
  {
    *(_QWORD *)(a1 + 640) = dsi_pll_4nm_configure;
    *(_QWORD *)(a1 + 664) = dsi_pll_4nm_toggle;
    return 0;
  }
  else
  {
    if ( a2 != 3 )
      return 0;
    *(_QWORD *)(a1 + 640) = dsi_pll_5nm_configure;
    *(_QWORD *)(a1 + 664) = dsi_pll_5nm_toggle;
    return 0;
  }
}
