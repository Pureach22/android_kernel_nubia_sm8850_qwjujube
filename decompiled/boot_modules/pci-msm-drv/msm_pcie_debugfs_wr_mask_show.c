__int64 __fastcall msm_pcie_debugfs_wr_mask_show(__int64 a1)
{
  seq_printf(a1, "0x%x\n", wr_mask);
  return 0;
}
