__int64 __fastcall cam_ife_csid_init_soc_resources(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 v13; // x26
  unsigned int dt_properties; // w0
  unsigned int v15; // w25
  const char *v16; // x5
  __int64 v17; // x4
  __int64 v18; // x28
  char v19; // w25
  size_t v20; // x0
  int variable_u32_array; // w0
  unsigned int drv_enable; // w0
  int v23; // w8
  unsigned int v24; // w0
  int v25; // w8
  __int64 v26; // x9
  unsigned __int64 StatusReg; // x25
  __int64 v28; // x26
  _QWORD v30[16]; // [xsp+8h] [xbp-C8h] BYREF
  __int64 v31; // [xsp+88h] [xbp-48h]
  __int64 v32; // [xsp+90h] [xbp-40h]
  __int64 v33; // [xsp+98h] [xbp-38h]
  __int64 v34; // [xsp+A0h] [xbp-30h]
  __int64 v35; // [xsp+A8h] [xbp-28h]
  __int64 v36; // [xsp+B0h] [xbp-20h] BYREF
  __int64 v37; // [xsp+B8h] [xbp-18h]
  __int64 v38; // [xsp+C0h] [xbp-10h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  if ( mem_trace_en == 1 )
    v10 = cam_mem_trace_alloc(16, 0xCC0u, 0, "cam_ife_csid_init_soc_resources", 0x4Du);
  else
    v10 = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
  v11 = v10;
  if ( !v10 )
  {
LABEL_37:
    v15 = -12;
    goto LABEL_38;
  }
  while ( 1 )
  {
    v12 = *(_QWORD *)a1;
    *(_QWORD *)(a1 + 3296) = v11;
    v13 = *(_QWORD *)(v12 + 760);
    dt_properties = cam_soc_util_get_dt_properties(a1);
    if ( dt_properties )
    {
      v15 = dt_properties;
      if ( (dt_properties & 0x80000000) != 0 )
      {
        v16 = "Failed in get_dt_properties, rc=%d";
        v17 = 85;
LABEL_28:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_init_soc_resources",
          v17,
          v16,
          v15);
        goto LABEL_32;
      }
LABEL_17:
      if ( (*(_BYTE *)(v11 + 12) & 1) != 0 )
        goto LABEL_21;
      goto LABEL_18;
    }
    v18 = *(_QWORD *)(a1 + 3296);
    v19 = 1;
    if ( (of_property_read_variable_u32_array(v13, "max-width", v18 + 8, 1, 0) & 0x80000000) != 0 )
    {
      v19 = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_get_dt_properties",
          28,
          "No max-width declared");
        v19 = 0;
      }
    }
    *(_BYTE *)(v18 + 13) = v19;
    *(_BYTE *)(v18 + 12) = 0;
    v20 = strlen(*(const char **)(a1 + 112));
    if ( strnstr(*(_QWORD *)(a1 + 112), "lite", v20) )
      *(_BYTE *)(v18 + 12) = 1;
    variable_u32_array = of_property_read_variable_u32_array(v13, "rt-wrapper-base", v18 + 4, 1, 0);
    if ( (variable_u32_array & 0x80000000) == 0 )
      goto LABEL_17;
    *(_DWORD *)(v18 + 4) = 0;
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_get_dt_properties",
      44,
      "rc: %d Error reading rt_wrapper_base for core_idx: %u",
      variable_u32_array & (variable_u32_array >> 31),
      *(_DWORD *)(a1 + 20));
    if ( (*(_BYTE *)(v11 + 12) & 1) != 0 )
      goto LABEL_21;
LABEL_18:
    drv_enable = cam_cpas_query_drv_enable(0, a1 + 3200);
    if ( drv_enable )
    {
      v15 = drv_enable;
      v16 = "Failed to query DRV enable rc:%d";
      v17 = 94;
      goto LABEL_28;
    }
LABEL_21:
    v23 = *(_DWORD *)(a1 + 104);
    v36 = 0;
    v37 = 0;
    if ( !v23 )
      break;
    v36 = a4;
    if ( v23 == 1 )
      break;
    v37 = a4;
    if ( v23 == 2 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v28 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_ife_csid_init_soc_resources__alloc_tag;
    v11 = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v28;
    if ( !v11 )
      goto LABEL_37;
  }
  v24 = cam_soc_util_request_platform_resource(a1, a2, &v36);
  if ( (v24 & 0x80000000) != 0 )
  {
    v15 = v24;
    v16 = "Error Request platform resources failed rc=%d";
    v17 = 103;
    goto LABEL_28;
  }
  if ( (a5 & 1) != 0 )
    strcpy((char *)v30, "csid-custom");
  else
    strcpy((char *)v30, "csid");
  v25 = *(_DWORD *)(a1 + 20);
  v26 = *(_QWORD *)(a1 + 8);
  v33 = a4;
  v34 = a3;
  LODWORD(v31) = v25;
  v32 = v26;
  v15 = cam_cpas_register_client((__int64)v30);
  if ( !v15 )
  {
    *(_DWORD *)v11 = v35;
    goto LABEL_38;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_init_soc_resources",
    120,
    "CPAS registration failed rc=%d",
    v15);
  cam_soc_util_release_platform_resource(a1);
LABEL_32:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v11, 0);
  else
    kvfree(v11);
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v15;
}
