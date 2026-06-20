__int64 __fastcall dp_get_sec_type(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3, unsigned __int8 a4)
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
  __int64 v17; // x8
  unsigned int v18; // w9
  unsigned int v25; // w11
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  __int64 v31; // x21
  unsigned int v32; // w19
  const char *v34; // x2
  unsigned int v35; // w0
  unsigned int v36; // w1
  unsigned int v38; // w9

  v8 = dp_peer_find_hash_find(a1, (int)a3);
  if ( v8 )
  {
    if ( *(_DWORD *)(v8 + 408) != 1 )
      goto LABEL_17;
    v17 = *(_QWORD *)(v8 + 416);
    if ( !v17 )
      goto LABEL_17;
    v18 = *(_DWORD *)(v17 + 40);
    do
    {
      if ( !v18 )
      {
        dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
        goto LABEL_23;
      }
      _X13 = (unsigned int *)(v17 + 40);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v25 = __ldxr(_X13);
        if ( v25 != v18 )
          break;
        if ( !__stlxr(v18 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v25 == v18;
      v18 = v25;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v17 + 292);
    while ( 1 )
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v38 = __ldxr(_X8);
      while ( __stxr(v38 + 1, _X8) );
      v31 = *(_QWORD *)(v8 + 416);
      dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
      v8 = v31;
      if ( !v31 )
        break;
LABEL_17:
      _X8 = *(unsigned int **)v8;
      if ( !*(_QWORD *)v8 )
      {
        dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
        v34 = "%s: %pK: txrx peer is NULL!";
        v35 = 129;
        v36 = 8;
        goto LABEL_24;
      }
      if ( a4 < 2u )
      {
        v32 = _X8[3 * a4 + 16];
        dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
        return v32;
      }
      __break(0x5512u);
    }
  }
  else
  {
    if ( a3 )
    {
      v26 = *a3;
      v27 = a3[1];
      v28 = a3[2];
      v29 = a3[5];
    }
    else
    {
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v29 = 0;
    }
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_peer_get_tgt_peer_hash_find",
      v26,
      v27,
      v28,
      v29,
      a2);
  }
LABEL_23:
  v34 = "%s: %pK: Peer is NULL!";
  v35 = 137;
  v36 = 2;
LABEL_24:
  qdf_trace_msg(v35, v36, v34, v9, v10, v11, v12, v13, v14, v15, v16, "dp_get_sec_type", a1);
  return 0;
}
