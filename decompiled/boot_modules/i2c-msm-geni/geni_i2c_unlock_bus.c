void __fastcall geni_i2c_unlock_bus(_QWORD *a1)
{
  __int64 v1; // x21
  _BYTE *v3; // x22
  unsigned __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x9
  __int64 v7; // x0
  __int64 (*v8)(void); // x8
  int v9; // w0
  void (*v10)(void); // x8
  __int64 v11; // x0
  __int64 (*v12)(void); // x8
  __int64 v13; // x21
  __int64 v14; // x0
  unsigned int v15; // w21

  v1 = a1[638];
  v3 = a1 + 1024;
  if ( v1 )
  {
    if ( *((_DWORD *)a1 + 1278) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v1, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_unlock_bus", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  if ( v3[912] == 1 && v3[917] == 1 )
  {
    ipc_log_string(a1[637], "%s:gpi reset happened for levm, no need to do unlock\n", "geni_i2c_unlock_bus");
    if ( *a1 )
      i2c_trace_log();
    return;
  }
  v5 = a1[1115];
  a1[644] = 0;
  a1[645] = 0x31010000000000LL;
  sg_init_table(v5, 1);
  v6 = a1[1115];
  *(_QWORD *)v6 = (*(_QWORD *)v6 & 3LL
                 | ((unsigned __int64)(((__int64)((_QWORD)(a1 + 644) << 8) >> 8) + 0x8000000000LL) >> 12 << 6))
                - 0x140000000LL;
  *(_DWORD *)(v6 + 8) = ((_DWORD)a1 + 5152) & 0xFFF;
  *(_DWORD *)(v6 + 12) = 16;
  v7 = geni_i2c_prep_desc(a1, 1, 1);
  a1[1121] = v7;
  if ( v7 )
  {
    v3[913] = 1;
    *((_DWORD *)a1 + 318) = 0;
    v8 = *(__int64 (**)(void))(v7 + 24);
    if ( *((_DWORD *)v8 - 1) != 1188179853 )
      __break(0x8228u);
    v9 = v8();
    if ( v9 < 0 )
    {
      v15 = v9;
      ipc_log_string(a1[637], "%s: dmaengine_submit failed (%d)\n", "geni_i2c_unlock_bus", v9);
      if ( *a1 )
        dev_err(*a1, "%s: dmaengine_submit failed (%d)\n", "geni_i2c_unlock_bus", v15);
      else
        printk(&unk_F551, "geni_i2c_unlock_bus", v15);
      if ( *a1 )
        i2c_trace_log();
    }
    else
    {
      v10 = *(void (**)(void))(*(_QWORD *)a1[640] + 360LL);
      if ( *((_DWORD *)v10 - 1) != 905352215 )
        __break(0x8228u);
      v10();
      v11 = wait_for_completion_timeout(a1 + 159, 250);
      if ( (_DWORD)v11 )
        goto LABEL_25;
      ipc_log_string(a1[637], "%s failed\n", "geni_i2c_unlock_bus");
      if ( *a1 )
        i2c_trace_log();
      geni_i2c_se_dump_dbg_regs((__int64)(a1 + 620), a1[1], a1[637]);
    }
  }
  v11 = a1[640];
  v12 = *(__int64 (**)(void))(*(_QWORD *)v11 + 336LL);
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != -403578064 )
      __break(0x8228u);
    v11 = v12();
  }
  *((_DWORD *)a1 + 2238) = 0;
LABEL_25:
  v13 = a1[638];
  v3[913] = 0;
  if ( v13 && v4 && *((_DWORD *)a1 + 1278) )
  {
    v14 = sched_clock(v11);
    ipc_log_string(v13, "%s:took %llu nsec(%llu usec)\n", "geni_i2c_unlock_bus", v14 - v4, (v14 - v4) / 0x3E8);
  }
}
