__int64 __fastcall dp_tx_comp_process_desc_list(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x22
  __int64 v12; // x20
  __int64 v13; // x23
  unsigned int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x28
  int v17; // w8
  __int64 v18; // x8
  int v19; // w12
  __int64 v20; // x10
  __int64 v21; // x8
  __int64 v22; // x0
  int v23; // w1
  __int64 v24; // x26
  __int64 v25; // x21
  __int64 v26; // x24
  __int64 v27; // x25
  __int64 v28; // x27
  __int64 v29; // x0
  __int64 v30; // x24
  __int64 v31; // x8
  int v32; // w11
  __int64 v33; // x9
  unsigned int v34; // w8
  unsigned int v37; // w10
  _DWORD *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w8
  unsigned int v71; // w10
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-38h]
  __int64 v74; // [xsp+10h] [xbp-30h]
  _QWORD v75[5]; // [xsp+18h] [xbp-28h] BYREF

  v75[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v75, 0, 32);
  if ( !a2 )
    goto LABEL_68;
  v11 = a2;
  v12 = result;
  v13 = 0;
  v14 = 65534;
  StatusReg = _ReadStatusReg(SP_EL0);
  v74 = 0;
  do
  {
    v16 = *(_QWORD *)v11;
    if ( v14 == *(unsigned __int16 *)(v11 + 50) )
    {
      v17 = *(_DWORD *)(v11 + 32);
      if ( (v17 & 0x20000) != 0 )
        goto LABEL_37;
      goto LABEL_10;
    }
    if ( v13 )
    {
      dp_txrx_peer_unref_delete(v74, 1u, a4, a5, a6, a7, a8, a9, a10, a11);
      v14 = *(unsigned __int16 *)(v11 + 50);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_28;
    }
    else
    {
      v14 = *(unsigned __int16 *)(v11 + 50);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_28;
    }
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
LABEL_28:
      raw_spin_lock(v12 + 13304);
      goto LABEL_29;
    }
    raw_spin_lock_bh(v12 + 13304);
    *(_QWORD *)(v12 + 13312) |= 1uLL;
