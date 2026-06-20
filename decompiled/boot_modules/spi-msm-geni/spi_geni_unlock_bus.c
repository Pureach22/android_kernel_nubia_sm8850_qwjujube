void __fastcall spi_geni_unlock_bus(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 (*v8)(void); // x9
  unsigned __int64 v9; // x8
  __int64 (*v10)(void); // x8
  int v11; // w3
  void (*v12)(void); // x8
  __int64 v13; // x0
  void (*v14)(void); // x8

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 312);
  if ( *(_BYTE *)(v1 + 503) == 1 && *(_BYTE *)(v1 + 512) == 1 )
  {
    ipc_log_string(
      *(_QWORD *)(v1 + 472),
      "%s:gpi reset happened for levm, no need to do unlock\n",
      "spi_geni_unlock_bus");
    if ( *(_QWORD *)(v1 + 200) )
      spi_trace_log();
    return;
  }
  v4 = *(_QWORD *)(v1 + 472);
  *(_DWORD *)(v1 + 384) = 0;
  ipc_log_string(v4, "%s %d\n", "spi_geni_unlock_bus", 0);
  if ( *(_QWORD *)(v1 + 200) )
    spi_trace_log();
  v5 = *(_QWORD *)(v1 + 312);
  *(_QWORD *)(v5 + 16) = 0;
  *(_QWORD *)(v5 + 24) = 0x31010000000000LL;
  v5 += 16;
  sg_init_table(v3 + 128, 1);
  *(_QWORD *)(v3 + 128) = (*(_QWORD *)(v3 + 128) & 3LL | ((unsigned __int64)((v5 << 8 >> 8) + 0x8000000000LL) >> 12 << 6))
                        - 0x140000000LL;
  *(_DWORD *)(v3 + 136) = v5 & 0xFFF;
  *(_DWORD *)(v3 + 140) = 16;
  *(_QWORD *)(*(_QWORD *)(v1 + 312) + 440LL) = a1;
  v7 = *(_QWORD *)(v1 + 312);
  v6 = *(_QWORD *)(v1 + 320);
  if ( v6 )
  {
    if ( *(_QWORD *)v6 && (v8 = *(__int64 (**)(void))(*(_QWORD *)v6 + 272LL)) != nullptr )
    {
      if ( *((_DWORD *)v8 - 1) != -1221891457 )
        __break(0x8229u);
      v6 = v8();
      v7 = *(_QWORD *)(v1 + 312);
    }
    else
    {
      v6 = 0;
    }
  }
  *(_QWORD *)(v7 + 424) = v6;
  v9 = *(_QWORD *)(*(_QWORD *)(v1 + 312) + 424LL);
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*(_QWORD *)(v1 + 200), "Err setting up tx desc\n");
    goto LABEL_31;
  }
  *(_QWORD *)(v9 + 40) = spi_gsi_tx_callback;
  *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 312) + 424LL) + 56LL) = *(_QWORD *)(v1 + 312) + 328LL;
  *(_QWORD *)(*(_QWORD *)(v1 + 312) + 360LL) = *(_QWORD *)(v1 + 312) + 440LL;
  v10 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v1 + 312) + 424LL) + 24LL);
  if ( *((_DWORD *)v10 - 1) != 1188179853 )
    __break(0x8228u);
  *(_DWORD *)(*(_QWORD *)(v1 + 312) + 320LL) = v10();
  v11 = *(_DWORD *)(*(_QWORD *)(v1 + 312) + 320LL);
  if ( v11 < 0 )
  {
    dev_err(*(_QWORD *)(v1 + 200), "%s: dmaengine_submit failed (%d)\n", "spi_geni_unlock_bus", v11);
LABEL_31:
    v14 = *(void (**)(void))(**(_QWORD **)(v1 + 320) + 336LL);
    if ( v14 )
    {
      if ( *((_DWORD *)v14 - 1) != -403578064 )
        __break(0x8228u);
      v14();
    }
    return;
  }
  v12 = *(void (**)(void))(**(_QWORD **)(v1 + 320) + 360LL);
  if ( *((_DWORD *)v12 - 1) != 905352215 )
    __break(0x8228u);
  v12();
  if ( (int)wait_for_completion_timeout(v1 + 384, 375) <= 0 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 472), "%s failed\n", "spi_geni_unlock_bus");
    v13 = *(_QWORD *)(v1 + 200);
    if ( v13 )
      dev_err(v13, "%s failed\n", "spi_geni_unlock_bus");
    else
      printk(&unk_EB58);
    if ( *(_QWORD *)(v1 + 200) )
      spi_trace_log();
    geni_spi_se_dump_dbg_regs(v1, *(_QWORD *)(v1 + 184), *(_QWORD *)(v1 + 472));
    goto LABEL_31;
  }
}
