__int64 __fastcall dsi_display_clk_ctrl(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v6; // w19

  if ( a1 && a2 <= 0xF && a3 < 3 )
  {
    mutex_lock(&dsi_mngr_clk_mutex);
    v6 = dsi_clk_req_state(a1, a2, a3, 1);
    if ( v6 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed set clk state, rc = %d\n", v6);
    mutex_unlock(&dsi_mngr_clk_mutex);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid arg\n");
    return (unsigned int)-22;
  }
  return v6;
}
