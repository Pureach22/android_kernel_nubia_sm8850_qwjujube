__int64 __fastcall cam_soc_util_get_option_clk_by_name(__int64 a1, const char *a2, unsigned int *a3)
{
  __int64 v6; // x24
  unsigned int matched; // w0
  unsigned int v8; // w23
  __int64 result; // x0
  const char **v10; // x22
  int v11; // w0
  unsigned __int64 v12; // x26
  __int64 *v13; // x26
  __int64 v14; // x8
  int *v15; // x25
  unsigned int u32_index; // w0
  unsigned int v17; // w24
  const char *v18; // x5
  __int64 v19; // x4
  const char *v20; // x6
  __int64 v21; // x7
  int v22; // w8
  unsigned int v23; // w6
  int v24; // w8
  __int64 v25; // [xsp+18h] [xbp-88h]
  unsigned int v26; // [xsp+24h] [xbp-7Ch] BYREF
  _QWORD v27[2]; // [xsp+28h] [xbp-78h] BYREF
  _QWORD v28[2]; // [xsp+38h] [xbp-68h] BYREF
  __int64 v29; // [xsp+48h] [xbp-58h] BYREF
  __int64 v30; // [xsp+50h] [xbp-50h]
  __int64 v31; // [xsp+58h] [xbp-48h]
  __int64 v32; // [xsp+60h] [xbp-40h]
  __int64 v33; // [xsp+68h] [xbp-38h]
  __int64 v34; // [xsp+70h] [xbp-30h]
  __int64 v35; // [xsp+78h] [xbp-28h]
  __int64 v36; // [xsp+80h] [xbp-20h]
  __int64 v37; // [xsp+88h] [xbp-18h]
  __int64 v38; // [xsp+90h] [xbp-10h]
  __int64 v39; // [xsp+98h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  if ( !a1 || !a2 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_option_clk_by_name",
      2416,
      "Invalid params soc_info %pK clk_name %s clk_index %pK",
      (const void *)a1,
      a2,
      a3);
    result = 4294967274LL;
    goto LABEL_30;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 744LL);
  matched = of_property_match_string(v6, "clock-names-option", a2);
  if ( (matched & 0x80000000) != 0 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_option_clk_by_name",
        2425,
        "No clk data for %s",
        a2);
    result = 4294967274LL;
    goto LABEL_29;
  }
  v8 = matched;
  if ( matched >= 7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_option_clk_by_name",
      2432,
      "Insufficient optional clk entries %d %d",
      matched,
      7);
    result = 4294967274LL;
    goto LABEL_30;
  }
  v10 = (const char **)(a1 + 8LL * matched + 3016);
  of_property_read_string_helper(v6, "clock-names-option", v10, 1, matched);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( (debug_bypass_drivers & 4) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_soc_util_option_clk_get",
      2382,
      "Bypass option clk get");
    v13 = (__int64 *)(a1 + 8LL * v8 + 3072);
    *v13 = 3735928559LL;
  }
  else
  {
    v11 = _of_parse_phandle_with_args(v6, "clocks-option", "#clock-cells", 0xFFFFFFFFLL, v8, &v29);
    if ( v11 )
    {
      v12 = v11;
    }
    else
    {
      v28[0] = 0;
      v28[1] = 0;
      v27[0] = 0;
      v27[1] = 0;
      if ( (debug_bypass_drivers & 4) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x20000,
          2,
          "cam_wrapper_of_clk_get_from_provider",
          385,
          "Bypass of clk get from provider");
        v12 = 3735928559LL;
      }
      else
      {
        if ( clk_rgltr_bus_ops_profiling == 1 )
          ktime_get_real_ts64(v28);
        v12 = of_clk_get_from_provider(&v29);
        if ( clk_rgltr_bus_ops_profiling == 1 )
          ktime_get_real_ts64(v27);
      }
      *(_DWORD *)(a1 + 3156 + 4LL * v8) = HIDWORD(v30);
    }
    v14 = a1 + 8LL * v8;
    *(_QWORD *)(v14 + 3072) = v12;
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_get_option_clk_by_name",
        2444,
        "No clk named %s found. Dev %s",
        a2,
        *(const char **)(a1 + 24));
      result = 4294967282LL;
LABEL_29:
      *a3 = -1;
      goto LABEL_30;
    }
    v13 = (__int64 *)(v14 + 3072);
  }
  *a3 = v8;
  v15 = (int *)(a1 + 4LL * v8 + 3128);
  u32_index = of_property_read_u32_index(v6, "clock-rates-option", v8, v15);
  if ( u32_index )
  {
    v17 = u32_index;
    v18 = "Error reading clock-rates clk_name %s index %d";
    v19 = 2455;
    v20 = a2;
    v21 = v8;
LABEL_28:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_option_clk_by_name",
      v19,
      v18,
      v20,
      v21);
    cam_wrapper_clk_put(*v13);
    result = v17;
    *v15 = 0;
    *v13 = 0;
    goto LABEL_29;
  }
  v22 = *v15;
  v25 = a1 + 3156;
  if ( !*v15 )
    v22 = -2;
  *v15 = v22;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_get_option_clk_by_name",
      2468,
      "clk_name %s index %d clk_rate %d",
      a2,
      *a3,
      v22);
  if ( (unsigned int)of_property_read_u32_index(v6, "shared-clks-option", v8, &v26) )
  {
    result = 0;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_option_clk_by_name",
        2474,
        "Not shared clk  %s index %d",
        a2,
        v8);
      result = 0;
    }
  }
  else
  {
    v23 = v26;
    if ( v26 >= 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        2,
        "cam_soc_util_get_option_clk_by_name",
        2476,
        "Invalid shared clk val %d",
        v26);
      result = 0;
      goto LABEL_30;
    }
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_option_clk_by_name",
        2481,
        "Dev %s shared clk  %s index %d, clk id %d, shared_clk_val %d",
        *(const char **)(a1 + 24),
        a2,
        v8,
        *(_DWORD *)(v25 + 4LL * v8),
        v26);
      v23 = v26;
    }
    if ( !v23 )
    {
      result = 0;
      goto LABEL_30;
    }
    v24 = debug_mdl;
    *(_DWORD *)(a1 + 3184) |= 1 << v8;
    if ( (v24 & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v24 & 0x20000LL,
        4,
        "cam_soc_util_get_option_clk_by_name",
        2491,
        "Dev %s, clk %s, id %d register wrapper entry for shared clk",
        *(const char **)(a1 + 24),
        *v10,
        *(_DWORD *)(v25 + 4LL * v8));
    result = cam_soc_util_clk_wrapper_register_entry(*(unsigned int *)(v25 + 4LL * v8), *v13, 0, a1, *v15, *v10);
    if ( (_DWORD)result )
    {
      v20 = *(const char **)(a1 + 24);
      v21 = *(unsigned int *)(v25 + 4LL * v8);
      v17 = result;
      v18 = "Failed in registering shared clk Dev %s id %d";
      v19 = 2503;
      goto LABEL_28;
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
