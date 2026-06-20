__int64 __fastcall cam_res_mgr_component_bind(__int64 a1)
{
  __int64 v2; // x23
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  int v6; // w0
  unsigned int v7; // w22
  int v8; // w8
  __int64 v9; // x1
  __int64 v10; // x20
  __int64 v11; // x22
  int v12; // w0
  __int64 v13; // x8
  int v14; // w9
  int v15; // w11
  unsigned int string_helper; // w0
  int v17; // w6
  __int64 v18; // x21
  __int64 v19; // x28
  __int64 v20; // x27
  unsigned int v21; // w0
  unsigned __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x24
  __int64 v25; // x20
  unsigned __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  unsigned __int64 v29; // x9
  __int64 v30; // x9
  const char *v31; // x5
  __int64 v32; // x4
  __int64 v33; // x6
  int v34; // w10
  _QWORD *v35; // x8
  const char *v37; // x5
  __int64 v38; // x4
  unsigned __int64 StatusReg; // x21
  __int64 v40; // x22
  _QWORD v41[2]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v42[2]; // [xsp+18h] [xbp-88h] BYREF
  char v43[8]; // [xsp+28h] [xbp-78h] BYREF
  __int64 v44; // [xsp+30h] [xbp-70h]
  __int64 v45; // [xsp+38h] [xbp-68h]
  __int64 v46; // [xsp+40h] [xbp-60h]
  __int64 v47; // [xsp+48h] [xbp-58h]
  __int64 v48; // [xsp+50h] [xbp-50h]
  __int16 v49; // [xsp+58h] [xbp-48h]
  char s[8]; // [xsp+60h] [xbp-40h] BYREF
  __int64 v51; // [xsp+68h] [xbp-38h]
  __int64 v52; // [xsp+70h] [xbp-30h]
  __int64 v53; // [xsp+78h] [xbp-28h]
  __int64 v54; // [xsp+80h] [xbp-20h]
  __int64 v55; // [xsp+88h] [xbp-18h]
  __int16 v56; // [xsp+90h] [xbp-10h]
  __int64 v57; // [xsp+98h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42[0] = 0;
  v42[1] = 0;
  v41[0] = 0;
  v41[1] = 0;
  ktime_get_real_ts64(v42);
  v2 = (__int64)&unk_2FD000;
  if ( mem_trace_en == 1 )
    v3 = cam_mem_trace_alloc(584, 0xCC0u, 0, "cam_res_mgr_component_bind", 0x386u);
  else
    v3 = _kvmalloc_node_noprof(584, 0, 3520, 0xFFFFFFFFLL);
  v4 = v3;
  while ( 1 )
  {
    cam_res = v4;
    if ( !v4 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x200000,
        1,
        "cam_res_mgr_component_bind",
        904,
        "Not Enough Mem");
      v7 = -12;
      goto LABEL_72;
    }
    *(_QWORD *)v4 = a1;
    if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200000,
        4,
        "cam_res_mgr_component_bind",
        909,
        "ENTER");
      v4 = cam_res;
    }
    v5 = *(_QWORD *)(a1 + 744);
    v6 = of_property_count_elems_of_size(v5, "gpios-shared", 4);
    *(_DWORD *)(v4 + 112) = v6;
    if ( v6 <= 0 )
    {
      v8 = debug_priority;
      v9 = debug_mdl & 0x200000;
      if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v9,
          4,
          "cam_res_mgr_parse_dt_shared_gpio",
          770,
          "Not found any shared gpio");
        v8 = debug_priority;
        v9 = debug_mdl & 0x200000;
        if ( (debug_mdl & 0x200000) == 0 )
          goto LABEL_19;
      }
      else if ( !v9 )
      {
        goto LABEL_19;
      }
      if ( !v8 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v9,
          4,
          "cam_res_mgr_parse_dt",
          863,
          "Shared GPIO resources not available");
    }
    else
    {
      if ( (unsigned int)v6 >= 0x10 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000,
          1,
          "cam_res_mgr_parse_dt_shared_gpio",
          778,
          "shared_gpio: %d max supported: %d",
          16,
          v6);
LABEL_55:
        v31 = "Shared gpio parsing failed: rc: %d";
        v32 = 866;
        v33 = 4294967274LL;
        v7 = -22;
        goto LABEL_68;
      }
      if ( (of_property_read_variable_u32_array(v5, "gpios-shared", v4 + 8, (unsigned int)v6, 0) & 0x80000000) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x200000,
          1,
          "cam_res_mgr_parse_dt_shared_gpio",
          785,
          "Get shared gpio array failed.");
        goto LABEL_55;
      }
    }
