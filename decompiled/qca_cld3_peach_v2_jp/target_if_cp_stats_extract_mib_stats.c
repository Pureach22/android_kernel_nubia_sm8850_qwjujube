__int64 __fastcall target_if_cp_stats_extract_mib_stats(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int mib_stats; // w19
  __int64 v13; // x5
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  mib_stats = *(_DWORD *)(a2 + 48);
  if ( !mib_stats )
    return mib_stats;
  if ( mib_stats != 1 )
  {
    v13 = *(unsigned int *)(a2 + 52);
    goto LABEL_8;
  }
  v13 = *(unsigned int *)(a2 + 52);
  if ( (unsigned int)v13 >= 2 )
  {
LABEL_8:
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: number of mib stats wrong, num_mib_stats %d, num_mib_extd_stats %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_cp_stats_extract_mib_stats",
      mib_stats,
      v13);
    return 4;
  }
  *(_DWORD *)(a3 + 104) = 1;
  v17 = _qdf_mem_malloc(0xB0u, "target_if_cp_stats_extract_mib_stats", 728);
  *(_QWORD *)(a3 + 112) = v17;
  if ( v17 )
  {
    mib_stats = wmi_extract_mib_stats(a1, a4, v17);
    if ( mib_stats )
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: wmi_extract_mib_stats failed",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "target_if_cp_stats_extract_mib_stats");
  }
  else
  {
    return 2;
  }
  return mib_stats;
}
