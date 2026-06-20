__int64 __fastcall cam_sfe_init_soc_resources(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  unsigned int cpas_hw_version; // w0
  __int64 v9; // x7
  unsigned int v10; // w23
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x25
  __int64 v14; // x26
  unsigned int dt_properties; // w0
  int variable_u32_array; // w0
  char v17; // w8
  int v18; // w0
  int v19; // w23
  unsigned int drv_enable; // w0
  int v21; // w8
  unsigned int v22; // w0
  int v23; // w9
  __int64 v24; // x10
  unsigned __int64 StatusReg; // x23
  __int64 v26; // x25
  __int64 v28; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v29; // [xsp+8h] [xbp-B8h]
  __int64 v30; // [xsp+10h] [xbp-B0h]
  __int64 v31; // [xsp+18h] [xbp-A8h]
  __int64 v32; // [xsp+20h] [xbp-A0h]
  __int64 v33; // [xsp+28h] [xbp-98h]
  __int64 v34; // [xsp+30h] [xbp-90h]
  __int64 v35; // [xsp+38h] [xbp-88h]
  __int64 v36; // [xsp+40h] [xbp-80h]
  __int64 v37; // [xsp+48h] [xbp-78h]
  __int64 v38; // [xsp+50h] [xbp-70h]
  __int64 v39; // [xsp+58h] [xbp-68h]
  __int64 v40; // [xsp+60h] [xbp-60h]
  __int64 v41; // [xsp+68h] [xbp-58h]
  __int64 v42; // [xsp+70h] [xbp-50h]
  __int64 v43; // [xsp+78h] [xbp-48h]
  __int64 v44; // [xsp+80h] [xbp-40h]
  __int64 v45; // [xsp+88h] [xbp-38h]
  __int64 v46; // [xsp+90h] [xbp-30h]
  __int64 v47; // [xsp+98h] [xbp-28h]
  __int64 v48; // [xsp+A0h] [xbp-20h]
  __int64 v49; // [xsp+A8h] [xbp-18h] BYREF
  __int64 v50; // [xsp+B0h] [xbp-10h]
  __int64 v51; // [xsp+B8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
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
  v28 = 0;
  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(32, 0xCC0u, 0, "cam_sfe_init_soc_resources", 0x59u);
  else
    v6 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  v7 = v6;
  if ( !v6 )
  {
LABEL_39:
    v10 = -12;
    goto LABEL_40;
  }
  while ( 1 )
  {
    *(_QWORD *)(a1 + 3296) = v7;
    cpas_hw_version = cam_cpas_get_cpas_hw_version((_DWORD *)(v7 + 4));
    if ( cpas_hw_version )
    {
      v10 = cpas_hw_version;
      v11 = "Error! Invalid cpas version rc=%d";
      v12 = 96;
LABEL_25:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_init_soc_resources",
        v12,
        v11,
        v10,
        v9,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47);
      goto LABEL_26;
    }
    v13 = *(_QWORD *)(a1 + 3296);
    v14 = *(_QWORD *)a1;
    *(_DWORD *)(a1 + 16) = *(_DWORD *)(v7 + 4);
    dt_properties = cam_soc_util_get_dt_properties(a1);
    if ( dt_properties )
    {
      v10 = dt_properties;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_get_dt_properties",
        22,
        "Error get DT properties failed rc=%d",
        dt_properties);
      if ( (v10 & 0x80000000) != 0 )
      {
        v11 = "Error Get DT properties failed rc=%d";
        v12 = 103;
        goto LABEL_25;
      }
    }
    else
    {
      variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v14 + 760), "rt-wrapper-base", v13 + 8, 1, 0);
      if ( variable_u32_array < 0 )
      {
        v17 = debug_mdl;
        *(_DWORD *)(v13 + 8) = 0;
        if ( (v17 & 8) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v17 & 8,
            4,
            "cam_sfe_get_dt_properties",
            31,
            "rc: %d Error reading rt_wrapper_base for core_idx: %u",
            variable_u32_array & (variable_u32_array >> 31),
            *(_DWORD *)(a1 + 20));
      }
      *(_DWORD *)(v13 + 12) = 0;
      v18 = of_property_count_elems_of_size(*(_QWORD *)(v14 + 760), "cam_hw_pid", 4);
      v19 = v18;
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_get_dt_properties",
          37,
          "sfe:%d pid count %d",
          *(_DWORD *)(a1 + 20),
          v18);
      if ( (unsigned int)(v19 - 5) >= 0xFFFFFFFC )
      {
        of_property_read_u32_index(*(_QWORD *)(v14 + 760), "cam_hw_pid", 0, v13 + 16);
        if ( v19 != 1 )
        {
          of_property_read_u32_index(*(_QWORD *)(v14 + 760), "cam_hw_pid", 1, v13 + 20);
          if ( v19 != 2 )
          {
            of_property_read_u32_index(*(_QWORD *)(v14 + 760), "cam_hw_pid", 2, v13 + 24);
            if ( v19 != 3 )
              of_property_read_u32_index(*(_QWORD *)(v14 + 760), "cam_hw_pid", 3, v13 + 28);
          }
        }
        *(_DWORD *)(v13 + 12) = v19;
      }
    }
    drv_enable = cam_cpas_query_drv_enable(0, a1 + 3200);
    if ( drv_enable )
    {
      v10 = drv_enable;
      v11 = "Failed to query DRV enable rc:%d";
      v12 = 109;
      goto LABEL_25;
    }
    v21 = *(_DWORD *)(a1 + 104);
    v49 = 0;
    v50 = 0;
    if ( !v21 )
      break;
    v49 = a3;
    if ( v21 == 1 )
      break;
    v50 = a3;
    if ( v21 == 2 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v26 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_sfe_init_soc_resources__alloc_tag;
    v7 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v26;
    if ( !v7 )
      goto LABEL_39;
  }
  v22 = cam_soc_util_request_platform_resource(a1, a2, &v49);
  if ( v22 )
  {
    v10 = v22;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_request_platform_resource",
      64,
      "Error Request platform resource failed rc=%d",
      v22);
    if ( (v10 & 0x80000000) != 0 )
    {
      v11 = "Error Request platform resources failed rc=%d";
      v12 = 117;
      goto LABEL_25;
    }
  }
  v23 = *(_DWORD *)(a1 + 20);
  v24 = *(_QWORD *)(a1 + 8);
  v46 = a1;
  v47 = 0;
  LODWORD(v28) = 6645363;
  LODWORD(v44) = v23;
  v45 = v24;
  v10 = cam_cpas_register_client((__int64)&v28);
  if ( !v10 )
  {
    *(_DWORD *)v7 = v48;
    goto LABEL_40;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_init_soc_resources",
    129,
    "CPAS registration failed rc=%d",
    v10);
  cam_soc_util_release_platform_resource(a1);
LABEL_26:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v7, 0);
  else
    kvfree(v7);
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v10;
}
