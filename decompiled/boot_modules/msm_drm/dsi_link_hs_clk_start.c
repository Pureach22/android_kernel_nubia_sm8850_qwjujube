__int64 __fastcall dsi_link_hs_clk_start(_QWORD *a1, int a2)
{
  unsigned int v2; // w19
  _QWORD *v4; // x8
  int v5; // w0
  int v6; // w0
  unsigned int v7; // w0
  __int64 v8; // x0
  int v9; // w0
  unsigned int v10; // w0
  int v12; // w0
  __int64 v13; // x0
  unsigned int v14; // w0
  int v15; // w0
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // w0

  if ( a2 >= 2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid DSI ctrl index\n");
    return (unsigned int)-22;
  }
  v4 = &a1[-6 * a2];
  if ( (v4[28] & 1) == 0 && (*((_BYTE *)v4 + 225) & 1) == 0 )
  {
    v7 = clk_set_rate(*a1, *((unsigned int *)a1 + 8));
    if ( v7 )
    {
      v2 = v7;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: clk_set_rate failed for byte_clk rc = %d\n", v7);
    }
    else
    {
      v10 = clk_set_rate(a1[1], *((unsigned int *)a1 + 10));
      if ( v10 )
      {
        v2 = v10;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: clk_set_rate failed for pixel_clk rc = %d\n", v10);
      }
      else
      {
        v13 = a1[2];
        if ( !v13 )
          goto LABEL_5;
        v14 = clk_set_rate(v13, *((unsigned int *)a1 + 9));
        if ( !v14 )
          goto LABEL_5;
        v2 = v14;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: set_rate failed for byte_intf_clk rc = %d\n", v14);
      }
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set HS clk rates, rc = %d\n", v2);
    return v2;
  }
LABEL_5:
  v5 = clk_prepare(*a1);
  if ( v5 )
  {
    v2 = v5;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to prepare dsi byte clk, rc=%d\n", v5);
LABEL_10:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to prepare link HS clks, rc = %d\n", v2);
    return v2;
  }
  v6 = clk_prepare(a1[1]);
  if ( v6 )
  {
    v2 = v6;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to prepare dsi pixel clk, rc=%d\n", v6);
LABEL_9:
    clk_unprepare(*a1);
    goto LABEL_10;
  }
  v8 = a1[2];
  if ( v8 )
  {
    v9 = clk_prepare(v8);
    if ( v9 )
    {
      v2 = v9;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to prepare dsi byte intf clk, rc=%d\n", v9);
      clk_unprepare(a1[1]);
      goto LABEL_9;
    }
  }
  v12 = clk_enable(*a1);
  if ( v12 )
  {
    v2 = v12;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to enable dsi byte clk, rc=%d\n", v12);
  }
  else
  {
    v15 = clk_enable(a1[1]);
    if ( v15 )
    {
      v2 = v15;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to enable dsi pixel clk, rc=%d\n", v15);
    }
    else
    {
      v17 = a1[2];
      if ( !v17 || (v18 = clk_enable(v17)) == 0 )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: HS Link clocks are enabled\n");
        return 0;
      }
      v2 = v18;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to enable dsi byte intf clk, rc=%d\n", v18);
      clk_disable(a1[1]);
    }
    clk_disable(*a1);
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable link HS clks, rc = %d\n", v2);
  v16 = a1[2];
  if ( v16 )
    clk_unprepare(v16);
  clk_unprepare(a1[1]);
  clk_unprepare(*a1);
  return v2;
}
