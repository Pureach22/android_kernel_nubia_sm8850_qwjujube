__int64 __fastcall spi_geni_remove(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x23
  __int64 v6; // x24
  int v7; // w0
  unsigned int v8; // w8
  unsigned int v15; // w10
  __int64 v16; // x0

  v1 = *(_QWORD *)(a1 + 168);
  v3 = *(_QWORD *)(v1 + 152);
  sysfs_remove_file_ns(a1 + 16, &dev_attr_spi_slave_state, 0);
  device_remove_file(*(_QWORD *)(v3 + 200), &dev_attr_capture_kpi);
  v4 = *(_QWORD *)(v3 + 24);
  v5 = *(_QWORD *)(v3 + 120);
  v6 = *(_QWORD *)(v3 + 128);
  clk_disable(v4);
  clk_unprepare(v4);
  clk_disable(v5);
  clk_unprepare(v5);
  clk_disable(v6);
  clk_unprepare(v6);
  v7 = geni_icc_disable(v3);
  if ( v7 )
  {
    ipc_log_string(*(_QWORD *)(v3 + 472), "%s failing at geni_icc_disable ret=%d\n", "spi_geni_remove", v7);
    if ( *(_QWORD *)(v3 + 200) )
      spi_trace_log();
  }
  spi_unregister_controller(v1);
  v8 = *(_DWORD *)(a1 + 496);
  do
  {
    if ( !v8 )
      break;
    _X12 = (unsigned int *)(a1 + 496);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v15 = __ldxr(_X12);
      if ( v15 != v8 )
        break;
      if ( !__stlxr(v8 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v15 == v8;
    v8 = v15;
  }
  while ( !_ZF );
  _pm_runtime_disable(a1 + 16, 1);
  if ( *(_BYTE *)(v3 + 536) == 1 && *(_QWORD *)(v3 + 552) )
  {
    v16 = *(_QWORD *)(v3 + 288);
    if ( v16 )
      dma_free_attrs(v16, 65552);
    *(_QWORD *)(v3 + 552) = 0;
    *(_QWORD *)(v3 + 544) = 0;
  }
  if ( *(_QWORD *)(v3 + 472) )
    ipc_log_context_destroy();
  if ( *(_QWORD *)(v3 + 488) )
    ipc_log_context_destroy();
  if ( *(_QWORD *)(v3 + 480) )
    ipc_log_context_destroy();
  return device_remove_file(a1 + 16, &dev_attr_spi_max_dump_size);
}
