void __fastcall hal_rx_msdu_link_desc_set_be(__int64 a1, __int64 a2, _QWORD *a3, int a4)
{
  unsigned int v4; // w8
  bool v5; // zf
  __int64 v6; // x0

  v4 = *(_DWORD *)(a2 + 8) & 0xFFFFFE00;
  v5 = (*a3 & 0xFFFFFFFFFFLL) == 0;
  *(_QWORD *)a2 = *a3;
  *(_DWORD *)(a2 + 8) = (8 * a4) & 0x638 | v4 | 0x44;
  if ( v5 )
  {
    hal_dump_wbm_rel_desc(a2);
    v6 = printk(
           &unk_9BB309,
           "0",
           "hal_rx_msdu_link_desc_set_be",
           "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hal/wifi3.0/be/hal_be_generic_api.c");
    dump_stack(v6);
  }
}
