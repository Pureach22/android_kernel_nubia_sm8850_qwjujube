__int64 __fastcall cam_soc_util_get_gpio_info(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  int gpio_counts; // w22
  _QWORD *v5; // x20
  __int64 v6; // x23
  __int64 v7; // x28
  unsigned __int16 named_gpio; // w0
  __int64 result; // x0
  __int64 v10; // x23
  unsigned int v11; // w8
  bool v12; // cc
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned int v15; // w9
  __int64 v16; // x9
  unsigned __int16 *v17; // x10
  int v18; // t1
  __int64 property; // x0
  int v20; // w8
  unsigned int v21; // w21
  __int64 v22; // x0
  __int64 v23; // x0
  _QWORD *v24; // x25
  __int64 v25; // x0
  __int64 v26; // x3
  int variable_u32_array; // w0
  int v28; // w8
  __int64 v29; // x3
  __int64 v30; // x6
  int v31; // w27
  __int64 v32; // x0
  int v33; // w27
  int v34; // w0
  unsigned int v35; // w8
  int v36; // w9
  int v37; // w27
  unsigned int v38; // w28
  int string_helper; // w0
  const char *v40; // x5
  int v41; // w6
  __int64 v42; // x4
  _QWORD *v43; // x0
  unsigned int v44; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
  {
    result = 4294967274LL;
    goto LABEL_101;
  }
  v2 = *(_QWORD *)(v1 + 744);
  if ( !v2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_gpio_info",
      3333,
      "Invalid param of_node");
    result = 4294967274LL;
    goto LABEL_101;
  }
  gpio_counts = (__int16)cam_get_gpio_counts();
  if ( gpio_counts < 1 )
  {
    result = 0;
    goto LABEL_101;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_get_gpio_info",
      3342,
      "gpio count %d",
      gpio_counts);
  if ( mem_trace_en == 1 )
  {
    v5 = (_QWORD *)cam_mem_trace_alloc(2LL * (gpio_counts & 0x7FFF), 0xCC0u, 0, "cam_soc_util_get_gpio_info", 0xD10u);
    if ( v5 )
      goto LABEL_9;
LABEL_38:
    result = 4294967284LL;
LABEL_100:
    *(_QWORD *)(a1 + 3208) = 0;
    goto LABEL_101;
  }
  v5 = (_QWORD *)_kvmalloc_node_noprof(2LL * (gpio_counts & 0x7FFF), 0, 3520, 0xFFFFFFFFLL);
  if ( !v5 )
    goto LABEL_38;
LABEL_9:
  v6 = 0;
  if ( gpio_counts <= 1 )
    v7 = 1;
  else
    v7 = (unsigned int)gpio_counts;
  do
  {
    named_gpio = cam_get_named_gpio(a1, (unsigned int)v6);
    *((_WORD *)v5 + v6) = named_gpio;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_get_gpio_info",
        3352,
        "gpio_array[%d] = %d",
        v6,
        named_gpio);
    ++v6;
  }
  while ( v7 != v6 );
  if ( mem_trace_en == 1 )
  {
    v10 = cam_mem_trace_alloc(32, 0xCC0u, 0, "cam_soc_util_get_gpio_info", 0xD1Bu);
    if ( v10 )
      goto LABEL_20;
LABEL_40:
    v21 = -12;
    goto LABEL_96;
  }
  v10 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  if ( !v10 )
    goto LABEL_40;
LABEL_20:
  v44 = 0;
  if ( !of_get_property(v2, "gpio-req-tbl-num", &v44) )
    goto LABEL_23;
  v11 = v44;
  v12 = v44 > 3;
  v44 >>= 2;
  if ( !v12 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_gpio_req_tbl",
      3245,
      "gpio-req-tbl-num 0");
    goto LABEL_23;
  }
  if ( mem_trace_en == 1 )
    v23 = cam_mem_trace_alloc(v11 & 0xFFFFFFFC, 0xCC0u, 0, "cam_soc_util_get_dt_gpio_req_tbl", 0xCB1u);
  else
    v23 = _kvmalloc_node_noprof(4LL * v44, 0, 3520, 0xFFFFFFFFLL);
  v24 = (_QWORD *)v23;
  if ( !v23 )
  {
    v33 = -12;
LABEL_92:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_gpio_info",
      3364,
      "failed in msm_camera_get_dt_gpio_req_tbl");
    v21 = v33;
LABEL_93:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v10, 0);
    else
      kvfree(v10);
LABEL_96:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    result = v21;
    goto LABEL_100;
  }
  if ( mem_trace_en != 1 )
  {
    v32 = _kvmalloc_node_noprof(24LL * v44, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v10 + 16) = v32;
    if ( v32 )
      goto LABEL_50;
LABEL_59:
    v33 = -12;
    goto LABEL_86;
  }
  v25 = cam_mem_trace_alloc(24LL * v44, 0xCC0u, 0, "cam_soc_util_get_dt_gpio_req_tbl", 0xCB6u);
  *(_QWORD *)(v10 + 16) = v25;
  if ( !v25 )
    goto LABEL_59;
