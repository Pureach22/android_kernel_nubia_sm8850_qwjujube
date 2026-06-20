__int64 __fastcall dsi_phy_driver_probe(__int64 a1)
{
  __int64 matched; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x24
  unsigned int v6; // w22
  __int64 v7; // x0
  unsigned int *v8; // x23
  __int64 v9; // x0
  _QWORD *v10; // x20
  __int64 v11; // x0
  __int64 v12; // x21
  int v13; // w8
  unsigned __int64 v14; // x22
  __int64 v16; // x0
  __int64 property; // x0
  const char *v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x4
  long double v22; // q0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x0
  int v28; // w4
  const void *v29; // x5
  long double v30; // q0
  int v31; // w0
  int v32; // w0
  __int64 v33; // x3
  __int64 v34; // x8
  int v35; // w9
  __int64 v36; // x0
  bool v37; // w9
  __int64 v38; // x0
  unsigned int v39; // w0
  int v40; // w0
  int v41; // w3
  int v42; // [xsp+4h] [xbp-5Ch] BYREF
  __int64 v43; // [xsp+8h] [xbp-58h] BYREF
  __int64 v44; // [xsp+10h] [xbp-50h]
  __int64 v45; // [xsp+18h] [xbp-48h]
  __int64 v46; // [xsp+20h] [xbp-40h]
  __int64 v47; // [xsp+28h] [xbp-38h]
  __int64 v48; // [xsp+30h] [xbp-30h]
  __int64 v49; // [xsp+38h] [xbp-28h]
  __int64 v50; // [xsp+40h] [xbp-20h]
  __int64 v51; // [xsp+48h] [xbp-18h]
  __int64 v52; // [xsp+50h] [xbp-10h]
  __int64 v53; // [xsp+58h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  if ( !a1 || !*(_QWORD *)(a1 + 760) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: pdev not found\n");
    goto LABEL_18;
  }
  matched = of_match_node(&msm_dsi_phy_of_match);
  if ( !matched )
  {
LABEL_18:
    LODWORD(v14) = -19;
    goto LABEL_19;
  }
  v3 = matched;
  v4 = *(_QWORD *)(a1 + 760);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v4, "qcom,mdp", 0, 0, 0, &v43) || (v5 = v43) == 0 )
  {
LABEL_12:
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: %s no qcom,mdp node\n", "dsi_phy_driver_probe");
  }
  else
  {
    v6 = 1;
    while ( (of_node_name_eq(v5, "qcom,mdss_mdp") & 1) == 0
         || (of_device_is_available(v5) & 1) == 0
         || (*(_QWORD *)(v5 + 232) & 8) == 0 )
    {
      v7 = *(_QWORD *)(a1 + 760);
      v51 = 0;
      v52 = 0;
      v49 = 0;
      v50 = 0;
      v47 = 0;
      v48 = 0;
      v45 = 0;
      v46 = 0;
      v43 = 0;
      v44 = 0;
      if ( !(unsigned int)_of_parse_phandle_with_args(v7, "qcom,mdp", 0, 0, v6, &v43) )
      {
        v5 = v43;
        ++v6;
        if ( v43 )
          continue;
      }
      goto LABEL_12;
    }
    if ( !*(_QWORD *)(of_find_device_by_node(v5) + 168) )
    {
      printk(&unk_21AF09, v25);
      LODWORD(v14) = -517;
      goto LABEL_19;
    }
  }
  v8 = *(unsigned int **)(v3 + 192);
  v9 = devm_kmalloc(a1 + 16, 24, 3520);
  if ( v9 )
  {
    v10 = (_QWORD *)v9;
    v11 = devm_kmalloc(a1 + 16, 1368, 3520);
    if ( v11 )
    {
      v12 = v11;
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "cell-index", &v42, 1, 0) & 0x80000000) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: cell index not set, default to 0\n", *(_DWORD *)(v12 + 8));
        v13 = 0;
        v42 = 0;
      }
      else
      {
        v13 = v42;
      }
      v16 = *(_QWORD *)(a1 + 760);
      *(_DWORD *)(v12 + 8) = v13;
      property = of_get_property(v16, "label", 0);
      v18 = "MDSS PHY CTRL";
      if ( property )
        v18 = (const char *)property;
      v19 = *(_QWORD *)(a1 + 760);
      *(_QWORD *)(v12 + 16) = v18;
      v20 = of_find_property(v19, "qcom,dsi-phy-pll-bypass", 0);
      v21 = *(unsigned int *)(v12 + 8);
      *(_BYTE *)(v12 + 120) = v20 != 0;
      *(double *)&v22 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Probing device\n", v21);
      *(_QWORD *)(v12 + 80) = v8;
      if ( *v8 == 9 )
      {
        v23 = 9;
        *(_QWORD *)(v12 + 80) = &dsi_phy_v7_2;
        *(_BYTE *)(v12 + 120) = 1;
        *(_DWORD *)(v12 + 776) = 1;
      }
      else
      {
        v24 = *(_QWORD *)(v12 + 16);
        *(_DWORD *)(v12 + 776) = 0;
        v14 = msm_ioremap(a1, "dsi_phy", v24);
        if ( v14 > 0xFFFFFFFFFFFFF000LL )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: DSI_%d: Failed to parse register information, rc=%d\n",
            *(_DWORD *)(v12 + 8),
            v14);
