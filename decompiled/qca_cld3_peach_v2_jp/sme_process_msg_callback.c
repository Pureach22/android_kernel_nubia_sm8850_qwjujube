__int64 __fastcall sme_process_msg_callback(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  if ( a10 )
    return sme_process_msg();
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Empty message for SME Msg callback",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "sme_process_msg_callback");
  return 16;
}
