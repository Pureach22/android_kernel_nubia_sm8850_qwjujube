__int64 __fastcall wmi_control_diag_rx(
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
  __int64 v10; // x0
  __int64 v11; // x19
  __int64 result; // x0

  v10 = *(_QWORD *)(a1 + 5184);
  v11 = *(_QWORD *)(a2 + 16);
  if ( v10 )
    return wmi_process_control_rx(v10, *(_QWORD *)(a2 + 16));
  result = qdf_trace_msg(
             0x31u,
             2u,
             "%s: unable to get wmi_handle for diag event end point id:%d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wmi_control_diag_rx",
             *(unsigned int *)(a2 + 48));
  if ( v11 )
    return _qdf_nbuf_free(v11);
  return result;
}
