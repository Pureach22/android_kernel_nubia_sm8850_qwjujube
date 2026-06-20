__int64 __fastcall cam_cpas_get_domain_id_support_clks(__int64 a1, __int64 a2, __int64 a3)
{
  char *v3; // x25
  __int64 v7; // x0
  __int64 v8; // x19
  __int64 string_helper; // x22
  __int64 v10; // x27
  __int64 v11; // x23
  __int64 v12; // x28
  unsigned __int64 StatusReg; // x23
  __int64 v15; // x24

  v3 = (char *)&unk_2FD000;
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(88, 0xCC0u, 0, "cam_cpas_get_domain_id_support_clks", 0x4FBu);
  else
    v7 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
  v8 = v7;
  *(_QWORD *)(a3 + 1648) = v7;
  if ( v7 )
  {
    while ( 1 )
    {
      string_helper = (unsigned int)of_property_read_string_helper(a1, "domain-id-support-clks", 0, 0, 0);
      if ( (debug_mdl & 4) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_get_domain_id_support_clks",
          1284,
          "Domain-id clk count: %d",
          string_helper);
        if ( (int)string_helper >= 8 )
        {
LABEL_8:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_get_domain_id_support_clks",
            1286,
            "Invalid cnt of clocks, count: %d",
            string_helper);
          goto LABEL_23;
        }
      }
      else if ( (int)string_helper >= 8 )
      {
        goto LABEL_8;
      }
      if ( (int)string_helper <= 0 )
        break;
      v10 = 0;
      v3 = nullptr;
      v11 = 0;
      v12 = v8 + 56;
      *(_DWORD *)(v8 + 84) = string_helper;
      while ( v11 != 8 )
      {
        if ( (of_property_read_string_helper(a1, "domain-id-support-clks", v8 + v10, 1, (unsigned int)v11) & 0x80000000) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_get_domain_id_support_clks",
            1304,
            "Failed reading domain-id clk name at i: %d, total clks: %d",
            v11,
            string_helper);
LABEL_22:
          v3 = (char *)&unk_2FD000;
          goto LABEL_23;
        }
        if ( (unsigned int)cam_soc_util_get_option_clk_by_name(
                             a2,
                             *(const char **)(v8 + 8 * v11),
                             (unsigned int *)&v3[v12]) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_get_domain_id_support_clks",
            1314,
            "Failed reading domain-id clk %s at i: %d, total clks; %d",
            *(const char **)(v8 + 8 * v11),
            v11,
            string_helper);
          goto LABEL_22;
        }
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_get_domain_id_support_clks",
            1320,
            "Domain-id-clk %s with clk index %d",
            *(const char **)(v8 + 8 * v11),
            *(_DWORD *)(v12 + 4 * v11));
        ++v11;
        v3 += 4;
        v10 += 8;
        if ( (unsigned int)string_helper == v11 )
          return 0;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v15 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_cpas_get_domain_id_support_clks__alloc_tag;
      v8 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v15;
      *(_QWORD *)(string_helper + 1648) = v8;
      if ( !v8 )
        goto LABEL_29;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_domain_id_support_clks",
      1291,
      "No domain-id clk found");
LABEL_23:
    if ( v3[2904] == 1 )
      cam_mem_trace_free((_QWORD *)v8, 0);
    else
      kvfree(v8);
    return 4294967274LL;
  }
  else
  {
LABEL_29:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_domain_id_support_clks",
      1277,
      "Failed in allocating memory for domain_id_clk");
    return 4294967284LL;
  }
}