LABEL_19:
    v10 = *(_QWORD *)(a1 + 744);
    v11 = cam_res;
    v12 = of_property_count_elems_of_size(v10, "gpios-shared-pinctrl", 4);
    *(_DWORD *)(v11 + 116) = v12;
    if ( v12 <= 0 )
      break;
    if ( (unsigned int)v12 >= 0xA )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000,
        1,
        "cam_res_mgr_parse_dt_shared_pinctrl_gpio",
        813,
        "Invalid Pinctrl GPIO number %d. No shared gpio.",
        v12);
LABEL_66:
      v7 = -22;
LABEL_67:
      v31 = "Pinctrl parsing failed: rc: %d";
      v32 = 878;
      v33 = v7;
LABEL_68:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x200000,
        1,
        "cam_res_mgr_parse_dt",
        v32,
        v31,
        v33);
LABEL_69:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000,
        1,
        "cam_res_mgr_component_bind",
        913,
        "Error in parsing device tree, rc: %d",
        v7);
      if ( *(_BYTE *)(v2 + 2904) == 1 )
        cam_mem_trace_free((_QWORD *)cam_res, 0);
      else
        kvfree(cam_res);
      goto LABEL_72;
    }
    string_helper = of_property_read_string_helper(v10, "shared-pctrl-gpio-names", 0, 0, 0);
    v17 = *(_DWORD *)(v11 + 116);
    v18 = string_helper;
    if ( string_helper != v17 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000,
        1,
        "cam_res_mgr_parse_dt_shared_pinctrl_gpio",
        824,
        "Mismatch between entries:: pctrl_gpio: %d and pctrl_name: %d",
        v17,
        string_helper);
      goto LABEL_66;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000,
      3,
      "cam_res_mgr_parse_dt_shared_pinctrl_gpio",
      829,
      "number of pctrl_gpio: %d",
      string_helper);
    if ( (of_property_read_variable_u32_array(v10, "gpios-shared-pinctrl", v11 + 72, *(int *)(v11 + 116), 0) & 0x80000000) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x200000,
        1,
        "cam_res_mgr_parse_dt_shared_pinctrl_gpio",
        834,
        "Get shared pinctrl gpio array failed.");
      goto LABEL_66;
    }
    if ( (int)v18 < 1 )
    {
LABEL_37:
      v56 = 0;
      v2 = cam_res;
      v54 = 0;
      v55 = 0;
      v52 = 0;
      v53 = 0;
      *(_QWORD *)s = 0;
      v51 = 0;
      v49 = 0;
      v47 = 0;
      v48 = 0;
      v45 = 0;
      v46 = 0;
      *(_QWORD *)v43 = 0;
      v44 = 0;
      v22 = devm_pinctrl_get(a1);
      v23 = cam_res;
      *(_QWORD *)(cam_res + 208) = v22;
      if ( !v22 || v22 > 0xFFFFFFFFFFFFF000LL )
      {
        v37 = "Pinctrl not available";
        v38 = 716;
LABEL_77:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x200000,
          1,
          "cam_res_mgr_shared_pinctrl_init",
          v38,
          v37);
        v7 = -22;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000,
          1,
          "cam_res_mgr_parse_dt",
          885,
          "Pinctrl init failed rc: %d",
          -22);
        v2 = (__int64)&unk_2FD000;
        goto LABEL_69;
      }
      if ( *(int *)(v2 + 116) < 1 )
      {
LABEL_80:
        *(_DWORD *)(v23 + 204) = 0;
        goto LABEL_28;
      }
      v24 = 0;
      v25 = 0;
      while ( v25 != 10 )
      {
        snprintf(s, 0x32u, "%s%s", *(const char **)(v23 + 8 * v25 + 120), "_active");
        if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000,
            4,
            "cam_res_mgr_shared_pinctrl_init",
            726,
            "pctrl_active at index: %d name: %s",
            v25,
            s);
        snprintf(v43, 0x32u, "%s%s", *(const char **)(cam_res + 8 * v25 + 120), "_suspend");
        if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000,
            4,
            "cam_res_mgr_shared_pinctrl_init",
            732,
            "pctrl_suspend at index: %d name: %s",
            v25,
            v43);
        v26 = pinctrl_lookup_state(*(_QWORD *)(cam_res + 208), s);
        v27 = cam_res;
        *(_QWORD *)(cam_res + v24 + 216) = v26;
        if ( !v26 || v26 >= 0xFFFFFFFFFFFFF001LL )
        {
          v37 = "Failed to get the active state pinctrl handle";
          v38 = 738;
          goto LABEL_77;
        }
        v28 = pinctrl_lookup_state(*(_QWORD *)(v27 + 208), v43);
        v23 = cam_res;
        v29 = *(_QWORD *)(cam_res + v24 + 216);
        *(_QWORD *)(cam_res + v24 + 224) = v28;
        if ( !v29 || v29 >= 0xFFFFFFFFFFFFF001LL )
        {
          v37 = "Failed to get the active state pinctrl handle";
          v38 = 746;
          goto LABEL_77;
        }
        v30 = v23 + v24;
        ++v25;
        v24 += 24;
        *(_DWORD *)(v30 + 232) = 0;
        if ( v25 >= *(int *)(v2 + 116) )
          goto LABEL_80;
      }
    }
    else
    {
      v19 = 0;
      v2 = 0;
      v20 = v11 + 120;
      while ( 1 )
      {
        v21 = of_property_read_string_helper(v10, "shared-pctrl-gpio-names", v20 + v19, 1, (unsigned int)v2);
        if ( v2 == 10 )
          break;
        v7 = v21;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000,
          3,
          "cam_res_mgr_parse_dt_shared_pinctrl_gpio",
          843,
          "shared-pctrl-gpio-names[%d] = %s",
          v2,
          *(const char **)(v20 + 8 * v2));
        if ( (v7 & 0x80000000) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x200000,
            1,
            "cam_res_mgr_parse_dt_shared_pinctrl_gpio",
            847,
            "i= %d pinctrl_name_nodes= %d reading clock-names failed",
            v2,
            v18);
          v2 = (__int64)&unk_2FD000;
          if ( v7 == -19 )
            goto LABEL_25;
          goto LABEL_67;
        }
        ++v2;
        v19 += 8;
        if ( v18 == v2 )
          goto LABEL_37;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v40 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_res_mgr_component_bind__alloc_tag;
    v4 = _kvmalloc_node_noprof(584, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v40;
  }
  if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000,
      4,
      "cam_res_mgr_parse_dt_shared_pinctrl_gpio",
      806,
      "Not found any shared pinctrl res");
