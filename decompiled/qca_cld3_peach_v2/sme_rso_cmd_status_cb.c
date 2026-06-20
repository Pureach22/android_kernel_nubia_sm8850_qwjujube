__int64 __fastcall sme_rso_cmd_status_cb(
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
  *(_QWORD *)(a1 + 14408) = a2;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Registered RSO command status callback",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sme_rso_cmd_status_cb");
  return 0;
}