LABEL_41:
          devm_kfree(a1 + 16);
          devm_kfree(a1 + 16);
          goto LABEL_19;
        }
        v26 = *(_QWORD *)(v12 + 16);
        *(_QWORD *)(v12 + 88) = v14;
        v27 = msm_ioremap(a1, "dyn_refresh_base", v26);
        v28 = *(_DWORD *)(v12 + 8);
        v29 = *(const void **)(v12 + 88);
        *(_QWORD *)(v12 + 104) = v27;
        *(double *)&v30 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: map dsi_phy registers to %pK\n", v28, v29);
        v31 = dsi_phy_supplies_init(a1, v12, v30);
        if ( v31 )
        {
          LODWORD(v14) = v31;
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: DSI_%d: failed to parse voltage supplies, rc = %d\n",
            *(_DWORD *)(v12 + 8),
            v31);
LABEL_40:
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: unmap registers\n", *(_DWORD *)(v12 + 8));
          goto LABEL_41;
        }
        v23 = *v8;
      }
      v32 = dsi_catalog_phy_setup(v12 + 88, v23, *(unsigned int *)(v12 + 8), v22);
      if ( v32 )
      {
        LODWORD(v14) = v32;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_%d: Catalog does not support version (%d)\n",
          *(unsigned int *)(v12 + 8),
          *v8);
LABEL_39:
        dsi_phy_supplies_deinit(v12);
        goto LABEL_40;
      }
      *(_DWORD *)(v12 + 884) = *(_DWORD *)(*(_QWORD *)(v12 + 80) + 4LL);
      LODWORD(v14) = dsi_phy_parse_dt_per_lane_cfgs(a1, v12 + 816, "qcom,platform-lane-config");
      if ( (_DWORD)v14
        || (*(_DWORD *)(v12 + 956) = *(_DWORD *)(*(_QWORD *)(v12 + 80) + 8LL),
            LODWORD(v14) = dsi_phy_parse_dt_per_lane_cfgs(a1, v12 + 888, "qcom,platform-strength-ctrl"),
            (_DWORD)v14) )
      {
LABEL_38:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_%d: failed to parse lane cfgs, rc=%d\n",
          *(_DWORD *)(v12 + 8),
          v14);
        v33 = *(unsigned int *)(v12 + 8);
        *(_DWORD *)(v12 + 884) = 0;
        *(_DWORD *)(v12 + 956) = 0;
        *(_DWORD *)(v12 + 1104) = 0;
        *(_DWORD *)(v12 + 1028) = 0;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_%d: Failed to parse phy setting, rc=%d\n",
          v33,
          (unsigned int)v14);
        goto LABEL_39;
      }
      v34 = *(_QWORD *)(v12 + 80);
      v35 = *(_DWORD *)(v34 + 12);
      *(_DWORD *)(v12 + 1104) = v35;
      if ( v35 )
      {
        LODWORD(v14) = dsi_phy_parse_dt_per_lane_cfgs(a1, v12 + 1036, "qcom,platform-regulator-settings");
        if ( (_DWORD)v14 )
          goto LABEL_38;
        v34 = *(_QWORD *)(v12 + 80);
      }
      v36 = *(_QWORD *)(a1 + 760);
      *(_DWORD *)(v12 + 1028) = *(_DWORD *)(v34 + 16);
      v37 = of_find_property(v36, "qcom,panel-allow-phy-poweroff", 0) != 0;
      v38 = *(_QWORD *)(a1 + 760);
      *(_BYTE *)(v12 + 1352) = v37;
      of_property_read_variable_u32_array(v38, "qcom,dsi-phy-regulator-min-datarate-bps", v12 + 1356, 1, 0);
      *(_BYTE *)(v12 + 1362) = of_find_property(*(_QWORD *)(a1 + 760), "qcom,dsi-phy-shared", 0) != 0;
      v39 = dsi_pll_init(a1, v12 + 1344);
      if ( v39 )
      {
        LODWORD(v14) = v39;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_%d: Failed to initialize DSI PLL, rc=%d\n",
          *(unsigned int *)(v12 + 8),
          v39);
      }
      else
      {
        v40 = dsi_catalog_phy_pll_setup(v12 + 88, *(unsigned int *)(*(_QWORD *)(v12 + 1344) + 80LL));
        if ( !v40 )
        {
          *v10 = v12;
          mutex_lock(&dsi_phy_list_lock);
          list_add(v10 + 1);
          mutex_unlock(&dsi_phy_list_lock);
          _mutex_init(v12 + 32, "&dsi_phy->phy_lock", &dsi_phy_driver_probe___key);
          v41 = *(_DWORD *)(v12 + 8);
          *(_QWORD *)v12 = a1;
          *(_QWORD *)(a1 + 168) = v12;
          drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_%d: Probe successful\n", v41);
          LODWORD(v14) = 0;
          goto LABEL_19;
        }
        LODWORD(v14) = v40;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_%d: Catalog does not support PLL version (%d)\n",
          *(unsigned int *)(v12 + 8),
          *(unsigned int *)(*(_QWORD *)(v12 + 1344) + 80LL));
      }
      dsi_phy_settings_deinit(v12);
      goto LABEL_39;
    }
    devm_kfree(a1 + 16);
    LODWORD(v14) = -12;
  }
  else
  {
    LODWORD(v14) = -12;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v14;
}
