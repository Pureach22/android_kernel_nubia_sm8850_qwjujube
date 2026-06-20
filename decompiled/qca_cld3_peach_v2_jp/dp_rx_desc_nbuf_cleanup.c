_QWORD *__fastcall dp_rx_desc_nbuf_cleanup(__int64 a1, _QWORD *a2, _QWORD *a3, unsigned __int16 a4, char a5)
{
  _QWORD *v7; // x23
  __int64 v9; // x26
  int v10; // w8
  __int64 v11; // x1
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x27
  __int64 v21; // x28
  __int64 v22; // x27
  __int64 v23; // x0
  _QWORD *result; // x0
  _QWORD *v25; // x19

  if ( a2 )
  {
    v7 = a2;
    do
    {
      v9 = (__int64)v7;
      v7 = (_QWORD *)*v7;
      if ( (a5 & 1) != 0 || (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 831LL) & 1) != 0 )
        goto LABEL_14;
      v10 = *(_DWORD *)(v9 + 48);
      if ( *(_DWORD *)(a1 + 20208) )
      {
        if ( (v10 & 0x2000000) == 0 )
        {
          if ( a1 )
            ++*(_DWORD *)(a1 + 14028);
          goto LABEL_14;
        }
      }
      else
      {
        if ( (v10 & 0x2000000) == 0 )
          goto LABEL_14;
        if ( a1 )
        {
          ++*(_DWORD *)(a1 + 14032);
          v10 = *(_DWORD *)(v9 + 48);
        }
      }
      v11 = *(_QWORD *)(v9 + 40);
      *(_DWORD *)(v9 + 48) = v10 & 0xFDFFFFFF;
      pld_audio_smmu_unmap(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), v11, a4);
LABEL_14:
      if ( (unsigned int)dp_ipa_handle_rx_buf_smmu_mapping(a1, v9, a4, 0, "dp_rx_desc_nbuf_cleanup", 196, 0) )
      {
        v20 = jiffies;
        if ( dp_rx_desc_nbuf_cleanup___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Unable to unmap nbuf: %pK",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "dp_rx_desc_nbuf_cleanup",
            v9);
          dp_rx_desc_nbuf_cleanup___last_ticks = v20;
        }
      }
      v21 = *(_QWORD *)(a1 + 24);
      v22 = *(_QWORD *)(v9 + 40);
      if ( (_qdf_is_pp_nbuf(v9) & 1) != 0 && *(_QWORD *)(v9 + 40) )
      {
        v23 = *(_QWORD *)(v21 + 40);
        if ( (*(_BYTE *)(v23 + 844) & 0x40) == 0 )
          _dma_sync_single_for_cpu(v23, v22);
      }
      else if ( v22 )
      {
        qdf_mem_skb_total_dec(*(int *)(v9 + 212));
        dma_unmap_page_attrs(*(_QWORD *)(v21 + 40), v22, a4, 0, 0);
      }
      _qdf_nbuf_free(v9);
    }
    while ( v7 );
  }
  result = a3;
  if ( a3 )
  {
    do
    {
      v25 = (_QWORD *)*result;
      _qdf_nbuf_free((__int64)result);
      result = v25;
    }
    while ( v25 );
  }
  return result;
}
