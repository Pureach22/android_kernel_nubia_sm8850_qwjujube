__int64 __fastcall dp_set_key_sec_type_wifi3(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, int a4, char a5)
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
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 v36; // x8
  int v37; // w9
  int v38; // w10
  const char *v39; // x2
  const char *v41; // x11
  __int64 v42; // x4
  _QWORD *v43; // x19
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v53; // w9

  v10 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( !v10 )
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
LABEL_23:
    v39 = "%s: %pK: Peer is NULL!\n";
    goto LABEL_24;
  }
  if ( *(_DWORD *)(v10 + 408) == 1 )
  {
    v19 = *(_QWORD *)(v10 + 416);
    if ( v19 )
    {
      v20 = *(_DWORD *)(v19 + 40);
      do
      {
        if ( !v20 )
        {
          dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
          goto LABEL_23;
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
      if ( !v33 )
        goto LABEL_23;
    }
  }
  if ( !*(_QWORD *)v10 )
  {
    dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
    v39 = "%s: %pK: txrx peer is NULL!\n";
LABEL_24:
    qdf_trace_msg(0x81u, 8u, v39, v11, v12, v13, v14, v15, v16, v17, v18, "dp_set_key_sec_type_wifi3", a1);
    return 16;
  }
  if ( v10 == -44 )
  {
    v36 = -44;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v38 = 0;
  }
  else
  {
    v34 = *(unsigned __int8 *)(v10 + 44);
    v35 = *(unsigned __int8 *)(v10 + 45);
    v36 = v10;
    v37 = *(unsigned __int8 *)(v10 + 46);
    v38 = *(unsigned __int8 *)(v10 + 49);
  }
  v41 = "mcast";
  if ( (a5 & 1) != 0 )
    v41 = "ucast";
  v42 = a1;
  v43 = (_QWORD *)v36;
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: %pK: key sec spec for peer %pK %02x:%02x:%02x:**:**:%02x: %s key of type %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "dp_set_key_sec_type_wifi3",
    v42,
    v36,
    v34,
    v35,
    v37,
    v38,
    v41,
    a4);
  *(_DWORD *)(*v43 + 12LL * (a5 & 1) + 64) = a4;
  dp_peer_unref_delete((__int64)v43, 7u, v44, v45, v46, v47, v48, v49, v50, v51);
  return 0;
}
