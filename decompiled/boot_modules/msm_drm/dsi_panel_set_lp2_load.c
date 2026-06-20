__int64 __fastcall dsi_panel_set_lp2_load(__int64 a1, char a2)
{
  unsigned int v4; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 1040);
    if ( *(_BYTE *)(a1 + 1973) == 1 )
    {
      v4 = dsi_pwr_set_lp2_load(a1 + 1440, a2 & 1);
      if ( v4 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to set panel lp2 vreg, rc=%d\n",
          *(const char **)a1,
          v4);
    }
    else
    {
      v4 = 0;
    }
    mutex_unlock(a1 + 1040);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return (unsigned int)-22;
  }
  return v4;
}
