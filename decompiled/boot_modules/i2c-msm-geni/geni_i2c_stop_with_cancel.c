__int64 __fastcall geni_i2c_stop_with_cancel(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  int v4; // w0
  __int64 v5; // x20
  int v6; // w0
  __int64 v7; // x20
  __int64 v8; // x21
  int v9; // w0
  __int64 v10; // x20
  int v11; // w0
  __int64 v12; // x8
  int v13; // w8
  __int64 result; // x0
  __int64 v15; // x8
  int v16; // w8

  if ( *(_BYTE *)(a1 + 9121) == 1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5096), "%s: test_bus:%d\n", "geni_se_select_test_bus", 8);
    if ( *(_QWORD *)a1 )
      i2c_trace_log();
    writel_relaxed(8u, (unsigned int *)(*(_QWORD *)(a1 + 8) + 68LL));
    v2 = *(_QWORD *)(a1 + 5096);
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 5088) + 152LL);
    writel_relaxed(5u, (unsigned int *)(*(_QWORD *)v3 + 512LL));
    v4 = readl_relaxed((unsigned int *)(*(_QWORD *)v3 + 512LL));
    ipc_log_string(
      v2,
      "%s: readback TEST_BUS_SEL: 0x%x @address:%p\n",
      "test_bus_select_per_qupv3",
      v4,
      (const void *)(*(_QWORD *)v3 + 512LL));
    v5 = *(_QWORD *)(a1 + 5096);
    v6 = readl_relaxed((unsigned int *)(**(_QWORD **)(*(_QWORD *)(a1 + 5088) + 152LL) + 520LL));
    ipc_log_string(v5, "%s: dump QUPV3_TEST_BUS_REG:0x%x\n", "test_bus_read_per_qupv3", v6);
    ipc_log_string(*(_QWORD *)(a1 + 5096), "%s: test_bus:%d\n", "geni_se_select_test_bus", 5);
    if ( *(_QWORD *)a1 )
      i2c_trace_log();
    writel_relaxed(5u, (unsigned int *)(*(_QWORD *)(a1 + 8) + 68LL));
    v7 = *(_QWORD *)(a1 + 5096);
    v8 = *(_QWORD *)(*(_QWORD *)(a1 + 5088) + 152LL);
    writel_relaxed(5u, (unsigned int *)(*(_QWORD *)v8 + 512LL));
    v9 = readl_relaxed((unsigned int *)(*(_QWORD *)v8 + 512LL));
    ipc_log_string(
      v7,
      "%s: readback TEST_BUS_SEL: 0x%x @address:%p\n",
      "test_bus_select_per_qupv3",
      v9,
      (const void *)(*(_QWORD *)v8 + 512LL));
    v10 = *(_QWORD *)(a1 + 5096);
    v11 = readl_relaxed((unsigned int *)(**(_QWORD **)(*(_QWORD *)(a1 + 5088) + 152LL) + 520LL));
    ipc_log_string(v10, "%s: dump QUPV3_TEST_BUS_REG:0x%x\n", "test_bus_read_per_qupv3", v11);
  }
  v12 = *(_QWORD *)(a1 + 4960);
  *(_DWORD *)(a1 + 1304) = 0;
  writel_relaxed(4u, (unsigned int *)(v12 + 1540));
  v13 = wait_for_completion_timeout(a1 + 1304, 250);
  result = 0;
  if ( !v13 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5096), "%s:Cancel failed\n", "geni_i2c_stop_with_cancel");
    if ( *(_QWORD *)a1 )
      i2c_trace_log();
    v15 = *(_QWORD *)(a1 + 4960);
    *(_DWORD *)(a1 + 1272) = 0;
    writel_relaxed(2u, (unsigned int *)(v15 + 1540));
    v16 = wait_for_completion_timeout(a1 + 1272, 250);
    result = 0;
    if ( !v16 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 5096), "%s:Abort failed\n", "geni_i2c_stop_with_cancel");
      if ( *(_QWORD *)a1 )
        i2c_trace_log();
      return 1;
    }
  }
  return result;
}
