__int64 __fastcall wlan_cfg_rx_buffer_size(__int64 a1)
{
  int v1; // w8
  __int64 v4; // x0

  v1 = *(_DWORD *)(a1 + 128);
  if ( v1 > 1663 )
    return (unsigned int)v1;
  v4 = printk(
         &unk_9BB309,
         "0",
         "wlan_cfg_rx_buffer_size",
         "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/wlan_cfg/wlan_cfg.c");
  dump_stack(v4);
  return *(unsigned int *)(a1 + 128);
}
