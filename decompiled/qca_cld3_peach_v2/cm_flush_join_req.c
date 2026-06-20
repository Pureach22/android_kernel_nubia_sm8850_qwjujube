__int64 __fastcall cm_flush_join_req(
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
  __int64 v9; // x0

  if ( a1 && (v9 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    cm_free_join_req(v9);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: msg or msg->bodyptr is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "cm_flush_join_req");
    return 4;
  }
}
