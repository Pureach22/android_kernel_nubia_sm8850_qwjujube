__int64 __fastcall dp_rx_bar_frame_handle(
        __int64 a1,
        unsigned int *a2,
        __int64 *a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 v6; // x22
  __int64 v8; // x27
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w0
  unsigned int v19; // w27
  unsigned int v20; // w26
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _QWORD *v29; // x28
  __int64 v30; // x0
  void (__fastcall *v31)(__int64, __int64, __int64, __int64, __int64, __int64); // x26
  unsigned __int16 v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  char v42; // w8
  __int64 v43; // x8
  __int64 v44; // x25
  __int64 (__fastcall *v45)(_QWORD); // x8
  __int16 v46; // w24
  _DWORD *v47; // x8
  unsigned __int64 v48; // x23
  __int64 v49; // x1
  __int64 v50; // x8
  __int64 v51; // x2
  __int64 v52; // x1
  __int64 v53; // x8
  unsigned __int16 v54; // [xsp+Ch] [xbp-14h]
  _QWORD v55[2]; // [xsp+10h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *((unsigned __int8 *)a3 + 28) >= 5uLL )
    __break(0x5512u);
  v6 = *a3;
  v8 = a1 + 120LL * *((unsigned __int8 *)a3 + 28);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18464);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18464);
    *(_QWORD *)(a1 + 18472) |= 1uLL;
  }
  dp_rx_nbuf_unmap_pool(a1, v8 + 12368, v6);
  *((_BYTE *)a3 + 30) |= 2u;
  v15 = *(_QWORD *)(a1 + 18472);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 18472) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 18464);
  }
  else
  {
    raw_spin_unlock(a1 + 18464);
  }
  v16 = *(_QWORD *)(v6 + 224);
  v17 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 392LL);
  if ( *((_DWORD *)v17 - 1) != 855462014 )
    __break(0x8228u);
  v18 = v17(v16);
  v19 = *((unsigned __int8 *)a3 + 28);
  v20 = v18;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), v19)
    || (v29 = *(_QWORD **)(a1 + 72)) == nullptr )
  {
    result = qdf_trace_msg(
               0x82u,
               8u,
               "%s: %pK: pdev is null for pool_id = %d",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "dp_rx_bar_frame_handle",
               a1,
               *((unsigned __int8 *)a3 + 28));
  }
  else
  {
    dp_rx_bar_frame_handle(a1, a4, v20, a5, a6);
    v30 = *(_QWORD *)(a1 + 40);
    v31 = (void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64))v29[11948];
    v55[0] = 0;
    v32 = wlan_cfg_rx_buffer_size(v30);
    if ( v31 )
    {
      v44 = *(_QWORD *)(v6 + 224);
      v54 = v32;
      v45 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
      if ( *((_DWORD *)v45 - 1) != 855462014 )
        __break(0x8228u);
      v46 = v45(v44);
      v47 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 880LL);
      if ( *(v47 - 1) != -177782713 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v47)(v44, v55);
      if ( *(_WORD *)(a4 + 12) || (*(_BYTE *)(a4 + 6) & 0x10) != 0 )
        v48 = *(unsigned __int16 *)(a1 + 1138);
      else
        v48 = LOWORD(v55[0]) + (unsigned __int64)*(unsigned __int16 *)(a1 + 1138);
      if ( (unsigned __int16)(v46 + v48) >= (unsigned int)v54 )
        v49 = v54;
      else
        v49 = (unsigned __int16)(v46 + v48);
      qdf_nbuf_set_pktlen(v6, v49);
      v50 = *(_QWORD *)(v6 + 40);
      if ( v50 )
        *(_QWORD *)(v6 + 40) = v50 + v48;
      skb_pull(v6, (unsigned int)v48);
      v51 = *(unsigned __int8 *)(v6 + 86);
      v52 = *(unsigned __int8 *)v29;
      if ( *((_DWORD *)v31 - 1) != -915278510 )
        __break(0x823Au);
      v31(a1, v52, v51, v6, 4, 3);
      v53 = *(_QWORD *)(v6 + 40);
      if ( v53 )
        *(_QWORD *)(v6 + 40) = v53 - v48;
      skb_push(v6, (unsigned int)v48);
    }
    dp_rx_link_desc_return_by_addr(a1, a2, 0, v33, v34, v35, v36, v37, v38, v39, v40);
    result = dp_rx_buffer_pool_nbuf_free(a1, *a3, *((unsigned __int8 *)a3 + 28));
    v42 = *((_BYTE *)a3 + 30);
    *a3 = 0;
    *((_BYTE *)a3 + 30) = v42 & 0xFE;
    *a3 = v29[11903];
    v43 = v29[11904];
    v29[11903] = a3;
    if ( !v43 || !*a3 )
      v29[11904] = a3;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
