__int64 __fastcall dp_rx_word_mask_subscribe_be(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        int *a10,
        __int64 a11)
{
  __int64 result; // x0
  int v14; // w8
  unsigned int v15; // w8
  int v16; // w9
  unsigned int v17; // w8
  int v18; // w9

  if ( a10 )
  {
    if ( a11 )
    {
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: enable %d, rx_mpdu_start_wmask 0x%x, rx_msdu_end_wmask 0x%x",
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 "dp_rx_word_mask_subscribe_be",
                 (*(_DWORD *)(a11 + 74) >> 15) & 1,
                 *(unsigned int *)(a11 + 60),
                 *(unsigned int *)(a11 + 68));
      if ( (*(_BYTE *)(a11 + 75) & 0x80) == 0 && *(_DWORD *)(a11 + 60) && *(_DWORD *)(a11 + 68) )
      {
        v14 = *a10;
        a10[3] = 0;
        *a10 = v14 | 0x800000;
        v15 = *(_DWORD *)(a11 + 60);
        if ( v15 >= 0x10000 )
        {
          result = printk(
                     &unk_881311,
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_rx.c",
                     1947,
                     "!((tlv_filter->rx_mpdu_start_wmask) & ~((HTT_RX_RING_SELECTION_CFG_RX_MPDU_START_WORD_MASK_M) >> (H"
                     "TT_RX_RING_SELECTION_CFG_RX_MPDU_START_WORD_MASK_S)))");
          v15 = *(_DWORD *)(a11 + 60);
          v16 = a10[3];
        }
        else
        {
          v16 = 0;
        }
        a10[3] = v16 | v15;
        a10[4] = 0;
        v17 = *(_DWORD *)(a11 + 68);
        if ( v17 >= 0x20000 )
        {
          result = printk(
                     &unk_881311,
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_rx.c",
                     1954,
                     "!((tlv_filter->rx_msdu_end_wmask) & ~((HTT_RX_RING_SELECTION_CFG_RX_MSDU_END_WORD_MASK_M) >> (HTT_R"
                     "X_RING_SELECTION_CFG_RX_MSDU_END_WORD_MASK_S)))");
          v17 = *(_DWORD *)(a11 + 68);
          v18 = a10[4];
        }
        else
        {
          v18 = 0;
        }
        a10[4] = v18 | v17;
      }
    }
  }
  return result;
}
