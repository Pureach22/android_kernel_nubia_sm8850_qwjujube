__int64 __fastcall dp_rx_nbuf_unmap_pool(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x2
  int v7; // w8
  __int64 v8; // x1
  __int64 v9; // x22
  __int64 v10; // x20
  __int64 v11; // x21
  __int64 result; // x0
  __int64 v13; // x19

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 831LL) & 1) != 0 )
    goto LABEL_10;
  v6 = *(unsigned __int16 *)(a2 + 74);
  v7 = *(_DWORD *)(a3 + 48);
  if ( !*(_DWORD *)(a1 + 20208) )
  {
    if ( (v7 & 0x2000000) == 0 )
      goto LABEL_10;
    if ( a1 )
    {
      ++*(_DWORD *)(a1 + 14032);
      v7 = *(_DWORD *)(a3 + 48);
    }
LABEL_9:
    v8 = *(_QWORD *)(a3 + 40);
    *(_DWORD *)(a3 + 48) = v7 & 0xFDFFFFFF;
    pld_audio_smmu_unmap(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), v8, v6);
    goto LABEL_10;
  }
  if ( (v7 & 0x2000000) != 0 )
    goto LABEL_9;
  if ( a1 )
    ++*(_DWORD *)(a1 + 14028);
LABEL_10:
  dp_ipa_handle_rx_buf_smmu_mapping(a1, a3, *(unsigned __int16 *)(a2 + 74), 0, "dp_rx_nbuf_unmap_pool", 3162, 0);
  v9 = *(_QWORD *)(a1 + 24);
  v10 = *(unsigned __int16 *)(a2 + 74);
  v11 = *(_QWORD *)(a3 + 40);
  result = _qdf_is_pp_nbuf(a3);
  if ( (result & 1) != 0 && *(_QWORD *)(a3 + 40) )
  {
    result = *(_QWORD *)(v9 + 40);
    if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
      return _dma_sync_single_for_cpu(result, v11);
  }
  else if ( v11 )
  {
    v13 = *(int *)(a3 + 212);
    qdf_mem_dp_rx_skb_cnt_dec();
    qdf_mem_dp_rx_skb_dec(v13);
    qdf_mem_skb_total_dec(v13);
    return dma_unmap_page_attrs(*(_QWORD *)(v9 + 40), v11, v10, 2, 0);
  }
  return result;
}
