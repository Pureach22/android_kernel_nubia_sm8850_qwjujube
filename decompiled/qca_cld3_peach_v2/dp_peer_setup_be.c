__int64 __fastcall dp_peer_setup_be(int a1, int a2, int a3)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19

  result = dp_peer_setup_wifi3(a1, a2, a3);
  if ( (_DWORD)result )
  {
    v12 = result;
    qdf_trace_msg(0x45u, 2u, "%s: Unable to dp peer setup", v4, v5, v6, v7, v8, v9, v10, v11, "dp_peer_setup_be");
    return v12;
  }
  return result;
}
