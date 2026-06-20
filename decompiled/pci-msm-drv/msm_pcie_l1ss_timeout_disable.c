__int64 __fastcall msm_pcie_l1ss_timeout_disable(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  int v3; // w0
  __int64 v4; // x19

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL);
  v2 = *(_QWORD *)(v1 + 872);
  v3 = readl_relaxed_0((unsigned int *)(v2 + 400));
  writel_relaxed_0(v3 & 0xFFFFFFFE, v2 + 400);
  readl_relaxed_0((unsigned int *)(v2 + 400));
  v4 = *(_QWORD *)(v1 + 872);
  writel_relaxed_0(0, v4 + 384);
  return readl_relaxed_0((unsigned int *)(v4 + 384));
}
