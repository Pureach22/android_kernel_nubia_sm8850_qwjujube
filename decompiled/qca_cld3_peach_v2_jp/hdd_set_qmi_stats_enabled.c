__int64 __fastcall hdd_set_qmi_stats_enabled(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8

  if ( *a1 && (v9 = *(_QWORD *)(*a1 + 2800LL)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
    return wmi_set_qmi_stats(v10, *(_BYTE *)(a1[13] + 124LL));
  else
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: could not get wmi handle",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hdd_set_qmi_stats_enabled");
}
