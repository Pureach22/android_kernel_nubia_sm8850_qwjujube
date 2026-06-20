__int64 ufs_qcom_phy_qrbtc_sdm845_phy_calibrate()
{
  __int64 ufs_qcom_phy; // x19
  __int64 result; // x0
  __int64 v2; // x8
  unsigned int v3; // w19

  ufs_qcom_phy = get_ufs_qcom_phy();
  result = ufs_qcom_phy_calibrate();
  if ( (_DWORD)result )
  {
    v2 = *(_QWORD *)(ufs_qcom_phy + 16);
    v3 = result;
    dev_err(v2, "%s: ufs_qcom_phy_calibrate() failed %d\n", "ufs_qcom_phy_qrbtc_sdm845_phy_calibrate", result);
    return v3;
  }
  return result;
}
