__int64 btfm_swr_unregister_hwep()
{
  printk(&unk_7090, "btfm_swr_unregister_hwep");
  return btfmcodec_unregister_hw_ep("btfmswr_slave");
}
