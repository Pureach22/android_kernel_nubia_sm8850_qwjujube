__int64 __fastcall cam_ipe_init_soc_resources(__int64 a1, __int64 a2, __int64 a3)
{
  char *j; // x25
  __int64 v7; // x0
  __int64 i; // x22
  __int64 v9; // x8
  __int64 v10; // x23
  unsigned int dt_properties; // w0
  unsigned __int64 v12; // x24
  __int64 v13; // x0
  unsigned int v14; // w19
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x27
  int v18; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v20; // x24
  const char *v21; // x3
  const char *v22; // x5
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x4
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  __int64 v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  j = (char *)&unk_2FD000;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(16, 0xCC0u, 0, "cam_ipe_init_soc_resources", 0x82u);
  else
    v7 = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
  for ( i = v7; i; *(_QWORD *)(StatusReg + 80) = v20 )
  {
    v9 = *(_QWORD *)a1;
    *(_QWORD *)(a1 + 3296) = i;
    v10 = *(_QWORD *)(v9 + 760);
    dt_properties = cam_soc_util_get_dt_properties(a1);
    if ( (dt_properties & 0x80000000) != 0 )
    {
      v14 = dt_properties;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_ipe_get_dt_properties",
        84,
        "get ipe dt prop is failed");
      result = v14;
      goto LABEL_29;
    }
    v12 = (unsigned int)of_property_count_elems_of_size(v10, "cam_hw_pid", 4);
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_ipe_get_dt_properties",
        89,
        "IPE pid count: %d",
        v12);
      if ( (int)v12 < 1 )
        goto LABEL_17;
    }
    else if ( (int)v12 < 1 )
    {
      goto LABEL_17;
    }
    if ( j[2904] == 1 )
    {
      v13 = cam_mem_trace_alloc(4 * v12, 0xCC0u, 0, "cam_ipe_get_dt_properties", 0x5Eu);
      *(_QWORD *)(i + 8) = v13;
      if ( !v13 )
        goto LABEL_27;
    }
    else
    {
      v16 = _kvmalloc_node_noprof(4 * v12, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(i + 8) = v16;
      if ( !v16 )
      {
LABEL_27:
        v21 = "cam_ipe_get_dt_properties";
        v22 = "Failed at allocating memory for IPE hw pids";
        v23 = 256;
        v24 = 1;
        v25 = 96;
LABEL_28:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v23,
          v24,
          v21,
          v25,
          v22);
        result = 4294967284LL;
        goto LABEL_29;
      }
    }
    v17 = 0;
    for ( j = nullptr; j != (char *)v12; ++j )
    {
      of_property_read_u32_index(v10, "cam_hw_pid", (unsigned int)j, *(_QWORD *)(i + 8) + v17);
      v17 += 4;
    }
    *(_DWORD *)i = v12;
LABEL_17:
    v18 = *(_DWORD *)(a1 + 104);
    v26 = 0;
    v27 = 0;
    if ( !v18 || (v26 = a3, v18 == 1) || (v27 = a3, v18 == 2) )
    {
      result = cam_soc_util_request_platform_resource(a1, a2, &v26);
      goto LABEL_29;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_ipe_init_soc_resources__alloc_tag;
    i = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
  }
  result = 4294967284LL;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v21 = "cam_ipe_init_soc_resources";
    v22 = "Failed at allocating IPE soc_private";
    v23 = debug_mdl & 0x100;
    v24 = 4;
    v25 = 132;
    goto LABEL_28;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
