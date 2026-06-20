void __fastcall geni_i3c_dump_dbg_regs(__int64 a1)
{
  __int64 v2; // x26
  int v3; // w21
  int v4; // w23
  int v5; // w24
  int v6; // w20
  int v7; // w22
  int v8; // w25
  int v9; // w20
  int v10; // w0
  int v11; // w0

  v2 = a1 + 20480;
  geni_i3c_se_dump_dbg_regs(a1, *(_QWORD *)a1, *(_QWORD *)(a1 + 2528));
  if ( (*(_BYTE *)(v2 + 840) & 1) != 0 || *(_BYTE *)(v2 + 841) == 1 )
  {
    v3 = readl_relaxed(*(unsigned int **)(a1 + 21328));
    v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 12LL));
    v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 16LL));
    v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 40LL));
    v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 44LL));
    v8 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 4100LL));
    ipc_log_string(
      *(_QWORD *)(a1 + 2528),
      "ibi_gen_config:0x%x, gpii_ibi_en:0x%x, ibi_gen_irq_status:0x%x\n",
      v3,
      v4,
      v5);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    ipc_log_string(
      *(_QWORD *)(a1 + 2528),
      "ibi_unexpect_ibi_info:0x%x, ibi_legacy_mode:0x%x, ibi_irq_status_0:0x%x\n",
      v6,
      v7,
      v8);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  if ( (*(_BYTE *)(v2 + 840) & 1) != 0 || *(_BYTE *)(v2 + 841) == 1 )
  {
    writel_relaxed(0x11u, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 260LL));
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 256LL));
    v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 260LL));
    v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 256LL));
    ipc_log_string(*(_QWORD *)(a1 + 2528), "ibi_test_bus_en:0x%x, ibi_test_bus_sel:0x%x\n", v9, v10);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 264LL));
    ipc_log_string(*(_QWORD *)(a1 + 2528), "ibi_test_bus_reg:0x%x\n", v11);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  if ( *(_DWORD *)(a1 + 108) == 3 )
  {
    if ( *(_QWORD *)(a1 + 2800) )
      gpi_dump_for_geni();
  }
}
