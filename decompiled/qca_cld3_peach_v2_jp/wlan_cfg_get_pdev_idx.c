__int64 __fastcall wlan_cfg_get_pdev_idx(__int64 a1, int a2)
{
  __int64 v2; // x15
  int v3; // s27
  int v4; // s28
  __int64 v6; // x0

  if ( a2 >= 2 )
  {
    v6 = printk(
           &unk_9BB309,
           "hw_macid < 2",
           "wlan_cfg_get_pdev_idx",
           "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/wlan_cfg/wlan_cfg.c");
    a1 = dump_stack(v6);
  }
  else if ( (unsigned int)a2 < 2 )
  {
    return *(unsigned int *)(a1 + 4LL * (unsigned int)a2 + 516);
  }
  __break(0x5512u);
  *(_DWORD *)(v2 - 120) = v4;
  *(_DWORD *)(v2 - 116) = v3;
  return wlan_cfg_set_ce_ring_mask(a1);
}
