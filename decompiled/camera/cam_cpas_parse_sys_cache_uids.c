__int64 __fastcall cam_cpas_parse_sys_cache_uids(__int64 a1, __int64 a2)
{
  const char *v4; // x5
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x4
  unsigned int v8; // w26
  int string_helper; // w0
  unsigned int v10; // w26
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x27
  __int64 i; // x25
  unsigned int v16; // w0
  __int64 v17; // x22
  const char *v18; // x26
  int v19; // w28
  unsigned int u32_index; // w0
  unsigned int v21; // w0
  __int64 v22; // x8
  unsigned __int64 v23; // x0
  int slice_id; // w26
  char v25; // w8
  const char *v26; // x5
  __int64 v27; // x4
  _QWORD *v28; // x0

  *(_QWORD *)(a2 + 1600) = 0;
  *(_DWORD *)(a2 + 1592) = 0;
  if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
  {
    v4 = "PRESIL parse syscache uids is DISABLED";
    v5 = 4;
    v6 = 3;
    v7 = 1089;
    goto LABEL_3;
  }
  string_helper = of_property_read_string_helper(a1, "sys-cache-names", 0, 0, 0);
  if ( string_helper <= 0 )
  {
    v8 = 0;
    if ( (debug_mdl & 4) == 0 || debug_priority )
      return v8;
    v4 = "no cache-names found";
    v5 = debug_mdl & 4;
    v6 = 4;
    v7 = 1095;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v5,
      v6,
      "cam_cpas_parse_sys_cache_uids",
      v7,
      v4);
    return 0;
  }
  v10 = string_helper;
  if ( mem_trace_en == 1 )
  {
    v11 = cam_mem_trace_alloc(
            (unsigned __int64)(unsigned int)string_helper << 6,
            0xCC0u,
            0,
            "cam_cpas_parse_sys_cache_uids",
            0x44Cu);
    *(_QWORD *)(a2 + 1600) = v11;
    if ( !v11 )
      return (unsigned int)-12;
  }
  else
  {
    v12 = _kvmalloc_node_noprof((unsigned __int64)(unsigned int)string_helper << 6, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a2 + 1600) = v12;
    if ( !v12 )
      return (unsigned int)-12;
  }
  v13 = 0;
  v14 = v10;
  for ( i = 32; ; i += 64 )
  {
    v16 = of_property_read_string_helper(a1, "sys-cache-names", *(_QWORD *)(a2 + 1600) + i, 1, (unsigned int)v13);
    if ( (v16 & 0x80000000) != 0 )
    {
      v8 = v16;
      v26 = "failed to read cache-names at %d";
      v27 = 1108;
LABEL_56:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_sys_cache_uids",
        v27,
        v26,
        (unsigned int)v13);
      goto LABEL_61;
    }
    v17 = *(_QWORD *)(a2 + 1600);
    v18 = *(const char **)(v17 + i);
    if ( !strcmp(v18, "small-1") )
    {
      v19 = 0;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "small-2") )
    {
      v19 = 1;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "large-1") )
    {
      v19 = 2;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "large-2") )
    {
      v19 = 3;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "large-3") )
    {
      v19 = 4;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "large-4") )
    {
      v19 = 5;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "ofe_ip") )
    {
      v19 = 6;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "ipe_rt_ip") )
    {
      v19 = 7;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "ipe_srt_ip") )
    {
      v19 = 8;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "ipe_rt_rf") )
    {
      v19 = 9;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "ipe_srt_rf") )
    {
      v19 = 10;
      goto LABEL_43;
    }
    if ( !strcmp(v18, "ipe_stripe_overlap_srt") )
    {
      v19 = 11;
      goto LABEL_43;
    }
    if ( strcmp(v18, "ipe_stripe_overlap_rt") )
      break;
    v19 = 12;
LABEL_43:
    *(_DWORD *)(v17 + i - 28) = v19;
    u32_index = of_property_read_u32_index(a1, "sys-cache-uids", (unsigned int)v13, *(_QWORD *)(a2 + 1600) + i - 24);
    if ( (u32_index & 0x80000000) != 0 )
    {
      v8 = u32_index;
      v26 = "unable to read sys cache uid at index %d";
      v27 = 1127;
      goto LABEL_56;
    }
    v21 = of_property_read_u32_index(a1, "sys-cache-concur", (unsigned int)v13, *(_QWORD *)(a2 + 1600) + i + 28);
    if ( (v21 & 0x80000000) != 0 )
    {
      if ( (unsigned int)(v19 - 6) <= 7 )
      {
        v8 = v21;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_parse_sys_cache_uids",
          1136,
          "unable to read sys cache concur at index %d cache type = %d",
          v13,
          v19);
        goto LABEL_61;
      }
      *(_DWORD *)(*(_QWORD *)(a2 + 1600) + i + 28) = 1;
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_parse_sys_cache_uids",
          1143,
          "read sys cache concur at index %d cache type = %d",
          v13,
          v19);
    }
    *(_QWORD *)(*(_QWORD *)(a2 + 1600) + i + 8) = llcc_slice_getd(*(unsigned int *)(*(_QWORD *)(a2 + 1600) + i - 24));
    v22 = *(_QWORD *)(a2 + 1600) + i;
    v23 = *(_QWORD *)(v22 + 8);
    if ( !v23 || v23 >= 0xFFFFFFFFFFFFF001LL )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_parse_sys_cache_uids",
        1152,
        "Failed to get slice desc for uid %u",
        *(_DWORD *)(v22 - 24));
      goto LABEL_58;
    }
    slice_id = llcc_get_slice_id();
    *(_DWORD *)(*(_QWORD *)(a2 + 1600) + i - 8) = slice_id;
    *(_QWORD *)(*(_QWORD *)(a2 + 1600) + i - 16) = llcc_get_slice_size(*(_QWORD *)(*(_QWORD *)(a2 + 1600) + i + 8));
    *(_DWORD *)(*(_QWORD *)(a2 + 1600) + i + 16) = 0;
    *(_DWORD *)(*(_QWORD *)(a2 + 1600) + i + 20) = 1;
    *(_DWORD *)(*(_QWORD *)(a2 + 1600) + i + 24) = 1;
    v25 = debug_mdl;
    ++*(_DWORD *)(a2 + 1592);
    if ( (v25 & 4) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v25 & 4,
        4,
        "cam_cpas_parse_sys_cache_uids",
        1170,
        "Cache: %s uid: %u scid: %d size: %zukb",
        *(const char **)(*(_QWORD *)(a2 + 1600) + i),
        *(_DWORD *)(*(_QWORD *)(a2 + 1600) + i - 24),
        slice_id,
        *(_QWORD *)(*(_QWORD *)(a2 + 1600) + i - 16));
    if ( v14 == ++v13 )
      return 0;
  }
  if ( !strcmp(v18, "ofe_stripe_overlap") )
  {
    v19 = 13;
    goto LABEL_43;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_parse_sys_cache_uids",
    1116,
    "Unsupported cache found: %s",
    v18);
LABEL_58:
  v8 = -22;
LABEL_61:
  v28 = *(_QWORD **)(a2 + 1600);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v28, 0);
  else
    kvfree(v28);
  *(_QWORD *)(a2 + 1600) = 0;
  return v8;
}
