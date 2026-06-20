__int64 __fastcall wlan_cfg_get_target_pdev_id(__int64 a1, int a2)
{
  __int64 v3; // x0

  if ( *(_DWORD *)(a1 + 512) == a2 )
    return 1;
  v3 = printk(
         &unk_9BB309,
         "idx < 1",
         "wlan_cfg_get_target_pdev_id",
         "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/wlan_cfg/wlan_cfg.c");
  dump_stack(v3);
  return 0xFFFFFFFFLL;
}
