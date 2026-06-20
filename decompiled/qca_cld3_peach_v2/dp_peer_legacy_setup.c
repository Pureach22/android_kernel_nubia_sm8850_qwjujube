__int64 __fastcall dp_peer_legacy_setup(__int64 a1, _QWORD *a2)
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

  if ( *a2 )
    return 0;
  result = dp_txrx_peer_attach(a1, a2);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(0x45u, 2u, "%s: peer txrx ctx alloc failed", v3, v4, v5, v6, v7, v8, v9, v10, "dp_peer_legacy_setup");
    return 16;
  }
  return result;
}
