__int64 __fastcall ufs_qcom_phy_set_src_clk_h8_exit(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x19
  int v5; // w0
  int v6; // w20
  int v7; // w0
  int v8; // w20
  int v9; // w20

  v1 = *(_QWORD **)(a1 + 152);
  result = v1[13];
  if ( result )
  {
    if ( v1[14] )
    {
      if ( v1[15] )
      {
        v3 = v1[16];
        if ( v3 )
        {
          if ( v1[17] && v1[18] )
          {
            v4 = v1[2];
            v5 = clk_set_parent(result, v3);
            if ( v5 )
            {
              v6 = v5;
              if ( (unsigned int)__ratelimit(&ufs_qcom_phy_set_src_clk_h8_exit__rs, "ufs_qcom_phy_set_src_clk_h8_exit") )
                dev_err(v4, "%s: fail rx_sym0_mux_clk %d\n", "ufs_qcom_phy_set_src_clk_h8_exit", v6);
            }
            v7 = clk_set_parent(v1[14], v1[17]);
            if ( v7 )
            {
              v8 = v7;
              if ( (unsigned int)__ratelimit(
                                   &ufs_qcom_phy_set_src_clk_h8_exit__rs_35,
                                   "ufs_qcom_phy_set_src_clk_h8_exit") )
                dev_err(v4, "%s: fail rx_sym1_mux_clk %d\n", "ufs_qcom_phy_set_src_clk_h8_exit", v8);
            }
            result = clk_set_parent(v1[15], v1[18]);
            if ( (_DWORD)result )
            {
              v9 = result;
              result = __ratelimit(&ufs_qcom_phy_set_src_clk_h8_exit__rs_36, "ufs_qcom_phy_set_src_clk_h8_exit");
              if ( (_DWORD)result )
                return dev_err(v4, "%s: fail tx_sym0_mux_clk %d\n", "ufs_qcom_phy_set_src_clk_h8_exit", v9);
            }
          }
        }
      }
    }
  }
  return result;
}
