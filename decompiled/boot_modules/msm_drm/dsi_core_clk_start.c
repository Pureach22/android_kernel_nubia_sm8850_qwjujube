__int64 __fastcall dsi_core_clk_start(_QWORD *a1)
{
  __int64 v1; // x21
  unsigned int v3; // w20
  unsigned int v4; // w0
  __int64 v5; // x21
  unsigned int v6; // w0
  __int64 v7; // x21
  unsigned int v8; // w0
  __int64 v9; // x21
  unsigned int v10; // w0
  __int64 v11; // x21
  unsigned int v12; // w0
  __int64 v13; // x21
  __int64 v14; // x21
  __int64 v15; // x21
  __int64 v16; // x21
  __int64 v17; // x21
  __int64 v18; // x19

  v1 = *a1;
  if ( *a1 )
  {
    v3 = clk_prepare(*a1);
    if ( v3 )
    {
LABEL_5:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable mdp_core_clk, rc=%d\n", v3);
      return v3;
    }
    v4 = clk_enable(v1);
    if ( v4 )
    {
      v3 = v4;
      clk_unprepare(v1);
      goto LABEL_5;
    }
  }
  v5 = a1[5];
  if ( !v5 )
    goto LABEL_11;
  v3 = clk_prepare(a1[5]);
  if ( !v3 )
  {
    v6 = clk_enable(v5);
    if ( v6 )
    {
      v3 = v6;
      clk_unprepare(v5);
      goto LABEL_10;
    }
LABEL_11:
    v7 = a1[1];
    if ( v7 )
    {
      v3 = clk_prepare(a1[1]);
      if ( v3 )
      {
LABEL_15:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable iface_clk, rc=%d\n", v3);
LABEL_36:
        v17 = a1[5];
        if ( v17 )
        {
          clk_disable(a1[5]);
          clk_unprepare(v17);
        }
        goto LABEL_38;
      }
      v8 = clk_enable(v7);
      if ( v8 )
      {
        v3 = v8;
        clk_unprepare(v7);
        goto LABEL_15;
      }
    }
    v9 = a1[2];
    if ( v9 )
    {
      v3 = clk_prepare(a1[2]);
      if ( v3 )
      {
LABEL_20:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable ahb_swi_clk, rc=%d\n", v3);
LABEL_34:
        v16 = a1[1];
        if ( v16 )
        {
          clk_disable(a1[1]);
          clk_unprepare(v16);
        }
        goto LABEL_36;
      }
      v10 = clk_enable(v9);
      if ( v10 )
      {
        v3 = v10;
        clk_unprepare(v9);
        goto LABEL_20;
      }
    }
    v11 = a1[4];
    if ( v11 )
    {
      v3 = clk_prepare(a1[4]);
      if ( v3 )
      {
LABEL_25:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable bus_clk, rc=%d\n", v3);
LABEL_32:
        v15 = a1[2];
        if ( v15 )
        {
          clk_disable(a1[2]);
          clk_unprepare(v15);
        }
        goto LABEL_34;
      }
      v12 = clk_enable(v11);
      if ( v12 )
      {
        v3 = v12;
        clk_unprepare(v11);
        goto LABEL_25;
      }
    }
    v13 = a1[3];
    if ( !v13 )
      return 0;
    v3 = clk_prepare(a1[3]);
    if ( !v3 )
    {
      v3 = clk_enable(v13);
      if ( !v3 )
        return v3;
      clk_unprepare(v13);
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable core_mmss_clk, rc=%d\n", v3);
    v14 = a1[4];
    if ( v14 )
    {
      clk_disable(a1[4]);
      clk_unprepare(v14);
    }
    goto LABEL_32;
  }
LABEL_10:
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable mnoc_clk, rc=%d\n", v3);
LABEL_38:
  v18 = *a1;
  if ( v18 )
  {
    clk_disable(v18);
    clk_unprepare(v18);
  }
  return v3;
}
