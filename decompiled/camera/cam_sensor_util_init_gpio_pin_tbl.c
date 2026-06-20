__int64 __fastcall cam_sensor_util_init_gpio_pin_tbl(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x22
  unsigned int v4; // w23
  __int64 v5; // x20
  __int64 v7; // x0
  const char *v8; // x5
  __int64 v9; // x4
  __int64 result; // x0
  __int64 v11; // x19
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int v15; // w0
  int v16; // w0
  int v17; // w0
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w8
  int v23; // w8
  int v24; // w8
  int v25; // w6
  const char *v26; // x5
  __int64 v27; // x4
  const char *v28; // x5
  __int64 v29; // x4
  int v30; // w8
  int v31; // w8
  unsigned int v32; // w20
  int v33; // w8
  int v34; // w8
  int v35; // w8
  int v36; // w8
  int v37; // w8
  unsigned int v38; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v38 = 0;
  if ( !v2 )
  {
    v8 = "device node NULL";
    v9 = 1849;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_init_gpio_pin_tbl",
      v9,
      v8);
    result = 4294967274LL;
    goto LABEL_12;
  }
  v3 = *(_QWORD *)(a1 + 3208);
  if ( !v3 )
  {
    v8 = "No gpio_common_table is found";
    v9 = 1857;
    goto LABEL_11;
  }
  if ( !*(_QWORD *)v3 )
  {
    v8 = "gpio_common_table is not initialized";
    v9 = 1862;
    goto LABEL_11;
  }
  v4 = *(unsigned __int8 *)(v3 + 8);
  if ( !*(_BYTE *)(v3 + 8) )
  {
    v8 = "invalid size of gpio table";
    v9 = 1869;
    goto LABEL_11;
  }
  v5 = *(_QWORD *)(v2 + 744);
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(42, 0xCC0u, 0, "cam_sensor_util_init_gpio_pin_tbl", 0x752u);
  else
    v7 = _kvmalloc_node_noprof(42, 0, 3520, 0xFFFFFFFFLL);
  v11 = v7;
  *a2 = v7;
  if ( !v7 )
  {
    result = 4294967284LL;
    goto LABEL_12;
  }
  v12 = of_property_read_variable_u32_array(v5, "gpio-vana", &v38, 1, 0);
  if ( v12 != -22 )
  {
    if ( v12 < 0 )
    {
      v25 = v12 & (v12 >> 31);
      v26 = "read gpio-vana failed rc %d";
      v27 = 1882;
      goto LABEL_95;
    }
    if ( v38 >= v4 )
    {
      v28 = "gpio-vana invalid %d";
      v29 = 1885;
      goto LABEL_97;
    }
    v22 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
    *(_BYTE *)(v11 + 29) = 1;
    *(_WORD *)(v11 + 2) = v22;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_util_init_gpio_pin_tbl",
        1894,
        "gpio-vana %d",
        (unsigned __int16)v22);
  }
  v13 = of_property_read_variable_u32_array(v5, "gpio-vana1", &v38, 1, 0);
  if ( v13 != -22 )
  {
    if ( v13 < 0 )
    {
      v25 = v13 & (v13 >> 31);
      v26 = "read gpio-vana1 failed rc %d";
      v27 = 1900;
      goto LABEL_95;
    }
    if ( v38 >= v4 )
    {
      v28 = "gpio-vana1 invalid %d";
      v29 = 1903;
      goto LABEL_97;
    }
    v23 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
    *(_BYTE *)(v11 + 40) = 1;
    *(_WORD *)(v11 + 24) = v23;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_util_init_gpio_pin_tbl",
        1912,
        "gpio-vana1 %d",
        (unsigned __int16)v23);
  }
  v14 = of_property_read_variable_u32_array(v5, "gpio-vio", &v38, 1, 0);
  if ( v14 == -22 )
  {
LABEL_18:
    v15 = of_property_read_variable_u32_array(v5, "gpio-vaf", &v38, 1, 0);
    if ( v15 != -22 )
    {
      if ( v15 < 0 )
      {
        v25 = v15 & (v15 >> 31);
        v26 = "read gpio-vaf failed rc %d";
        v27 = 1935;
        goto LABEL_95;
      }
      if ( v38 >= v4 )
      {
        v28 = "gpio-vaf invalid %d";
        v29 = 1938;
        goto LABEL_97;
      }
      v30 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
      *(_BYTE *)(v11 + 32) = 1;
      *(_WORD *)(v11 + 8) = v30;
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_util_init_gpio_pin_tbl",
          1947,
          "gpio-vaf %d",
          (unsigned __int16)v30);
    }
    v16 = of_property_read_variable_u32_array(v5, "gpio-vdig", &v38, 1, 0);
    if ( v16 != -22 )
    {
      if ( v16 < 0 )
      {
        v25 = v16 & (v16 >> 31);
        v26 = "read gpio-vdig failed rc %d";
        v27 = 1953;
        goto LABEL_95;
      }
      if ( v38 >= v4 )
      {
        v28 = "gpio-vdig invalid %d";
        v29 = 1956;
        goto LABEL_97;
      }
      v31 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
      *(_BYTE *)(v11 + 30) = 1;
      *(_WORD *)(v11 + 4) = v31;
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_util_init_gpio_pin_tbl",
          1965,
          "gpio-vdig %d",
          (unsigned __int16)v31);
    }
    v17 = of_property_read_variable_u32_array(v5, "gpio-reset", &v38, 1, 0);
    if ( v17 != -22 )
    {
      if ( v17 < 0 )
      {
        v25 = v17 & (v17 >> 31);
        v26 = "read gpio-reset failed rc %d";
        v27 = 1971;
        goto LABEL_95;
      }
      if ( v38 >= v4 )
      {
        v28 = "gpio-reset invalid %d";
        v29 = 1974;
        goto LABEL_97;
      }
      v33 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
      *(_BYTE *)(v11 + 36) = 1;
      *(_WORD *)(v11 + 16) = v33;
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_util_init_gpio_pin_tbl",
          1983,
          "gpio-reset %d",
          (unsigned __int16)v33);
    }
    v18 = of_property_read_variable_u32_array(v5, "gpio-standby", &v38, 1, 0);
    if ( v18 != -22 )
    {
      if ( v18 < 0 )
      {
        v25 = v18 & (v18 >> 31);
        v26 = "read gpio-standby failed rc %d";
        v27 = 1990;
        goto LABEL_95;
      }
      if ( v38 >= v4 )
      {
        v28 = "gpio-standby invalid %d";
        v29 = 1993;
        goto LABEL_97;
      }
      v34 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
      *(_BYTE *)(v11 + 37) = 1;
      *(_WORD *)(v11 + 18) = v34;
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_util_init_gpio_pin_tbl",
          2002,
          "gpio-standby %d",
          (unsigned __int16)v34);
    }
    v19 = of_property_read_variable_u32_array(v5, "gpio-af-pwdm", &v38, 1, 0);
    if ( v19 != -22 )
    {
      if ( v19 < 0 )
      {
        v25 = v19 & (v19 >> 31);
        v26 = "read gpio-af-pwdm failed rc %d";
        v27 = 2009;
        goto LABEL_95;
      }
      if ( v38 >= v4 )
      {
        v28 = "gpio-af-pwdm invalid %d";
        v29 = 2012;
        goto LABEL_97;
      }
      v35 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
      *(_BYTE *)(v11 + 33) = 1;
      *(_WORD *)(v11 + 10) = v35;
      if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000000LL,
          4,
          "cam_sensor_util_init_gpio_pin_tbl",
          2021,
          "gpio-af-pwdm %d",
          (unsigned __int16)v35);
    }
    v20 = of_property_read_variable_u32_array(v5, "gpio-custom1", &v38, 1, 0);
    if ( v20 == -22 )
    {
LABEL_24:
      v21 = of_property_read_variable_u32_array(v5, "gpio-custom2", &v38, 1, 0);
      if ( v21 == -22 )
      {
        result = 0;
        goto LABEL_12;
      }
      if ( (v21 & 0x80000000) == 0 )
      {
        if ( v38 < v4 )
        {
          result = 0;
          v37 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
          *(_BYTE *)(v11 + 39) = 1;
          *(_WORD *)(v11 + 22) = v37;
          if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x800000000LL,
              4,
              "cam_sensor_util_init_gpio_pin_tbl",
              2059,
              "gpio-custom2 %d",
              (unsigned __int16)v37);
            result = 0;
          }
          goto LABEL_12;
        }
        v28 = "gpio-custom2 invalid %d";
        v29 = 2050;
        goto LABEL_97;
      }
      v25 = v21 & (v21 >> 31);
      v26 = "read gpio-custom2 failed rc %d";
      v27 = 2047;
      goto LABEL_95;
    }
    if ( (v20 & 0x80000000) == 0 )
    {
      if ( v38 < v4 )
      {
        v36 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
        *(_BYTE *)(v11 + 38) = 1;
        *(_WORD *)(v11 + 20) = v36;
        if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000000LL,
            4,
            "cam_sensor_util_init_gpio_pin_tbl",
            2040,
            "gpio-custom1 %d",
            (unsigned __int16)v36);
        goto LABEL_24;
      }
      v28 = "gpio-custom1 invalid %d";
      v29 = 2031;
