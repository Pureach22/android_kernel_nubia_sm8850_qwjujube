__int64 __fastcall dp_ipa_disable_pipes(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x0
  unsigned __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  char is_opt_wifi_dp_enabled; // w8
  __int64 result; // x0
  __int64 v26; // x0

  qdf_sleep();
  v5 = *(_QWORD *)(a1 + 7640);
  if ( v5 )
  {
    v6 = *(_QWORD *)(a1 + 18056);
    hal_srng_dst_set_hp_paddr_confirm(v5, v6);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Reset WBM HP addr paddr: %pK",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_ipa_reset_tx_doorbell_pa",
      v6);
  }
  v15 = ipa_wdi_disable_pipes_per_inst(a3);
  if ( (_DWORD)v15 )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: Disable WDI PIPE fail, code %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_ipa_disable_pipes",
      (unsigned int)v15);
    v26 = printk(
            &unk_9BB309,
            "0",
            "dp_ipa_disable_pipes",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
    dump_stack(v26);
    return 16;
  }
  else
  {
    *(_DWORD *)(a1 + 18144) = 0;
    is_opt_wifi_dp_enabled = wlan_ipa_config_is_opt_wifi_dp_enabled(v15);
    result = 0;
    if ( (is_opt_wifi_dp_enabled & 1) == 0 )
    {
      if ( (wlan_ipa_is_shared_smmu_enabled(0) & 1) == 0 )
      {
        *(_DWORD *)(a1 + 17976) = 0;
        dp_ipa_handle_rx_buf_pool_smmu_mapping(a1, 0, 0, (__int64)"dp_ipa_disable_pipes", 3907, 0);
      }
      return 0;
    }
  }
  return result;
}
