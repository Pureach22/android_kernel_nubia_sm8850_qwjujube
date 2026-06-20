__int64 __fastcall target_if_cp_stats_is_service_cstats_enabled(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x0
  char v13; // w8

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 2800);
    if ( v10 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
    {
      v13 = wmi_service_enabled(v11, 0x137u, a3, a4, a5, a6, a7, a8, a9, a10);
      *a2 = v13 & 1;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: wmi_handle is null",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_cp_stats_is_service_cstats_enabled");
      return 29;
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc is NULL!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_cp_stats_is_service_cstats_enabled");
    return 4;
  }
}