LABEL_50:
  v26 = v44;
  *(_BYTE *)(v10 + 24) = v44;
  variable_u32_array = of_property_read_variable_u32_array(v2, "gpio-req-tbl-num", v24, v26, 0);
  if ( variable_u32_array < 0 )
  {
    v33 = variable_u32_array;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_gpio_req_tbl",
      3265,
      "failed in reading gpio-req-tbl-num, rc = %d",
      variable_u32_array);
  }
  else if ( v44 )
  {
    v28 = 0;
    while ( 1 )
    {
      v30 = *((unsigned int *)v24 + v28);
      if ( (unsigned int)v30 >= gpio_counts )
        break;
      v31 = v28;
      *(_DWORD *)(*(_QWORD *)(v10 + 16) + 24LL * v28) = *((unsigned __int16 *)v5 + v30);
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_get_dt_gpio_req_tbl",
          3277,
          "cam_gpio_req_tbl[%d].gpio = %d",
          v28,
          *(_DWORD *)(*(_QWORD *)(v10 + 16) + 24LL * v28));
      v29 = v44;
      v28 = v31 + 1;
      if ( v31 + 1 >= v44 )
        goto LABEL_62;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_gpio_req_tbl",
      3272,
      "gpio req tbl index %d invalid",
      v30);
    v33 = 0;
  }
  else
  {
    v29 = 0;
LABEL_62:
    v34 = of_property_read_variable_u32_array(v2, "gpio-req-tbl-flags", v24, v29, 0);
    if ( v34 < 0 )
    {
      v40 = "Failed in gpio-req-tbl-flags, rc %d";
      v41 = v34;
      v42 = 3283;
    }
    else
    {
      v35 = v44;
      if ( !v44 )
        goto LABEL_77;
      v36 = 0;
      do
      {
        v37 = v36;
        *(_QWORD *)(*(_QWORD *)(v10 + 16) + 24LL * v36 + 8) = *((unsigned int *)v24 + v36);
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_soc_util_get_dt_gpio_req_tbl",
            3290,
            "cam_gpio_req_tbl[%d].flags = %ld",
            v36,
            *(_QWORD *)(*(_QWORD *)(v10 + 16) + 24LL * v36 + 8));
          v35 = v44;
        }
        v36 = v37 + 1;
      }
      while ( v37 + 1 < v35 );
      if ( !v35 )
      {
LABEL_77:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v24, 0);
        else
          kvfree(v24);
        goto LABEL_23;
      }
      v38 = 0;
      while ( 1 )
      {
        string_helper = of_property_read_string_helper(
                          v2,
                          "gpio-req-tbl-label",
                          *(_QWORD *)(v10 + 16) + 24LL * (int)v38 + 16,
                          1,
                          v38);
        if ( string_helper < 0 )
          break;
        if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20000,
            4,
            "cam_soc_util_get_dt_gpio_req_tbl",
            3302,
            "cam_gpio_req_tbl[%d].label = %s",
            v38,
            *(const char **)(*(_QWORD *)(v10 + 16) + 24LL * (int)v38 + 16));
        if ( ++v38 >= v44 )
          goto LABEL_77;
      }
      v40 = "Failed rc %d";
      v41 = string_helper;
      v42 = 3298;
    }
    v33 = v41;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_gpio_req_tbl",
      v42,
      v40);
  }
  v43 = *(_QWORD **)(v10 + 16);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v43, 0);
  else
    kvfree(v43);
LABEL_86:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v24, 0);
  else
    kvfree(v24);
  *(_BYTE *)(v10 + 24) = 0;
  if ( v33 )
    goto LABEL_92;
LABEL_23:
  if ( mem_trace_en != 1 )
  {
    v22 = _kvmalloc_node_noprof(24LL * gpio_counts, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)v10 = v22;
    if ( v22 )
      goto LABEL_25;
    goto LABEL_42;
  }
  v13 = cam_mem_trace_alloc(24LL * gpio_counts, 0xCC0u, 0, "cam_soc_util_get_gpio_info", 0xD29u);
  *(_QWORD *)v10 = v13;
  if ( !v13 )
  {
LABEL_42:
    v21 = -12;
    goto LABEL_93;
  }
LABEL_25:
  v14 = 0;
  if ( gpio_counts <= 1 )
    v15 = 1;
  else
    v15 = gpio_counts;
  v16 = 24LL * v15;
  v17 = (unsigned __int16 *)v5;
  do
  {
    v18 = *v17++;
    *(_DWORD *)(*(_QWORD *)v10 + v14) = v18;
    v14 += 24;
  }
  while ( v16 != v14 );
  *(_BYTE *)(v10 + 8) = gpio_counts;
  *(_QWORD *)(a1 + 3208) = v10;
  property = of_find_property(v2, "gpio_for_vmrm_purpose", 0);
  v20 = debug_mdl;
  *(_BYTE *)(*(_QWORD *)(a1 + 3208) + 25LL) = property != 0;
  if ( (v20 & 0x20000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      *(_QWORD *)&v20 & 0x20000LL,
      4,
      "cam_soc_util_get_gpio_info",
      3384,
      "dev name %s gpio_for_vmrm_purpose %d",
      *(const char **)(a1 + 24),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 3208) + 25LL));
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
  result = 0;
LABEL_101:
  _ReadStatusReg(SP_EL0);
  return result;
}
