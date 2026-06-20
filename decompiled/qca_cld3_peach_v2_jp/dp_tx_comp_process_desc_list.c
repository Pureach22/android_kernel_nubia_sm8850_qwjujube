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
  __int64 v23; // x0
  int v24; // w1
  __int64 v25; // x26
  __int64 v26; // x21
  __int64 v27; // x24
  __int64 v28; // x25
  __int64 v29; // x27
  __int64 v30; // x0
  __int64 v31; // x24
  __int64 v32; // x8
  int v33; // w11
  __int64 v34; // x9
  unsigned int v35; // w8
  unsigned int v38; // w10
  _DWORD *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w8
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
      raw_spin_lock(v12 + 13256);
      goto LABEL_29;
    }
    raw_spin_lock_bh(v12 + 13256);
    *(_QWORD *)(v12 + 13264) |= 1uLL;
LABEL_29:
    if ( *(_DWORD *)(v12 + 13276) > v14 )
    {
      v31 = *(_QWORD *)(*(_QWORD *)(v12 + 13088) + 8LL * v14);
      if ( !v31 )
        goto LABEL_33;
      if ( *(unsigned __int8 *)(v31 + 380) <= 2u )
      {
        v35 = *(_DWORD *)(v31 + 40);
        while ( v35 )
        {
          _X12 = (unsigned int *)(v31 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v38 = __ldxr(_X12);
            if ( v38 != v35 )
              break;
            if ( !__stlxr(v35 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v38 == v35;
          v35 = v38;
          if ( _ZF )
            goto LABEL_33;
        }
      }
    }
    v31 = 0;
LABEL_33:
    v32 = *(_QWORD *)(v12 + 13264);
    if ( (v32 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 13264) = v32 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v12 + 13256);
      if ( v31 )
      {
LABEL_35:
        v13 = *(_QWORD *)v31;
        if ( *(_QWORD *)v31 )
        {
          v74 = v31;
          v17 = *(_DWORD *)(v11 + 32);
          if ( (v17 & 0x20000) != 0 )
            goto LABEL_37;
        }
        else
        {
          result = dp_peer_unref_delete(v31, 1u, a4, a5, a6, a7, a8, a9, a10, a11);
          v17 = *(_DWORD *)(v11 + 32);
          if ( (v17 & 0x20000) != 0 )
            goto LABEL_37;
        }
        goto LABEL_10;
      }
    }
    else
    {
      result = raw_spin_unlock(v12 + 13256);
      if ( v31 )
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
          v33 = *(unsigned __int8 *)(v11 + 49);
          v34 = *(_QWORD *)(v13 + 24) + *(unsigned __int16 *)(v11 + 16);
          ++*(_QWORD *)(v13 + 16);
          *(_QWORD *)(v13 + 24) = v34;
          if ( v33 )
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
      v21 = v18 + 90112;
      _X9 = (unsigned int *)(v21 + 3388);
      __asm { PRFM            #0x11, [X9] }
      do
        v71 = __ldxr(_X9);
      while ( __stxr(v71 - 1, _X9) );
      v23 = *(unsigned int *)(v21 + 3388);
      v24 = *(_DWORD *)(v21 + 3392);
      if ( v24 < (int)v23 )
      {
        v24 = *(_DWORD *)(v21 + 3388);
        *(_DWORD *)(v21 + 3392) = v23;
      }
      qdf_mem_tx_desc_cnt_update(v23, v24);
      v25 = *(_QWORD *)(v11 + 8);
      v26 = *(_QWORD *)(v12 + 24);
      v27 = *(_QWORD *)(v11 + 40);
      v28 = *(unsigned __int16 *)(v11 + 16);
      v29 = *(int *)(v25 + 212);
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(v29);
      qdf_mem_skb_total_dec(v29);
      if ( *(_BYTE *)(v26 + 624) == 1 && (_qdf_is_pp_nbuf(v25) & 1) != 0 && *(_QWORD *)(v25 + 40) )
      {
        v30 = *(_QWORD *)(v26 + 40);
        if ( (*(_BYTE *)(v30 + 844) & 0x40) == 0 )
          _dma_sync_single_for_cpu(v30, v27);
      }
      else
      {
        dma_unmap_page_attrs(*(_QWORD *)(v26 + 40), v27, v28, 1, 0);
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
    v39 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(v12 + 1128) + 74392LL) + 152LL);
    if ( *(v39 - 1) != -1819724828 )
      __break(0x8228u);
    v40 = ((double (__fastcall *)(__int64, _QWORD *))v39)(v11 + 104, v75);
    dp_tx_comp_process_tx_status(
      v12,
      v11,
      (__int64)v75,
      (unsigned __int8 *)v13,
      a3,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47);
    v56 = dp_tx_comp_process_desc(v12, v11, v48, v49, v50, v51, v52, v53, v54, v55, (__int64)v75, v13);
    v65 = *(_DWORD *)(v11 + 32);
    if ( (v65 & 0x40000) != 0 )
    {
      v15 = *(_QWORD *)(v11 + 8);
      if ( !v15 )
        goto LABEL_6;
      goto LABEL_5;
    }
    if ( (v65 & 0x40) != 0 )
      v56 = dp_tx_comp_free_buf(v12, v11, 0, v57, v58, v59, v60, v61, v62, v63, v64);
    result = dp_tx_desc_release(v56, v11, *(unsigned __int8 *)(v11 + 67));
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
