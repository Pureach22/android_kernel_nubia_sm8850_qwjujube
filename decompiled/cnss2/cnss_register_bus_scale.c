__int64 __fastcall cnss_register_bus_scale(_QWORD *a1)
{
  unsigned __int64 v1; // x28
  unsigned __int64 v2; // x26
  _DWORD *v3; // x21
  const char *v4; // x27
  __int64 v5; // x6
  __int64 v6; // x7
  _DWORD *v7; // x23
  int variable_u32_array; // w0
  __int64 v9; // x6
  __int64 v10; // x7
  __int64 v11; // x22
  unsigned __int64 v12; // x24
  __int64 v13; // x6
  __int64 v14; // x7
  __int64 v15; // x20
  int v16; // w0
  __int64 v17; // x6
  __int64 v18; // x7
  unsigned __int64 v19; // x19
  int v20; // w9
  const char *v21; // x1
  unsigned __int64 v22; // x8
  const char *v23; // x1
  unsigned __int64 StatusReg; // x8
  unsigned int v25; // w26
  const char *v26; // x1
  __int16 v27; // w9
  const char *v28; // x8
  const char *v29; // x1
  __int16 v30; // w9
  const char *v31; // x8
  __int64 v32; // x0
  unsigned int string_helper; // w0
  unsigned __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x7
  const char *v37; // x1
  __int64 v38; // x21
  unsigned int v39; // w9
  const char *v40; // x1
  __int64 *v41; // x1
  const char *v42; // x1
  unsigned __int64 *v43; // x9
  unsigned __int64 v44; // x10
  unsigned __int64 **v45; // x8
  unsigned __int64 *v46; // x11
  unsigned __int64 v47; // x19
  _DWORD *v48; // x25
  __int64 v49; // x21
  unsigned __int64 v50; // x8
  const char *v51; // x1
  __int16 v52; // w9
  const char *v53; // x8
  char v55; // [xsp+0h] [xbp-40h]
  _DWORD *v56; // [xsp+10h] [xbp-30h]
  _QWORD *v57; // [xsp+18h] [xbp-28h]
  const char *v58; // [xsp+20h] [xbp-20h]
  unsigned __int64 v59; // [xsp+28h] [xbp-18h]
  __int64 v60; // [xsp+30h] [xbp-10h]

  v1 = (unsigned __int64)(a1 + 43);
  v2 = *a1;
  v3 = a1;
  a1[43] = a1 + 43;
  v4 = (const char *)(a1 + 45);
  a1[44] = a1 + 43;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "qcom,icc-path-count", a1 + 45, 1, 0) & 0x80000000) == 0 )
  {
    v7 = v3 + 92;
    variable_u32_array = of_property_read_variable_u32_array(
                           *(_QWORD *)(*(_QWORD *)v3 + 760LL),
                           "qcom,bus-bw-cfg-count",
                           v3 + 92,
                           1,
                           0);
    if ( variable_u32_array < 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v25 = variable_u32_array & (variable_u32_array >> 31);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v26 = "irq";
      }
      else
      {
        v30 = *(_DWORD *)(StatusReg + 16);
        v31 = (const char *)(StatusReg + 2320);
        if ( (v30 & 0xFF00) != 0 )
          v26 = "soft_irq";
        else
          v26 = v31;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v26,
        "cnss_register_bus_scale",
        3u,
        3u,
        "Failed to get Bus BW Config table size\n",
        v9,
        v10,
        v55);
      v15 = 0;
    }
    else
    {
      v11 = (unsigned int)(2 * *(_DWORD *)v4 * *v7);
      v12 = 4 * v11;
      v15 = _kmalloc_noprof(4 * v11, 3520);
      if ( !v15 )
        goto LABEL_73;
      while ( 1 )
      {
        v16 = of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)v3 + 760LL), "qcom,bus-bw-cfg", v15, v11, 0);
        v19 = _ReadStatusReg(SP_EL0);
        v20 = *(_DWORD *)(v19 + 16) & 0xF0000;
        if ( v16 < 0 )
          break;
        if ( v20 )
        {
          v21 = "irq";
        }
        else if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
        {
          v21 = "soft_irq";
        }
        else
        {
          v21 = (const char *)(v19 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v21,
          "cnss_register_bus_scale",
          7u,
          7u,
          "ICC Path_Count: %d BW_CFG_Count: %d\n",
          *(unsigned int *)v4,
          (unsigned int)*v7,
          v55);
        v58 = v4;
        if ( !*(_DWORD *)v4 )
        {
LABEL_51:
          kfree(v15);
          return 0;
        }
        v4 = "cnss_register_bus_scale";
        v60 = 0;
        v56 = v3;
        v57 = (_QWORD *)v1;
        v59 = v2;
        while ( 1 )
        {
          v32 = devm_kmalloc(v2 + 16, 40, 3520);
          if ( !v32 )
          {
LABEL_52:
            v25 = -12;
            goto LABEL_64;
          }
          v11 = v32;
          string_helper = of_property_read_string_helper(
                            *(_QWORD *)(v2 + 760),
                            "interconnect-names",
                            v32 + 16,
                            1,
                            HIDWORD(v60));
          if ( (string_helper & 0x80000000) != 0 )
          {
            v25 = string_helper;
            goto LABEL_64;
          }
          v34 = of_icc_get(*(_QWORD *)v3 + 16LL, *(_QWORD *)(v11 + 16));
          *(_QWORD *)(v11 + 24) = v34;
          if ( v34 >= 0xFFFFFFFFFFFFF001LL )
          {
            v25 = v34;
            if ( (_DWORD)v34 != -517 )
            {
              if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
              {
                v42 = "irq";
              }
              else if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
              {
                v42 = "soft_irq";
              }
              else
              {
                v42 = (const char *)(v19 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v42,
                "cnss_register_bus_scale",
                3u,
                3u,
                "Failed to get Interconnect path for %s. Err: %d\n",
                *(_QWORD *)(v11 + 16),
                (unsigned int)v34,
                v55);
LABEL_64:
              v43 = *(unsigned __int64 **)v1;
              if ( *(_QWORD *)v1 != v1 )
              {
                v44 = 0xDEAD000000000100LL;
                do
                {
                  v46 = (unsigned __int64 *)*v43;
                  v45 = (unsigned __int64 **)v43[1];
                  if ( *v45 == v43 && (unsigned __int64 *)v46[1] == v43 )
                  {
                    v46[1] = (unsigned __int64)v45;
                    *v45 = v46;
                  }
                  else
                  {
                    _list_del_entry_valid_or_report(v43);
                  }
                  *v43 = v44;
                  v43[1] = v44 + 34;
                  v43 = v46;
                }
                while ( v46 != (unsigned __int64 *)v1 );
              }
              goto LABEL_79;
            }
          }
          v35 = devm_kmalloc(v59 + 16, 8LL * (unsigned int)*v7, 3520);
          *(_QWORD *)(v11 + 32) = v35;
          if ( !v35 )
            goto LABEL_52;
          v37 = "irq";
          if ( (*(_DWORD *)(v19 + 16) & 0xF0000) == 0 )
          {
            if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
              v37 = "soft_irq";
            else
              v37 = (const char *)(v19 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v37,
            "cnss_register_bus_scale",
            7u,
            7u,
            "ICC Vote CFG for path: %s\n",
            *(_QWORD *)(v11 + 16),
            v36,
            v55);
          if ( *v7 )
            break;
LABEL_44:
          v3 = v56;
          v1 = (unsigned __int64)v57;
          v41 = *((__int64 **)v56 + 44);
          if ( (_QWORD *)v11 == v57 || v41 == (__int64 *)v11 || (_QWORD *)*v41 != v57 )
          {
            _list_add_valid_or_report(v11, v41);
          }
          else
          {
            *((_QWORD *)v56 + 44) = v11;
            *(_QWORD *)v11 = v57;
            *(_QWORD *)(v11 + 8) = v41;
            *v41 = v11;
          }
          v2 = v59;
          LODWORD(v60) = v60 + 2;
          if ( ++HIDWORD(v60) >= *(_DWORD *)v58 )
            goto LABEL_51;
        }
        v38 = 0;
        v2 = 0;
        v1 = (unsigned int)(*v7 * v60);
        while ( v12 > 4 * (unsigned __int64)(unsigned int)(v1 + v38) )
        {
          v39 = v1 + v38 + 1;
          *(_DWORD *)(*(_QWORD *)(v11 + 32) + 4 * v38) = *(_DWORD *)(v15 + 4LL * (unsigned int)(v1 + v38));
          if ( v12 <= 4 * (unsigned __int64)v39 )
            break;
          v40 = "irq";
          *(_DWORD *)(*(_QWORD *)(v11 + 32) + 4 * v38 + 4) = *(_DWORD *)(v15 + 4LL * v39);
          if ( (*(_DWORD *)(v19 + 16) & 0xF0000) == 0 )
          {
            if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
              v40 = "soft_irq";
            else
              v40 = (const char *)(v19 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v40,
            "cnss_register_bus_scale",
            7u,
            7u,
            "ICC Vote BW: %d avg: %d peak: %d\n",
            (unsigned int)v2++,
            *(unsigned int *)(*(_QWORD *)(v11 + 32) + 4 * v38),
            *(_DWORD *)(*(_QWORD *)(v11 + 32) + 4 * v38 + 4));
          v38 += 2;
          if ( v2 >= (unsigned int)*v7 )
            goto LABEL_44;
        }
        __break(1u);
        v12 = 4LL * (unsigned int)v11;
        v47 = _ReadStatusReg(SP_EL0);
        v48 = (_DWORD *)v38;
        v49 = *(_QWORD *)(v47 + 80);
        *(_QWORD *)(v47 + 80) = &cnss_register_bus_scale__alloc_tag;
        v15 = _kmalloc_noprof(v12, 3520);
        *(_QWORD *)(v47 + 80) = v49;
        v3 = v48;
        if ( !v15 )
        {
LABEL_73:
          v50 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v50 + 16) & 0xF0000) != 0 )
          {
            v51 = "irq";
          }
          else
          {
            v52 = *(_DWORD *)(v50 + 16);
            v53 = (const char *)(v50 + 2320);
            if ( (v52 & 0xFF00) != 0 )
              v51 = "soft_irq";
            else
              v51 = v53;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v51,
            "cnss_register_bus_scale",
            3u,
            3u,
            "Failed to alloc cfg table mem\n",
            v13,
            v14,
            v55);
          v15 = 0;
          v25 = -12;
          goto LABEL_79;
        }
      }
      v25 = v16 & (v16 >> 31);
      if ( v20 )
      {
        v29 = "irq";
      }
      else if ( (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
      {
        v29 = "soft_irq";
      }
      else
      {
        v29 = (const char *)(v19 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v29,
        "cnss_register_bus_scale",
        3u,
        3u,
        "Invalid Bus BW Config Table\n",
        v17,
        v18,
        v55);
    }
LABEL_79:
    kfree(v15);
    *(_QWORD *)(v1 + 16) = 0;
    *(_QWORD *)(v1 + 24) = 0;
    *(_QWORD *)v1 = 0;
    *(_QWORD *)(v1 + 8) = 0;
    return v25;
  }
  v22 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
  {
    v23 = "irq";
  }
  else
  {
    v27 = *(_DWORD *)(v22 + 16);
    v28 = (const char *)(v22 + 2320);
    if ( (v27 & 0xFF00) != 0 )
      v23 = "soft_irq";
    else
      v23 = v28;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v23,
    "cnss_register_bus_scale",
    7u,
    7u,
    "Platform Bus Interconnect path not configured\n",
    v5,
    v6,
    v55);
  return 0;
}
