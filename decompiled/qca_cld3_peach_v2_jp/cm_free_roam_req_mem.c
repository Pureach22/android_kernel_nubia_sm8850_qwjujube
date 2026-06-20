__int64 __fastcall cm_free_roam_req_mem(
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

  result = *(_QWORD *)(a1 + 112);
  if ( result )
    return scm_purge_scan_results(result, a2, a3, a4, a5, a6, a7, a8, a9);
  return result;
}
