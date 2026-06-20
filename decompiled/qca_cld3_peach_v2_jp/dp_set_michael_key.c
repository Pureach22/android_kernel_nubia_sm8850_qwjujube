__int64 __fastcall dp_set_michael_key(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, char a4, const void *a5)
{
  _QWORD *v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v8 = (_QWORD *)dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v8 )
  {
    v17 = (__int64)v8;
    qdf_mem_copy((void *)(*v8 + 12LL * (a4 & 1) + 68), a5, 8u);
    dp_peer_unref_delete(v17, 7u, v18, v19, v20, v21, v22, v23, v24, v25);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: peer not found ",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_set_michael_key",
      a1);
    return 16;
  }
}
