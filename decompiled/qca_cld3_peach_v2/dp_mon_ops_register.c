__int64 __fastcall dp_mon_ops_register(__int64 a1)
{
  __int64 v1; // x19
  unsigned int target_type; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v12; // x0

  v1 = *(_QWORD *)(a1 + 20112);
  target_type = hal_get_target_type(*(__int64 **)(a1 + 1128));
  if ( target_type > 0x2B )
  {
LABEL_7:
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %s: Unknown tgt type %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_mon_ops_register",
      "dp_mon_ops_register",
      target_type);
    v12 = printk(
            &unk_AAA255,
            "0",
            "dp_mon_ops_register",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c");
    return dump_stack(v12);
  }
  if ( ((1LL << target_type) & 0xD76FFB00000LL) == 0 )
  {
    if ( ((1LL << target_type) & 0x28900000000LL) != 0 )
      return dp_mon_ops_register_2_0(v1);
    goto LABEL_7;
  }
  dp_mon_ops_register_1_0(v1);
  dp_mon_ops_register_cmn_2_0(v1);
  return dp_mon_ops_register_tx_2_0(v1);
}
