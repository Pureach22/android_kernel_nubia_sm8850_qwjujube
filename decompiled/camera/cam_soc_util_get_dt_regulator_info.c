__int64 __fastcall cam_soc_util_get_dt_regulator_info(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 string_helper; // x0
  __int64 result; // x0
  const char *v6; // x5
  __int64 v7; // x4
  unsigned __int64 v8; // x21
  const char **v9; // x22
  unsigned int v10; // w28
  __int64 v11; // x3

  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
  {
    v6 = "Invalid parameters";
    v7 = 3465;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_regulator_info",
      v7,
      v6);
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(v1 + 744);
  *(_DWORD *)(a1 + 488) = 0;
  string_helper = of_property_read_string_helper(v2, "regulator-names", 0, 0, 0);
  if ( (_DWORD)string_helper == -22 )
  {
    result = 0;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_regulator_info",
        3482,
        "No regulators node found");
      return 0;
    }
    return result;
  }
  if ( (int)string_helper <= 0 )
  {
    v6 = "no regulators found";
    v7 = 3475;
    goto LABEL_11;
  }
  *(_DWORD *)(a1 + 488) = string_helper;
  if ( (unsigned int)string_helper > 0xA )
  {
    v6 = "Invalid regulator count:%d";
    v7 = 3488;
    goto LABEL_11;
  }
  v8 = 0;
  v9 = (const char **)(a1 + 496);
  do
  {
    if ( v8 == 11 )
    {
LABEL_35:
      __break(0x5512u);
      return cam_soc_util_get_dt_clk_info(string_helper);
    }
    string_helper = of_property_read_string_helper(v2, "regulator-names", v9, 1, (unsigned int)v8);
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      if ( v8 == 10 )
        goto LABEL_35;
      v10 = string_helper;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_dt_regulator_info",
        3496,
        "rgltr_name[%d] = %s",
        v8,
        *v9);
      string_helper = v10;
      if ( (v10 & 0x80000000) != 0 )
      {
LABEL_22:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_get_dt_regulator_info",
          3498,
          "no regulator resource at cnt=%d",
          v8);
        return 4294967277LL;
      }
    }
    else if ( (string_helper & 0x80000000) != 0 )
    {
      goto LABEL_22;
    }
    ++v8;
    ++v9;
  }
  while ( v8 < *(unsigned int *)(a1 + 488) );
  if ( of_find_property(v2, "rgltr-cntrl-support", 0) )
  {
    v11 = *(unsigned int *)(a1 + 488);
    *(_DWORD *)(a1 + 576) = 1;
    if ( (of_property_read_variable_u32_array(v2, "rgltr-min-voltage", a1 + 580, v11, 0) & 0x80000000) != 0 )
    {
      v6 = "No minimum volatage value found, rc=%d";
      v7 = 3514;
    }
    else if ( (of_property_read_variable_u32_array(v2, "rgltr-max-voltage", a1 + 620, *(unsigned int *)(a1 + 488), 0)
             & 0x80000000) != 0 )
    {
      v6 = "No maximum volatage value found, rc=%d";
      v7 = 3521;
    }
    else
    {
      if ( (of_property_read_variable_u32_array(v2, "rgltr-load-current", a1 + 660, *(unsigned int *)(a1 + 488), 0)
          & 0x80000000) == 0 )
        return 0;
      v6 = "No Load curent found rc=%d";
      v7 = 3528;
    }
    goto LABEL_11;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_get_dt_regulator_info",
      3504,
      "No regulator control parameter defined");
  *(_DWORD *)(a1 + 576) = 0;
  return 0;
}
