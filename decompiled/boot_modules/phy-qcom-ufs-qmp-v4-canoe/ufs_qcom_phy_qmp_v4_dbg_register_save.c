__int64 __fastcall ufs_qcom_phy_qmp_v4_dbg_register_save(__int64 a1)
{
  ufs_qcom_phy_save_regs(a1, 0, 0x2000, "PHY QSERDES COM Registers ");
  ufs_qcom_phy_save_regs(a1, 2048, 128, "PHY PCS2 Registers ");
  ufs_qcom_phy_save_regs(a1, 1024, 628, "PHY Registers ");
  ufs_qcom_phy_save_regs(a1, 4608, 1024, "PHY RX0 Registers ");
  ufs_qcom_phy_save_regs(a1, 4096, 448, "PHY TX0 Registers ");
  ufs_qcom_phy_save_regs(a1, 6656, 1024, "PHY RX1 Registers ");
  return ufs_qcom_phy_save_regs(a1, 6144, 448, "PHY TX1 Registers ");
}
