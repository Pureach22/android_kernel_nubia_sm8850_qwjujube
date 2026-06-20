__int64 __fastcall wma_set_ric_req(
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
  if ( a1 )
    return wmi_unified_set_ric_req_cmd(*a1);
  else
    return qdf_trace_msg(0x36u, 2u, "%s: wma handle is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wma_set_ric_req");
}
