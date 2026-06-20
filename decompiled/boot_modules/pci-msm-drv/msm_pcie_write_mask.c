__int64 __fastcall msm_pcie_write_mask(unsigned int *a1, int a2, unsigned int a3)
{
  int v6; // w0

  v6 = readl_relaxed_0(a1);
  writel_relaxed_0(v6 & ~a2 | a3, a1);
  return readl_relaxed_0(a1);
}
