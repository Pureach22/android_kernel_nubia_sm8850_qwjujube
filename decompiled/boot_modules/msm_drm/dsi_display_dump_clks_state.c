__int64 __fastcall dsi_display_dump_clks_state(_QWORD *a1)
{
  _QWORD *v2; // x19
  unsigned int v3; // w0
  unsigned int v4; // w20
  const char *v5; // x2
  unsigned int v7; // w0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display argument\n");
    return 4294967274LL;
  }
  if ( !a1[164] )
  {
    v5 = "*ERROR* [msm-dsi-error]: invalid clk manager\n";
    goto LABEL_10;
  }
  if ( !a1[165] || !a1[166] )
  {
    v5 = "*ERROR* [msm-dsi-error]: invalid clk handles\n";
LABEL_10:
    drm_dev_printk(0, &unk_248D72, v5);
    return 4294967274LL;
  }
  mutex_lock(a1 + 9);
  v2 = a1;
  v3 = dsi_display_dump_clk_handle_state(a1[165]);
  if ( v3 )
  {
    v4 = v3;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to dump dsi clock state\n");
  }
  else
  {
    v7 = dsi_display_dump_clk_handle_state(a1[166]);
    if ( v7 )
    {
      v4 = v7;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to dump mdp clock state\n");
    }
    else
    {
      v4 = 0;
    }
  }
  mutex_unlock(v2 + 9);
  return v4;
}
