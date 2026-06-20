__int64 __fastcall cam_hw_cdm_soc_get_dt_properties(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v3; // x21
  unsigned int dt_properties; // w0
  unsigned int v7; // w19
  __int64 v8; // x0
  const char *v9; // x5
  __int64 v10; // x4
  __int64 matched; // x0
  __int64 v12; // x8
  __int64 v13; // x19
  _QWORD *v14; // x0

  if ( !a1 || *(_QWORD *)(a1 + 3392) || !*(_QWORD *)(a1 + 96) )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 3680);
  dt_properties = cam_soc_util_get_dt_properties(a1 + 96);
  if ( dt_properties )
  {
    v7 = dt_properties;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_soc_get_dt_properties",
      191,
      "Failed to retrieve the CDM dt properties");
    return v7;
  }
  if ( mem_trace_en == 1 )
    v8 = cam_mem_trace_alloc(2080, 0xCC0u, 0, "cam_hw_cdm_soc_get_dt_properties", 0xC5u);
  else
    v8 = _kvmalloc_node_noprof(2080, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 3392) = v8;
  if ( !v8 )
    return 4294967284LL;
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))cam_cdm_soc_load_dt_private)(*(_QWORD *)(a1 + 96)) )
  {
    v9 = "Failed to load CDM dt private data";
    v10 = 204;
LABEL_23:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_soc_get_dt_properties",
      v10,
      v9);
    v14 = *(_QWORD **)(a1 + 3392);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v14, 0);
    else
      kvfree(v14);
    *(_QWORD *)(a1 + 3392) = 0;
    return 4294967274LL;
  }
  matched = of_match_node(a2, *(_QWORD *)(*(_QWORD *)(a1 + 96) + 760LL));
  if ( !matched || (v12 = *(_QWORD *)(matched + 192), v13 = matched, !v12) )
  {
    v9 = "Failed to retrieve the CDM id table";
    v10 = 210;
    goto LABEL_23;
  }
  *(_QWORD *)(v3 + 232) = v12;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_soc_get_dt_properties",
      216,
      "name %s",
      (const char *)(v3 + 4));
  snprintf((char *)(v3 + 4), 0x80u, "%s%d", (const char *)(v13 + 64), *(_DWORD *)(a1 + 116));
  result = 0;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_soc_get_dt_properties",
      221,
      "name %s",
      (const char *)(v3 + 4));
    return 0;
  }
  return result;
}
