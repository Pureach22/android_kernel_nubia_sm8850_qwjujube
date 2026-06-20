__int64 __fastcall tdls_set_valid(__int64 a1, unsigned __int8 *a2)
{
  _QWORD *peer; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x8

  peer = tdls_find_peer(a1, a2);
  if ( peer )
  {
    v11 = peer;
    *((_BYTE *)v11 + 30) = 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: peer is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "tdls_set_valid");
    return 16;
  }
}
