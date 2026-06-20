__int64 __fastcall dp_set_addba_response(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        __int16 a5)
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
  __int64 v42; // x21
  __int64 v43; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v56; // w9

  v10 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
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
        goto LABEL_25;
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
      v56 = __ldxr(_X8);
    while ( __stxr(v56 + 1, _X8) );
    v33 = *(_QWORD *)(v10 + 416);
    dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
    v10 = v33;
    if ( v33 )
    {
LABEL_17:
      v42 = *(_QWORD *)(v10 + 88) + 144LL * a4;
      v43 = v10;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v42 + 88);
        v45 = *(_QWORD *)(v42 + 96);
        *(_WORD *)(v42 + 80) = a5;
        if ( (v45 & 1) == 0 )
        {
LABEL_21:
          raw_spin_unlock(v42 + 88);
LABEL_22:
          dp_peer_unref_delete(v43, 7u, v46, v47, v48, v49, v50, v51, v52, v53);
          return 0;
        }
      }
      else
      {
        raw_spin_lock_bh(v42 + 88);
        v45 = *(_QWORD *)(v42 + 96) | 1LL;
        *(_QWORD *)(v42 + 96) = v45;
        *(_WORD *)(v42 + 80) = a5;
        if ( (v45 & 1) == 0 )
          goto LABEL_21;
      }
      *(_QWORD *)(v42 + 96) = v45 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v42 + 88);
      goto LABEL_22;
    }
  }
  else
  {
    if ( a2 )
    {
      v28 = *(unsigned __int8 *)a2;
      v29 = *((unsigned __int8 *)a2 + 1);
      v30 = *((unsigned __int8 *)a2 + 2);
      v31 = *((unsigned __int8 *)a2 + 5);
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
      a3);
  }
LABEL_25:
  qdf_trace_msg(
    0x81u,
    8u,
    "%s: %pK: Peer is NULL!",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "dp_set_addba_response",
    a1);
  return 16;
}
