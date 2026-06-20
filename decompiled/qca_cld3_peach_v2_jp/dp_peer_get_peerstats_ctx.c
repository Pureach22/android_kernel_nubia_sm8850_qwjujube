__int64 __fastcall dp_peer_get_peerstats_ctx(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 (*v15)(void); // x8
  __int64 v16; // x20
  __int64 v17; // x19
  __int64 v18; // x19

  if ( !a3 )
    return 0;
  result = dp_peer_find_hash_find(a1, a3);
  if ( !result )
    return result;
  v13 = *(_QWORD *)(a1 + 20056);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v13 + 416);
    if ( v14 )
    {
      v15 = *(__int64 (**)(void))(v14 + 152);
      if ( v15 )
      {
        v16 = result;
        if ( *((_DWORD *)v15 - 1) != -409965488 )
          __break(0x8228u);
        v17 = v15();
        result = v16;
        goto LABEL_12;
      }
    }
    v18 = result;
    qdf_trace_msg(
      0x92u,
      8u,
      "%s: callback not registered",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "dp_monitor_peer_get_peerstats_ctx");
    result = v18;
  }
  v17 = 0;
LABEL_12:
  dp_peer_unref_delete(result, 7u, v5, v6, v7, v8, v9, v10, v11, v12);
  return v17;
}
