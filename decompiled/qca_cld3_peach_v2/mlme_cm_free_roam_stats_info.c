__int64 __fastcall mlme_cm_free_roam_stats_info(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  if ( !*(_DWORD *)(a1 + 23600) )
    return qdf_trace_msg(
             0x68u,
             8u,
             "%s: enhanced roam disable, no need free memory",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "mlme_cm_free_roam_stats_info");
  qdf_mutex_destroy(a1 + 23608);
  result = _qdf_mem_free(*(_QWORD *)(a1 + 23592));
  *(_QWORD *)(a1 + 23592) = 0;
  return result;
}
