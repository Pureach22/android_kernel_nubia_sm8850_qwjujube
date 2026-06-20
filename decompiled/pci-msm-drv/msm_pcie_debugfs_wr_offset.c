size_t __fastcall msm_pcie_debugfs_wr_offset(__int64 a1, unsigned __int64 a2, size_t a3)
{
  size_t v3; // x19
  int v4; // w0

  v3 = a3;
  wr_offset = 0;
  v4 = msm_pcie_debugfs_parse_input(a2, a3, (__int64)&wr_offset);
  if ( v4 )
    return v4;
  printk(&unk_24C0E);
  return v3;
}
