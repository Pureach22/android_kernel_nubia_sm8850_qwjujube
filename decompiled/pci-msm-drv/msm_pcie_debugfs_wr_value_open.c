__int64 __fastcall msm_pcie_debugfs_wr_value_open(__int64 a1, __int64 a2)
{
  return single_open(a2, msm_pcie_debugfs_wr_value_show, 0);
}
