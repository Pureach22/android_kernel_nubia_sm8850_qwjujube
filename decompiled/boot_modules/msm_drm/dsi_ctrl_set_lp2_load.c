__int64 __fastcall dsi_ctrl_set_lp2_load(__int64 a1, char a2)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    v2 = dsi_pwr_set_lp2_load(a1 + 2416, a2 & 1);
    if ( v2 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set lp2 load rc = %d\n", v2);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v2;
}
