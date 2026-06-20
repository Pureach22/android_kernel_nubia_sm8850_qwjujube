__int64 __fastcall cam_vfe_init_soc_resources(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  unsigned int cpas_hw_version; // w0
  unsigned int v9; // w23
  const char *v10; // x5
  __int64 v11; // x4
  __int64 v12; // x28
  __int64 v13; // x27
  __int64 v14; // x24
  unsigned int dt_properties; // w0
  int variable_u32_array; // w0
  size_t v17; // x0
  int v18; // w24
  unsigned int drv_enable; // w0
  int option_clk_by_name; // w0
  int v21; // w8
  unsigned int v22; // w0
  int v23; // w9
  __int64 v24; // x10
  unsigned int u32_index; // w25
  bool v26; // zf
  unsigned __int64 StatusReg; // x23
  __int64 v28; // x24
  _QWORD v30[16]; // [xsp+8h] [xbp-C8h] BYREF
  __int64 v31; // [xsp+88h] [xbp-48h]
  __int64 v32; // [xsp+90h] [xbp-40h]
  __int64 v33; // [xsp+98h] [xbp-38h]
  __int64 (__fastcall *v34)(); // [xsp+A0h] [xbp-30h]
  __int64 v35; // [xsp+A8h] [xbp-28h]
  __int64 v36; // [xsp+B0h] [xbp-20h] BYREF
  __int64 v37; // [xsp+B8h] [xbp-18h]
  __int64 v38; // [xsp+C0h] [xbp-10h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = nullptr;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(64, 0xCC0u, 0, "cam_vfe_init_soc_resources", 0x9Au);
  else
    v6 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
  v7 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      *(_QWORD *)(a1 + 3296) = v7;
      cpas_hw_version = cam_cpas_get_cpas_hw_version((_DWORD *)(v7 + 4));
      if ( cpas_hw_version )
      {
        v9 = cpas_hw_version;
        v10 = "Error! Invalid cpas version rc=%d";
        v11 = 163;
LABEL_7:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_init_soc_resources",
          v11,
          v10,
          v9);
        goto LABEL_8;
      }
      v12 = *(_QWORD *)a1;
      v13 = *(_QWORD *)(a1 + 3296);
      *(_DWORD *)(a1 + 16) = *(_DWORD *)(v7 + 4);
      v14 = *(_QWORD *)(v12 + 760);
      dt_properties = cam_soc_util_get_dt_properties(a1);
      if ( dt_properties )
      {
        v9 = dt_properties;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_get_dt_properties",
          52,
          "Error! get DT properties failed rc=%d",
          dt_properties);
      }
      else
      {
        variable_u32_array = of_property_read_variable_u32_array(v14, "rt-wrapper-base", v13 + 8, 1, 0);
        if ( variable_u32_array < 0 )
        {
          *(_DWORD *)(v13 + 8) = 0;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_get_dt_properties",
              60,
              "rc: %d Error reading rt_wrapper_base for core_idx: %u",
              variable_u32_array & (variable_u32_array >> 31),
              *(_DWORD *)(a1 + 20));
        }
        *(_BYTE *)(v13 + 24) = 0;
        v17 = strlen(*(const char **)(a1 + 112));
        if ( strnstr(*(_QWORD *)(a1 + 112), "lite", v17) )
        {
          v9 = 0;
          *(_BYTE *)(v13 + 24) = 1;
        }
        else if ( of_find_property(v14, "ubwc-static-cfg", 0) )
        {
          v9 = of_property_count_elems_of_size(v14, "ubwc-static-cfg", 4);
          if ( v9 <= 2 )
          {
            if ( v9 )
            {
              u32_index = of_property_read_u32_index(v14, "ubwc-static-cfg", 0, v13 + 16);
              if ( (u32_index & 0x80000000) != 0 )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_vfe_get_dt_properties",
                  92,
                  "unable to read ubwc static config");
              v26 = v9 == 1;
              v9 = u32_index;
              if ( !v26 )
              {
                v9 = of_property_read_u32_index(v14, "ubwc-static-cfg", 1, v13 + 20);
                if ( (v9 & 0x80000000) != 0 )
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_vfe_get_dt_properties",
                    92,
                    "unable to read ubwc static config");
              }
            }
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_get_dt_properties",
              81,
              "wrong num_ubwc_cfg: %d",
              v9);
          }
        }
        else
        {
          v9 = 0;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_get_dt_properties",
              72,
              "ubwc-static-cfg not supported");
            v9 = 0;
          }
        }
        *(_DWORD *)(v13 + 40) = 0;
        v18 = of_property_count_elems_of_size(*(_QWORD *)(v12 + 760), "cam_hw_pid", 4);
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_vfe_get_dt_properties",
            100,
            "vfe:%d pid count %d",
            *(_DWORD *)(a1 + 20),
            v18);
        if ( (unsigned int)(v18 - 5) >= 0xFFFFFFFC )
        {
          of_property_read_u32_index(*(_QWORD *)(v12 + 760), "cam_hw_pid", 0, v13 + 44);
          if ( v18 != 1 )
          {
            of_property_read_u32_index(*(_QWORD *)(v12 + 760), "cam_hw_pid", 1, v13 + 48);
            if ( v18 != 2 )
            {
              of_property_read_u32_index(*(_QWORD *)(v12 + 760), "cam_hw_pid", 2, v13 + 52);
              if ( v18 != 3 )
                of_property_read_u32_index(*(_QWORD *)(v12 + 760), "cam_hw_pid", 3, v13 + 56);
            }
          }
          *(_DWORD *)(v13 + 40) = v18;
        }
      }
      if ( (v9 & 0x80000000) != 0 )
      {
        v10 = "Error! Get DT properties failed rc=%d";
        v11 = 170;
        goto LABEL_7;
      }
      if ( (*(_BYTE *)(v7 + 24) & 1) == 0 )
      {
        drv_enable = cam_cpas_query_drv_enable(0, a1 + 3200);
        if ( drv_enable )
        {
          v9 = drv_enable;
          v10 = "Failed to query DRV enable rc:%d";
          v11 = 177;
          goto LABEL_7;
        }
      }
      option_clk_by_name = cam_soc_util_get_option_clk_by_name(a1, "ife_dsp_clk", (unsigned int *)(v7 + 12));
      if ( option_clk_by_name && (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_init_soc_resources",
          185,
          "Option clk get failed with rc %d",
          option_clk_by_name);
      v21 = *(_DWORD *)(a1 + 104);
      v36 = 0;
      v37 = 0;
      if ( !v21 )
        break;
      v36 = a3;
      if ( v21 == 1 )
        break;
      v37 = a3;
      if ( v21 == 2 )
        break;
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v28 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_vfe_init_soc_resources__alloc_tag;
      v7 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v28;
      if ( !v7 )
        goto LABEL_59;
    }
    v22 = cam_soc_util_request_platform_resource(a1, a2, &v36);
    if ( v22 )
    {
      v9 = v22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_request_platform_resource",
        129,
        "Error! Request platform resource failed rc=%d",
        v22);
      if ( (v9 & 0x80000000) != 0 )
      {
        v10 = "Error! Request platform resources failed rc=%d";
        v11 = 191;
        goto LABEL_7;
      }
    }
    v23 = *(_DWORD *)(a1 + 20);
    v33 = a1;
    v34 = cam_vfe_cpas_cb;
    v24 = *(_QWORD *)(a1 + 8);
    LODWORD(v30[0]) = 6645353;
    LODWORD(v31) = v23;
    v32 = v24;
    v9 = cam_cpas_register_client((__int64)v30);
    if ( !v9 )
    {
      *(_DWORD *)v7 = v35;
      goto LABEL_62;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_init_soc_resources",
      204,
      "CPAS registration failed rc=%d",
      v9);
    cam_soc_util_release_platform_resource(a1);
LABEL_8:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v7, 0);
    else
      kvfree(v7);
  }
  else
  {
LABEL_59:
    v9 = -12;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_init_soc_resources",
        156,
        "Error! soc_private Alloc Failed");
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return v9;
}
