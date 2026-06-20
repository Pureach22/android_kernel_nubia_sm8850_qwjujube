__int64 __fastcall wmi_control_rx(
        _DWORD *a1,
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
  int v10; // w4
  __int64 v11; // x19
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 result; // x0

  v10 = *(_DWORD *)(a2 + 48);
  v11 = *(_QWORD *)(a2 + 16);
  if ( a1[1302] == v10 )
  {
    v12 = 0;
  }
  else if ( a1[1303] == v10 )
  {
    v12 = 1;
  }
  else
  {
    if ( a1[1304] != v10 )
      goto LABEL_9;
    v12 = 2;
  }
  v13 = *(_QWORD *)&a1[2 * v12 + 1296];
  if ( v13 )
    return wmi_process_control_rx(v13, *(_QWORD *)(a2 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
LABEL_9:
  result = qdf_trace_msg(
             0x31u,
             2u,
             "%s: unable to get wmi_handle to Endpoint %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wmi_control_rx");
  if ( v11 )
    return _qdf_nbuf_free(v11);
  return result;
}