LABEL_29:
    if ( *(_DWORD *)(v12 + 13324) > v14 )
    {
      v30 = *(_QWORD *)(*(_QWORD *)(v12 + 13136) + 8LL * v14);
      if ( !v30 )
        goto LABEL_33;
      if ( *(unsigned __int8 *)(v30 + 388) <= 2u )
      {
        v34 = *(_DWORD *)(v30 + 40);
        while ( v34 )
        {
          _X12 = (unsigned int *)(v30 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v37 = __ldxr(_X12);
            if ( v37 != v34 )
              break;
            if ( !__stlxr(v34 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v37 == v34;
          v34 = v37;
          if ( _ZF )
            goto LABEL_33;
        }
      }
    }
    v30 = 0;
LABEL_33:
    v31 = *(_QWORD *)(v12 + 13312);
    if ( (v31 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 13312) = v31 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v12 + 13304);
      if ( v30 )
      {
LABEL_35:
        v13 = *(_QWORD *)v30;
        if ( *(_QWORD *)v30 )
        {
          v74 = v30;
          v17 = *(_DWORD *)(v11 + 32);
          if ( (v17 & 0x20000) != 0 )
            goto LABEL_37;
        }
        else
        {
          result = dp_peer_unref_delete(v30, 1u, a4, a5, a6, a7, a8, a9, a10, a11);
          v17 = *(_DWORD *)(v11 + 32);
          if ( (v17 & 0x20000) != 0 )
            goto LABEL_37;
        }
        goto LABEL_10;
      }
    }
    else
    {
      result = raw_spin_unlock(v12 + 13304);
      if ( v30 )
        goto LABEL_35;
    }
    v13 = 0;
    v17 = *(_DWORD *)(v11 + 32);
    if ( (v17 & 0x20000) != 0 )
    {
LABEL_37:
      if ( v13 )
      {
        if ( (v17 & 4) != 0 )
        {
          v32 = *(unsigned __int8 *)(v11 + 49);
          v33 = *(_QWORD *)(v13 + 24) + *(unsigned __int16 *)(v11 + 16);
          ++*(_QWORD *)(v13 + 16);
          *(_QWORD *)(v13 + 24) = v33;
          if ( v32 )
            ++*(_DWORD *)(v13 + 12);
        }
      }
      goto LABEL_7;
    }
LABEL_10:
    if ( (v17 & 4) != 0 )
    {
      v18 = *(_QWORD *)(v11 + 56);
      if ( v13 )
      {
        v19 = *(unsigned __int8 *)(v11 + 49);
        v20 = *(_QWORD *)(v13 + 24) + *(unsigned __int16 *)(v11 + 16);
        ++*(_QWORD *)(v13 + 16);
        *(_QWORD *)(v13 + 24) = v20;
        if ( v19 )
          ++*(_DWORD *)(v13 + 12);
      }
      v21 = v18 + 94208;
      _X9 = (unsigned int *)(v21 + 188);
      __asm { PRFM            #0x11, [X9] }
      do
        v71 = __ldxr(_X9);
      while ( __stxr(v71 - 1, _X9) );
      v22 = *(unsigned int *)(v21 + 188);
      v23 = *(_DWORD *)(v21 + 192);
      if ( v23 < (int)v22 )
      {
        v23 = *(_DWORD *)(v21 + 188);
        *(_DWORD *)(v21 + 192) = v22;
      }
      qdf_mem_tx_desc_cnt_update(v22, v23);
      v24 = *(_QWORD *)(v11 + 8);
      v25 = *(_QWORD *)(v12 + 24);
      v26 = *(_QWORD *)(v11 + 40);
      v27 = *(unsigned __int16 *)(v11 + 16);
      v28 = *(int *)(v24 + 212);
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(v28);
      qdf_mem_skb_total_dec(v28);
      if ( *(_BYTE *)(v25 + 624) == 1 && (_qdf_is_pp_nbuf(v24) & 1) != 0 && *(_QWORD *)(v24 + 40) )
      {
        v29 = *(_QWORD *)(v25 + 40);
        if ( (*(_BYTE *)(v29 + 844) & 0x40) == 0 )
          _dma_sync_single_for_cpu(v29, v26);
      }
      else
      {
        dma_unmap_page_attrs(*(_QWORD *)(v25 + 40), v26, v27, 1, 0);
      }
      v15 = *(_QWORD *)(v11 + 8);
      if ( !v15 )
        goto LABEL_6;
LABEL_5:
      _qdf_nbuf_free(v15);
LABEL_6:
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_tx_desc_free)(
                 v12,
                 v11,
                 *(unsigned __int8 *)(v11 + 67));
      goto LABEL_7;
    }
    v38 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(v12 + 1128) + 74392LL) + 152LL);
    if ( *(v38 - 1) != -1819724828 )
      __break(0x8228u);
    v39 = ((double (__fastcall *)(__int64, _QWORD *))v38)(v11 + 104, v75);
    dp_tx_comp_process_tx_status(v12, v11, (__int64)v75, (__int64 *)v13, a3, v39, v40, v41, v42, v43, v44, v45, v46);
    v55 = dp_tx_comp_process_desc(v12, v11, v47, v48, v49, v50, v51, v52, v53, v54, (__int64)v75, v13);
    v64 = *(_DWORD *)(v11 + 32);
    if ( (v64 & 0x40000) != 0 )
    {
      v15 = *(_QWORD *)(v11 + 8);
      if ( !v15 )
        goto LABEL_6;
      goto LABEL_5;
    }
    if ( (v64 & 0x40) != 0 )
      v55 = dp_tx_comp_free_buf(v12, v11, 0, v56, v57, v58, v59, v60, v61, v62, v63);
    result = dp_tx_desc_release(v55, v11, *(unsigned __int8 *)(v11 + 67));
LABEL_7:
    v11 = v16;
  }
  while ( v16 );
  if ( v13 )
    result = dp_txrx_peer_unref_delete(v74, 1u, a4, a5, a6, a7, a8, a9, a10, a11);
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return result;
}
