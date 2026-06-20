__int64 __fastcall dp_register_packetdump_callback(
        __int64 result,
        char a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x8
  __int64 v15; // x8

  if ( a2 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: pdev is NULL!",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "dp_register_packetdump_callback",
             v12,
             v13);
  v14 = *(_QWORD *)(result + 72);
  if ( !v14 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: pdev is NULL!",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "dp_register_packetdump_callback",
             v12,
             v13);
  v15 = v14 + 94208;
  *(_QWORD *)(v15 + 1368) = a3;
  *(_QWORD *)(v15 + 1376) = a4;
  return result;
}
