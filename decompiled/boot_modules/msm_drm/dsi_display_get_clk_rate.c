__int64 __fastcall dsi_display_get_clk_rate(__int64 a1)
{
  if ( a1 && *(_QWORD *)(a1 + 1328) )
    return ((__int64 (*)(void))dsi_display_clk_mngr_get_clk_rate)();
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid arg\n");
  return 4294967274LL;
}
