__int64 __fastcall msm_geni_serial_startup(__int64 a1)
{
  __int64 v1; // x21
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x8
  unsigned int qup_hw_version; // w0
  int v9; // w21
  unsigned int v10; // w0
  unsigned int v11; // w8
  unsigned int v12; // w0
  int v15; // w21
  unsigned int v16; // w21
  __int64 v17; // x8
  __int64 v18; // x22
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x20

  v1 = *(_QWORD *)(a1 + 968);
  if ( v1 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v3 = ((__int64 (*)(void))sched_clock)();
      ipc_log_string(v1, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_startup", v3, v3 / 0x3E8);
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
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Start %d\n", "msm_geni_serial_startup", 1);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Start %d\n");
  v5 = *(_QWORD *)(a1 + 264);
  if ( !v5 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v5 + 74) )
  {
    *(_BYTE *)(a1 + 1512) = 0;
    v4 = msm_geni_serial_power_on(a1);
    if ( (_DWORD)v4 )
    {
      v16 = v4;
      dev_err(*(_QWORD *)(a1 + 344), "%s:Failed to power on %d\n", "msm_geni_serial_startup", v4);
      return v16;
    }
  }
  if ( !a1 )
  {
LABEL_32:
    if ( (*(_BYTE *)(a1 + 600) & 1) != 0 )
      goto LABEL_40;
    goto LABEL_33;
  }
  qup_hw_version = geni_se_get_qup_hw_version(a1 + 712);
  if ( ((qup_hw_version & 0xFFE0000) <= 0x90000 || qup_hw_version >> 28 != 3) && (qup_hw_version & 0xC0000000) == 0 )
    v9 = 4128768;
  else
    v9 = 16711680;
  v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 712) + 3620LL));
  *(_DWORD *)(a1 + 552) = (v9 & v10) >> 16;
  if ( (v9 & v10) != 0 )
  {
    v11 = ((unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 712) + 3620LL)) >> 24) & 0x3F;
    *(_DWORD *)(a1 + 556) = v11;
    if ( v11 )
    {
      v12 = geni_se_get_qup_hw_version(a1 + 712);
      if ( ((v12 & 0xFFE0000) <= 0x90000 || v12 >> 28 != 3) && (v12 & 0xC0000000) == 0 )
        v15 = 4128768;
      else
        v15 = 16711680;
      v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 712) + 3624LL));
      *(_DWORD *)(a1 + 560) = (v15 & (unsigned int)v4) >> 16;
      if ( (v15 & (unsigned int)v4) != 0 )
      {
        *(_DWORD *)(a1 + 188) = (unsigned int)(*(_DWORD *)(a1 + 556) * *(_DWORD *)(a1 + 552)) >> 3;
        goto LABEL_32;
      }
      v4 = dev_err(*(_QWORD *)(a1 + 344), "%s:Invalid RX FIFO depth read\n", "get_tx_fifo_size");
    }
    else
    {
      v4 = dev_err(*(_QWORD *)(a1 + 344), "%s:Invalid TX FIFO width read\n", "get_tx_fifo_size");
    }
  }
  else
  {
    v4 = dev_err(*(_QWORD *)(a1 + 344), "%s:Invalid TX FIFO depth read\n", "get_tx_fifo_size");
  }
  if ( (*(_BYTE *)(a1 + 600) & 1) != 0 )
    goto LABEL_40;
LABEL_33:
  v4 = msm_geni_serial_port_setup(a1);
  if ( (_DWORD)v4 )
  {
    v16 = v4;
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: port_setup Fail ret:%d\n", "msm_geni_serial_startup", v4);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: port_setup Fail ret:%d\n");
    goto LABEL_49;
  }
LABEL_40:
  __dsb(0xFu);
  v17 = *(_QWORD *)(a1 + 264);
  if ( v17 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v17 + 74) || *(_BYTE *)(a1 + 1336) == 1 )
    v4 = enable_irq(*(unsigned int *)(a1 + 168));
  v18 = *(_QWORD *)(a1 + 968);
  *(_DWORD *)(a1 + 1516) = 2;
  if ( v18 )
  {
    v16 = 0;
    if ( !v3 || !*(_DWORD *)(a1 + 916) )
      goto LABEL_49;
    v19 = sched_clock(v4);
    ipc_log_string(v18, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_startup", v19 - v3, (v19 - v3) / 0x3E8);
  }
  v16 = 0;
LABEL_49:
  v20 = *(_QWORD *)(a1 + 264);
  if ( !v20 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v20 + 74) )
  {
    v21 = *(_QWORD *)(a1 + 344);
    if ( *(_DWORD *)(v21 + 480) )
    {
      if ( (*(_WORD *)(v21 + 488) & 7) == 0 )
      {
        *(_QWORD *)(v21 + 520) = ktime_get_mono_fast_ns();
        _pm_runtime_suspend(*(_QWORD *)(a1 + 344), 13);
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a1 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Usage Count is already 0\n");
    }
  }
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: ret:%d\n", "msm_geni_serial_startup", v16);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: ret:%d\n");
  return v16;
}
