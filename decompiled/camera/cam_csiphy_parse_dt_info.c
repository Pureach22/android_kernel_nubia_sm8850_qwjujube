__int64 __fastcall cam_csiphy_parse_dt_info(__int64 a1, __int64 a2)
{
  unsigned int dt_properties; // w0
  bool v4; // w8
  unsigned int v5; // w20
  const char *v6; // x5
  __int64 v7; // x4
  __int64 v8; // x10
  int v9; // w8
  _UNKNOWN **v10; // x9
  unsigned int v11; // w6
  __int64 v12; // x20
  __int64 v13; // x26
  const char *v14; // x25
  size_t v15; // x0
  __int16 v16; // w8
  int v17; // w8
  unsigned int drv_enable; // w0
  int v20; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-18h] BYREF
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v22 = 0;
  dt_properties = cam_soc_util_get_dt_properties(a2 + 912);
  if ( (dt_properties & 0x80000000) != 0 )
  {
    v5 = dt_properties;
    v6 = "parsing common soc dt(rc %d)";
    v7 = 312;
    goto LABEL_41;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "rgltr-enable-sync", &v20, 1, 0)
      & 0x80000000) != 0 )
  {
    v4 = 0;
    v20 = 0;
  }
  else
  {
    v4 = v20 != 0;
  }
  v8 = *(_QWORD *)(a2 + 920);
  *(_BYTE *)(a2 + 4728) = v4;
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v8 + 744), "qcom,csiphy-v2.1.0") )
  {
    v9 = 528;
    v10 = &ctrl_reg_2_1_0;
  }
  else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "qcom,csiphy-v2.1.1") )
  {
    v9 = 529;
    v10 = &ctrl_reg_2_1_1;
  }
  else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "qcom,csiphy-v2.1.2") )
  {
    v9 = 530;
    v10 = &ctrl_reg_2_1_2;
  }
  else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "qcom,csiphy-v2.1.3") )
  {
    v9 = 531;
    v10 = &ctrl_reg_2_1_3;
  }
  else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "qcom,csiphy-v2.2.0") )
  {
    v9 = 544;
    v10 = &ctrl_reg_2_2_0;
  }
  else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "qcom,csiphy-v2.2.1") )
  {
    v9 = 545;
    v10 = &ctrl_reg_2_2_1;
  }
  else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "qcom,csiphy-v2.3.0") )
  {
    v9 = 560;
    v10 = &ctrl_reg_2_3_0;
  }
  else
  {
    if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a2 + 920) + 744LL), "qcom,csiphy-v2.4.0") )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_parse_dt_info",
        366,
        "invalid hw version : 0x%x",
        *(_DWORD *)(a2 + 72));
      v5 = -22;
      goto LABEL_42;
    }
    v9 = 576;
    v10 = &ctrl_reg_2_4_0;
  }
  v11 = *(_DWORD *)(a2 + 1780);
  *(_QWORD *)(a2 + 112) = v10;
  *(_BYTE *)(a2 + 101) = 1;
  *(_DWORD *)(a2 + 72) = v9;
  *(_DWORD *)(a2 + 76) = 0;
  if ( v11 <= 0x10 )
  {
    if ( v11 )
    {
      v12 = 0;
      v13 = a2 + 1784;
      while ( 1 )
      {
        if ( v12 == 32 )
          goto LABEL_45;
        v14 = *(const char **)(v13 + 8 * v12);
        if ( strcmp(v14, "cphy_rx_clk_src") )
          break;
        *(_BYTE *)(a2 + 99) = v12;
        v16 = debug_mdl;
        if ( (debug_mdl & 0x8000) != 0 )
          goto LABEL_34;
LABEL_26:
        if ( ++v12 >= (unsigned __int64)*(unsigned int *)(a2 + 1780) )
          goto LABEL_36;
      }
      v15 = strlen(v14);
      if ( strnstr(v14, "phytimer_clk_src", v15) )
        *(_BYTE *)(a2 + 100) = v12;
      v16 = debug_mdl;
      if ( (debug_mdl & 0x8000) == 0 )
        goto LABEL_26;
LABEL_34:
      if ( !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v16 & 0x8000,
          4,
          "cam_csiphy_parse_dt_info",
          388,
          "PHY:%d clk_rate[0][%d] = %d",
          *(_DWORD *)(a2 + 932),
          v12,
          *(_DWORD *)(v13 + 4 * v12 + 512));
      goto LABEL_26;
    }
LABEL_36:
    v17 = *(_DWORD *)(a2 + 1016);
    if ( v17 )
    {
      v21 = a2;
      if ( v17 != 1 )
      {
        v22 = a2;
        if ( v17 != 2 )
LABEL_45:
          __break(0x5512u);
      }
    }
    drv_enable = cam_cpas_query_drv_enable(0, a2 + 4112);
    if ( !drv_enable )
    {
      v5 = cam_soc_util_request_platform_resource(a2 + 912, (__int64)cam_csiphy_irq, &v21);
      goto LABEL_42;
    }
    v5 = drv_enable;
    v6 = "Failed to query DRV enable rc:%d";
    v7 = 396;
LABEL_41:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_parse_dt_info",
      v7,
      v6,
      v5);
    goto LABEL_42;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_parse_dt_info",
    373,
    "invalid clk count=%d, max is %d",
    v11,
    16);
  v5 = -22;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v5;
}
