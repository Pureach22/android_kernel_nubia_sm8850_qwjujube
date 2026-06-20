_DWORD *__fastcall dp_rx_mon_hdr_length_set(_DWORD *result, __int64 a2)
{
  int v2; // w8
  _DWORD *v3; // x19

  if ( result && a2 )
  {
    v2 = *(_DWORD *)(a2 + 74);
    if ( (v2 & 0x800) != 0 )
    {
      v3 = result;
      printk(
        &unk_94DB9D,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon_filter.c",
        569,
        "!((tlv_filter->rx_hdr_length) & ~((HTT_RX_RING_SELECTION_CFG_RX_HDR_LEN_M) >> (HTT_RX_RING_SELECTION_CFG_RX_HDR_LEN_S)))");
      result = v3;
      v2 = *(_DWORD *)(a2 + 74);
    }
    *result |= (v2 << 16) & 0xE000000;
  }
  return result;
}
