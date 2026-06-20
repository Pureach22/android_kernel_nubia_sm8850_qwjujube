__int64 __fastcall target_if_send_oob_connect_request(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x0

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 2800);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 16);
      if ( v11 )
        return wmi_unified_oob_connect_request_send(
                 v11,
                 *a2 | ((unsigned __int64)*((unsigned int *)a2 + 1) << 32),
                 *((unsigned int *)a2 + 2));
    }
  }
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: wmi_handle is null.",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_send_oob_connect_request");
  return 29;
}
