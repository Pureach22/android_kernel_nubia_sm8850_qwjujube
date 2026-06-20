__int64 __fastcall ufs_qcom_phy_init_clks(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  __int64 v4; // x20
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x0
  unsigned int v16; // w21

  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(a1[2] + 744LL), "qcom,msm8996-ufs-phy-qmp-14nm") )
  {
    v2 = devm_clk_get(a1[2], "tx_iface_clk");
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
      a1[5] = v2;
    v3 = devm_clk_get(a1[2], "rx_iface_clk");
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
      a1[6] = v3;
  }
  v4 = a1[2];
  v5 = devm_clk_get(v4, "ref_clk_src");
  if ( v5 > 0xFFFFFFFFFFFFF000LL )
  {
    v16 = v5;
    dev_err(v4, "failed get %s, %d\n", "ref_clk_src", v5);
  }
  else
  {
    a1[8] = v5;
    v6 = devm_clk_get(a1[2], "ref_clk_parent");
    if ( v6 <= 0xFFFFFFFFFFFFF000LL )
      a1[9] = v6;
    v7 = devm_clk_get(a1[2], "ref_clk");
    if ( v7 <= 0xFFFFFFFFFFFFF000LL )
      a1[10] = v7;
    v8 = devm_clk_get(a1[2], "ref_aux_clk");
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
      a1[11] = v8;
    v9 = devm_clk_get(a1[2], "qref_clk");
    if ( v9 <= 0xFFFFFFFFFFFFF000LL )
      a1[12] = v9;
    v10 = devm_clk_get(a1[2], "rx_sym0_mux_clk");
    if ( v10 <= 0xFFFFFFFFFFFFF000LL )
      a1[13] = v10;
    v11 = devm_clk_get(a1[2], "rx_sym1_mux_clk");
    if ( v11 <= 0xFFFFFFFFFFFFF000LL )
      a1[14] = v11;
    v12 = devm_clk_get(a1[2], "tx_sym0_mux_clk");
    if ( v12 <= 0xFFFFFFFFFFFFF000LL )
      a1[15] = v12;
    v13 = devm_clk_get(a1[2], "rx_sym0_phy_clk");
    if ( v13 <= 0xFFFFFFFFFFFFF000LL )
      a1[16] = v13;
    v14 = devm_clk_get(a1[2], "rx_sym1_phy_clk");
    if ( v14 <= 0xFFFFFFFFFFFFF000LL )
      a1[17] = v14;
    v15 = devm_clk_get(a1[2], "tx_sym0_phy_clk");
    if ( v15 <= 0xFFFFFFFFFFFFF000LL )
      a1[18] = v15;
    if ( !a1[13] || !a1[14] || !a1[15] || !a1[8] || !a1[16] || !a1[17] || !a1[18] )
      dev_err(a1[2], "%s: null clock\n", "ufs_qcom_phy_init_clks");
    return 0;
  }
  return v16;
}
