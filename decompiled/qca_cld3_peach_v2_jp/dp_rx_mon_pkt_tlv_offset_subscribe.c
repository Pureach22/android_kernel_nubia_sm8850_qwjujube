int *__fastcall dp_rx_mon_pkt_tlv_offset_subscribe(int *result, __int64 a2)
{
  int v2; // w8
  int v3; // w9
  int *v4; // x19

  if ( result )
  {
    if ( a2 )
    {
      *result = 0;
      if ( *(_WORD *)(a2 + 72) )
      {
        v2 = 1;
        *result = 1;
        v3 = *(__int16 *)(a2 + 72);
        if ( v3 < 0 )
        {
          v4 = result;
          printk(
            &unk_881311,
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_mon_filter_2.0.c",
            253,
            "!((tlv_filter->rx_pkt_tlv_offset) & ~((HTT_RX_RING_SELECTION_CFG_RX_PKT_TLV_OFFSET_M) >> (HTT_RX_RING_SELECT"
            "ION_CFG_RX_PKT_TLV_OFFSET_S)))");
          LOWORD(v3) = *(_WORD *)(a2 + 72);
          result = v4;
          v2 = *v4;
        }
        *result = v2 | (2 * (unsigned __int16)v3);
      }
    }
  }
  return result;
}
