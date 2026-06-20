__int64 __fastcall pe_stop(
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

  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s:  PE STOP: Set LIM state to eLIM_MLM_OFFLINE_STATE",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "pe_stop");
  *(_DWORD *)(a1 + 4020) = 0;
  return result;
}
