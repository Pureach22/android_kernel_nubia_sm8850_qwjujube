__int64 __fastcall dp_set_pn_check_wifi3(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int16 *a3,
        unsigned int a4,
        _DWORD *a5)
{
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 v19; // x8
  unsigned int v20; // w9
  unsigned int v27; // w11
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  __int64 v33; // x21
  __int64 v34; // x23
  __int64 v35; // x21
  __int64 v36; // x9
  unsigned int v37; // w22
  __int64 v38; // x26
  unsigned __int64 StatusReg; // x25
  __int64 v40; // x23
  __int64 v41; // x27
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x24
  __int64 v51; // x10
  int v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x9
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 result; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  int v79; // w10
  __int64 v80; // x9
  unsigned int v82; // w9
  __int64 v83; // [xsp+0h] [xbp-50h]
  __int64 v84; // [xsp+8h] [xbp-48h]
  char v85; // [xsp+18h] [xbp-38h]
  char v86; // [xsp+1Ch] [xbp-34h]
  _QWORD v87[6]; // [xsp+20h] [xbp-30h] BYREF

  v87[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v87, 0, 40);
  v9 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( !v9 )
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
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_peer_get_tgt_peer_hash_find",
      v28,
      v29,
      v30,
      v31,
      a2);
LABEL_42:
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: Peer is NULL!",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_set_pn_check_wifi3",
      0);
    goto LABEL_43;
  }
  v18 = v9;
  if ( *(_DWORD *)(v9 + 408) == 1 )
  {
    v19 = *(_QWORD *)(v9 + 416);
    if ( v19 )
    {
      v20 = *(_DWORD *)(v19 + 40);
      do
      {
        if ( !v20 )
        {
          dp_peer_unref_delete(v9, 7u, v10, v11, v12, v13, v14, v15, v16, v17);
          goto LABEL_42;
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
        v82 = __ldxr(_X8);
      while ( __stxr(v82 + 1, _X8) );
      v33 = *(_QWORD *)(v9 + 416);
      dp_peer_unref_delete(v9, 7u, v10, v11, v12, v13, v14, v15, v16, v17);
      v18 = v33;
      if ( !v33 )
        goto LABEL_42;
    }
  }
  v34 = *(_QWORD *)(v18 + 24);
  if ( !v34 )
  {
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: VDEV is NULL!",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_set_pn_check_wifi3",
      0);
    dp_peer_unref_delete(v18, 7u, v71, v72, v73, v74, v75, v76, v77, v78);
LABEL_43:
    result = 16;
    goto LABEL_44;
  }
  v35 = *(_QWORD *)(*(_QWORD *)(v34 + 24) + 8LL);
  qdf_mem_set(v87, 0x28u, 0);
  v36 = *(_QWORD *)((char *)&v87[2] + 4);
  LOBYTE(v87[0]) = 1;
  *(_QWORD *)((char *)&v87[2] + 4) &= ~0x20000uLL;
  if ( a4 > 0xA )
    goto LABEL_48;
  if ( ((1 << a4) & 0x760) != 0 )
  {
    *(_QWORD *)((char *)&v87[2] + 4) = v36 & 0xFFFFFFFFFFFC7FFFLL | 0x8000;
    *(_QWORD *)((char *)&v87[1] + 4) |= 0x800000000628800uLL;
    v85 = 48;
    v86 = 0;
    goto LABEL_21;
  }
  if ( a4 == 7 )
  {
    v79 = *(_DWORD *)(v34 + 32);
    *(_QWORD *)((char *)&v87[2] + 4) = v36 & 0xFFFFFFFFFFFC7FFFLL | 0x10000;
    v86 = 0;
    if ( v79 == 1 )
      v80 = 0x1800000000629800LL;
    else
      v80 = 0x280000000062A800LL;
    *(_QWORD *)((char *)&v87[1] + 4) |= v80;
    v85 = 0x80;
  }
  else
  {
LABEL_48:
    *(_QWORD *)((char *)&v87[1] + 4) = *(_QWORD *)((char *)&v87[1] + 4) & 0xF7FFFFFFFF9D77FFLL | 0x628800;
    v85 = 0;
    v86 = 1;
  }
LABEL_21:
  v37 = 0;
  v38 = -2448;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v40 = *(_QWORD *)(v18 + 88);
    v41 = v40 + v38;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v41 + 2536);
    }
    else
    {
      raw_spin_lock_bh(v41 + 2536);
      *(_QWORD *)(v40 + v38 + 2544) |= 1uLL;
    }
    v50 = v40 + v38;
    if ( *(_QWORD *)(v40 + v38 + 2480) )
    {
      HIDWORD(v87[0]) = *(_QWORD *)(v50 + 2504);
      LOBYTE(v87[1]) = *(_DWORD *)(v50 + 2508);
      if ( (v86 & 1) == 0 )
      {
        LODWORD(v84) = *a5;
        LODWORD(v83) = a5[1];
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: %pK: PN set for TID:%d pn:%x:%x:%x:%x",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "dp_set_pn_check_wifi3",
          v35,
          v37,
          (unsigned int)a5[3],
          (unsigned int)a5[2],
          v83,
          v84);
        v51 = *(_QWORD *)(a5 + 1);
        LODWORD(v87[3]) = *a5;
        v52 = a5[3];
        *(_QWORD *)((char *)&v87[3] + 4) = v51;
        *(_QWORD *)((char *)&v87[1] + 4) |= 0x200000uLL;
        HIDWORD(v87[4]) = v52;
      }
      *(_BYTE *)(v40 + v38 + 2472) = v85;
      if ( (unsigned int)dp_reo_send_cmd(
                           v35,
                           5u,
                           v42,
                           v43,
                           v44,
                           v45,
                           v46,
                           v47,
                           v48,
                           v49,
                           (__int64)v87,
                           (__int64)dp_rx_tid_update_cb,
                           v41 + 2448) )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: fail to send CMD_UPDATE_RX_REO_QUEUEtid %d desc %pK",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "dp_set_pn_check_wifi3",
          *(unsigned int *)(v41 + 2448),
          *(_QWORD *)(v50 + 2504));
        if ( v35 )
          ++*(_DWORD *)(v35 + 14092);
      }
    }
    else
    {
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: %pK: PN Check not setup for TID :%d ",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dp_set_pn_check_wifi3",
        v35,
        v37);
    }
    v61 = *(_QWORD *)(v40 + v38 + 2544);
    if ( (v61 & 1) != 0 )
    {
      *(_QWORD *)(v40 + v38 + 2544) = v61 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v41 + 2536);
    }
    else
    {
      raw_spin_unlock(v41 + 2536);
    }
    v38 += 144;
    ++v37;
  }
  while ( v38 );
  dp_peer_unref_delete(v18, 7u, v62, v63, v64, v65, v66, v67, v68, v69);
  result = 0;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
