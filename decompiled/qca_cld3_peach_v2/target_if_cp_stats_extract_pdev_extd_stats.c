__int64 __fastcall target_if_cp_stats_extract_pdev_extd_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  __int64 v9; // x0
  __int64 v10; // x0
  _DWORD *v11; // x23
  __int64 v12; // x25
  unsigned __int64 v13; // x24
  unsigned int pdev_ext_stats; // w0
  __int64 v15; // x8
  unsigned int v16; // w19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // [xsp+8h] [xbp-48h]

  if ( (*(_BYTE *)(a2 + 2) & 2) == 0 )
    return 0;
  v25 = v4;
  v9 = _qdf_mem_malloc(0x20u, "target_if_cp_stats_extract_pdev_extd_stats", 506);
  *(_QWORD *)(a3 + 24) = v9;
  if ( !v9 )
    return 2;
  v10 = _qdf_mem_malloc(0x78u, "target_if_cp_stats_extract_pdev_extd_stats", 510);
  if ( !v10 )
    return 2;
  *(_DWORD *)(a3 + 16) = 0;
  v11 = (_DWORD *)v10;
  if ( *(_DWORD *)(a2 + 8) )
  {
    v12 = 0;
    v13 = 0;
    while ( 1 )
    {
      qdf_mem_set(v11, 0x78u, 0);
      pdev_ext_stats = wmi_extract_pdev_ext_stats(a1);
      if ( pdev_ext_stats )
        break;
      ++v13;
      ++*(_DWORD *)(a3 + 16);
      *(_DWORD *)(*(_QWORD *)(a3 + 24) + v12) = v11[29];
      *(_DWORD *)(*(_QWORD *)(a3 + 24) + v12 + 4) = v11[26];
      *(_DWORD *)(*(_QWORD *)(a3 + 24) + v12 + 8) = v11[27];
      v15 = *(_QWORD *)(a3 + 24) + v12;
      v12 += 16;
      *(_DWORD *)(v15 + 12) = v11[28];
      if ( v13 >= *(unsigned int *)(a2 + 8) )
        goto LABEL_9;
    }
    v16 = pdev_ext_stats;
    _qdf_mem_free((__int64)v11);
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: wmi_extract_pdev_ext_stats failed",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_cp_stats_extract_pdev_extd_stats",
      v3,
      v25);
    return v16;
  }
  else
  {
LABEL_9:
    _qdf_mem_free((__int64)v11);
    return 0;
  }
}
