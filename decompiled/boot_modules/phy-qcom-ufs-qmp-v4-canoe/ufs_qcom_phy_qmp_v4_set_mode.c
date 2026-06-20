__int64 __fastcall ufs_qcom_phy_qmp_v4_set_mode(__int64 a1, int a2, int a3)
{
  __int64 ufs_qcom_phy; // x8

  ufs_qcom_phy = get_ufs_qcom_phy();
  *(_DWORD *)(ufs_qcom_phy + 424) = a2;
  *(_DWORD *)(ufs_qcom_phy + 428) = a3;
  return 0;
}
