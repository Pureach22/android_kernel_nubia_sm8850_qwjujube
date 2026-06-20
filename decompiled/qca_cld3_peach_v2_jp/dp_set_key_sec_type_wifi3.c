__int64 __fastcall dp_set_key_sec_type_wifi3(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, int a4, char a5)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x10
  _QWORD *v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v28; // x2

  v8 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( !v8 )
  {
    v28 = "%s: %pK: Peer is NULL!\n";
LABEL_8:
    qdf_trace_msg(0x81u, 8u, v28, v9, v10, v11, v12, v13, v14, v15, v16, "dp_set_key_sec_type_wifi3", a1);
    return 16;
  }
  if ( !*(_QWORD *)v8 )
  {
    dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
    v28 = "%s: %pK: txrx peer is NULL!\n";
    goto LABEL_8;
  }
  v17 = "mcast";
  v18 = (_QWORD *)v8;
  if ( (a5 & 1) != 0 )
    v17 = "ucast";
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: %pK: key sec spec for peer %pK %02x:%02x:%02x:**:**:%02x: %s key of type %d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "dp_set_key_sec_type_wifi3",
    a1,
    v8,
    *(unsigned __int8 *)(v8 + 44),
    *(unsigned __int8 *)(v8 + 45),
    *(unsigned __int8 *)(v8 + 46),
    *(unsigned __int8 *)(v8 + 49),
    v17,
    a4);
  *(_DWORD *)(*v18 + 12LL * (a5 & 1) + 64) = a4;
  dp_peer_unref_delete((__int64)v18, 7u, v19, v20, v21, v22, v23, v24, v25, v26);
  return 0;
}
