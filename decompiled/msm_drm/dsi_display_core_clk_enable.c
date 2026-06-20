__int64 __fastcall dsi_display_core_clk_enable(__int64 a1, int a2, unsigned int a3)
{
  __int64 *v5; // x19
  int v7; // w0
  unsigned int v8; // w19
  int v10; // w23
  _QWORD *v11; // x0
  int v12; // w0
  unsigned int v13; // w20

  v5 = (__int64 *)(a1 + 56LL * a3);
  v7 = dsi_core_clk_start(v5);
  if ( v7 )
  {
    v8 = v7;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to turn on master clocks, rc=%d\n", v7);
    return v8;
  }
  else if ( a2 )
  {
    v10 = 0;
    while ( 1 )
    {
      if ( v10 != (unsigned __int64)a3 )
      {
        v11 = (_QWORD *)(a1 + 56LL * v10);
        if ( v11 )
        {
          v12 = dsi_core_clk_start(v11);
          if ( v12 )
            break;
        }
      }
      if ( a2 == ++v10 )
        return 0;
    }
    v13 = v12;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to turn on clocks, rc=%d\n", v12);
    dsi_core_clk_stop(v5);
    return v13;
  }
  else
  {
    return 0;
  }
}
