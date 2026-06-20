__int64 __fastcall cam_soc_util_get_dt_properties(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x19
  unsigned int variable_u32_array; // w0
  int string_helper; // w0
  unsigned __int64 v6; // x21
  unsigned int *v7; // x24
  const char **v8; // x22
  unsigned int v9; // w0
  __int64 resource_byname; // x0
  __int64 result; // x0
  unsigned int v12; // w19
  int string; // w0
  __int64 v14; // x3
  unsigned int v15; // w0
  int v16; // w0
  int irq; // w0

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(v1 + 744);
  variable_u32_array = of_property_read_variable_u32_array(v3, "cell-index", a1 + 20, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v12 = variable_u32_array;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_properties",
      3719,
      "device %s failed to read cell-index",
      *(const char **)(a1 + 24));
    return v12;
  }
  string_helper = of_property_read_string_helper(v3, "reg-names", 0, 0, 0);
  if ( string_helper <= 0 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_properties",
        3726,
        "no reg-names found for: %s",
        *(const char **)(a1 + 24));
    LODWORD(v6) = 0;
    *(_DWORD *)(a1 + 120) = 0;
    v7 = (unsigned int *)(a1 + 120);
LABEL_17:
    string = of_property_read_string(v3, "label", a1 + 56);
    if ( string && (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_properties",
        3752,
        "Label is not available in the node: %d",
        string);
      v14 = *v7;
      if ( (_DWORD)v14 )
      {
LABEL_21:
        v15 = of_property_read_variable_u32_array(v3, "reg-cam-base", a1 + 192, v14, 0);
        if ( (v15 & 0x80000000) != 0 )
        {
          v12 = v15;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x20000,
            1,
            "cam_soc_util_get_dt_properties",
            3758,
            "Error reading register offsets");
          return v12;
        }
      }
    }
    else
    {
      v14 = *v7;
      if ( (_DWORD)v14 )
        goto LABEL_21;
    }
    v16 = of_property_read_string_helper(v3, "interrupt-names", 0, 0, 0);
    if ( v16 <= 0 )
    {
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_get_dt_properties",
          3765,
          "No interrupt line present for: %s",
          *(const char **)(a1 + 24));
      *(_DWORD *)(a1 + 104) = 0;
LABEL_37:
      if ( (of_property_read_string_helper(v3, "compatible", a1 + 112, 1, 0) & 0x80000000) != 0
        && (debug_mdl & 0x20000) != 0
        && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_get_dt_properties",
          3805,
          "No compatible string present for: %s",
          *(const char **)(a1 + 24));
      }
      *(_BYTE *)(a1 + 32) = 0;
      if ( of_find_property(v3, "nrt-device", 0) )
        *(_BYTE *)(a1 + 32) = 1;
      *(_BYTE *)(a1 + 3201) = 0;
      if ( of_find_property(v3, "cam-crmb-clk", 0) )
        *(_BYTE *)(a1 + 3201) = 1;
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_get_dt_properties",
          3816,
          "Dev %s, nrt_dev: %d is_crmb_clk: %d",
          *(const char **)(a1 + 24),
          *(unsigned __int8 *)(a1 + 32),
          *(unsigned __int8 *)(a1 + 3201));
      result = cam_soc_util_get_dt_power_domain_info(a1);
      if ( !(_DWORD)result )
      {
        result = cam_soc_util_get_dt_regulator_info(a1);
        if ( !(_DWORD)result )
        {
          result = cam_soc_util_get_dt_clk_info(a1);
          if ( !(_DWORD)result )
          {
            result = cam_soc_util_get_gpio_info(a1);
            if ( !(_DWORD)result )
            {
              of_find_property(v3, "qcom,cam-cx-ipeak", 0);
              return 0;
            }
          }
        }
      }
      return result;
    }
    if ( (unsigned int)v16 >= 3 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_get_dt_properties",
        3771,
        "Number of interrupt: %d exceeds maximum allowable interrupts: %d",
        v16,
        2);
      return 4294967274LL;
    }
    *(_DWORD *)(a1 + 104) = v16;
    irq = cam_compat_util_get_irq(a1);
    if ( irq == 22 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_get_dt_properties",
        3779,
        "failed to read interrupt name at %d",
        v6);
      return 22;
    }
    if ( (irq & 0x80000000) == 0 )
      goto LABEL_37;
    v12 = irq;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_properties",
      3784,
      "get irq resource failed: %d for: %s",
      irq,
      *(const char **)(a1 + 24));
    return v12;
  }
  v6 = 0;
  *(_DWORD *)(a1 + 120) = string_helper;
  v7 = (unsigned int *)(a1 + 120);
  v8 = (const char **)(a1 + 128);
  while ( 1 )
  {
    v9 = of_property_read_string_helper(v3, "reg-names", v8, 1, (unsigned int)v6);
    if ( (v9 & 0x80000000) != 0 )
    {
      v12 = v9;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_get_dt_properties",
        3735,
        "failed to read reg-names at %d",
        v6);
      return v12;
    }
    if ( v6 == 8 )
      break;
    resource_byname = platform_get_resource_byname(*(_QWORD *)a1, 512, *v8);
    v8[12] = (const char *)resource_byname;
    if ( !resource_byname )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_get_dt_properties",
        3744,
        "no mem resource by name %s",
        *v8);
      return 4294967277LL;
    }
    ++v6;
    ++v8;
    if ( v6 >= *v7 )
      goto LABEL_17;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))cam_soc_util_get_dt_power_domain_info)();
}
