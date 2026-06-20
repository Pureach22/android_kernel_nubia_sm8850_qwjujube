unsigned __int64 __fastcall msm_m31_eusb2_phy_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 match_data; // x0
  unsigned __int64 result; // x0
  unsigned __int64 v7; // x23
  __int64 resource_byname; // x0
  unsigned __int64 v9; // x0
  __int64 v10; // x0
  _QWORD *v11; // x22
  unsigned __int64 v12; // x0
  __int64 v13; // x0
  int variable_u32_array; // w0
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x0
  int v18; // w0
  __int64 v19; // x0
  int v20; // w0
  const char *v21; // x1
  unsigned int v22; // w19
  const char *v23; // x1
  unsigned int v24; // w19
  unsigned int v25; // w19
  unsigned int v26; // w19

  v1 = a1 + 16;
  v3 = devm_kmalloc(a1 + 16, 576, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = v3;
  match_data = of_device_get_match_data(v1);
  *(_QWORD *)(v4 + 568) = match_data;
  if ( !match_data )
    return 4294967277LL;
  result = devm_usb_get_repeater_by_phandle(v1, "usb-repeater", 0);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  v7 = result;
  resource_byname = platform_get_resource_byname(a1, 512, "eusb2_phy_base");
  if ( !resource_byname )
  {
    v21 = "missing eusb2phy memory resource\n";
LABEL_32:
    dev_err(v1, v21);
    return 4294967277LL;
  }
  v9 = devm_ioremap_resource(v1, resource_byname);
  *(_QWORD *)(v4 + 368) = v9;
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    v22 = v9;
    dev_err(v1, "ioremap failed\n");
    return v22;
  }
  v10 = platform_get_resource_byname(a1, 512, "eud_enable_reg");
  if ( v10 )
  {
    v11 = (_QWORD *)v10;
    v12 = devm_ioremap_resource(v1, v10);
    *(_QWORD *)(v4 + 384) = v12;
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      v23 = "eud_enable_reg ioremap err:%d\n";
      goto LABEL_37;
    }
    *(_QWORD *)(v4 + 376) = *v11;
  }
  v13 = platform_get_resource_byname(a1, 512, "eud_detect_reg");
  if ( !v13 )
  {
    v21 = "missing eud_detect register address\n";
    goto LABEL_32;
  }
  v12 = devm_ioremap_resource(v1, v13);
  *(_QWORD *)(v4 + 392) = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    v23 = "eud_detect_reg ioremap err:%d\n";
LABEL_37:
    v24 = v12;
    dev_err(v1, v23);
    return v24;
  }
  result = devm_clk_get(v1, "ref_clk_src");
  *(_QWORD *)(v4 + 408) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  result = devm_clk_get_optional(v1, "ref_clk");
  *(_QWORD *)(v4 + 416) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  result = _devm_reset_control_get(v1, "phy_reset", 0, 0, 0, 1);
  *(_QWORD *)(v4 + 424) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  variable_u32_array = of_property_read_variable_u32_array(
                         *(_QWORD *)(a1 + 760),
                         "qcom,vdd-voltage-level",
                         v4 + 456,
                         0,
                         3);
  if ( variable_u32_array <= 1 )
  {
    v25 = variable_u32_array;
    dev_err(v1, "error reading qcom,vdd-voltage-level property\n");
    return v25;
  }
  v15 = devm_regulator_get(v1, "vdd");
  *(_QWORD *)(v4 + 432) = v15;
  if ( v15 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v1, "unable to get vdd supply\n");
    return *(unsigned int *)(v4 + 432);
  }
  v16 = devm_regulator_get(v1, "vdda12");
  *(_QWORD *)(v4 + 440) = v16;
  if ( v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v1, "unable to get vdda12 supply\n");
    return *(unsigned int *)(v4 + 440);
  }
  v17 = devm_regulator_get(v1, "vdd_refgen");
  *(_QWORD *)(v4 + 448) = v17;
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v1, "unable to get vdd_refgen supply\n");
    return *(unsigned int *)(v4 + 448);
  }
  v18 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), "qcom,param-override-seq", 4);
  *(_DWORD *)(v4 + 536) = v18;
  if ( v18 >= 1 )
  {
    if ( (v18 & 1) != 0 )
    {
      dev_err(v1, "invalid param_override_seq_len\n");
      return 4294967274LL;
    }
    v19 = devm_kmalloc(v1, 4LL * (unsigned int)v18, 3520);
    *(_QWORD *)(v4 + 528) = v19;
    if ( v19 )
    {
      v20 = of_property_read_variable_u32_array(
              *(_QWORD *)(a1 + 760),
              "qcom,param-override-seq",
              v19,
              0,
              *(int *)(v4 + 536));
      if ( (v20 & 1) != 0 )
      {
        v26 = v20;
        dev_err(v1, "qcom,param-override-seq read failed %d\n", v20);
        return v26;
      }
      goto LABEL_23;
    }
    return 4294967284LL;
  }
LABEL_23:
  *(_QWORD *)(v4 + 264) = msm_m31_eusb2_phy_init;
  *(_QWORD *)(v4 + 560) = v7;
  *(_QWORD *)(v4 + 312) = msm_m31_eusb2_phy_notify_connect;
  *(_QWORD *)(v4 + 320) = msm_m31_eusb2_phy_notify_disconnect;
  *(_QWORD *)(a1 + 168) = v4;
  *(_QWORD *)(v4 + 288) = msm_m31_eusb2_phy_set_power;
  *(_QWORD *)(v4 + 296) = msm_m31_eusb2_phy_set_suspend;
  *(_DWORD *)(v4 + 20) = 1;
  *(_QWORD *)v4 = v1;
  *(_QWORD *)(v4 + 8) = "M31 eUSB2";
  result = usb_add_phy_dev(v4);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(v4 + 496) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v4 + 504) = v4 + 504;
    *(_QWORD *)(v4 + 512) = v4 + 504;
    *(_QWORD *)(v4 + 520) = msm_m31_eusb2_phy_vbus_draw_work;
    msm_m31_eusb2_phy_create_debugfs(v4);
    result = *(_QWORD *)(v4 + 384);
    if ( result )
    {
      if ( (readl_relaxed() & 1) != 0 )
      {
        msm_m31_eusb2_phy_power(v4, 1);
        msm_m31_eusb2_phy_clocks(v4, 1);
        msm_m31_eusb2_repeater_reset_and_init(v4);
      }
      return 0;
    }
  }
  return result;
}
