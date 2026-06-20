__int64 __fastcall dsi_ctrl_clocks_init(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v4; // x0
  const char *v5; // x4
  unsigned __int64 v6; // x0
  const char *v7; // x4
  unsigned __int64 v8; // x0
  const char *v9; // x4
  unsigned __int64 v10; // x0
  const char *v11; // x4
  unsigned __int64 v12; // x0
  const char *v13; // x4
  unsigned __int64 v14; // x0
  const char *v15; // x4
  unsigned __int64 v16; // x0
  unsigned int v17; // w21
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x0
  int v20; // w21
  unsigned __int64 v21; // x0
  unsigned int v22; // w22
  unsigned __int64 v23; // x0
  int v24; // w22
  unsigned __int64 v25; // x0
  const char *v26; // x4
  unsigned __int64 v27; // x0
  unsigned __int64 v28; // x0
  unsigned __int64 v30; // x0
  const char *v31; // x4

  v4 = devm_clk_get(a1 + 16, "mdp_core_clk");
  a2[272] = v4;
  if ( v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    v5 = (const char *)a2[2];
    a2[272] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: failed to get mdp_core_clk, rc=%d\n", v5, 0);
  }
  v6 = devm_clk_get(a1 + 16, "iface_clk");
  a2[273] = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    v7 = (const char *)a2[2];
    a2[273] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: failed to get iface_clk, rc=%d\n", v7, 0);
  }
  v8 = devm_clk_get(a1 + 16, "ahb_swi_clk");
  a2[274] = v8;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    v9 = (const char *)a2[2];
    a2[274] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: failed to get ahb_swi_clk, rc=%d\n", v9, 0);
  }
  v10 = devm_clk_get(a1 + 16, "core_mmss_clk");
  a2[275] = v10;
  if ( v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = (const char *)a2[2];
    a2[275] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: failed to get core_mmss_clk, rc=%d\n", v11, 0);
  }
  v12 = devm_clk_get(a1 + 16, "bus_clk");
  a2[276] = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v13 = (const char *)a2[2];
    a2[276] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: failed to get bus_clk, rc=%d\n", v13, 0);
  }
  v14 = devm_clk_get(a1 + 16, "mnoc_clk");
  a2[277] = v14;
  if ( v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    v15 = (const char *)a2[2];
    a2[277] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: can't get mnoc clock, rc=%d\n", v15, 0);
  }
  v16 = devm_clk_get(a1 + 16, "byte_clk");
  a2[279] = v16;
  if ( v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    v17 = v16;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get byte_clk, rc=%d\n",
      (const char *)a2[2],
      v16);
LABEL_31:
    dsi_ctrl_clocks_deinit(a2);
    return v17;
  }
  v18 = devm_clk_get(a1 + 16, "pixel_clk");
  a2[280] = v18;
  if ( v18 >= 0xFFFFFFFFFFFFF001LL )
  {
    v17 = v18;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get pixel_clk, rc=%d\n",
      (const char *)a2[2],
      v18);
    goto LABEL_31;
  }
  v19 = devm_clk_get(a1 + 16, "esync_clk");
  a2[287] = v19;
  if ( v19 < 0xFFFFFFFFFFFFF001LL )
  {
    v20 = 0;
  }
  else
  {
    v20 = v19;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: can't find esync_clk, rc=%d\n", (const char *)a2[2], v19);
  }
  v21 = devm_clk_get(a1 + 16, "esc_clk");
  a2[282] = v21;
  if ( v21 >= 0xFFFFFFFFFFFFF001LL )
  {
    v22 = v21;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get esc_clk, rc=%d\n",
      a2[2],
      (unsigned int)v21);
LABEL_30:
    v17 = v22;
    goto LABEL_31;
  }
  v23 = devm_clk_get(a1 + 16, "osc_clk");
  a2[288] = v23;
  if ( v23 >= 0xFFFFFFFFFFFFF001LL )
  {
    v24 = v23;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: can't find osc_clk, rc=%d\n", (const char *)a2[2], v23);
    v20 = v24;
  }
  v25 = devm_clk_get(a1 + 16, "byte_intf_clk");
  a2[281] = v25;
  if ( v25 >= 0xFFFFFFFFFFFFF001LL )
  {
    v26 = (const char *)a2[2];
    a2[281] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: can't find byte intf clk, rc=%d\n", v26, v20);
  }
  v27 = devm_clk_get(a1 + 16, "byte_clk_rcg");
  a2[283] = v27;
  if ( v27 >= 0xFFFFFFFFFFFFF001LL )
  {
    v22 = v27;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get byte_clk_rcg, rc=%d\n",
      a2[2],
      (unsigned int)v27);
    goto LABEL_30;
  }
  v28 = devm_clk_get(a1 + 16, "pixel_clk_rcg");
  a2[284] = v28;
  if ( v28 >= 0xFFFFFFFFFFFFF001LL )
  {
    v22 = v28;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get pixel_clk_rcg, rc=%d\n",
      a2[2],
      (unsigned int)v28);
    goto LABEL_30;
  }
  v30 = devm_clk_get(a1 + 16, "xo");
  a2[285] = v30;
  if ( v30 >= 0xFFFFFFFFFFFFF001LL )
  {
    v31 = (const char *)a2[2];
    a2[285] = 0;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: failed to get xo clk, rc=%d\n", v31, v20);
    v30 = a2[285];
  }
  v17 = 0;
  a2[286] = v30;
  return v17;
}
