bool __fastcall sap_is_conc_sap_doing_scc_dfs(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x9
  char v21; // w8
  unsigned int *v23; // x9
  unsigned int *v24; // x9
  unsigned int *v25; // x9
  unsigned int *v26; // x9
  unsigned int *v27; // x9

  if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), *a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 14896) | 2) == 3 && (v20 = *(unsigned int **)(a1 + 14888)) != nullptr )
    {
      v21 = 0;
      if ( v20 != a2 && v20[182] )
        v21 = *a2 == *v20;
    }
    else
    {
      v21 = 0;
    }
    if ( (*(_DWORD *)(a1 + 14912) | 2) == 3 )
    {
      v23 = *(unsigned int **)(a1 + 14904);
      if ( v23 )
      {
        if ( v23 != a2 && v23[182] && *a2 == *v23 )
          ++v21;
      }
    }
    if ( (*(_DWORD *)(a1 + 14928) | 2) == 3 )
    {
      v24 = *(unsigned int **)(a1 + 14920);
      if ( v24 )
      {
        if ( v24 != a2 && v24[182] && *a2 == *v24 )
          ++v21;
      }
    }
    if ( (*(_DWORD *)(a1 + 14944) | 2) == 3 )
    {
      v25 = *(unsigned int **)(a1 + 14936);
      if ( v25 )
      {
        if ( v25 != a2 && v25[182] && *a2 == *v25 )
          ++v21;
      }
    }
    if ( (*(_DWORD *)(a1 + 14960) | 2) == 3 )
    {
      v26 = *(unsigned int **)(a1 + 14952);
      if ( v26 )
      {
        if ( v26 != a2 && v26[182] && *a2 == *v26 )
          ++v21;
      }
    }
    if ( (*(_DWORD *)(a1 + 14976) | 2) == 3 )
    {
      v27 = *(unsigned int **)(a1 + 14968);
      if ( v27 )
      {
        if ( v27 != a2 && v27[182] && *a2 == *v27 )
          ++v21;
      }
    }
    return v21 != 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: skip this loop as provided channel is non-dfs",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sap_is_conc_sap_doing_scc_dfs");
    return 0;
  }
}
