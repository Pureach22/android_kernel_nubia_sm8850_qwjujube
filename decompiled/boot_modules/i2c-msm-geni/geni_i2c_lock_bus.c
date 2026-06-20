__int64 __fastcall geni_i2c_lock_bus(_QWORD *a1)
{
  __int64 v1; // x21
  unsigned __int8 *v3; // x22
  unsigned __int64 v4; // x20
  __int64 result; // x0
  int v6; // w8
  _QWORD *v7; // x21
  int v8; // w8
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 (*v11)(void); // x8
  int v12; // w0
  void (*v13)(void); // x8
  int v14; // w8
  __int64 v15; // x0
  __int64 (*v16)(void); // x8
  __int64 v17; // x21
  __int64 v18; // x0
  unsigned int v19; // w21

  v1 = a1[638];
  v3 = (unsigned __int8 *)(a1 + 1024);
  if ( v1 )
  {
    if ( *((_DWORD *)a1 + 1278) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v1, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_lock_bus", v4, v4 / 0x3E8);
      if ( (v3[915] & 1) != 0 )
        goto LABEL_9;
    }
    else
    {
      v4 = 0;
      if ( (*((_BYTE *)a1 + 9107) & 1) != 0 )
        goto LABEL_9;
    }
  }
  else
  {
    v4 = -22;
    if ( (*((_BYTE *)a1 + 9107) & 1) != 0 )
      goto LABEL_9;
  }
  result = geni_i2c_gsi_request_channel(a1);
  if ( (_DWORD)result )
    return result;
LABEL_9:
  v6 = v3[893];
  a1[642] = 0;
  v7 = a1 + 642;
  *((_DWORD *)a1 + 1286) = 0;
  if ( v6 == 1 )
  {
    if ( *((_BYTE *)a1 + 1360) )
      v8 = 3146753;
    else
      v8 = 3145729;
    goto LABEL_15;
  }
  if ( v3[912] == 1 )
  {
    v8 = 3145984;
LABEL_15:
    *((_DWORD *)a1 + 1287) = v8;
  }
  sg_init_table(a1[1115], 1);
  v9 = a1[1115];
  *(_QWORD *)v9 = (*(_QWORD *)v9 & 3LL
                 | ((unsigned __int64)(((__int64)((_QWORD)v7 << 8) >> 8) + 0x8000000000LL) >> 12 << 6))
                - 0x140000000LL;
  *(_DWORD *)(v9 + 8) = (unsigned __int16)v7 & 0xFFF;
  *(_DWORD *)(v9 + 12) = 16;
  v10 = geni_i2c_prep_desc(a1, 1, 1);
  a1[1121] = v10;
  if ( v10 )
  {
    v3[913] = 1;
    *((_DWORD *)a1 + 318) = 0;
    v11 = *(__int64 (**)(void))(v10 + 24);
    if ( *((_DWORD *)v11 - 1) != 1188179853 )
      __break(0x8228u);
    v12 = v11();
    if ( v12 < 0 )
    {
      v19 = v12;
      ipc_log_string(a1[637], "%s: dmaengine_submit failed (%d)\n", "geni_i2c_lock_bus", v12);
      if ( *a1 )
        dev_err(*a1, "%s: dmaengine_submit failed (%d)\n", "geni_i2c_lock_bus", v19);
      else
        printk(&unk_F551, "geni_i2c_lock_bus", v19);
      if ( *a1 )
        i2c_trace_log();
      v14 = -22;
    }
    else
    {
      v13 = *(void (**)(void))(*(_QWORD *)a1[640] + 360LL);
      if ( *((_DWORD *)v13 - 1) != 905352215 )
        __break(0x8228u);
      v13();
      if ( (unsigned int)wait_for_completion_timeout(a1 + 159, 250) )
      {
        v3[913] = 0;
        return 0;
      }
      ipc_log_string(a1[637], "%s timedout\n", "geni_i2c_lock_bus");
      if ( *a1 )
        i2c_trace_log();
      geni_i2c_se_dump_dbg_regs((__int64)(a1 + 620), a1[1], a1[637]);
      v14 = -110;
    }
  }
  else
  {
    v14 = -12;
  }
  v15 = a1[640];
  *((_DWORD *)a1 + 6) = v14;
  v16 = *(__int64 (**)(void))(*(_QWORD *)v15 + 336LL);
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != -403578064 )
      __break(0x8228u);
    v15 = v16();
  }
  v17 = a1[638];
  *((_DWORD *)a1 + 2238) = 0;
  v3[913] = 0;
  if ( v17 && v4 )
  {
    if ( *((_DWORD *)a1 + 1278) )
    {
      v18 = sched_clock(v15);
      ipc_log_string(v17, "%s:took %llu nsec(%llu usec)\n", "geni_i2c_lock_bus", v18 - v4, (v18 - v4) / 0x3E8);
    }
  }
  return *((unsigned int *)a1 + 6);
}
