__int64 __fastcall pe_register_callbacks_with_wma(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = wma_register_roaming_callbacks(a2[1], a2[2], a2[5], a2[6]);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Registering roaming callbacks with WMA failed",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "pe_register_callbacks_with_wma");
  return result;
}
