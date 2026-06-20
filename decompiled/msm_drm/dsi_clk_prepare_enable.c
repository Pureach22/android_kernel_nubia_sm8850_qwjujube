__int64 __fastcall dsi_clk_prepare_enable(_QWORD *a1)
{
  __int64 v1; // x20
  unsigned int v3; // w19
  unsigned int v4; // w0
  __int64 v6; // x20

  v1 = *a1;
  v3 = clk_prepare(*a1);
  if ( !v3 )
  {
    v4 = clk_enable(v1);
    if ( !v4 )
    {
      v6 = a1[1];
      v3 = clk_prepare(v6);
      if ( !v3 )
      {
        v3 = clk_enable(v6);
        if ( !v3 )
          return v3;
        clk_unprepare(v6);
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable pixel src clk %d\n", v3);
      return v3;
    }
    v3 = v4;
    clk_unprepare(v1);
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable byte src clk %d\n", v3);
  return v3;
}
