__int64 __fastcall dp_tx_prepare_tso(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  unsigned int tso_num_seg; // w24
  __int64 v7; // x21
  _QWORD *v8; // x25
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int64 StatusReg; // x28
  _QWORD *v27; // x22
  __int64 v28; // x8
  __int64 v29; // x23
  unsigned __int64 v30; // x8
  _QWORD *v31; // x22
  __int64 v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int tso_info; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x3
  __int64 v59; // x1
  __int64 v60; // x22
  __int64 v61; // x8
  __int64 v62; // x8
  int v63; // w9
  unsigned int v70; // w8
  unsigned int v71; // w8
  __int64 v72; // [xsp+0h] [xbp-10h]

  tso_num_seg = _qdf_nbuf_get_tso_num_seg(a2);
  v72 = *(_QWORD *)(a1 + 24);
  v7 = *(_QWORD *)(v72 + 8);
  *(_DWORD *)(a3 + 20) = tso_num_seg;
  *(_DWORD *)a3 = 1;
  *(_QWORD *)(a3 + 24) = 0;
  v8 = (_QWORD *)(a3 + 24);
  *(_QWORD *)(a3 + 32) = 0;
  *(_QWORD *)(a3 + 40) = 0;
  qdf_trace_msg(0x45u, 0, " %s: num_seg: %d", v9, v10, v11, v12, v13, v14, v15, v16, "dp_tx_prepare_tso", tso_num_seg);
  if ( tso_num_seg )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( *(unsigned __int8 *)(a3 + 4) >= 6uLL )
        goto LABEL_41;
      v3 = v7 + 4848 + 72LL * *(unsigned __int8 *)(a3 + 4);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        break;
      }
      raw_spin_lock_bh(v3 + 56);
      *(_QWORD *)(v3 + 64) |= 1uLL;
      v27 = *(_QWORD **)(v3 + 8);
      if ( v27 )
        goto LABEL_8;
LABEL_9:
      v28 = *(_QWORD *)(v3 + 64);
      if ( (v28 & 1) != 0 )
      {
        *(_QWORD *)(v3 + 64) = v28 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v3 + 56);
        if ( !v27 )
        {
LABEL_27:
          v60 = jiffies;
          if ( dp_tx_prepare_tso___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Failed to alloc tso seg desc",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "dp_tx_prepare_tso");
            dp_tx_prepare_tso___last_ticks = v60;
          }
          v61 = *(_QWORD *)(a1 + 24);
          if ( v61 )
          {
            ++*(_QWORD *)(v61 + 91360);
            v62 = *(_QWORD *)(a1 + 24);
            if ( v62 )
            {
              if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
                v63 = *(unsigned __int16 *)(a2 + 66);
              else
                v63 = 0;
              *(_QWORD *)(v62 + 91368) += (unsigned int)(*(_DWORD *)(a2 + 112) + v63);
            }
          }
          goto LABEL_38;
        }
      }
      else
      {
        raw_spin_unlock(v3 + 56);
        if ( !v27 )
          goto LABEL_27;
      }
      --tso_num_seg;
      *v27 = *v8;
      *v8 = v27;
      if ( !tso_num_seg )
        goto LABEL_17;
    }
    raw_spin_lock(v3 + 56);
    v27 = *(_QWORD **)(v3 + 8);
    if ( !v27 )
      goto LABEL_9;
LABEL_8:
    --*(_WORD *)(v3 + 2);
    *(_QWORD *)(v3 + 8) = *v27;
    goto LABEL_9;
  }
LABEL_17:
  qdf_trace_msg(0x45u, 0, " %s: num_seg: %d", v18, v19, v20, v21, v22, v23, v24, v25, "dp_tx_prepare_tso", 0);
  if ( *(unsigned __int8 *)(a3 + 4) >= 6uLL )
  {
LABEL_41:
    __break(0x5512u);
LABEL_42:
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v70 = __ldxr(_X9);
      v71 = v70 + 1;
    }
    while ( __stlxr(v71, _X9) );
    __dmb(0xBu);
    v58 = *(unsigned int *)(a3 + 8);
    v59 = v71 % 5;
    *(_DWORD *)(a3 + 48) = v59;
    ((void (__fastcall *)(__int64, __int64, __int64, __int64))dp_tso_packet_update)(v7, v59, v3, v58);
    dp_tso_segment_stats_update(v7, *(_QWORD *)(a3 + 24), *(_DWORD *)(a3 + 48));
    dp_stats_tso_segment_histogram_update(v7, *(_DWORD *)(a3 + 8));
    return 0;
  }
  v29 = v7 + 72LL * *(unsigned __int8 *)(a3 + 4);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v30 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v30 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v30 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v29 + 5336);
    v31 = *(_QWORD **)(v29 + 5288);
    if ( !v31 )
      goto LABEL_23;
    goto LABEL_22;
  }
  raw_spin_lock_bh(v29 + 5336);
  *(_QWORD *)(v29 + 5344) |= 1uLL;
  v31 = *(_QWORD **)(v29 + 5288);
  if ( v31 )
  {
LABEL_22:
    --*(_WORD *)(v29 + 5282);
    *(_QWORD *)(v29 + 5288) = *v31;
  }
LABEL_23:
  v32 = *(_QWORD *)(v29 + 5344);
  if ( (v32 & 1) != 0 )
  {
    *(_QWORD *)(v29 + 5344) = v32 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v29 + 5336);
    v3 = a2;
    if ( v31 )
      goto LABEL_25;
  }
  else
  {
    raw_spin_unlock(v29 + 5336);
    v3 = a2;
    if ( v31 )
    {
LABEL_25:
      *v31 = *(_QWORD *)(a3 + 40);
      *(_QWORD *)(a3 + 40) = v31;
      tso_info = _qdf_nbuf_get_tso_info(*(_QWORD *)(v7 + 24), v3, a3 + 16);
      *(_DWORD *)(a3 + 8) = tso_info;
      qdf_trace_msg(
        0x45u,
        0,
        " %s: msdu_info->num_seg: %d",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dp_tx_prepare_tso",
        tso_info);
      if ( !*(_DWORD *)(a3 + 8) )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Failed to get tso info",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "dp_tx_prepare_tso");
        dp_tx_free_remaining_tso_desc(v7, a3, 1);
        return 4;
      }
      v7 = v72;
      *(_QWORD *)(a3 + 32) = *(_QWORD *)(a3 + 24);
      _X9 = (unsigned int *)(v72 + 95440);
      goto LABEL_42;
    }
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Failed to alloc - Number of segs desc",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "dp_tx_prepare_tso");
LABEL_38:
  dp_tx_free_remaining_tso_desc(v7, a3, 0);
  return 2;
}
