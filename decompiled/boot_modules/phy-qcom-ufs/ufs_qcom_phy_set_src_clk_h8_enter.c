__int64 __fastcall ufs_qcom_phy_set_src_clk_h8_enter(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 result; // x0
  __int64 v3; // x19
  int v4; // w0
  int v5; // w20
  int v6; // w0
  int v7; // w20
  int v8; // w20

  v1 = *(_QWORD **)(a1 + 152);
  result = v1[13];
  if ( result && v1[14] && v1[15] && v1[8] )
  {
    v3 = v1[2];
    v4 = ((__int64 (*)(void))clk_set_parent)();
    if ( v4 )
    {
      v5 = v4;
      if ( (unsigned int)__ratelimit(&ufs_qcom_phy_set_src_clk_h8_enter__rs, "ufs_qcom_phy_set_src_clk_h8_enter") )
        dev_err(v3, "%s: fail rx_sym0_mux_clk %d\n", "ufs_qcom_phy_set_src_clk_h8_enter", v5);
    }
    v6 = clk_set_parent(v1[14], v1[8]);
    if ( v6 )
    {
      v7 = v6;
      if ( (unsigned int)__ratelimit(&ufs_qcom_phy_set_src_clk_h8_enter__rs_31, "ufs_qcom_phy_set_src_clk_h8_enter") )
        dev_err(v3, "%s: fail rx_sym1_mux_clk %d\n", "ufs_qcom_phy_set_src_clk_h8_enter", v7);
    }
    result = clk_set_parent(v1[15], v1[8]);
    if ( (_DWORD)result )
    {
      v8 = result;
      result = __ratelimit(&ufs_qcom_phy_set_src_clk_h8_enter__rs_33, "ufs_qcom_phy_set_src_clk_h8_enter");
      if ( (_DWORD)result )
        return dev_err(v3, "%s: fail tx_sym0_mux_clk %d\n", "ufs_qcom_phy_set_src_clk_h8_enter", v8);
    }
  }
  return result;
}
