__int64 __fastcall msm_pcie_l1ss_timeout_enable(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x20
  int v4; // w0
  __int64 v5; // x20
  int v6; // w0
  int v7; // w8
  __int64 v8; // x19

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL);
  v2 = *(_QWORD *)(v1 + 872);
  writel_relaxed_0(0x80000000LL, v2 + 384);
  readl_relaxed_0((unsigned int *)(v2 + 384));
  v3 = *(_QWORD *)(v1 + 872);
  v4 = readl_relaxed_0((unsigned int *)(v3 + 552));
  writel_relaxed_0(v4 | 0x200u, v3 + 552);
  readl_relaxed_0((unsigned int *)(v3 + 552));
  v5 = *(_QWORD *)(v1 + 872);
  v6 = readl_relaxed_0((unsigned int *)(v5 + 400));
  writel_relaxed_0(v6 | 1u, v5 + 400);
  readl_relaxed_0((unsigned int *)(v5 + 400));
  v7 = *(_DWORD *)(v1 + 1324);
  v8 = *(_QWORD *)(v1 + 872);
  writel_relaxed_0((100000 * v7) | 0x80000000, v8 + 384);
  return readl_relaxed_0((unsigned int *)(v8 + 384));
}
