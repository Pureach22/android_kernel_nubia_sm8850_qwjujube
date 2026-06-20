__int64 __fastcall disp_cc_mx_canoe_probe(__int64 a1)
{
  __int64 regmap; // x20
  unsigned int v3; // w20

  regmap = dev_get_regmap(*(_QWORD *)(a1 + 112), 0);
  clk_pongo_elu_pll_configure(&disp_cc_pll2, regmap, &disp_cc_pll2_config);
  v3 = qcom_cc_really_probe(a1 + 16, &disp_cc_mx_canoe_desc, regmap);
  if ( v3 )
    dev_err(a1 + 16, "Failed to register DISP CC MX clocks\n");
  else
    dev_info(a1 + 16, "Registered DISP CC MX clocks\n");
  return v3;
}
