__int64 __fastcall msm_pcie_iatu_setup_ecam_blocker(__int64 a1)
{
  __int64 v1; // x21
  unsigned __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  unsigned __int64 v6; // x21
  unsigned int v7; // w0
  __int64 v8; // x23
  unsigned __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x21
  __int64 v12; // x21
  __int64 v13; // x22
  unsigned __int64 v14; // x21
  __int64 v15; // x22
  __int64 v16; // x20
  unsigned int *v17; // x19

  v1 = *(_QWORD *)(a1 + 872);
  v3 = **(_QWORD **)(a1 + 408);
  writel_relaxed_0(v3, (unsigned int *)(v1 + 896));
  readl_relaxed_0((unsigned int *)(v1 + 896));
  v4 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(HIDWORD(v3), (unsigned int *)(v4 + 900));
  readl_relaxed_0((unsigned int *)(v4 + 900));
  v5 = *(_QWORD *)(a1 + 872);
  v6 = v3 + 4096;
  v7 = v3 + 4096;
  v3 += 0xFFFFFLL;
  writel_relaxed_0(v7, (unsigned int *)(v5 + 864));
  readl_relaxed_0((unsigned int *)(v5 + 864));
  v8 = *(_QWORD *)(a1 + 872);
  v9 = HIDWORD(v6);
  writel_relaxed_0(HIDWORD(v6), (unsigned int *)(v8 + 868));
  readl_relaxed_0((unsigned int *)(v8 + 868));
  v10 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v6, (unsigned int *)(v10 + 880));
  readl_relaxed_0((unsigned int *)(v10 + 880));
  v11 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v9, (unsigned int *)(v11 + 884));
  readl_relaxed_0((unsigned int *)(v11 + 884));
  v12 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v3, (unsigned int *)(v12 + 872));
  readl_relaxed_0((unsigned int *)(v12 + 872));
  v13 = *(_QWORD *)(a1 + 872);
  v14 = HIDWORD(v3);
  writel_relaxed_0(HIDWORD(v3), (unsigned int *)(v13 + 876));
  readl_relaxed_0((unsigned int *)(v13 + 876));
  v15 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v3, (unsigned int *)(v15 + 888));
  readl_relaxed_0((unsigned int *)(v15 + 888));
  v16 = *(_QWORD *)(a1 + 872);
  writel_relaxed_0(v14, (unsigned int *)(v16 + 892));
  readl_relaxed_0((unsigned int *)(v16 + 892));
  v17 = *(unsigned int **)(a1 + 872);
  writel_relaxed_0(0x4000000u, v17);
  return readl_relaxed_0(v17);
}
