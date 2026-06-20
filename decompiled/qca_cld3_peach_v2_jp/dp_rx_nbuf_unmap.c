__int64 __fastcall dp_rx_nbuf_unmap(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x21
  __int64 v9; // x24
  __int64 v10; // x25
  __int64 v13; // x22
  unsigned __int64 StatusReg; // x9
  __int64 v15; // x21
  __int64 v16; // x2
  unsigned __int16 *v17; // x21
  unsigned int v18; // t1
  __int64 v19; // x8
  int v20; // w9
  __int64 v21; // x1
  __int64 v22; // x23
  __int64 v23; // x26
  __int64 v24; // x21
  __int64 v25; // x22
  __int64 result; // x0
  __int64 v27; // x23
  __int64 v28; // x9

  v8 = a2[28];
  if ( v8 >= 5 || (unsigned __int8)a3 >= 8u )
  {
    __break(0x5512u);
    return dp_rx_get_txrx_peer_and_vdev(a1, a2, a3, a4, a5, a6, a7, a8);
  }
  v9 = (unsigned __int8)a3;
  v10 = a1 + 18480;
  v13 = a1 + 12368;
  if ( *(_BYTE *)(a1 + 18480 + (unsigned __int8)a3) )
  {
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
  }
  v15 = v13 + 120LL * (unsigned int)v8;
  v18 = *(unsigned __int16 *)(v15 + 74);
  v17 = (unsigned __int16 *)(v15 + 74);
  v16 = v18;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 831LL) & 1) == 0 )
  {
    v19 = *(_QWORD *)a2;
    v20 = *(_DWORD *)(*(_QWORD *)a2 + 48LL);
    if ( *(_DWORD *)(a1 + 20208) )
    {
      if ( (v20 & 0x2000000) == 0 )
      {
        if ( a1 )
          ++*(_DWORD *)(a1 + 14028);
        goto LABEL_17;
      }
      goto LABEL_16;
    }
    if ( (v20 & 0x2000000) != 0 )
    {
      if ( a1 )
      {
        ++*(_DWORD *)(a1 + 14032);
        v20 = *(_DWORD *)(v19 + 48);
      }
LABEL_16:
      v21 = *(_QWORD *)(v19 + 40);
      *(_DWORD *)(v19 + 48) = v20 & 0xFDFFFFFF;
      pld_audio_smmu_unmap(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), v21, v16);
      v16 = *v17;
    }
  }
LABEL_17:
  dp_ipa_handle_rx_buf_smmu_mapping(a1, *(_QWORD *)a2, v16, 0, "dp_rx_nbuf_unmap", 3142, 0);
  if ( (a2[30] & 0x20) != 0 )
    a2[30] &= ~0x20u;
  v22 = *(_QWORD *)a2;
  v23 = *(_QWORD *)(a1 + 24);
  v24 = *v17;
  v25 = *(_QWORD *)(*(_QWORD *)a2 + 40LL);
  result = _qdf_is_pp_nbuf(*(_QWORD *)a2);
  if ( (result & 1) != 0 && *(_QWORD *)(v22 + 40) )
  {
    result = *(_QWORD *)(v23 + 40);
    if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
      result = _dma_sync_single_for_cpu();
  }
  else if ( v25 )
  {
    v27 = *(int *)(v22 + 212);
    qdf_mem_dp_rx_skb_cnt_dec();
    qdf_mem_dp_rx_skb_dec(v27);
    qdf_mem_skb_total_dec(v27);
    result = dma_unmap_page_attrs(*(_QWORD *)(v23 + 40), v25, v24, 2, 0);
  }
  a2[30] |= 2u;
  if ( *(_BYTE *)(v10 + v9) )
  {
    v28 = *(_QWORD *)(a1 + 18472);
    if ( (v28 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18472) = v28 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a1 + 18464);
    }
    else
    {
      return raw_spin_unlock(a1 + 18464);
    }
  }
  return result;
}
