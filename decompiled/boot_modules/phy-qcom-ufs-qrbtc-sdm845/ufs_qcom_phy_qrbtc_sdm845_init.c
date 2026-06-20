__int64 ufs_qcom_phy_qrbtc_sdm845_init()
{
  __int64 ufs_qcom_phy; // x19
  __int64 v1; // x20
  __int64 v2; // x2
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x8
  unsigned int v7; // w19
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ufs_qcom_phy = get_ufs_qcom_phy();
  v1 = *(_QWORD *)(*(_QWORD *)(ufs_qcom_phy + 16) + 744LL);
  v8[0] = 0;
  if ( (of_property_read_variable_u32_array(v1, "qcom,soc_emulation_type_addr", (char *)v8 + 4, 1, 0) & 0x80000000) == 0 )
  {
    if ( (of_property_read_variable_u32_array(v1, "qcom,soc_emulation_type_bits", v8, 1, 0) & 0x80000000) != 0 )
    {
      dev_err(*(_QWORD *)(ufs_qcom_phy + 16), "can't get soc_emulation_type bits\n");
    }
    else
    {
      if ( arm64_use_ng_mappings )
        v2 = 0x68000000000F13LL;
      else
        v2 = 0x68000000000713LL;
      v3 = ioremap_prot(HIDWORD(v8[0]), LODWORD(v8[0]), v2);
      if ( v3 )
      {
        v4 = v3;
        *(_DWORD *)(ufs_qcom_phy + 456) = readl_relaxed();
        iounmap(v4);
      }
      else
      {
        dev_err(*(_QWORD *)(ufs_qcom_phy + 16), "can't map soc_emulation_type addr\n");
      }
    }
  }
  result = ufs_qcom_phy_get_reset(ufs_qcom_phy);
  if ( (_DWORD)result )
  {
    v6 = *(_QWORD *)(ufs_qcom_phy + 16);
    v7 = result;
    dev_err(v6, "Failed to get reset control %d\n", result);
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
