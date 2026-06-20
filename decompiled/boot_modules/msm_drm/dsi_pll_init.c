__int64 __fastcall dsi_pll_init(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  const char *property; // x22
  int v7; // w3
  unsigned int *v8; // x21
  int v9; // w8
  __int64 v10; // x9
  __int64 v11; // x0
  int variable_u32_array; // w0
  __int64 v13; // x0
  int v14; // w0
  __int64 v15; // x8
  const char *v16; // x0
  __int64 v17; // x0
  int v18; // w8
  bool v19; // zf
  char v20; // w9
  __int64 v21; // x0
  __int64 v23; // x0
  int v24; // w0

  if ( !*(_QWORD *)(a1 + 760) )
  {
    printk(&unk_217323, "dsi_pll_init");
    LODWORD(property) = -524;
    return (unsigned int)property;
  }
  v4 = devm_kmalloc(a1 + 16, 192, 3520);
  if ( !v4 )
    goto LABEL_34;
  *a2 = v4;
  v5 = v4;
  property = (const char *)of_get_property(*(_QWORD *)(a1 + 760), "pll-label", 0);
  v8 = (unsigned int *)(v5 + 100);
  v7 = *(_DWORD *)(v5 + 100);
  if ( !property )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: DSI pll label not specified\n", v7);
    return (unsigned int)property;
  }
  drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_PLL_%d: DSI pll label = %s\n", v7, property);
  if ( !strcmp(property, "dsi_pll_3nm") )
  {
    v9 = 0;
LABEL_15:
    v10 = 80;
    goto LABEL_16;
  }
  if ( !strcmp(property, "dsi_pll_3nm_hfi") )
  {
    v9 = 1;
    v10 = 160;
    *(_DWORD *)(v5 + 80) = 1;
LABEL_16:
    v11 = *(_QWORD *)(a1 + 760);
    *(_DWORD *)(v5 + v10) = v9;
    variable_u32_array = of_property_read_variable_u32_array(v11, "cell-index", v5 + 100, 1, 0);
    LODWORD(property) = variable_u32_array & (variable_u32_array >> 31);
    if ( variable_u32_array < 0 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_PLL_%d: Unable to get the cell-index rc=%d\n",
        *v8,
        (_DWORD)property);
      *v8 = 0;
    }
    v13 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,dsi-pll-ssc-en", 0);
    *(_BYTE *)(v5 + 104) = v13 != 0;
    if ( v13 )
    {
      drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: DSI_PLL_%d: PLL SSC enabled\n", *(_DWORD *)(v5 + 100));
      of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,ssc-frequency-hz", v5 + 108, 1, 0);
      v14 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,ssc-ppm", v5 + 112, 1, 0);
      v15 = *(_QWORD *)(a1 + 760);
      LODWORD(property) = v14 & (v14 >> 31);
      *(_BYTE *)(v5 + 105) = 0;
      v16 = (const char *)of_get_property(v15, "qcom,dsi-pll-ssc-mode", 0);
      if ( v16 )
      {
        if ( !strcmp(v16, "center-spread") )
          *(_BYTE *)(v5 + 105) = 1;
      }
    }
    v17 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,dsi-phy-pll-bypass", 0);
    v18 = *(_DWORD *)(v5 + 160);
    v19 = v18 != 1 && v17 == 0;
    v20 = !v19;
    *(_BYTE *)(v5 + 172) = v20;
    if ( !v19 )
    {
LABEL_29:
      LODWORD(property) = 0;
      return (unsigned int)property;
    }
    if ( v18 )
      return (unsigned int)property;
    if ( !platform_get_resource_byname(a1, 512, "pll_base") || (v21 = devm_ioremap(a1 + 16), (*(_QWORD *)v5 = v21) != 0) )
    {
      printk(&unk_24A875, "dsi_pll_init");
      if ( (unsigned int)dsi_pll_get_ioresources(a1, v5 + 8, "dsi_phy") )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_PLL_%d: Unable to remap pll phy base resources\n",
          *v8);
      }
      else
      {
        if ( !(unsigned int)dsi_pll_get_ioresources(a1, v5 + 24, "dyn_refresh_base") )
        {
          if ( (unsigned int)dsi_pll_get_ioresources(a1, v5 + 16, "gdsc_base") )
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: Unable to remap gdsc base resources\n", *v8);
          v23 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,dsi-pll-in-trusted-vm", 0);
          *(_BYTE *)(v5 + 180) = v23 != 0;
          if ( v23 )
          {
            drm_dev_printk(
              0,
              &unk_2597DF,
              "[msm-dsi-info]: DSI_PLL_%d: Bypassing PLL clock register for Trusted VM\n",
              *v8);
            return (unsigned int)property;
          }
          v24 = dsi_pll_clock_register(a1, v5);
          if ( v24 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: DSI_PLL_%d: clock register failed rc=%d\n",
              *v8,
              v24);
            LODWORD(property) = -22;
            return (unsigned int)property;
          }
          goto LABEL_29;
        }
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_PLL_%d: Unable to remap dynamic pll base resources\n",
          *v8);
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: Unable to remap pll base resources\n", *v8);
    }
LABEL_34:
    LODWORD(property) = -12;
    return (unsigned int)property;
  }
  if ( !strcmp(property, "dsi_pll_4nm") )
  {
    v9 = 2;
    goto LABEL_15;
  }
  if ( !strcmp(property, "dsi_pll_5nm") )
  {
    v9 = 3;
    goto LABEL_15;
  }
  LODWORD(property) = -524;
  return (unsigned int)property;
}
