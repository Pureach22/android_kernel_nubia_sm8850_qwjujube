__int64 __fastcall dp_peer_get_authorize(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  unsigned int v16; // w19
  _DWORD *v18; // x8

  v6 = dp_peer_find_hash_find(a1, a3);
  if ( v6 )
    goto LABEL_13;
  v18 = *(_DWORD **)(a1 + 1536);
  if ( !v18 )
    goto LABEL_10;
  if ( *(v18 - 1) != 69695039 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))v18)(a1, a3, 0, 7, a2);
  if ( v6 )
  {
LABEL_13:
    if ( *(_DWORD *)(v6 + 408) != 1 || (v15 = *(_QWORD *)(v6 + 416)) == 0 )
      v15 = v6;
    v16 = *(unsigned __int8 *)(v15 + 120);
    dp_peer_unref_delete(v6, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
    return (v16 >> 1) & 1;
  }
  else
  {
LABEL_10:
    qdf_trace_msg(0x89u, 8u, "%s: %pK: Peer is NULL!", v7, v8, v9, v10, v11, v12, v13, v14, "dp_peer_get_authorize", a1);
    return 0;
  }
}
