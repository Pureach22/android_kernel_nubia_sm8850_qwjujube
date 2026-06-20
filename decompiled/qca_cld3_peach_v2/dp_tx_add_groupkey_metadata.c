void *__fastcall dp_tx_add_groupkey_metadata(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  unsigned int v4; // w20
  void *result; // x0

  v4 = a3;
  result = qdf_mem_set((void *)(a2 + 56), 0x24u, 0);
  *(_DWORD *)(a2 + 56) |= 0x200u;
  if ( v4 >= 0x100 )
    result = (void *)printk(
                       &unk_94DB9D,
                       "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c",
                       9592,
                       "!((group_key) & ~((HTT_TX_MSDU_EXT2_DESC_KEY_FLAGS_M) >> (HTT_TX_MSDU_EXT2_DESC_KEY_FLAGS_S)))");
  *(_DWORD *)(a2 + 64) |= v4 << 8;
  return result;
}
