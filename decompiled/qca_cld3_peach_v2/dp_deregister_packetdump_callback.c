__int64 __fastcall dp_deregister_packetdump_callback(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8
  _QWORD *v13; // x8

  if ( a2 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: pdev is NULL!",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_deregister_packetdump_callback",
             v10,
             v11);
  v12 = *(_QWORD *)(result + 72);
  if ( !v12 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: pdev is NULL!",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_deregister_packetdump_callback",
             v10,
             v11);
  v13 = (_QWORD *)(v12 + 96504);
  *v13 = 0;
  v13[1] = 0;
  return result;
}
