__int64 __fastcall msm_pcie_iatu_config_shift(__int64 a1, int a2, unsigned __int8 a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x23
  __int64 v6; // x22
  __int64 v7; // x25
  __int64 v8; // x26
  __int64 v9; // x27
  __int64 v10; // x24

  v5 = *(_QWORD *)(a1 + 896);
  v6 = ((a2 & 0x3FFFFF) << 9) | 4u;
  v7 = (unsigned int)(a2 << 9);
  v8 = ((a2 & 0x3FFFFF) << 9) | 8u;
  v9 = ((a2 & 0x3FFFFF) << 9) | 0xCu;
  v10 = ((a2 & 0x3FFFFF) << 9) | 0x10u;
  writel_relaxed_0(0, (unsigned int *)(v5 + v6));
  readl_relaxed_0((unsigned int *)(v5 + v6));
  writel_relaxed_0(a3, (unsigned int *)(v5 + v7));
  readl_relaxed_0((unsigned int *)(v5 + v7));
  writel_relaxed_0(a4, (unsigned int *)(v5 + v8));
  readl_relaxed_0((unsigned int *)(v5 + v8));
  writel_relaxed_0(HIDWORD(a4), (unsigned int *)(v5 + v9));
  readl_relaxed_0((unsigned int *)(v5 + v9));
  writel_relaxed_0(a5, (unsigned int *)(v5 + v10));
  readl_relaxed_0((unsigned int *)(v5 + v10));
  writel_relaxed_0(0x90000000, (unsigned int *)(v5 + v6));
  return readl_relaxed_0((unsigned int *)(v5 + v6));
}
