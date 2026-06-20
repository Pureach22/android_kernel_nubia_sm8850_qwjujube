__int64 __fastcall test_bus_enable_per_qupv3(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  int v4; // w0

  v2 = *(_QWORD *)(a1 + 152);
  writel_relaxed(0x11u, (unsigned int *)(*(_QWORD *)v2 + 516LL));
  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)v2 + 516LL));
  return ipc_log_string(
           a2,
           "%s: TEST_BUS_EN: 0x%x @address:%p\n",
           "test_bus_enable_per_qupv3",
           v4,
           (const void *)(*(_QWORD *)v2 + 516LL));
}
