__int64 __fastcall dp_set_michael_key(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, char a4, const void *a5)
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
  __int64 v19; // x8
  unsigned int v20; // w9
  unsigned int v27; // w11
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  __int64 v33; // x22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x19
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v53; // w9

  v10 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v10 )
  {
    if ( *(_DWORD *)(v10 + 408) != 1 )
      goto LABEL_17;
    v19 = *(_QWORD *)(v10 + 416);
    if ( !v19 )
      goto LABEL_17;
    v20 = *(_DWORD *)(v19 + 40);
    do
    {
      if ( !v20 )
      {
        dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
        goto LABEL_20;
      }
      _X13 = (unsigned int *)(v19 + 40);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v27 = __ldxr(_X13);
        if ( v27 != v20 )
          break;
        if ( !__stlxr(v20 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v27 == v20;
      v20 = v27;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v19 + 292);
    __asm { PRFM            #0x11, [X8] }
    do
      v53 = __ldxr(_X8);
    while ( __stxr(v53 + 1, _X8) );
    v33 = *(_QWORD *)(v10 + 416);
    dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
    v10 = v33;
    if ( v33 )
    {
LABEL_17:
      v42 = v10;
      qdf_mem_copy((void *)(*(_QWORD *)v10 + 12LL * (a4 & 1) + 68), a5, 8u);
      dp_peer_unref_delete(v42, 7u, v43, v44, v45, v46, v47, v48, v49, v50);
      return 0;
    }
  }
  else
  {
    if ( a3 )
    {
      v28 = *(unsigned __int8 *)a3;
      v29 = *((unsigned __int8 *)a3 + 1);
      v30 = *((unsigned __int8 *)a3 + 2);
      v31 = *((unsigned __int8 *)a3 + 5);
    }
    else
    {
      v30 = 0;
      v28 = 0;
      v29 = 0;
      v31 = 0;
    }
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_peer_get_tgt_peer_hash_find",
      v28,
      v29,
      v30,
      v31,
      a2);
  }
LABEL_20:
  qdf_trace_msg(0x81u, 2u, "%s: %pK: peer not found ", v34, v35, v36, v37, v38, v39, v40, v41, "dp_set_michael_key", a1);
  return 16;
}
