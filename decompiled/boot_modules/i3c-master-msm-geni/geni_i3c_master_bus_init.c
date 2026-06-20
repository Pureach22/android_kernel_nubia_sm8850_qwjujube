__int64 __fastcall geni_i3c_master_bus_init(__int64 a1)
{
  __int64 v2; // x21
  unsigned __int64 v3; // x20
  int v4; // w0
  __int64 v5; // x9
  __int64 v6; // x8
  int v7; // w0
  unsigned int v8; // w21
  __int64 v9; // x8
  unsigned int v10; // w0
  int free_addr; // w0
  __int64 v12; // x0
  __int64 v13; // x22
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x0
  __int64 v18; // x3
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  unsigned int v22; // w2
  unsigned int v23; // w9
  unsigned int v30; // w11
  __int64 v32; // x3
  __int64 v33; // x0
  unsigned int v34; // w21
  __int64 v35; // x3
  __int64 v36; // x0
  __int64 v37; // [xsp+0h] [xbp-20h] BYREF
  __int64 v38; // [xsp+8h] [xbp-18h]
  __int64 v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 2424);
  v38 = 0;
  v39 = 0;
  v37 = 0;
  if ( v2 )
  {
    if ( *(_DWORD *)(a1 + 2432) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_bus_init", v3, v3 / 0x3E8);
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = -22;
  }
  v4 = _pm_runtime_resume(*(_QWORD *)(a1 - 104), 4);
  if ( v4 < 0 )
  {
    v8 = v4;
    ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: error turning SE resources:%d\n", "geni_i3c_master_bus_init", v4);
    v19 = *(_QWORD *)(a1 - 104);
    if ( v19 )
    {
      dev_err(v19, "%s: error turning SE resources:%d\n", "geni_i3c_master_bus_init", v8);
      if ( *(_QWORD *)(a1 - 104) )
        goto LABEL_67;
    }
    else
    {
      printk(&unk_12DA9, "geni_i3c_master_bus_init", v8, v18);
      if ( *(_QWORD *)(a1 - 104) )
      {
LABEL_67:
        i3c_trace_log();
        v20 = *(_QWORD *)(a1 - 104);
        goto LABEL_77;
      }
    }
    v20 = 0;
LABEL_77:
    v23 = *(_DWORD *)(v20 + 480);
    do
    {
      if ( !v23 )
        break;
      _X13 = (unsigned int *)(v20 + 480);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v30 = __ldxr(_X13);
        if ( v30 != v23 )
          break;
        if ( !__stlxr(v23 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v30 == v23;
      v23 = v30;
    }
    while ( !_ZF );
    _pm_runtime_set_status(*(_QWORD *)(a1 - 104), 2);
    goto LABEL_87;
  }
  v5 = *(_QWORD *)(a1 + 2296);
  v6 = *(_QWORD *)(a1 + 2304);
  if ( v5 == 100000 && *(_DWORD *)(a1 + 21136) == 19200000 )
    *(_QWORD *)(a1 + 21192) = &geni_i3c_clk_map;
  if ( v6 == 100000 )
    *(_QWORD *)(a1 + 21200) = &geni_i3c_clk_map;
  if ( v5 == 400000 && *(_DWORD *)(a1 + 21136) == 19200000 )
    *(_QWORD *)(a1 + 21192) = &unk_12474;
  if ( v6 == 400000 )
    *(_QWORD *)(a1 + 21200) = &unk_12474;
  if ( v5 == 1000000 && *(_DWORD *)(a1 + 21136) == 19200000 )
    *(_QWORD *)(a1 + 21192) = &unk_12488;
  if ( v6 == 1000000 )
    *(_QWORD *)(a1 + 21200) = &unk_12488;
  if ( v5 == 1920000 && *(_DWORD *)(a1 + 21136) == 19200000 )
    *(_QWORD *)(a1 + 21192) = &unk_1249C;
  if ( v6 == 1920000 )
    *(_QWORD *)(a1 + 21200) = &unk_1249C;
  if ( v5 == 3500000 && *(_DWORD *)(a1 + 21136) == 19200000 )
    *(_QWORD *)(a1 + 21192) = &unk_124B0;
  if ( v6 == 3500000 )
    *(_QWORD *)(a1 + 21200) = &unk_124B0;
  if ( v5 == 370000 && *(_DWORD *)(a1 + 21136) == 100000000 )
    *(_QWORD *)(a1 + 21192) = &unk_124C4;
  if ( v6 == 370000 )
    *(_QWORD *)(a1 + 21200) = &unk_124C4;
  if ( v5 == 12500000 && *(_DWORD *)(a1 + 21136) == 100000000 )
    *(_QWORD *)(a1 + 21192) = &unk_124D8;
  if ( v6 == 12500000 )
    *(_QWORD *)(a1 + 21200) = &unk_124D8;
  if ( v5 == 8300000 && *(_DWORD *)(a1 + 21136) == 64000000 )
    *(_QWORD *)(a1 + 21192) = &unk_124EC;
  if ( v6 == 8300000 )
    *(_QWORD *)(a1 + 21200) = &unk_124EC;
  if ( !*(_QWORD *)(a1 + 21192) || !*(_QWORD *)(a1 + 21200) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2416), "%s : clk mapping failed", "geni_i3c_clk_map_idx");
    v17 = *(_QWORD *)(a1 - 104);
    if ( v17 )
    {
      dev_err(v17, "%s : clk mapping failed", "geni_i3c_clk_map_idx");
      if ( !*(_QWORD *)(a1 - 104) )
        goto LABEL_70;
    }
    else
    {
      printk(&unk_14BE8, "geni_i3c_clk_map_idx", v15, v16);
      if ( !*(_QWORD *)(a1 - 104) )
      {
LABEL_70:
        ipc_log_string(
          *(_QWORD *)(a1 + 2416),
          "Invalid clk frequency %d Hz src or %ld Hz bus: %d\n",
          *(_DWORD *)(a1 + 21136),
          *(_QWORD *)(a1 + 2296),
          -22);
        v21 = *(_QWORD *)(a1 - 104);
        v22 = *(_DWORD *)(a1 + 21136);
        if ( v21 )
        {
          dev_err(v21, "Invalid clk frequency %d Hz src or %ld Hz bus: %d\n", v22, *(_QWORD *)(a1 + 2296), -22);
          if ( !*(_QWORD *)(a1 - 104) )
            goto LABEL_57;
          goto LABEL_97;
        }
        printk(&unk_13937, v22, *(_QWORD *)(a1 + 2296), 4294967274LL);
        if ( *(_QWORD *)(a1 - 104) )
LABEL_97:
          i3c_trace_log();
LABEL_57:
        v12 = _pm_runtime_suspend(*(_QWORD *)(a1 - 104), 4);
        v8 = v12;
        if ( (v12 & 0x80000000) != 0 )
        {
          ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: error turning SE resources:%d\n", "geni_i3c_master_bus_init", v12);
          v33 = *(_QWORD *)(a1 - 104);
          if ( v33 )
            dev_err(v33, "%s: error turning SE resources:%d\n", "geni_i3c_master_bus_init", v8);
          else
            printk(&unk_12DA9, "geni_i3c_master_bus_init", v8, v32);
          if ( *(_QWORD *)(a1 - 104) )
            goto LABEL_51;
        }
        else
        {
          v13 = *(_QWORD *)(a1 + 2424);
          if ( v13 && v3 && *(_DWORD *)(a1 + 2432) )
          {
            v14 = sched_clock(v12);
            ipc_log_string(
              v13,
              "%s:took %llu nsec(%llu usec)\n",
              "geni_i3c_master_bus_init",
              v14 - v3,
              (v14 - v3) / 0x3E8);
          }
        }
        goto LABEL_87;
      }
    }
    i3c_trace_log();
    goto LABEL_70;
  }
  v7 = qcom_geni_i3c_conf(a1 - 112, 0);
  if ( !v7 )
  {
    v9 = *(_QWORD *)(a1 + 2304);
    if ( v9 == 1000000 )
      v10 = 2;
    else
      v10 = v9 == 400000;
    writel_relaxed(v10, (unsigned int *)(*(_QWORD *)(a1 + 21216) + 4LL));
    free_addr = i3c_master_get_free_addr(a1, 0);
    if ( (free_addr & 0x80000000) == 0 )
    {
      BYTE3(v38) = free_addr;
      LOWORD(v38) = 96;
      v37 = 0;
      i3c_master_set_info(a1, &v37);
      goto LABEL_57;
    }
    v34 = free_addr;
    ipc_log_string(*(_QWORD *)(a1 + 2416), "%s: error No free addr:%d\n", "geni_i3c_master_bus_init", free_addr);
    v36 = *(_QWORD *)(a1 - 104);
    if ( v36 )
      dev_err(v36, "%s: error No free addr:%d\n", "geni_i3c_master_bus_init", v34);
    else
      printk(&unk_14A08, "geni_i3c_master_bus_init", v34, v35);
    if ( *(_QWORD *)(a1 - 104) )
      goto LABEL_97;
    goto LABEL_57;
  }
  v8 = v7;
  ipc_log_string(*(_QWORD *)(a1 + 2416), "%s:geni i3c config failed, ret:%d\n", "geni_i3c_master_bus_init", v7);
  if ( *(_QWORD *)(a1 - 104) )
LABEL_51:
    i3c_trace_log();
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return v8;
}