LABEL_97:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_util_init_gpio_pin_tbl",
        v29,
        v28);
      v32 = -22;
      goto LABEL_98;
    }
    v25 = v20 & (v20 >> 31);
    v26 = "read gpio-custom1 failed rc %d";
    v27 = 2028;
LABEL_95:
    v32 = v25;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_init_gpio_pin_tbl",
      v27,
      v26);
    goto LABEL_98;
  }
  if ( v14 < 0 )
  {
    v25 = v14 & (v14 >> 31);
    v26 = "read gpio-vio failed rc %d";
    v27 = 1918;
    goto LABEL_95;
  }
  if ( v38 < v4 )
  {
    v24 = *(_DWORD *)(*(_QWORD *)v3 + 24LL * v38);
    *(_BYTE *)(v11 + 31) = 1;
    *(_WORD *)(v11 + 6) = v24;
    if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x800000000LL,
        4,
        "cam_sensor_util_init_gpio_pin_tbl",
        1929,
        "gpio-vio %d",
        (unsigned __int16)v24);
    goto LABEL_18;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "cam_sensor_util_init_gpio_pin_tbl",
    1921,
    "gpio-vio invalid %d",
    v38);
  v32 = 0;
LABEL_98:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v11, 0);
  else
    kvfree(v11);
  result = v32;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
