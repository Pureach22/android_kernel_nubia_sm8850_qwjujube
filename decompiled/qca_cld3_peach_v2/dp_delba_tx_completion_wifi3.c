__int64 __fastcall dp_delba_tx_completion_wifi3(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned int a4,
        int a5)
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
  unsigned int v53; // w8
  __int64 v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  char v63; // w9
  __int64 v64; // x8
  __int64 v65; // x9
  __int64 v66; // x10
  _DWORD *v67; // x8
  __int64 v68; // x0
  __int64 v69; // x4
  __int64 v70; // x1
  int v72; // w9
  int v73; // w8
  unsigned int v75; // w9

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
LABEL_32:
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
      "dp_delba_tx_completion_wifi3",
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
          goto LABEL_32;
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
        v75 = __ldxr(_X8);
      while ( __stxr(v75 + 1, _X8) );
      v34 = *(_QWORD *)(v10 + 416);
      dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
      v19 = v34;
      if ( !v34 )
        goto LABEL_32;
    }
  }
  v43 = *(_QWORD *)(v19 + 88) + 144LL * (unsigned __int8)a4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v43 + 88);
    if ( a5 )
      goto LABEL_21;
  }
  else
  {
    raw_spin_lock_bh(v43 + 88);
    *(_QWORD *)(v43 + 96) |= 1uLL;
    if ( a5 )
    {
LABEL_21:
      v53 = *(unsigned __int8 *)(v43 + 109);
      ++*(_DWORD *)(v43 + 116);
      if ( v53 < 3 )
      {
        v63 = v53 + 1;
        v64 = *(_QWORD *)(v43 + 96);
        *(_BYTE *)(v43 + 109) = v63;
        *(_BYTE *)(v43 + 108) = 1;
        if ( (v64 & 1) != 0 )
        {
          *(_QWORD *)(v43 + 96) = v64 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v43 + 88);
        }
        else
        {
          raw_spin_unlock(v43 + 88);
        }
        v65 = *(_QWORD *)(v19 + 24);
        v66 = *(_QWORD *)(*(_QWORD *)(v65 + 24) + 8LL);
        v67 = *(_DWORD **)(*(_QWORD *)(v66 + 8) + 168LL);
        if ( v67 )
        {
          v68 = *(_QWORD *)(v66 + 16);
          v69 = *(unsigned __int8 *)(v43 + 120);
          v70 = *(unsigned __int8 *)(v65 + 59);
          if ( *(v67 - 1) != -1677196783 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD))v67)(v68, v70, v19 + 44, a4, v69, 0);
        }
        goto LABEL_40;
      }
      v54 = *(_QWORD *)(v43 + 96);
      *(_WORD *)(v43 + 108) = 0;
      if ( (v54 & 1) != 0 )
        goto LABEL_23;
LABEL_39:
      raw_spin_unlock(v43 + 88);
      goto LABEL_40;
    }
  }
  v72 = *(_DWORD *)(v43 + 112);
  v73 = *(_DWORD *)(v43 + 68);
  *(_WORD *)(v43 + 108) = 0;
  *(_DWORD *)(v43 + 112) = v72 + 1;
  if ( v73 != 1 )
  {
    if ( v73 != 2 )
      goto LABEL_38;
LABEL_43:
    dp_rx_tid_update_wifi3(v19, (unsigned __int8)a4, 1u, 0x1000u, 0, v45, v46, v47, v48, v49, v50, v51, v52);
    *(_DWORD *)(v43 + 68) = 0;
    v54 = *(_QWORD *)(v43 + 96);
    if ( (v54 & 1) == 0 )
      goto LABEL_39;
    goto LABEL_23;
  }
  dp_rx_tid_update_wifi3(v19, (unsigned __int8)a4, 1u, 0x1000u, 0, v45, v46, v47, v48, v49, v50, v51, v52);
  *(_DWORD *)(v43 + 68) = 0;
  --*(_WORD *)(v19 + 232);
  if ( *(_DWORD *)(v43 + 68) == 2 )
    goto LABEL_43;
LABEL_38:
  v54 = *(_QWORD *)(v43 + 96);
  if ( (v54 & 1) == 0 )
    goto LABEL_39;
LABEL_23:
  *(_QWORD *)(v43 + 96) = v54 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v43 + 88);
LABEL_40:
  dp_peer_unref_delete(v19, 7u, v55, v56, v57, v58, v59, v60, v61, v62);
  return 0;
}
