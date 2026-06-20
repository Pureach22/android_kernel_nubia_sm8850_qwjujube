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
  unsigned __int64 StatusReg; // x8
  unsigned int v17; // w9
  unsigned int v24; // w11
  __int64 v26; // x0
  __int64 (__fastcall *v27)(_QWORD); // x8
  int v28; // w23
  int v29; // w8
  unsigned int v30; // w9
  unsigned int v31; // w24
  unsigned int v32; // w8
  __int64 v33; // x8
  int v34; // w9
  int v35; // w9
  int v36; // w10
  __int64 v37; // x8
  __int64 v38; // x1
  __int64 (__fastcall *v39)(__int64, __int64); // x8
  __int64 v40; // x0
  __int64 v41; // x9
  __int64 ref_by_id_1; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v52; // w9
  __int64 v53; // x8

  v10 = *(unsigned __int16 *)(a2 + 62);
  v11 = *(unsigned int *)(result + 13276);
  v13 = result;
  if ( (unsigned int)v11 < v10 || (v15 = *(_WORD *)(a2 + 86), v11 = (unsigned __int8)v15, (unsigned __int8)v15 > 5u) )
  {
    v14 = 0;
  }
  else
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 18928);
    }
    else
    {
      raw_spin_lock_bh(result + 18928);
      *(_QWORD *)(v13 + 18936) |= 1uLL;
    }
    v14 = *(_QWORD *)(v13 + 8LL * (v15 & 7) + 12912);
    if ( v14 )
    {
      v17 = *(_DWORD *)(v14 + 42560);
      do
      {
        if ( !v17 )
          goto LABEL_25;
        _X13 = (unsigned int *)(v14 + 42560);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v24 = __ldxr(_X13);
          if ( v24 != v17 )
            break;
          if ( !__stlxr(v17 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v24 == v17;
        v17 = v24;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v14 + 42572);
      __asm { PRFM            #0x11, [X8] }
      do
        v52 = __ldxr(_X8);
      while ( __stxr(v52 + 1, _X8) );
      v53 = *(_QWORD *)(v13 + 18936);
      if ( (v53 & 1) != 0 )
      {
        *(_QWORD *)(v13 + 18936) = v53 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v13 + 18928);
        v11 = *(unsigned int *)(v14 + 272);
        if ( (_DWORD)v11 )
          goto LABEL_49;
      }
      else
      {
        result = raw_spin_unlock(v13 + 18928);
        v11 = *(unsigned int *)(v14 + 272);
        if ( (_DWORD)v11 )
          goto LABEL_49;
      }
      v11 = (unsigned int)*(char *)(a2 + 84);
      if ( (v11 & 0x80000000) != 0 )
        goto LABEL_49;
      v26 = *(_QWORD *)(a2 + 224);
      v27 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v13 + 1128) + 74392LL) + 536LL);
      if ( *((_DWORD *)v27 - 1) != 855462014 )
        __break(0x8228u);
      v28 = v27(v26);
      v29 = *(unsigned __int16 *)(a2 + 60) + *(unsigned __int16 *)(v13 + 1138);
      v30 = *(_DWORD *)(a2 + 112);
      *(_BYTE *)(a2 + 75) = 1;
      v31 = v28 + v29;
      v32 = v28 + v29 - v30;
      if ( v31 < v30 )
      {
        skb_trim(a2, v31);
LABEL_36:
        v37 = *(_QWORD *)(a2 + 40);
        v38 = v28 + (unsigned int)*(unsigned __int16 *)(v13 + 1138);
        if ( v37 )
          *(_QWORD *)(a2 + 40) = v37 + (unsigned int)v38;
        skb_pull(a2, v38);
        if ( _qdf_nbuf_data_is_ipv4_arp_pkt(*(_QWORD *)(a2 + 224))
          || _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a2 + 224))
          || _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a2 + 224))
          || _qdf_nbuf_data_is_ipv6_dhcp_pkt(*(unsigned __int16 **)(a2 + 224))
          || _qdf_nbuf_data_is_dns_query(*(_QWORD *)(a2 + 224))
          || _qdf_nbuf_data_is_dns_response(*(_QWORD *)(a2 + 224))
          || (result = _qdf_nbuf_is_ipv4_wapi_pkt(a2), (result & 1) != 0) )
        {
          if ( !*(_QWORD *)(v14 + 160) )
          {
            ref_by_id_1 = dp_peer_get_ref_by_id_1(v13, v10);
            if ( ref_by_id_1 )
              result = dp_peer_unref_delete(ref_by_id_1, 2u, v43, v44, v45, v46, v47, v48, v49, v50);
            else
              result = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a2 + 224));
            goto LABEL_49;
          }
          *(_DWORD *)(a2 + 48) |= 0x80u;
          v39 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 160);
          v40 = *(_QWORD *)(v14 + 88);
          if ( *((_DWORD *)v39 - 1) != 424933381 )
            __break(0x8228u);
          result = v39(v40, a2);
          if ( !(_DWORD)result )
          {
            if ( v13 )
            {
              v11 = (unsigned int)(*(_DWORD *)(v13 + 13700) + 1);
              *(_DWORD *)(v13 + 13700) = v11;
            }
            return dp_vdev_unref_delete(v13, v14, 2u, (unsigned int *)v11, a3, a4, a5, a6, a7, a8, a9, a10);
          }
        }
        goto LABEL_49;
      }
      if ( *(_DWORD *)(a2 + 116) )
      {
        v32 = v31 - v30;
        if ( v31 != v30 )
        {
          v34 = 0;
          goto LABEL_33;
        }
      }
      else
      {
        v36 = *(_DWORD *)(a2 + 208);
        v35 = *(_DWORD *)(a2 + 212);
        if ( v35 - v36 < v32 )
        {
          v34 = v36 - v35;
LABEL_33:
          if ( (unsigned int)pskb_expand_head(a2, 0, v34 + v32, 2080) )
            dev_kfree_skb_any_reason(a2, 1);
        }
      }
      skb_put(a2, v31 - *(_DWORD *)(a2 + 112));
      goto LABEL_36;
    }
LABEL_25:
    v33 = *(_QWORD *)(v13 + 18936);
    if ( (v33 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 18936) = v33 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v13 + 18928);
    }
    else
    {
      result = raw_spin_unlock(v13 + 18928);
    }
    v14 = 0;
  }
LABEL_49:
  if ( v13 )
  {
    v41 = *(_QWORD *)(v13 + 13728);
    ++*(_QWORD *)(v13 + 13720);
    v11 = v41 + *(unsigned __int16 *)(a2 + 60);
    *(_QWORD *)(v13 + 13728) = v11;
  }
  if ( a2 )
    result = _qdf_nbuf_free(a2);
  if ( v14 )
    return dp_vdev_unref_delete(v13, v14, 2u, (unsigned int *)v11, a3, a4, a5, a6, a7, a8, a9, a10);
  return result;
}
