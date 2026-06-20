__int64 __fastcall policy_mgr_dump_curr_freq_range(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19

  v9 = result;
  if ( *(_DWORD *)(result + 1460) | *(_DWORD *)(result + 1468) )
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "PLCY_MGR_FREQ_RANGE_CUR: mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               0);
  if ( *(_DWORD *)(v9 + 1476) | *(_DWORD *)(v9 + 1484) )
    return qdf_trace_msg(
             0x4Fu,
             8u,
             "PLCY_MGR_FREQ_RANGE_CUR: mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             1);
  return result;
}
