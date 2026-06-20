__int64 __fastcall dsi_link_lp_clk_start(_QWORD *a1, int a2)
{
  _QWORD *v2; // x19
  int v3; // w8
  unsigned int v4; // w20
  __int64 v6; // x19
  _QWORD *v7; // x21
  unsigned int v8; // w0

  if ( a2 >= 2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid DSI ctrl index\n");
    return 4294967274LL;
  }
  if ( &a1[-6 * a2] == &_ksymtab_msm_dss_iounmap )
    return 4294967274LL;
  if ( (a1[-6 * a2 + 25] & 1) != 0 || (v2 = a1, v3 = clk_set_rate(*a1, *((unsigned int *)a1 + 5)), a1 = v2, !v3) )
  {
    v6 = *a1;
    v7 = a1;
    v4 = clk_prepare(*a1);
    if ( !v4 )
    {
      v8 = clk_enable(v6);
      if ( !v8 )
      {
        v4 = 0;
        goto LABEL_12;
      }
      v4 = v8;
      clk_unprepare(v6);
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to enable dsi esc clk\n");
    clk_unprepare(*v7);
  }
  else
  {
    v4 = v3;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: clk_set_rate failed for esc_clk rc = %d\n", v3);
  }
LABEL_12:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: LP Link clocks are enabled\n");
  return v4;
}
