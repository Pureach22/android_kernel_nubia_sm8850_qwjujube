__int64 __fastcall btfm_slim_unregister_hwep(__int64 a1, __int64 a2, __int64 a3)
{
  printk(&unk_8293, "btfm_slim_unregister_hwep", a3);
  return btfmcodec_unregister_hw_ep("btfmslim");
}
