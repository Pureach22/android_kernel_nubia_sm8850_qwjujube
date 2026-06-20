__int64 __fastcall dp_set_pn_check_wifi3(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int16 *a3,
        unsigned int a4,
        _DWORD *a5)
{
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x23
  __int64 v17; // x20
  __int64 v18; // x21
  __int64 v19; // x9
  unsigned int v20; // w22
  __int64 v21; // x26
  unsigned __int64 StatusReg; // x25
  __int64 v23; // x23
  __int64 v24; // x27
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x24
  __int64 v34; // x10
  int v35; // w8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x9
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 result; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w10
  __int64 v63; // x9
  __int64 v64; // [xsp+0h] [xbp-50h]
  __int64 v65; // [xsp+8h] [xbp-48h]
  char v66; // [xsp+18h] [xbp-38h]
  char v67; // [xsp+1Ch] [xbp-34h]
  _QWORD v68[6]; // [xsp+20h] [xbp-30h] BYREF

  v68[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v68, 0, 40);
  v7 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( !v7 )
  {
    qdf_trace_msg(0x81u, 8u, "%s: %pK: Peer is NULL!", v8, v9, v10, v11, v12, v13, v14, v15, "dp_set_pn_check_wifi3", 0);
LABEL_26:
    result = 16;
    goto LABEL_27;
  }
  v16 = *(_QWORD *)(v7 + 24);
  v17 = v7;
  if ( !v16 )
  {
    qdf_trace_msg(0x81u, 8u, "%s: %pK: VDEV is NULL!", v8, v9, v10, v11, v12, v13, v14, v15, "dp_set_pn_check_wifi3", 0);
    dp_peer_unref_delete(v17, 7u, v54, v55, v56, v57, v58, v59, v60, v61);
    goto LABEL_26;
  }
  v18 = *(_QWORD *)(*(_QWORD *)(v16 + 24) + 8LL);
  qdf_mem_set(v68, 0x28u, 0);
  v19 = *(_QWORD *)((char *)&v68[2] + 4);
  LOBYTE(v68[0]) = 1;
  *(_QWORD *)((char *)&v68[2] + 4) &= ~0x20000uLL;
  if ( a4 > 0xA )
    goto LABEL_31;
  if ( ((1 << a4) & 0x760) != 0 )
  {
    *(_QWORD *)((char *)&v68[2] + 4) = v19 & 0xFFFFFFFFFFFC7FFFLL | 0x8000;
    *(_QWORD *)((char *)&v68[1] + 4) |= 0x800000000628800uLL;
    v66 = 48;
    v67 = 0;
    goto LABEL_6;
  }
  if ( a4 == 7 )
  {
    v62 = *(_DWORD *)(v16 + 32);
    *(_QWORD *)((char *)&v68[2] + 4) = v19 & 0xFFFFFFFFFFFC7FFFLL | 0x10000;
    v67 = 0;
    if ( v62 == 1 )
      v63 = 0x1800000000629800LL;
    else
      v63 = 0x280000000062A800LL;
    *(_QWORD *)((char *)&v68[1] + 4) |= v63;
    v66 = 0x80;
  }
  else
  {
LABEL_31:
    *(_QWORD *)((char *)&v68[1] + 4) = *(_QWORD *)((char *)&v68[1] + 4) & 0xF7FFFFFFFF9D77FFLL | 0x628800;
    v66 = 0;
    v67 = 1;
  }
LABEL_6:
  v20 = 0;
  v21 = -2448;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v23 = *(_QWORD *)(v17 + 88);
    v24 = v23 + v21;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v24 + 2536);
    }
    else
    {
      raw_spin_lock_bh(v24 + 2536);
      *(_QWORD *)(v23 + v21 + 2544) |= 1uLL;
    }
    v33 = v23 + v21;
    if ( *(_QWORD *)(v23 + v21 + 2480) )
    {
      HIDWORD(v68[0]) = *(_QWORD *)(v33 + 2504);
      LOBYTE(v68[1]) = *(_DWORD *)(v33 + 2508);
      if ( (v67 & 1) == 0 )
      {
        LODWORD(v65) = *a5;
        LODWORD(v64) = a5[1];
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: %pK: PN set for TID:%d pn:%x:%x:%x:%x",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "dp_set_pn_check_wifi3",
          v18,
          v20,
          (unsigned int)a5[3],
          (unsigned int)a5[2],
          v64,
          v65);
        v34 = *(_QWORD *)(a5 + 1);
        LODWORD(v68[3]) = *a5;
        v35 = a5[3];
        *(_QWORD *)((char *)&v68[3] + 4) = v34;
        *(_QWORD *)((char *)&v68[1] + 4) |= 0x200000uLL;
        HIDWORD(v68[4]) = v35;
      }
      *(_BYTE *)(v23 + v21 + 2472) = v66;
      if ( (unsigned int)dp_reo_send_cmd(
                           v18,
                           5u,
                           v25,
                           v26,
                           v27,
                           v28,
                           v29,
                           v30,
                           v31,
                           v32,
                           (__int64)v68,
                           (__int64)dp_rx_tid_update_cb,
                           v24 + 2448) )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: fail to send CMD_UPDATE_RX_REO_QUEUEtid %d desc %pK",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "dp_set_pn_check_wifi3",
          *(unsigned int *)(v24 + 2448),
          *(_QWORD *)(v33 + 2504));
        if ( v18 )
          ++*(_DWORD *)(v18 + 14036);
      }
    }
    else
    {
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: %pK: PN Check not setup for TID :%d ",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_set_pn_check_wifi3",
        v18,
        v20);
    }
    v44 = *(_QWORD *)(v23 + v21 + 2544);
    if ( (v44 & 1) != 0 )
    {
      *(_QWORD *)(v23 + v21 + 2544) = v44 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v24 + 2536);
    }
    else
    {
      raw_spin_unlock(v24 + 2536);
    }
    v21 += 144;
    ++v20;
  }
  while ( v21 );
  dp_peer_unref_delete(v17, 7u, v45, v46, v47, v48, v49, v50, v51, v52);
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
