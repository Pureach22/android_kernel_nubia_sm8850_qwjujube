__int64 __fastcall dp_ipa_uc_detach(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  int v10; // w8
  unsigned int v11; // w22

  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 )
  {
    dp_tx_ipa_uc_detach(a1);
    sg_free_table(a1 + 18384);
    sg_free_table(a1 + 18448);
    v10 = *(_DWORD *)(**(_QWORD **)(a1 + 1128) + 3944LL);
    if ( v10 >= 1 )
    {
      v11 = v10 + 1;
      do
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: opt_dp: cleanup call pcie link down",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          "dp_ipa_opt_wifi_dp_cleanup");
        hif_allow_l1(**(_QWORD **)(a1 + 1128));
        hif_enable_rtpm();
        --v11;
      }
      while ( v11 > 1 );
    }
  }
  return 0;
}
