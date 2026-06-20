__int64 __fastcall dp_get_sec_type(__int64 a1, int a2, int a3, unsigned __int8 a4)
{
  _QWORD *v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19
  const char *v16; // x2
  unsigned int v17; // w0
  unsigned int v18; // w1

  v6 = (_QWORD *)dp_peer_find_hash_find(a1, a3);
  if ( !v6 )
  {
    v16 = "%s: %pK: Peer is NULL!";
    v17 = 137;
    v18 = 2;
LABEL_7:
    qdf_trace_msg(v17, v18, v16, v7, v8, v9, v10, v11, v12, v13, v14, "dp_get_sec_type", a1);
    return 0;
  }
  if ( !*v6 )
  {
    dp_peer_unref_delete((__int64)v6, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
    v16 = "%s: %pK: txrx peer is NULL!";
    v17 = 129;
    v18 = 8;
    goto LABEL_7;
  }
  if ( a4 < 2u )
  {
    v15 = *(_DWORD *)(*v6 + 12LL * a4 + 64);
    dp_peer_unref_delete((__int64)v6, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
    return v15;
  }
  __break(0x5512u);
  return dp_set_pdev_param();
}
