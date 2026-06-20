__int64 __fastcall dp_soc_deinit(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x23
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 v13; // x21
  void (*v14)(void); // x8
  void (__fastcall *v15)(_QWORD); // x8
  void (__fastcall *v16)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x26
  __int64 v19; // x27
  __int64 v20; // x22
  __int64 v21; // x21
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int64 v31; // x8
  __int64 v32; // x26
  __int64 v33; // x22
  __int64 v34; // x21
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x8
  __int64 *v45; // x0
  __int64 *v46; // x9
  __int64 v47; // x8
  __int64 *v48; // x0
  __int64 *v49; // x9
  __int64 v50; // x4
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  _QWORD *v67; // x0
  _QWORD *v68; // x21
  __int64 result; // x0
  __int64 v70; // [xsp+0h] [xbp-10h] BYREF
  __int64 v71; // [xsp+8h] [xbp-8h]

  v10 = a1 + 0x4000;
  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 48);
  if ( a1 )
  {
    v12 = *(_QWORD *)(a1 + 20112);
    if ( v12 )
    {
      v13 = *(_QWORD *)(v12 + 416);
      if ( v13 )
      {
        v14 = *(void (**)(void))(v13 + 56);
        if ( v14 )
        {
          if ( *((_DWORD *)v14 - 1) != -1093861181 )
            __break(0x8228u);
          v14();
        }
        v15 = *(void (__fastcall **)(_QWORD))(v13 + 64);
        if ( v15 )
        {
          if ( *((_DWORD *)v15 - 1) != -1093861181 )
            __break(0x8228u);
          v15(a1);
        }
      }
    }
  }
  if ( *(_BYTE *)(v10 + 2391) == 1 )
  {
    dp_peer_find_detach(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    v16 = *(void (__fastcall **)(_QWORD))(a1 + 1248);
    if ( *((_DWORD *)v16 - 1) != -1093861181 )
      __break(0x8228u);
    v16(a1);
    *(_BYTE *)(v10 + 2391) = 0;
  }
  flush_work(a1 + 17944);
  cancel_work_sync(a1 + 17944);
  *(_QWORD *)(a1 + 13096) = 0;
  *(_QWORD *)(a1 + 13104) = 0;
  *(_WORD *)(a1 + 13112) = 0;
  v70 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17872);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17872);
    *(_QWORD *)(a1 + 17880) |= 1uLL;
  }
  while ( !(unsigned int)qdf_list_remove_front((_DWORD *)(a1 + 17848), &v70) )
  {
    v18 = v70;
    v19 = *(_QWORD *)(a1 + 24);
    v20 = *(int *)(v70 + 88);
    v21 = *(_QWORD *)(v70 + 80);
    qdf_mem_skb_total_dec(v20);
    dma_unmap_page_attrs(*(_QWORD *)(v19 + 40), v21, v20, 0, 0);
    _qdf_mem_free(*(_QWORD *)(v18 + 56));
    _qdf_mem_free(v70);
  }
  v22 = *(_QWORD *)(a1 + 17880);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17880) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17872);
    if ( !*(_DWORD *)(v10 + 1480) )
      goto LABEL_26;
    goto LABEL_25;
  }
  raw_spin_unlock(a1 + 17872);
  if ( *(_DWORD *)(v10 + 1480) )
LABEL_25:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "qdf_list_destroy",
      v70,
      v71);
LABEL_26:
  v70 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v31 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v31 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 20040);
  }
  else
  {
    raw_spin_lock_bh(a1 + 20040);
    *(_QWORD *)(a1 + 20048) |= 1uLL;
  }
  *(_BYTE *)(v10 + 3672) = 0;
  while ( !(unsigned int)qdf_list_remove_front((_DWORD *)(a1 + 20016), &v70) )
  {
    v32 = *(_QWORD *)(a1 + 24);
    v33 = *(int *)(v70 + 40);
    v34 = *(_QWORD *)(v70 + 32);
    qdf_mem_skb_total_dec(v33);
    dma_unmap_page_attrs(*(_QWORD *)(v32 + 40), v34, v33, 0, 0);
    _qdf_mem_free(*(_QWORD *)(v70 + 24));
    _qdf_mem_free(v70);
  }
  v35 = *(_QWORD *)(a1 + 20048);
  if ( (v35 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 20040);
    if ( !*(_DWORD *)(v10 + 3648) )
      goto LABEL_42;
    goto LABEL_35;
  }
  *(_QWORD *)(a1 + 20048) = v35 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 20040);
  if ( *(_DWORD *)(v10 + 3648) )
LABEL_35:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "qdf_list_destroy",
      v70);
LABEL_42:
  while ( 1 )
  {
    v45 = *(__int64 **)(a1 + 17992);
    if ( !v45 )
      break;
    v46 = *(__int64 **)(a1 + 18000);
    --*(_DWORD *)(v10 + 1624);
    if ( v45 == v46 )
    {
      v44 = 0;
      *(_QWORD *)(a1 + 18000) = 0;
    }
    else
    {
      v44 = *v45;
    }
    *(_QWORD *)(a1 + 17992) = v44;
    *v45 = 0;
    _qdf_nbuf_free((__int64)v45);
  }
  while ( 1 )
  {
    v48 = *(__int64 **)(a1 + 19992);
    if ( !v48 )
      break;
    v49 = *(__int64 **)(a1 + 20000);
    --*(_DWORD *)(v10 + 3624);
    if ( v48 == v49 )
    {
      v47 = 0;
      *(_QWORD *)(a1 + 20000) = 0;
    }
    else
    {
      v47 = *v48;
    }
    *(_QWORD *)(a1 + 19992) = v47;
    *v48 = 0;
    _qdf_nbuf_free((__int64)v48);
  }
  dp_reo_cmdlist_destroy((_QWORD *)a1);
  dp_soc_tx_desc_sw_pools_deinit(a1);
  ((void (__fastcall *)(__int64))dp_soc_srng_deinit)(a1);
  dp_ipa_uc_detach(a1, 0);
  dp_deinit_ipa_rx_alt_refill_buf_ring();
  dp_deinit_ipa_rx_refill_buf_ring((_QWORD *)a1);
  dp_srng_deinit(a1, (__int64 *)(a1 + 1960), 0xBu, 0, v50, v51, v52, v53, v54, v55, v56, v57, v58);
  dp_soc_print_inactive_objects(a1);
  htt_soc_htc_dealloc(*(_QWORD *)(a1 + 48));
  htt_soc_detach(v11);
  if ( a1 )
  {
    v67 = *(_QWORD **)(a1 + 18792);
    if ( v67 )
    {
      do
      {
        v68 = (_QWORD *)*v67;
        _qdf_nbuf_free((__int64)v67);
        v67 = v68;
      }
      while ( v68 );
    }
    *(_BYTE *)(v10 + 2400) = 0;
    *(_QWORD *)(a1 + 18792) = 0;
    *(_QWORD *)(a1 + 18800) = 0;
    *(_DWORD *)(a1 + 18808) = 0;
  }
  result = wlan_minidump_remove(v59, v60, v61, v62, v63, v64, v65, v66, a1, 22528, *(_QWORD *)(a1 + 16));
  _ReadStatusReg(SP_EL0);
  return result;
}
