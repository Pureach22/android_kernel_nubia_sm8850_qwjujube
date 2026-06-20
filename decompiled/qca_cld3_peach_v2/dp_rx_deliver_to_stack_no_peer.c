__int64 __fastcall dp_rx_deliver_to_stack_no_peer(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w22
  unsigned __int64 v11; // x8
  __int64 v13; // x19
  __int64 v14; // x21
  __int16 v15; // w21
  __int64 v16; // x23
  unsigned __int64 StatusReg; // x8
  unsigned int v18; // w9
  unsigned int v25; // w11
  __int64 v27; // x0
  __int64 (__fastcall *v28)(_QWORD); // x8
  unsigned int v29; // w0
  int v30; // w8
  unsigned int v31; // w9
  unsigned int v32; // w24
  unsigned int v33; // w8
  __int64 v34; // x8
  int v35; // w9
  int v36; // w9
  int v37; // w10
  __int64 v38; // x8
  __int64 v39; // x1
  _DWORD *v40; // x8
  __int64 v41; // x1
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int **v51; // x8
  unsigned __int64 v52; // x9
  __int64 v53; // x10
  __int64 (__fastcall *v54)(__int64, __int64); // x8
  __int64 v55; // x0
  __int64 v56; // x9
  __int64 tgt_peer_by_id; // x22
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v76; // w9
  __int64 v77; // x8

  v10 = *(unsigned __int16 *)(a2 + 62);
  v11 = *(unsigned int *)(result + 13324);
  v13 = result;
  if ( (unsigned int)v11 < v10 || (v15 = *(_WORD *)(a2 + 86), v11 = (unsigned __int8)v15, (unsigned __int8)v15 > 5u) )
  {
    v14 = 0;
    goto LABEL_60;
  }
  v16 = 18984;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(result + 18984);
  }
  else
  {
    raw_spin_lock_bh(result + 18984);
    *(_QWORD *)(v13 + 18992) |= 1uLL;
  }
  v14 = *(_QWORD *)(v13 + 8LL * (v15 & 7) + 12960);
  if ( !v14 )
  {
LABEL_25:
    v34 = *(_QWORD *)(v13 + 18992);
    if ( (v34 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 18992) = v34 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v13 + 18984);
    }
    else
    {
      result = raw_spin_unlock(v13 + 18984);
    }
    v14 = 0;
    goto LABEL_60;
  }
  v18 = *(_DWORD *)(v14 + 43384);
  do
  {
    if ( !v18 )
      goto LABEL_25;
    _X13 = (unsigned int *)(v14 + 43384);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v25 = __ldxr(_X13);
      if ( v25 != v18 )
        break;
      if ( !__stlxr(v18 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v25 == v18;
    v18 = v25;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v14 + 43396);
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v76 = __ldxr(_X8);
    while ( __stxr(v76 + 1, _X8) );
    v77 = *(_QWORD *)(v13 + 18992);
    if ( (v77 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 18992) = v77 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v13 + v16);
      v11 = *(unsigned int *)(v14 + 280);
      if ( (_DWORD)v11 )
        goto LABEL_60;
    }
    else
    {
      result = raw_spin_unlock(v13 + v16);
      v11 = *(unsigned int *)(v14 + 280);
      if ( (_DWORD)v11 )
        goto LABEL_60;
    }
    v11 = (unsigned int)*(char *)(a2 + 84);
    if ( (v11 & 0x80000000) != 0 )
      goto LABEL_60;
    v27 = *(_QWORD *)(a2 + 224);
    v28 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v13 + 1128) + 74392LL) + 536LL);
    if ( *((_DWORD *)v28 - 1) != 855462014 )
      __break(0x8228u);
    v29 = v28(v27);
    v16 = v29;
    v30 = *(unsigned __int16 *)(a2 + 60) + *(unsigned __int16 *)(v13 + 1138);
    v31 = *(_DWORD *)(a2 + 112);
    *(_BYTE *)(a2 + 75) = 1;
    v32 = v29 + v30;
    v33 = v29 + v30 - v31;
    if ( v32 < v31 )
    {
      skb_trim(a2, v32);
      goto LABEL_36;
    }
    if ( *(_DWORD *)(a2 + 116) )
    {
      v33 = v32 - v31;
      if ( v32 != v31 )
      {
        v35 = 0;
        goto LABEL_33;
      }
    }
    else
    {
      v37 = *(_DWORD *)(a2 + 208);
      v36 = *(_DWORD *)(a2 + 212);
      if ( v36 - v37 < v33 )
      {
        v35 = v37 - v36;
LABEL_33:
        if ( (unsigned int)pskb_expand_head(a2, 0, v35 + v33, 2080) )
          dev_kfree_skb_any_reason(a2, 1);
      }
    }
    skb_put(a2, v32 - *(_DWORD *)(a2 + 112));
