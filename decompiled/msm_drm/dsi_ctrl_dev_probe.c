__int64 __fastcall dsi_ctrl_dev_probe(__int64 a1)
{
  __int64 matched; // x0
  int v3; // w22
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x19
  int v8; // w9
  const void *v9; // x22
  __int64 v10; // x22
  int v11; // w8
  __int64 property; // x0
  const char *v13; // x8
  int v14; // w8
  __int64 v15; // x0
  int v16; // w8
  int v17; // w0
  const char *v18; // x4
  unsigned int v19; // w8
  __int64 v20; // x0
  __int64 v21; // x1
  void *v22; // x2
  const char *v23; // x3
  __int64 v24; // x2
  unsigned __int64 v25; // x0
  unsigned int v26; // w0
  int v28; // w0
  _QWORD v29[2]; // [xsp+0h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  matched = of_match_node(&msm_dsi_of_match);
  if ( !matched )
  {
    LODWORD(v9) = -19;
    goto LABEL_40;
  }
  v3 = **(_DWORD **)(matched + 192);
  v4 = devm_kmalloc(a1 + 16, 24, 3520);
  if ( !v4 || (v5 = v4, (v6 = devm_kmalloc(a1 + 16, 2936, 3520)) == 0) )
  {
    LODWORD(v9) = -12;
    goto LABEL_40;
  }
  v7 = v6;
  *(_DWORD *)(v6 + 88) = v3;
  if ( v3 == 7 )
  {
    v8 = 6;
    goto LABEL_10;
  }
  if ( v3 == 11 )
  {
    v8 = 10;
LABEL_10:
    *(_DWORD *)(v6 + 1608) = 1;
    *(_DWORD *)(v6 + 88) = v8;
    goto LABEL_12;
  }
  *(_DWORD *)(v6 + 1608) = 0;
LABEL_12:
  *(_DWORD *)(v6 + 1664) = 0;
  *(_QWORD *)(v6 + 2808) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v6 + 2816) = v6 + 2816;
  *(_QWORD *)(v6 + 2824) = v6 + 2816;
  *(_QWORD *)(v6 + 2832) = dsi_ctrl_post_cmd_transfer_work;
  *(_DWORD *)(v6 + 2852) = 0;
  v10 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(v6 + 1656) = 0xFFFFFFFF00000000LL;
  v29[0] = 0;
  if ( !v10 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: invalid dsi_ctrl:%d or of_node:%d\n",
      *(const char **)(v6 + 16),
      1,
      0);
    LODWORD(v9) = -22;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: dts parse failed, rc = %d\n",
      *(_QWORD *)(v7 + 16),
      4294967274LL);
    goto LABEL_40;
  }
  if ( (of_property_read_variable_u32_array(v10, "cell-index", (char *)v29 + 4, 1, 0) & 0x80000000) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: cell index not set, default to 0\n", *(const char **)(v7 + 16));
    v11 = 0;
    HIDWORD(v29[0]) = 0;
  }
  else
  {
    v11 = HIDWORD(v29[0]);
  }
  *(_DWORD *)(v7 + 8) = v11;
  property = of_get_property(v10, "label", 0);
  v13 = "MDSS DSI CTRL";
  if ( property )
    v13 = (const char *)property;
  *(_QWORD *)(v7 + 16) = v13;
  *(_BYTE *)(v7 + 2893) = of_find_property(v10, "qcom,null-insertion-enabled", 0) != 0;
  *(_BYTE *)(v7 + 2895) = of_find_property(v10, "qcom,split-link-supported", 0) != 0;
  *(_BYTE *)(v7 + 2892) = of_find_property(v10, "qcom,dsi-phy-pll-bypass", 0) != 0;
  if ( (of_property_read_variable_u32_array(v10, "frame-threshold-time-us", v29, 1, 0) & 0x80000000) != 0 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: %s: frame-threshold-time not specified, defaulting\n",
      *(const char **)(v7 + 16));
    v14 = 2666;
    LODWORD(v29[0]) = 2666;
  }
  else
  {
    v14 = v29[0];
  }
  *(_DWORD *)(v7 + 2872) = v14;
  v15 = of_find_property(v10, "qcom,dsi-ctrl-shared", 0);
  v16 = *(_DWORD *)(v7 + 1608);
  *(_BYTE *)(v7 + 2898) = v15 != 0;
  if ( v16 )
    goto LABEL_23;
  v9 = (const void *)msm_ioremap(a1, "dsi_ctrl", *(_QWORD *)(v7 + 16));
  if ( (unsigned __int64)v9 > 0xFFFFFFFFFFFFF000LL )
  {
LABEL_31:
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: Failed to parse register information, rc = %d\n",
      *(_QWORD *)(v7 + 16),
      (unsigned int)v9);
    goto LABEL_40;
  }
  v18 = *(const char **)(v7 + 16);
  *(_QWORD *)(v7 + 96) = v9;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: map dsi_ctrl registers to %pK\n", v18, v9);
  v19 = *(_DWORD *)(v7 + 88);
  if ( v19 <= 0xA && ((1 << v19) & 0x77E) != 0 )
  {
    v9 = (const void *)msm_ioremap(a1, "disp_cc_base", *(_QWORD *)(v7 + 16));
    if ( (unsigned __int64)v9 >= 0xFFFFFFFFFFFFF001LL )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: disp_cc base address not found for\n",
        *(const char **)(v7 + 16));
      goto LABEL_31;
    }
    v24 = *(_QWORD *)(v7 + 16);
    *(_QWORD *)(v7 + 128) = v9;
    *(_QWORD *)(v7 + 112) = 0;
    v25 = msm_ioremap(a1, "mdp_intf_base", v24);
    if ( v25 <= 0xFFFFFFFFFFFFF000LL )
      *(_QWORD *)(v7 + 144) = v25;
  }
  v26 = dsi_ctrl_supplies_init(a1, v7);
  if ( v26 )
  {
    LODWORD(v9) = v26;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: Failed to parse voltage supplies, rc = %d\n",
      *(_QWORD *)(v7 + 16),
      v26);
    goto LABEL_40;
  }
  v28 = dsi_ctrl_clocks_init(a1, v7);
  if ( v28 )
  {
    LODWORD(v9) = v28;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: Failed to parse clock information, rc = %d\n",
      *(const char **)(v7 + 16),
      v28);
    goto LABEL_25;
  }
