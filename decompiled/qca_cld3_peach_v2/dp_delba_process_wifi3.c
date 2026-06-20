__int64 __fastcall dp_delba_process_wifi3(__int64 a1, unsigned __int16 *a2, unsigned __int8 a3, int a4, char a5)
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
  __int64 v43; // x21
  unsigned __int64 StatusReg; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w20
  int v63; // w8
  __int64 v64; // x8
  unsigned int v67; // w9

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
LABEL_31:
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
      "dp_delba_process_wifi3",
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
          goto LABEL_31;
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
        v67 = __ldxr(_X8);
      while ( __stxr(v67 + 1, _X8) );
      v34 = *(_QWORD *)(v10 + 416);
      dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
      v19 = v34;
      if ( !v34 )
        goto LABEL_31;
    }
  }
  v43 = *(_QWORD *)(v19 + 88) + 144LL * a4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v43 + 88);
  }
  else
  {
    raw_spin_lock_bh(v43 + 88);
    *(_QWORD *)(v43 + 96) |= 1uLL;
  }
  if ( (*(_DWORD *)(v43 + 68) | 2) == 2 )
  {
    v53 = *(_QWORD *)(v43 + 96);
    if ( (v53 & 1) != 0 )
    {
      *(_QWORD *)(v43 + 96) = v53 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v43 + 88);
    }
    else
    {
      raw_spin_unlock(v43 + 88);
    }
    v62 = 16;
  }
  else
  {
    v63 = *(_DWORD *)(v43 + 12) + 1;
    *(_BYTE *)(v43 + 120) = a5;
    *(_DWORD *)(v43 + 12) = v63;
    dp_rx_tid_update_wifi3(v19, a4, 1u, 0x1000u, 0, v45, v46, v47, v48, v49, v50, v51, v52);
    *(_DWORD *)(v43 + 68) = 0;
    --*(_WORD *)(v19 + 232);
    v64 = *(_QWORD *)(v43 + 96);
    if ( (v64 & 1) != 0 )
    {
      *(_QWORD *)(v43 + 96) = v64 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v43 + 88);
    }
    else
    {
      raw_spin_unlock(v43 + 88);
    }
    v62 = 0;
  }
  dp_peer_unref_delete(v19, 7u, v54, v55, v56, v57, v58, v59, v60, v61);
  return v62;
}
