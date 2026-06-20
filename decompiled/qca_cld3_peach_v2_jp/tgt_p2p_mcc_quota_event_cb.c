__int64 __fastcall tgt_p2p_mcc_quota_event_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v11; // x2

  if ( a2 )
  {
    if ( a1 )
      return p2p_mcc_quota_event_process(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    v11 = "%s: psoc context passed is NULL";
  }
  else
  {
    v11 = "%s: invalid mcc quota event information";
  }
  qdf_trace_msg(0x4Eu, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_p2p_mcc_quota_event_cb");
  return 4;
}
