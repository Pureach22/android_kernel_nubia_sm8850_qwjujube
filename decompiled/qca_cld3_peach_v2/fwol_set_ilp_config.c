__int64 __fastcall fwol_set_ilp_config(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v2 = tgt_fwol_pdev_param_send(a1, (a2 << 32) | 0xCA, 0);
  if ( v2 )
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: wmi_pdev_param_pcie_hw_ilp failed %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "fwol_set_ilp_config",
      v2);
  return v2;
}
