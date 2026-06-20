__int64 __fastcall spi_geni_lock_bus(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  _QWORD *v5; // x22
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 (*v8)(void); // x9
  unsigned __int64 v9; // x8
  __int64 (*v10)(void); // x8
  int v11; // w3
  void (*v12)(void); // x8
  __int64 result; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  void (__fastcall *v16)(_QWORD); // x9
  unsigned int v17; // w19

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 472);
  v4 = *(_QWORD *)(v1 + 312);
  *(_DWORD *)(v1 + 384) = 0;
  ipc_log_string(v3, "%s %d\n", "spi_geni_lock_bus", 0);
  if ( *(_QWORD *)(v1 + 200) )
    spi_trace_log();
  v5 = *(_QWORD **)(v1 + 312);
  *v5 = 0;
  v5[1] = 0x30010000000000LL;
  sg_init_table(v4 + 128, 1);
  *(_QWORD *)(v4 + 128) = (*(_QWORD *)(v4 + 128) & 3LL
                         | ((unsigned __int64)(((__int64)((_QWORD)v5 << 8) >> 8) + 0x8000000000LL) >> 12 << 6))
                        - 0x140000000LL;
  *(_DWORD *)(v4 + 136) = (unsigned __int16)v5 & 0xFFF;
  *(_DWORD *)(v4 + 140) = 16;
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
  if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
  {
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
      dev_err(*(_QWORD *)(v1 + 200), "%s: dmaengine_submit failed (%d)\n", "spi_geni_lock_bus", v11);
      result = 4294967274LL;
    }
    else
    {
      v12 = *(void (**)(void))(**(_QWORD **)(v1 + 320) + 360LL);
      if ( *((_DWORD *)v12 - 1) != 905352215 )
        __break(0x8228u);
      v12();
      if ( (int)wait_for_completion_timeout(v1 + 384, 375) > 0 )
        return 0;
      ipc_log_string(*(_QWORD *)(v1 + 472), "%s failed\n", "spi_geni_lock_bus");
      v14 = *(_QWORD *)(v1 + 200);
      if ( v14 )
        dev_err(v14, "%s failed\n", "spi_geni_lock_bus");
      else
        printk(&unk_EB58);
      if ( *(_QWORD *)(v1 + 200) )
        spi_trace_log();
      geni_spi_se_dump_dbg_regs(v1, *(_QWORD *)(v1 + 184), *(_QWORD *)(v1 + 472));
      result = 4294967186LL;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(v1 + 200), "Err setting up tx desc\n");
    result = 4294967291LL;
  }
  v15 = *(_QWORD *)(v1 + 320);
  v16 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v15 + 336LL);
  if ( v16 )
  {
    v17 = result;
    if ( *((_DWORD *)v16 - 1) != -403578064 )
      __break(0x8229u);
    v16(v15);
    return v17;
  }
  return result;
}
