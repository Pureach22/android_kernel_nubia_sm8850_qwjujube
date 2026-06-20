__int64 __fastcall dp_peer_add_ast_wifi3(__int64 a1, int a2, int a3, __int64 a4, unsigned int a5, unsigned int a6)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20

  v10 = dp_peer_find_hash_find(a1, a3);
  if ( v10 )
  {
    v19 = v10;
    v20 = dp_peer_add_ast(a1, v10, a4, a5, a6);
    if ( v20 > 6 )
      v29 = -1;
    else
      v29 = dword_B28CFC[v20];
    dp_peer_unref_delete(v19, 7u, v21, v22, v23, v24, v25, v26, v27, v28);
  }
  else
  {
    qdf_trace_msg(0x81u, 8u, "%s: Peer is NULL!", v11, v12, v13, v14, v15, v16, v17, v18, "dp_peer_add_ast_wifi3");
    return (unsigned int)-1;
  }
  return v29;
}
