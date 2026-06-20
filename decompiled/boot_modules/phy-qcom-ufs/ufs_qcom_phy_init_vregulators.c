__int64 __fastcall ufs_qcom_phy_init_vregulators(__int64 a1)
{
  __int64 result; // x0

  result = ufs_qcom_phy_init_vreg(*(_QWORD *)(a1 + 16), a1 + 160, "vdda-pll");
  if ( !(_DWORD)result )
  {
    result = ufs_qcom_phy_init_vreg(*(_QWORD *)(a1 + 16), a1 + 192, "vdda-phy");
    if ( !(_DWORD)result )
    {
      ufs_qcom_phy_init_vreg(*(_QWORD *)(a1 + 16), a1 + 224, "vddp-ref-clk");
      ufs_qcom_phy_init_vreg(*(_QWORD *)(a1 + 16), a1 + 256, "vdd-phy-gdsc");
      ufs_qcom_phy_init_vreg(*(_QWORD *)(a1 + 16), a1 + 288, "vdda-qref");
      ufs_qcom_phy_init_vreg(*(_QWORD *)(a1 + 16), a1 + 320, "vdda-refgen");
      return 0;
    }
  }
  return result;
}
