__int64 __fastcall dsi_display_clk_ctrl_nolock(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // w19

  if ( a1 && a2 <= 0xF && a3 < 3 )
  {
    v3 = dsi_clk_req_state(a1, a2, a3, 0);
    if ( v3 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed set clk state, rc = %d\n", v3);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid arg\n");
    return (unsigned int)-22;
  }
  return v3;
}
