__int64 __fastcall dp_tx_desc_release(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v7; // x23
  __int64 v8; // x21
  __int64 v9; // x0
  int v10; // w1
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 v29; // x22
  __int64 v30; // x24
  unsigned __int64 v31; // x8
  __int16 v32; // w9
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x22
  _QWORD *v36; // x25
  unsigned __int64 v37; // x8
  __int16 v38; // w9
  __int64 v39; // x8
  __int64 v40; // x24
  _QWORD *v41; // x25
  __int64 v42; // x22
  __int64 v43; // x26
  unsigned __int64 v44; // x8
  int v45; // w9
  __int64 v46; // x8
  __int64 v47; // x22
  __int64 v48; // x24
  unsigned __int64 StatusReg; // x8
  __int16 v50; // w9
  __int64 v51; // x8
  __int64 v53; // x5
  const char *v54; // x2
  unsigned int v57; // w10
  unsigned int v63; // w10

  v3 = *(_QWORD *)(a2 + 56);
  v4 = *(_QWORD *)(a2 + 144);
  v7 = v3 + 94208;
  if ( v4 )
  {
    _qdf_nbuf_free(v4);
    *(_QWORD *)(a2 + 144) = 0;
  }
  v8 = *(_QWORD *)(v3 + 8);
  while ( 1 )
  {
    _X8 = (unsigned int *)(v7 + 188);
    __asm { PRFM            #0x11, [X8] }
    do
      v57 = __ldxr(_X8);
    while ( __stxr(v57 - 1, _X8) );
    v9 = *(unsigned int *)(v7 + 188);
    v10 = *(_DWORD *)(v7 + 192);
    if ( v10 < (int)v9 )
    {
      v10 = *(_DWORD *)(v7 + 188);
      *(_DWORD *)(v7 + 192) = v9;
    }
    result = qdf_mem_tx_desc_cnt_update(v9, v10);
    if ( !*(_QWORD *)(a2 + 72) )
      break;
    if ( *(_BYTE *)(a2 + 65) != 1 )
      goto LABEL_28;
    qdf_trace_msg(
      0x45u,
      0,
      "%s: Free the tso descriptor",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_tx_tso_desc_release");
    v28 = *(_QWORD *)(a2 + 72);
    if ( !*(_QWORD *)(v28 + 40) )
    {
      v54 = "%s: SO desc is NULL!";
      goto LABEL_59;
    }
    v29 = *(_QWORD *)(v28 + 48);
    if ( !v29 )
    {
      v54 = "%s: TSO num desc is NULL!";
LABEL_59:
      qdf_trace_msg(0x7Du, 2u, v54, v20, v21, v22, v23, v24, v25, v26, v27, "dp_tx_tso_desc_release");
      if ( (*(_BYTE *)(a2 + 32) & 0x80) == 0 )
      {
LABEL_37:
        v47 = *(_QWORD *)(a2 + 72);
        *(_WORD *)(v47 + 24) = 0;
        if ( (unsigned __int8)a3 < 6u )
        {
          v48 = v8 + 136LL * (unsigned __int8)a3;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v48 + 4192);
          }
          else
          {
            raw_spin_lock_bh(v48 + 4192);
            *(_QWORD *)(v48 + 4200) |= 1uLL;
          }
          *(_QWORD *)v47 = *(_QWORD *)(v48 + 4184);
          v50 = *(_WORD *)(v48 + 4088);
          v51 = *(_QWORD *)(v48 + 4200);
          *(_QWORD *)(v48 + 4184) = v47;
          *(_WORD *)(v48 + 4088) = v50 + 1;
          if ( (v51 & 1) != 0 )
          {
            *(_QWORD *)(v48 + 4200) = v51 & 0xFFFFFFFFFFFFFFFELL;
            result = raw_spin_unlock_bh(v48 + 4192);
          }
          else
          {
            result = raw_spin_unlock(v48 + 4192);
          }
          *(_QWORD *)(a2 + 72) = 0;
          break;
        }
        goto LABEL_67;
      }
LABEL_29:
      v40 = *(_QWORD *)(a2 + 56);
      v41 = *(_QWORD **)(*(_QWORD *)(a2 + 72) + 32LL);
      v42 = v41[2];
      if ( v42 )
      {
        v43 = *(_QWORD *)(*(_QWORD *)(v40 + 8) + 24LL);
        qdf_mem_dp_tx_skb_cnt_dec();
        qdf_mem_dp_tx_skb_dec(6);
        qdf_mem_skb_total_dec(6);
        dma_unmap_page_attrs(*(_QWORD *)(v43 + 40), v42, 6, 1, 0);
        v41[2] = 0;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v44 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v44 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v44 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v40 + 352);
      }
      else
      {
        raw_spin_lock_bh(v40 + 352);
        *(_QWORD *)(v40 + 360) |= 1uLL;
      }
      *v41 = *(_QWORD *)(v40 + 95888);
      v45 = *(_DWORD *)(v40 + 95896);
      v46 = *(_QWORD *)(v40 + 360);
      *(_QWORD *)(v40 + 95888) = v41;
      *(_DWORD *)(v40 + 95896) = v45 - 1;
      if ( (v46 & 1) != 0 )
      {
        *(_QWORD *)(v40 + 360) = v46 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v40 + 352);
      }
      else
      {
        raw_spin_unlock(v40 + 352);
      }
      goto LABEL_37;
    }
    if ( !*(_DWORD *)(v29 + 8) )
    {
      if ( *(unsigned __int8 *)(a2 + 67) >= 6uLL )
        goto LABEL_67;
      v30 = v8 + 72LL * *(unsigned __int8 *)(a2 + 67);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v31 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v31 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v30 + 5384);
      }
      else
      {
        raw_spin_lock_bh(v30 + 5384);
        *(_QWORD *)(v30 + 5392) |= 1uLL;
      }
      *(_QWORD *)v29 = *(_QWORD *)(v30 + 5336);
      v32 = *(_WORD *)(v30 + 5330);
      v33 = *(_QWORD *)(v30 + 5392);
      *(_QWORD *)(v30 + 5336) = v29;
      *(_WORD *)(v30 + 5330) = v32 + 1;
      if ( (v33 & 1) != 0 )
      {
        *(_QWORD *)(v30 + 5392) = v33 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v30 + 5384);
      }
      else
      {
        raw_spin_unlock(v30 + 5384);
      }
      *(_QWORD *)(*(_QWORD *)(a2 + 72) + 48LL) = 0;
      v34 = *(_QWORD *)(a2 + 56);
      if ( v34 )
        ++*(_DWORD *)(v34 + 92232);
    }
    if ( *(unsigned __int8 *)(a2 + 67) < 6uLL )
    {
      v35 = v8 + 72LL * *(unsigned __int8 *)(a2 + 67);
      v36 = *(_QWORD **)(*(_QWORD *)(a2 + 72) + 40LL);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v37 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v37 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v37 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v35 + 4952);
      }
      else
      {
        raw_spin_lock_bh(v35 + 4952);
        *(_QWORD *)(v35 + 4960) |= 1uLL;
      }
      *v36 = *(_QWORD *)(v35 + 4904);
      v38 = *(_WORD *)(v35 + 4898);
      v39 = *(_QWORD *)(v35 + 4960);
      *(_QWORD *)(v35 + 4904) = v36;
      *(_WORD *)(v35 + 4898) = v38 + 1;
      if ( (v39 & 1) != 0 )
      {
        *(_QWORD *)(v35 + 4960) = v39 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v35 + 4952);
      }
      else
      {
        raw_spin_unlock(v35 + 4952);
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
    _X8 = (unsigned int *)(v8 + 18756);
    __asm { PRFM            #0x11, [X8] }
    do
      v63 = __ldxr(_X8);
    while ( __stxr(v63 - 1, _X8) );
  }
  if ( (*(_BYTE *)(a2 + 64) & 0x1C) != 0 )
    v53 = 99;
  else
    v53 = *(unsigned __int8 *)(a2 + 49);
  if ( *(_BYTE *)(v8 + 1142) == 1 )
    result = qdf_trace_msg(
               0x7Du,
               8u,
               "%s: Tx Completion Release desc %d status %d outstanding %d",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "dp_tx_desc_release",
               *(unsigned int *)(a2 + 36),
               v53,
               *(unsigned int *)(v7 + 188));
  if ( (*(_BYTE *)(a2 + 34) & 8) == 0 )
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_tx_desc_free)(v8, a2, a3);
  return result;
}
