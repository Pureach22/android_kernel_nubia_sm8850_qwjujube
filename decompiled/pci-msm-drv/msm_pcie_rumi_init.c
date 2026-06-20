__int64 __fastcall msm_pcie_rumi_init(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w0
  __int64 v4; // x20
  __int64 v5; // x20
  __int64 v6; // x20
  __int64 v7; // x20
  __int64 v8; // x20
  int v9; // w0
  __int64 v10; // x20
  int v11; // w0
  __int64 v12; // x19

  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: enter.\n",
      "msm_pcie_rumi_init",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: PCIe: RC%d: enter.\n", "msm_pcie_rumi_init", *(_DWORD *)(a1 + 1348));
  }
  v2 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(0x7C70u, (unsigned int *)(v2 + 84));
  readl_relaxed_0((unsigned int *)(v2 + 84));
  v3 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 928) + 64LL));
  v4 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(v3 | 0x1000, (unsigned int *)(v4 + 64));
  readl_relaxed_0((unsigned int *)(v4 + 64));
  usleep_range_state(10000, 10001, 2);
  v5 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(0x800u, (unsigned int *)(v5 + 4));
  readl_relaxed_0((unsigned int *)(v5 + 4));
  usleep_range_state(50000, 50001, 2);
  v6 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(0xFFFFFFFF, (unsigned int *)(v6 + 4));
  readl_relaxed_0((unsigned int *)(v6 + 4));
  usleep_range_state(50000, 50001, 2);
  v7 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(0x800u, (unsigned int *)(v7 + 4));
  readl_relaxed_0((unsigned int *)(v7 + 4));
  usleep_range_state(50000, 50001, 2);
  v8 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(0, (unsigned int *)(v8 + 4));
  readl_relaxed_0((unsigned int *)(v8 + 4));
  usleep_range_state(50000, 50001, 2);
  v9 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 928) + 64LL));
  v10 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(v9 & 0xFFFFEFFF, (unsigned int *)(v10 + 64));
  readl_relaxed_0((unsigned int *)(v10 + 64));
  usleep_range_state(10000, 10001, 2);
  v11 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 928) + 64LL));
  v12 = *(_QWORD *)(a1 + 928);
  writel_relaxed_0(v11 & 0xFFFFFFFE, (unsigned int *)(v12 + 64));
  return readl_relaxed_0((unsigned int *)(v12 + 64));
}
