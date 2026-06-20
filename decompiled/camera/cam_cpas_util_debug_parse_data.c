__int64 __fastcall cam_cpas_util_debug_parse_data(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x26
  __int64 v3; // x27
  __int64 v4; // x8
  const char *v5; // x8
  int v6; // w24
  const char *v7; // x0
  __int64 v8; // x24
  __int64 v9; // x27

  if ( (cpas_dump & 1) != 0 )
  {
    v1 = 0;
    v2 = result + 360;
    do
    {
      v3 = *(_QWORD *)(v2 + 8 * v1);
      if ( !v3 )
        break;
      v4 = *(_QWORD *)(v3 + 112);
      if ( v4 )
        v5 = *(const char **)(v4 + 24);
      else
        v5 = "no parent";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        3,
        "cam_cpas_util_debug_parse_data",
        258,
        "NODE cell_idx: %d, level: %d, name: %s, axi_port_idx: %d, merge_type: %d, parent_name: %s camnoc_max_needed: %d",
        *(_DWORD *)v3,
        *(_DWORD *)(v3 + 4),
        *(const char **)(v3 + 24),
        **(_DWORD **)(v3 + 8),
        *(_DWORD *)(v3 + 40),
        v5,
        *(unsigned __int8 *)(v3 + 57));
      if ( !*(_DWORD *)(v3 + 4) )
      {
        v6 = *(_DWORD *)(v3 + 32);
        v7 = (const char *)cam_cpas_axi_util_trans_type_to_string(*(unsigned int *)(v3 + 36));
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          3,
          "cam_cpas_util_debug_parse_data",
          266,
          "path_type: %d, transac_type: %s drv_voting_idx:%d",
          v6,
          v7,
          *(_DWORD *)(v3 + 16));
        v8 = 0;
        v9 = v3 + 58;
        do
        {
          if ( *(_BYTE *)(v9 + v8) == 1 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              3,
              "cam_cpas_util_debug_parse_data",
              270,
              "Constituent path: %d",
              v8);
          ++v8;
        }
        while ( v8 != 42 );
      }
      ++v1;
    }
    while ( v1 != 63 );
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             4,
             3,
             "cam_cpas_util_debug_parse_data",
             274,
             "NUMBER OF NODES PARSED: %d",
             v1);
  }
  return result;
}
