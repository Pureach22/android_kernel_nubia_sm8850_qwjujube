__int64 __fastcall bs_state_non_wlan_req_entry(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( !result )
    return qdf_trace_msg(
             0xA1u,
             2u,
             "BS_SM context is null (via %s)",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "bs_sm_state_update",
             v9,
             v10);
  *(_DWORD *)(result + 88) = 1;
  return result;
}
