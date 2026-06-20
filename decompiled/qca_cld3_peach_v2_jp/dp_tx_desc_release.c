__int64 __fastcall dp_tx_desc_release(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v7; // x23
  __int64 v8; // x21
  __int64 v10; // x0
  int v11; // w1
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x22
  __int64 v31; // x24
  unsigned __int64 v32; // x8
  __int16 v33; // w9
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x22
  _QWORD *v37; // x25
  unsigned __int64 v38; // x8
  __int16 v39; // w9
  __int64 v40; // x8
  __int64 v41; // x24
  _QWORD *v42; // x25
  __int64 v43; // x22
  __int64 v44; // x26
  unsigned __int64 v45; // x8
  int v46; // w9
  __int64 v47; // x8
  __int64 v48; // x22
  __int64 v49; // x24
  unsigned __int64 StatusReg; // x8
  __int16 v51; // w9
  __int64 v52; // x8
  __int64 v54; // x5
  const char *v55; // x2
  unsigned int v57; // w10
  unsigned int v63; // w10

  v3 = *(_QWORD *)(a2 + 56);
  v4 = *(_QWORD *)(a2 + 144);
  v7 = v3 + 90112;
  if ( v4 )
  {
    _qdf_nbuf_free(v4);
    *(_QWORD *)(a2 + 144) = 0;
  }
  v8 = *(_QWORD *)(v3 + 8);
  _X8 = v7 + 3388;
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v57 = __ldxr((unsigned int *)_X8);
    while ( __stxr(v57 - 1, (unsigned int *)_X8) );
    v10 = *(unsigned int *)(v7 + 3388);
    v11 = *(_DWORD *)(v7 + 3392);
    if ( v11 < (int)v10 )
    {
      v11 = *(_DWORD *)(v7 + 3388);
      *(_DWORD *)(v7 + 3392) = v10;
    }
    result = qdf_mem_tx_desc_cnt_update(v10, v11);
    if ( !*(_QWORD *)(a2 + 72) )
      break;
    if ( *(_BYTE *)(a2 + 65) != 1 )
      goto LABEL_28;
    qdf_trace_msg(
      0x45u,
      0,
      "%s: Free the tso descriptor",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_tx_tso_desc_release");
    v29 = *(_QWORD *)(a2 + 72);
    if ( !*(_QWORD *)(v29 + 40) )
    {
      v55 = "%s: SO desc is NULL!";
      goto LABEL_59;
    }
    v30 = *(_QWORD *)(v29 + 48);
    if ( !v30 )
    {
      v55 = "%s: TSO num desc is NULL!";
LABEL_59:
      qdf_trace_msg(0x7Du, 2u, v55, v21, v22, v23, v24, v25, v26, v27, v28, "dp_tx_tso_desc_release");
      if ( (*(_BYTE *)(a2 + 32) & 0x80) == 0 )
      {
LABEL_37:
        v48 = *(_QWORD *)(a2 + 72);
        _X8 = (unsigned __int8)a3;
        *(_WORD *)(v48 + 24) = 0;
        if ( (unsigned __int8)a3 < 6u )
        {
          v49 = v8 + 136LL * (unsigned __int8)a3;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v49 + 4144);
          }
          else
          {
            raw_spin_lock_bh(v49 + 4144);
            *(_QWORD *)(v49 + 4152) |= 1uLL;
          }
          *(_QWORD *)v48 = *(_QWORD *)(v49 + 4136);
          v51 = *(_WORD *)(v49 + 4040);
          v52 = *(_QWORD *)(v49 + 4152);
          *(_QWORD *)(v49 + 4136) = v48;
          *(_WORD *)(v49 + 4040) = v51 + 1;
          if ( (v52 & 1) != 0 )
          {
            *(_QWORD *)(v49 + 4152) = v52 & 0xFFFFFFFFFFFFFFFELL;
            result = raw_spin_unlock_bh(v49 + 4144);
          }
          else
          {
            result = raw_spin_unlock(v49 + 4144);
          }
          *(_QWORD *)(a2 + 72) = 0;
          break;
        }
        goto LABEL_67;
      }
LABEL_29:
      v41 = *(_QWORD *)(a2 + 56);
      v42 = *(_QWORD **)(*(_QWORD *)(a2 + 72) + 32LL);
      v43 = v42[2];
      if ( v43 )
      {
        v44 = *(_QWORD *)(*(_QWORD *)(v41 + 8) + 24LL);
        qdf_mem_dp_tx_skb_cnt_dec();
        qdf_mem_dp_tx_skb_dec(6);
        qdf_mem_skb_total_dec(6);
        dma_unmap_page_attrs(*(_QWORD *)(v44 + 40), v43, 6, 1, 0);
        v42[2] = 0;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v45 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v45 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v41 + 352);
      }
      else
      {
        raw_spin_lock_bh(v41 + 352);
        *(_QWORD *)(v41 + 360) |= 1uLL;
      }
      *v42 = *(_QWORD *)(v41 + 94992);
      v46 = *(_DWORD *)(v41 + 95000);
      v47 = *(_QWORD *)(v41 + 360);
      *(_QWORD *)(v41 + 94992) = v42;
      *(_DWORD *)(v41 + 95000) = v46 - 1;
      if ( (v47 & 1) != 0 )
      {
        *(_QWORD *)(v41 + 360) = v47 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v41 + 352);
      }
      else
      {
        raw_spin_unlock(v41 + 352);
      }
      goto LABEL_37;
    }
    if ( !*(_DWORD *)(v30 + 8) )
    {
      _X8 = *(unsigned __int8 *)(a2 + 67);
      if ( _X8 >= 6 )
        goto LABEL_67;
      v31 = v8 + 72LL * *(unsigned __int8 *)(a2 + 67);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v32 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v32 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v32 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v31 + 5336);
      }
      else
      {
        raw_spin_lock_bh(v31 + 5336);
        *(_QWORD *)(v31 + 5344) |= 1uLL;
      }
      *(_QWORD *)v30 = *(_QWORD *)(v31 + 5288);
      v33 = *(_WORD *)(v31 + 5282);
      v34 = *(_QWORD *)(v31 + 5344);
      *(_QWORD *)(v31 + 5288) = v30;
      *(_WORD *)(v31 + 5282) = v33 + 1;
      if ( (v34 & 1) != 0 )
      {
        *(_QWORD *)(v31 + 5344) = v34 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v31 + 5336);
      }
      else
      {
        raw_spin_unlock(v31 + 5336);
      }
      *(_QWORD *)(*(_QWORD *)(a2 + 72) + 48LL) = 0;
      v35 = *(_QWORD *)(a2 + 56);
      if ( v35 )
        ++*(_DWORD *)(v35 + 91336);
    }
    _X8 = *(unsigned __int8 *)(a2 + 67);
    if ( _X8 < 6 )
    {
      v36 = v8 + 72LL * *(unsigned __int8 *)(a2 + 67);
      v37 = *(_QWORD **)(*(_QWORD *)(a2 + 72) + 40LL);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v38 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v38 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v38 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v36 + 4904);
      }
      else
      {
        raw_spin_lock_bh(v36 + 4904);
        *(_QWORD *)(v36 + 4912) |= 1uLL;
      }
      *v37 = *(_QWORD *)(v36 + 4856);
      v39 = *(_WORD *)(v36 + 4850);
      v40 = *(_QWORD *)(v36 + 4912);
      *(_QWORD *)(v36 + 4856) = v37;
      *(_WORD *)(v36 + 4850) = v39 + 1;
      if ( (v40 & 1) != 0 )
      {
        *(_QWORD *)(v36 + 4912) = v40 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v36 + 4904);
      }
      else
      {
        raw_spin_unlock(v36 + 4904);
      }
      *(_QWORD *)(*(_QWORD *)(a2 + 72) + 40LL) = 0;
LABEL_28:
      if ( (*(_BYTE *)(a2 + 32) & 0x80) == 0 )
        goto LABEL_37;
      goto LABEL_29;
    }
LABEL_67:
    __break(0x5512u);
  }
  if ( (*(_BYTE *)(a2 + 32) & 2) != 0 )
  {
    _X8 = (unsigned int *)(v8 + 18700);
    __asm { PRFM            #0x11, [X8] }
    do
      v63 = __ldxr(_X8);
    while ( __stxr(v63 - 1, _X8) );
  }
  if ( (*(_BYTE *)(a2 + 64) & 0x1C) != 0 )
    v54 = 99;
  else
    v54 = *(unsigned __int8 *)(a2 + 49);
  if ( *(_BYTE *)(v8 + 1142) == 1 )
    result = qdf_trace_msg(
               0x7Du,
               8u,
               "%s: Tx Completion Release desc %d status %d outstanding %d",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "dp_tx_desc_release",
               *(unsigned int *)(a2 + 36),
               v54,
               *(unsigned int *)(v7 + 3388));
  if ( (*(_BYTE *)(a2 + 34) & 8) == 0 )
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_tx_desc_free)(v8, a2, a3);
  return result;
}
