__int64 __fastcall cam_soc_util_request_pinctrl(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  unsigned __int64 v4; // x0
  int v5; // w0
  unsigned int v6; // w20
  int string_helper; // w0
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v10; // x6
  unsigned int v11; // w28
  unsigned int v13; // w22
  __int64 v14; // x26
  unsigned int v15; // w0
  unsigned __int64 v16; // x0
  __int64 v17; // x1
  unsigned int v18; // [xsp+Ch] [xbp-84h] BYREF
  const char *v19; // [xsp+10h] [xbp-80h] BYREF
  _QWORD v20[6]; // [xsp+18h] [xbp-78h] BYREF
  __int16 v21; // [xsp+48h] [xbp-48h]
  char s[8]; // [xsp+50h] [xbp-40h] BYREF
  __int64 v23; // [xsp+58h] [xbp-38h]
  __int64 v24; // [xsp+60h] [xbp-30h]
  __int64 v25; // [xsp+68h] [xbp-28h]
  __int64 v26; // [xsp+70h] [xbp-20h]
  __int64 v27; // [xsp+78h] [xbp-18h]
  __int16 v28; // [xsp+80h] [xbp-10h]
  __int64 v29; // [xsp+88h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v19 = nullptr;
  memset(v20, 0, sizeof(v20));
  v18 = 0;
  v3 = *(_QWORD *)(v2 + 744);
  v28 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  *(_QWORD *)s = 0;
  v23 = 0;
  v21 = 0;
  v4 = devm_pinctrl_get();
  *(_QWORD *)(a1 + 3216) = v4;
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_request_pinctrl",
        4036,
        "Pinctrl not available");
    v11 = 0;
    *(_QWORD *)(a1 + 3216) = 0;
    goto LABEL_18;
  }
  v5 = of_property_count_elems_of_size(v3, "pctrl-idx-mapping", 4);
  if ( v5 <= 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_pinctrl",
      4045,
      "Reading pctrl-idx-mapping failed");
LABEL_17:
    v11 = -22;
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return v11;
  }
  v6 = v5;
  string_helper = of_property_read_string_helper(v3, "pctrl-map-names", 0, 0, 0);
  if ( string_helper <= 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_pinctrl",
      4053,
      "no pinctrl-mapping found for: %s",
      *(const char **)(a1 + 24));
LABEL_16:
    *(_QWORD *)(a1 + 3216) = 0;
    goto LABEL_17;
  }
  if ( v6 != string_helper )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_pinctrl",
      4061,
      "Incorrect inputs mapping-idx count: %d mapping-names: %d",
      v6,
      string_helper);
    goto LABEL_16;
  }
  if ( v6 > 2 )
  {
    v8 = "Invalid mapping %u max supported: %d";
    v9 = 4068;
    v10 = v6;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_request_pinctrl",
      v9,
      v8,
      v10,
      2);
    goto LABEL_17;
  }
  v13 = 0;
  v14 = a1 + 3224;
  while ( 1 )
  {
    of_property_read_u32_index(v3, "pctrl-idx-mapping", v13, &v18);
    v10 = v18;
    if ( v18 >= 2 )
    {
      v8 = "Invalid Index: %d max supported: %d";
      v9 = 4078;
      goto LABEL_8;
    }
    v15 = of_property_read_string_helper(v3, "pctrl-map-names", &v19, 1, v13);
    if ( (v15 & 0x80000000) != 0 )
    {
      v11 = v15;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_request_pinctrl",
        4086,
        "failed to read pinctrl-mapping at %d",
        v13);
      goto LABEL_18;
    }
    snprintf(s, 0x32u, "%s%s", v19, "_active");
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_request_pinctrl",
        4093,
        "pctrl_active at index: %d name: %s",
        v13,
        s);
    snprintf((char *)v20, 0x32u, "%s%s", v19, "_suspend");
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_request_pinctrl",
        4097,
        "pctrl_suspend at index: %d name: %s",
        v13,
        (const char *)v20);
    v16 = pinctrl_lookup_state(*(_QWORD *)(a1 + 3216), s);
    if ( v18 >= 2 )
      break;
    *(_QWORD *)(v14 + 24LL * v18) = v16;
    if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
    {
      v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_request_pinctrl",
              4105,
              "Failed to get the active state pinctrl handle");
      if ( v18 <= 1 )
      {
        v11 = -22;
        *(_QWORD *)(v14 + 24LL * v18) = 0;
        goto LABEL_18;
      }
      break;
    }
    v16 = pinctrl_lookup_state(*(_QWORD *)(a1 + 3216), v20);
    if ( v18 > 1 )
      break;
    *(_QWORD *)(v14 + 24LL * v18 + 8) = v16;
    if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
    {
      v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x20000,
              1,
              "cam_soc_util_request_pinctrl",
              4116,
              "Failed to get the active state pinctrl handle");
      if ( v18 <= 1 )
      {
        v11 = -22;
        *(_QWORD *)(v14 + 24LL * v18 + 8) = 0;
        goto LABEL_18;
      }
      break;
    }
    ++v13;
    v11 = 0;
    if ( v6 == v13 )
      goto LABEL_18;
  }
  __break(0x5512u);
  return cam_soc_util_request_gpio_table(v16, v17);
}