LABEL_23:
  v17 = dsi_catalog_ctrl_setup(
          v7 + 96,
          *(unsigned int *)(v7 + 88),
          *(unsigned int *)(v7 + 8),
          *(unsigned __int8 *)(v7 + 2892),
          *(unsigned __int8 *)(v7 + 2893));
  if ( v17 )
  {
    LODWORD(v9) = v17;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: Catalog does not support version (%d)\n",
      *(const char **)(v7 + 16),
      *(_DWORD *)(v7 + 88));
    dsi_ctrl_clocks_deinit(v7);
LABEL_25:
    dsi_ctrl_supplies_deinit(v7);
    goto LABEL_40;
  }
  v20 = *(_QWORD *)(v7 + 96);
  v21 = *(_QWORD *)(v7 + 16);
  *(_QWORD *)v5 = v7;
  sde_dbg_dsi_ctrl_register(v20, v21);
  mutex_lock(&dsi_ctrl_list_lock);
  v22 = dsi_ctrl_list;
  if ( dsi_ctrl_list == (_UNKNOWN *)(v5 + 8)
    || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)dsi_ctrl_list) != &dsi_ctrl_list )
  {
    _list_add_valid_or_report(v5 + 8, &dsi_ctrl_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)dsi_ctrl_list) = v5 + 8;
    *(_QWORD *)(v5 + 8) = v22;
    *(_QWORD *)(v5 + 16) = &dsi_ctrl_list;
    dsi_ctrl_list = (_UNKNOWN *)(v5 + 8);
  }
  mutex_unlock(&dsi_ctrl_list_lock);
  _mutex_init(v7 + 32, "&dsi_ctrl->ctrl_lock", &dsi_ctrl_dev_probe___key_158);
  v23 = *(const char **)(v7 + 16);
  *(_BYTE *)(v7 + 2800) = 0;
  *(_QWORD *)v7 = a1;
  *(_QWORD *)(a1 + 168) = v7;
  drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: %s: Probe successful\n", v23);
  LODWORD(v9) = 0;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v9;
}
