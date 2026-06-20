__int64 __fastcall tdls_set_cap(__int64 a1, __int64 a2, int a3)
{
  __int64 peer; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8

  peer = tdls_get_peer();
  if ( peer )
  {
    v13 = peer;
    *(_DWORD *)(v13 + 32) = a3;
    return 0;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: curr_peer is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "tdls_set_cap");
    return 4294967274LL;
  }
}