LABEL_25:
  if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000,
      4,
      "cam_res_mgr_parse_dt",
      875,
      "Pinctrl shared resources not available");
LABEL_28:
  v13 = cam_res;
  if ( *(_DWORD *)(cam_res + 112) )
  {
    v14 = debug_mdl;
    v15 = debug_priority;
    goto LABEL_58;
  }
  v34 = *(_DWORD *)(cam_res + 116);
  v14 = debug_mdl;
  v15 = debug_priority;
  if ( v34 )
  {
LABEL_58:
    LOBYTE(v34) = 1;
    if ( (v14 & 0x200000) != 0 && !v15 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        *(_QWORD *)&v14 & 0x200000LL,
        4,
        "cam_res_mgr_component_bind",
        919,
        "Enable shared gpio support.");
      v13 = cam_res;
      LOBYTE(v34) = 1;
    }
  }
  else if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000,
      4,
      "cam_res_mgr_component_bind",
      922,
      "Disable shared gpio support.");
    v13 = cam_res;
    LOBYTE(v34) = 0;
  }
  *(_BYTE *)(v13 + 200) = v34;
  _mutex_init(v13 + 536, "&cam_res->flash_res_lock", &cam_res_mgr_component_bind___key);
  _mutex_init(cam_res + 488, "&cam_res->gpio_res_lock", &cam_res_mgr_component_bind___key_36);
  v35 = (_QWORD *)cam_res;
  *(_QWORD *)(cam_res + 456) = cam_res + 456;
  v35[58] = v35 + 57;
  v35[59] = v35 + 59;
  v35[60] = v35 + 59;
  if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000,
      4,
      "cam_res_mgr_component_bind",
      932,
      "Component bound successfully");
  ktime_get_real_ts64(v41);
  cam_record_bind_latency();
  v7 = 0;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return v7;
}
