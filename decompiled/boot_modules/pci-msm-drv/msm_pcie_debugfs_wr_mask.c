size_t __fastcall msm_pcie_debugfs_wr_mask(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  int v4; // w0

  v3 = a3;
  wr_mask = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, (__int64)&wr_mask);
  if ( v4 )
    return v4;
  printk(&unk_2E91D);
  return v3;
}
