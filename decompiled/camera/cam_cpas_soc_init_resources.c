__int64 __fastcall cam_cpas_soc_init_resources(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int dt_properties; // w0
  unsigned int domain_id_support_clks; // w23
  __int64 v8; // x0
  __int64 v9; // x20
  unsigned int custom_dt_info; // w0
  _QWORD *v11; // x0
  _QWORD *v12; // x0
  _QWORD *v13; // x0
  __int64 v14; // x0
  __int64 v15; // x25
  const char *v16; // x23
  int v17; // w8
  __int64 v18; // x0
  unsigned int v19; // w9
  __int64 v20; // x8
  const char *v21; // x5
  __int64 v22; // x4
  __int64 v23; // x6
  int v24; // w8
  __int64 v25; // x8
  unsigned int v26; // w9
  unsigned int v27; // w0
  _QWORD *v28; // x0
  _DWORD *v29; // x21
  int option_clk_by_name; // w0
  unsigned int v31; // w9
  unsigned __int64 StatusReg; // x23
  __int64 v33; // x25
  __int64 v35; // [xsp+8h] [xbp-18h] BYREF
  __int64 v36; // [xsp+10h] [xbp-10h]
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  dt_properties = cam_soc_util_get_dt_properties(a1);
  if ( dt_properties )
  {
    domain_id_support_clks = dt_properties;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_soc_init_resources",
      1913,
      "failed in get_dt_properties, rc=%d",
      dt_properties);
  }
  else if ( a2 || !*(_DWORD *)(a1 + 104) )
  {
    if ( mem_trace_en == 1 )
      v8 = cam_mem_trace_alloc(1664, 0xCC0u, 0, "cam_cpas_soc_init_resources", 0x783u);
    else
      v8 = _kvmalloc_node_noprof(1664, 0, 3520, 0xFFFFFFFFLL);
    v9 = v8;
    *(_QWORD *)(a1 + 3296) = v8;
    if ( v8 )
    {
      while ( 1 )
      {
        custom_dt_info = cam_cpas_get_custom_dt_info(a3, *(__int64 **)a1, (const char **)v9);
        if ( custom_dt_info )
        {
          domain_id_support_clks = custom_dt_info;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_soc_init_resources",
            1932,
            "failed in get_custom_info, rc=%d",
            custom_dt_info);
          goto LABEL_12;
        }
        if ( mem_trace_en == 1 )
        {
          v14 = cam_mem_trace_alloc(
                  16LL * *(unsigned int *)(a1 + 104),
                  0xCC0u,
                  0,
                  "cam_cpas_soc_init_resources",
                  0x792u);
          *(_QWORD *)(v9 + 1656) = v14;
          if ( !v14 )
            goto LABEL_30;
        }
        else
        {
          v18 = _kvmalloc_node_noprof(16LL * *(unsigned int *)(a1 + 104), 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(v9 + 1656) = v18;
          if ( !v18 )
          {
LABEL_30:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_soc_init_resources",
              1940,
              "Failed to allocate irq data");
            domain_id_support_clks = -12;
            goto LABEL_12;
          }
        }
        if ( !*(_DWORD *)(a1 + 104) )
          break;
        v15 = *(_QWORD *)(a1 + 3296);
        **(_QWORD **)(v15 + 1656) = a3;
        v16 = *(const char **)(a1 + 40);
        if ( !strcmp(v16, "cpas_camnoc") )
        {
          v17 = 0;
        }
        else if ( !strcmp(v16, "cpas_camnoc_rt") )
        {
          v17 = 1;
        }
        else
        {
          if ( strcmp(v16, "cpas_camnoc_nrt") )
            goto LABEL_37;
          v17 = 2;
        }
        *(_DWORD *)(*(_QWORD *)(v15 + 1656) + 8LL) = v17;
        v19 = *(_DWORD *)(a1 + 104);
        v20 = *(_QWORD *)(v15 + 1656);
        v35 = v20;
        if ( v19 < 2 )
          break;
        *(_QWORD *)(v20 + 16) = a3;
        v16 = *(const char **)(a1 + 48);
        if ( !strcmp(v16, "cpas_camnoc") )
        {
          v24 = 0;
        }
        else if ( !strcmp(v16, "cpas_camnoc_rt") )
        {
          v24 = 1;
        }
        else
        {
          if ( strcmp(v16, "cpas_camnoc_nrt") )
          {
LABEL_37:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_soc_fill_irq_data",
              1894,
              "Unable to identify interrupt name: %s",
              v16);
            v21 = "Failed to fill irq data rc=%d";
            v22 = 1947;
            v23 = 4294967274LL;
            domain_id_support_clks = -22;
LABEL_44:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_soc_init_resources",
              v22,
              v21,
              v23);
            goto LABEL_45;
          }
          v24 = 2;
        }
        *(_DWORD *)(*(_QWORD *)(v15 + 1656) + 24LL) = v24;
        v25 = *(_QWORD *)(v15 + 1656);
        v26 = *(_DWORD *)(a1 + 104);
        v36 = v25 + 16;
        if ( v26 <= 2 )
          break;
        *(_QWORD *)(v25 + 32) = a3;
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v33 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cam_cpas_soc_init_resources__alloc_tag;
        v9 = _kvmalloc_node_noprof(1664, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v33;
        *(_QWORD *)(a1 + 3296) = v9;
        if ( !v9 )
          goto LABEL_59;
      }
      *(_BYTE *)(a1 + 3200) = *(_BYTE *)(v9 + 1610);
      v27 = cam_soc_util_request_platform_resource(a1, a2, &v35);
      if ( v27 )
      {
        domain_id_support_clks = v27;
        v21 = "failed in request_platform_resource, rc=%d";
        v22 = 1955;
        v23 = v27;
        goto LABEL_44;
      }
      v29 = (_DWORD *)(v9 + 1624);
      option_clk_by_name = cam_soc_util_get_option_clk_by_name(a1, "cam_icp_clk", (unsigned int *)(v9 + 1624));
      v31 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 2);
      if ( option_clk_by_name )
      {
        if ( v31 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_soc_init_resources",
            1962,
            "ICP option clk get failed with rc %d",
            option_clk_by_name);
        *v29 = -1;
      }
      else if ( v31 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_soc_init_resources",
          1967,
          "ICP option clk get success index %d",
          *v29);
      }
      if ( *(_BYTE *)(v9 + 1644) != 1 )
      {
        domain_id_support_clks = 0;
        goto LABEL_60;
      }
      domain_id_support_clks = cam_cpas_get_domain_id_support_clks(*(_QWORD *)(*(_QWORD *)a1 + 760LL), a1, v9);
      if ( !domain_id_support_clks )
        goto LABEL_60;
      cam_soc_util_release_platform_resource(a1);
LABEL_45:
      v28 = *(_QWORD **)(v9 + 1656);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v28, 0);
      else
        kvfree(v28);
LABEL_12:
      v11 = *(_QWORD **)(v9 + 1600);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v11, 0);
      else
        kvfree(v11);
      v12 = *(_QWORD **)(v9 + 1616);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v12, 0);
      else
        kvfree(v12);
      v13 = *(_QWORD **)(a1 + 3296);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v13, 0);
      else
        kvfree(v13);
      *(_QWORD *)(a1 + 3296) = 0;
    }
    else
    {
LABEL_59:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_soc_init_resources",
        1925,
        "Failed to allocate soc private");
      domain_id_support_clks = -12;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_soc_init_resources",
      1918,
      "Invalid IRQ handler");
    domain_id_support_clks = -22;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return domain_id_support_clks;
}
