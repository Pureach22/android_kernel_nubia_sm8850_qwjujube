__int64 __fastcall dp_ipa_enable_pipes(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x0
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  unsigned __int64 v25; // x20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v35; // x1
  __int64 v36; // x0

  v3 = a1 + 0x4000;
  *(_DWORD *)(a1 + 18200) = 1;
  hal_srng_dst_set_hp_paddr_confirm(*(_QWORD *)(a1 + 7688), *(_QWORD *)(a1 + 18472));
  v14 = qdf_trace_msg(
          0x45u,
          5u,
          "%s: paddr %pK vaddr %pK",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "dp_ipa_set_tx_doorbell_paddr",
          *(_QWORD *)(a1 + 18472),
          *(_QWORD *)(a1 + 18480));
  if ( (wlan_ipa_config_is_opt_wifi_dp_enabled(v14) & 1) == 0 && (wlan_ipa_is_shared_smmu_enabled() & 1) == 0 )
  {
    *(_DWORD *)(v3 + 1648) = 1;
    dp_ipa_handle_rx_buf_pool_smmu_mapping(a1, 1, 0, "dp_ipa_enable_pipes", 3845, 1);
  }
  v15 = ipa_wdi_enable_pipes_per_inst(a3);
  if ( v15 )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: Enable WDI PIPE fail, code %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_ipa_enable_pipes",
      v15);
    *(_DWORD *)(v3 + 1816) = 0;
    v24 = *(_QWORD *)(a1 + 7688);
    if ( v24 )
    {
      v25 = *(_QWORD *)(a1 + 18112);
      hal_srng_dst_set_hp_paddr_confirm(v24, v25);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Reset WBM HP addr paddr: %pK",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "dp_ipa_reset_tx_doorbell_pa",
        v25);
    }
    if ( *(_DWORD *)(v3 + 1648) )
    {
      *(_DWORD *)(v3 + 1648) = 0;
      dp_ipa_handle_rx_buf_pool_smmu_mapping(a1, 0, 0, "dp_ipa_enable_pipes", 3860, 0);
    }
    return 16;
  }
  else
  {
    v35 = *(_QWORD *)(a1 + 7688);
    v36 = *(_QWORD *)(a1 + 1128);
    if ( *(_BYTE *)(v3 + 1820) == 1 )
    {
      hal_srng_dst_init_hp(v36, v35, *(_QWORD *)(a1 + 18480));
      *(_BYTE *)(v3 + 1820) = 0;
      return 0;
    }
    else
    {
      hal_srng_dst_update_hp_addr(v36, v35);
      return 0;
    }
  }
}
