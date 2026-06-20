__int64 __fastcall dp_rx_tid_update_ba_win_size(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int16 a5)
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
  __int64 v19; // x19
  __int64 v20; // x8
  unsigned int v21; // w9
  unsigned int v28; // w11
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  __int64 v34; // x23
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x22
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
  __int64 v54; // x4
  __int64 v55; // x5
  __int64 v56; // x6
  __int64 v57; // x7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v68; // w9

  v10 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( !v10 )
  {
    if ( a2 )
    {
      v29 = *(unsigned __int8 *)a2;
      v30 = *((unsigned __int8 *)a2 + 1);
      v31 = *((unsigned __int8 *)a2 + 2);
      v32 = *((unsigned __int8 *)a2 + 5);
    }
    else
    {
      v31 = 0;
      v29 = 0;
      v30 = 0;
      v32 = 0;
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
      v29,
      v30,
      v31,
      v32,
      a3);
LABEL_25:
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: Peer is NULL!",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "dp_rx_tid_update_ba_win_size",
      a1);
    return 16;
  }
  v19 = v10;
  if ( *(_DWORD *)(v10 + 408) == 1 )
  {
    v20 = *(_QWORD *)(v10 + 416);
    if ( v20 )
    {
      v21 = *(_DWORD *)(v20 + 40);
      do
      {
        if ( !v21 )
        {
          dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
          goto LABEL_25;
        }
        _X13 = (unsigned int *)(v20 + 40);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v28 = __ldxr(_X13);
          if ( v28 != v21 )
            break;
          if ( !__stlxr(v21 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v28 == v21;
        v21 = v28;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v20 + 292);
      __asm { PRFM            #0x11, [X8] }
      do
        v68 = __ldxr(_X8);
      while ( __stxr(v68 + 1, _X8) );
      v34 = *(_QWORD *)(v10 + 416);
      dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
      v19 = v34;
      if ( !v34 )
        goto LABEL_25;
    }
  }
  v43 = *(_QWORD *)(v19 + 88) + 144LL * a4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v43 + 88);
    v45 = *(_QWORD *)(v43 + 96);
    *(_WORD *)(v43 + 72) = a5;
    if ( (v45 & 1) == 0 )
      goto LABEL_21;
LABEL_28:
    *(_QWORD *)(v43 + 96) = v45 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v43 + 88);
    if ( v19 != -44 )
      goto LABEL_22;
LABEL_29:
    v56 = 0;
    v54 = 0;
    v55 = 0;
    v57 = 0;
    goto LABEL_30;
  }
  raw_spin_lock_bh(v43 + 88);
  v45 = *(_QWORD *)(v43 + 96) | 1LL;
  *(_QWORD *)(v43 + 96) = v45;
  *(_WORD *)(v43 + 72) = a5;
  if ( (v45 & 1) != 0 )
    goto LABEL_28;
LABEL_21:
  raw_spin_unlock(v43 + 88);
  if ( v19 == -44 )
    goto LABEL_29;
LABEL_22:
  v54 = *(unsigned __int8 *)(v19 + 44);
  v55 = *(unsigned __int8 *)(v19 + 45);
  v56 = *(unsigned __int8 *)(v19 + 46);
  v57 = *(unsigned __int8 *)(v19 + 49);
LABEL_30:
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: peer %02x:%02x:%02x:**:**:%02x, tid %d, update BA win size to %d",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "dp_rx_tid_update_ba_win_size",
    v54,
    v55,
    v56,
    v57,
    a4,
    a5);
  dp_peer_unref_delete(v19, 7u, v59, v60, v61, v62, v63, v64, v65, v66);
  return 0;
}