LABEL_36:
    v38 = *(_QWORD *)(a2 + 40);
    v39 = (unsigned int)v16 + *(unsigned __int16 *)(v13 + 1138);
    if ( v38 )
      *(_QWORD *)(a2 + 40) = v38 + (unsigned int)v39;
    skb_pull(a2, v39);
    if ( !_qdf_nbuf_data_is_ipv4_arp_pkt(*(_QWORD *)(a2 + 224))
      && !_qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a2 + 224))
      && !_qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a2 + 224))
      && !_qdf_nbuf_data_is_ipv6_dhcp_pkt(*(unsigned __int16 **)(a2 + 224))
      && !_qdf_nbuf_data_is_dns_query(*(_QWORD *)(a2 + 224))
      && !_qdf_nbuf_data_is_dns_response(*(_QWORD *)(a2 + 224)) )
    {
      result = _qdf_nbuf_is_ipv4_wapi_pkt(a2);
      if ( (result & 1) == 0 )
        goto LABEL_60;
    }
    if ( !*(_QWORD *)(v14 + 168) )
    {
      tgt_peer_by_id = dp_peer_get_tgt_peer_by_id(v13, v10);
      if ( !tgt_peer_by_id )
      {
        result = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a2 + 224));
        if ( (result & 1) == 0 )
          goto LABEL_60;
        result = dp_peer_get_tgt_peer_by_vdev(v13, v14);
        tgt_peer_by_id = result;
        if ( !result )
          goto LABEL_60;
      }
      if ( *(_DWORD *)(tgt_peer_by_id + 408) != 2 || !*(_QWORD *)tgt_peer_by_id )
      {
        result = dp_peer_unref_delete(tgt_peer_by_id, 2u, a3, a4, a5, a6, a7, a8, a9, a10);
        goto LABEL_60;
      }
      *(_DWORD *)(a2 + 48) |= 0x80u;
      if ( (unsigned int)dp_rx_enqueue_rx(tgt_peer_by_id, *(_QWORD *)tgt_peer_by_id, a2) )
      {
        if ( v13 )
        {
          v58 = (unsigned int *)(*(_QWORD *)(v13 + 13776) + 1LL);
          *(_QWORD *)(v13 + 13776) = v58;
        }
      }
      else if ( v13 )
      {
        v58 = (unsigned int *)(unsigned int)(*(_DWORD *)(v13 + 13756) + 1);
        *(_DWORD *)(v13 + 13756) = (_DWORD)v58;
      }
      dp_vdev_unref_delete(v13, v14, 2u, v58, v59, v60, v61, v62, v63, v64, v65, v66);
      return dp_peer_unref_delete(tgt_peer_by_id, 2u, v67, v68, v69, v70, v71, v72, v73, v74);
    }
    v40 = *(_DWORD **)(v13 + 1536);
    if ( !v40 )
      goto LABEL_57;
    v41 = *(_QWORD *)(a2 + 224) + 6LL;
    if ( *(v40 - 1) != 69695039 )
      __break(0x8228u);
    v42 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v40)(v13, v41, 0, 2, 255);
    if ( !v42 )
      goto LABEL_57;
    if ( *(_DWORD *)(v42 + 408) != 1 || (v51 = *(unsigned int ***)(v42 + 416)) == nullptr )
      v51 = (unsigned int **)v42;
    _X8 = *v51;
    if ( !_X8 )
      goto LABEL_56;
    v52 = *(unsigned int *)(a2 + 48);
    v53 = (v52 >> 18) & 0xF;
    if ( (unsigned int)v53 < 5 )
      break;
    __break(0x5512u);
  }
  *(_DWORD *)(a2 + 48) = v52 & 0xFE3FFFFF | ((*((_BYTE *)_X8 + v53 + 2276) & 7) << 22);
LABEL_56:
  dp_peer_unref_delete(v42, 2u, v43, v44, v45, v46, v47, v48, v49, v50);
LABEL_57:
  *(_DWORD *)(a2 + 48) |= 0x80u;
  v54 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 168);
  v55 = *(_QWORD *)(v14 + 88);
  if ( *((_DWORD *)v54 - 1) != 424933381 )
    __break(0x8228u);
  result = v54(v55, a2);
  if ( !(_DWORD)result )
  {
    if ( v13 )
    {
      v11 = (unsigned int)(*(_DWORD *)(v13 + 13756) + 1);
      *(_DWORD *)(v13 + 13756) = v11;
    }
    return dp_vdev_unref_delete(v13, v14, 2u, (unsigned int *)v11, a3, a4, a5, a6, a7, a8, a9, a10);
  }
LABEL_60:
  if ( v13 )
  {
    v56 = *(_QWORD *)(v13 + 13784);
    ++*(_QWORD *)(v13 + 13776);
    v11 = v56 + *(unsigned __int16 *)(a2 + 60);
    *(_QWORD *)(v13 + 13784) = v11;
  }
  if ( a2 )
    result = _qdf_nbuf_free(a2);
  if ( v14 )
    return dp_vdev_unref_delete(v13, v14, 2u, (unsigned int *)v11, a3, a4, a5, a6, a7, a8, a9, a10);
  return result;
}
