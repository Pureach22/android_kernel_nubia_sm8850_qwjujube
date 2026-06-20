__int64 __fastcall hdd_conn_set_connection_state(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v11; // x3

  v10 = *(_QWORD *)(result + 52832);
  v11 = *(unsigned int *)(v10 + 304);
  if ( (_DWORD)v11 != a2 )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "connection state changed %d --> %d for dev %s (vdev %d)",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               v11,
               a2,
               *(_QWORD *)(result + 32) + 296LL,
               *(unsigned __int8 *)(v10 + 8));
    *(_DWORD *)(v10 + 304) = a2;
  }
  return result;
}
