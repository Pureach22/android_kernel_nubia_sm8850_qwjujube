__int64 __fastcall tdls_set_force_peer(__int64 a1, unsigned __int8 *a2, char a3)
{
  _QWORD *peer; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x8

  peer = tdls_find_peer(a1, a2);
  if ( peer )
  {
    v13 = peer;
    *((_BYTE *)v13 + 489) = a3 & 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: peer is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "tdls_set_force_peer");
    return 16;
  }
}
