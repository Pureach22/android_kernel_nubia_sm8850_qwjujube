__int64 __fastcall htc_flush_endpoint(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8

  if ( a2 >= 0xA )
  {
    __break(0x5512u);
    if ( !a4 )
      JUMPOUT(0x16CEA0);
    JUMPOUT(0x1E0FA8);
  }
  v4 = a1 + 328LL * a2;
  if ( *(_WORD *)(v4 + 12) )
    return htc_flush_endpoint_tx(a1, v4 + 8);
  else
    return printk(&unk_881311, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 2882, "false");
}
