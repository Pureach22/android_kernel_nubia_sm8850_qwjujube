__int64 __fastcall dp_get_peer_id(__int64 a1, unsigned int a2, __int64 a3)
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
  unsigned int v15; // w19
  _DWORD *v16; // x8

  v6 = dp_peer_find_hash_find(a1, a3);
  if ( v6 )
    goto LABEL_2;
  v16 = *(_DWORD **)(a1 + 1536);
  if ( !v16 )
    goto LABEL_7;
  if ( *(v16 - 1) != 69695039 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))v16)(a1, a3, 0, 7, a2);
  if ( v6 )
  {
LABEL_2:
    v15 = *(unsigned __int16 *)(v6 + 16);
    dp_peer_unref_delete(v6, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
  }
  else
  {
LABEL_7:
    qdf_trace_msg(0x89u, 8u, "%s: %pK: Peer is NULL!", v7, v8, v9, v10, v11, v12, v13, v14, "dp_get_peer_id", a1);
    return 0xFFFF;
  }
  return v15;
}
