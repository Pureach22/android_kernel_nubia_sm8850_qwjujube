__int64 __fastcall msm_geni_serial_handle_dma_tx(__int64 a1)
{
  __int64 v1; // x26
  int v2; // w8
  __int64 v3; // x19
  __int64 v4; // x1
  unsigned int v5; // w8
  __int64 v6; // x27
  unsigned int v7; // w7
  __int64 v8; // x21
  __int64 v9; // x8
  int v10; // w6
  __int64 v11; // x9
  int v12; // w20
  unsigned int v13; // w7
  unsigned __int64 v14; // x3
  int v15; // w8
  int v16; // w8
  int v17; // w8
  int v18; // w9
  int v19; // w10
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x20

  v1 = *(_QWORD *)(a1 + 208);
  v2 = *(_DWORD *)(a1 + 816);
  v3 = a1;
  *(_DWORD *)(v1 + 380) += v2;
  v4 = *(_QWORD *)(a1 + 808);
  *(_DWORD *)(a1 + 236) += v2;
  if ( v4 && (*(_BYTE *)(a1 + 2001) & 1) == 0 )
    a1 = geni_se_tx_dma_unprep(a1 + 712, v4, *(unsigned int *)(a1 + 816));
  if ( *(_DWORD *)(v3 + 916) )
  {
    v5 = *(_DWORD *)(v3 + 580);
    if ( v5 >= 5 )
      goto LABEL_24;
    v6 = v3 + 1520;
    *(_DWORD *)(v3 + 1520 + 48LL * v5 + 32) = *(_DWORD *)(v3 + 816);
    a1 = sched_clock(a1);
    v7 = *(_DWORD *)(v3 + 580);
    if ( v7 > 4 )
      goto LABEL_24;
    v8 = a1;
    v9 = v6 + 48LL * v7;
    v10 = *(_DWORD *)(v3 + 1000);
    v11 = *(_QWORD *)(v9 + 8);
    v12 = *(_DWORD *)(v9 + 32);
    *(_QWORD *)(v9 + 40) = a1;
    ipc_log_string(
      *(_QWORD *)(v3 + 968),
      "%s:TX transfer time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n",
      "msm_geni_serial_handle_dma_tx",
      a1 - v11,
      (a1 - v11) / 0x3E8uLL,
      v12,
      v10,
      v7);
    _ftrace_dbg(*(_QWORD *)(v3 + 344), "%s:TX transfer time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n");
    v13 = *(_DWORD *)(v3 + 580);
    if ( v13 > 4 )
    {
LABEL_24:
      __break(0x5512u);
      return msm_geni_serial_prep_dma_tx(a1);
    }
    v14 = v8 - *(_QWORD *)(v6 + 48LL * v13 + 24);
    ipc_log_string(
      *(_QWORD *)(v3 + 968),
      "%s:TX Hardware time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n",
      "msm_geni_serial_handle_dma_tx",
      v14,
      v14 / 0x3E8,
      v12,
      *(_DWORD *)(v3 + 1000),
      v13);
    _ftrace_dbg(*(_QWORD *)(v3 + 344), "%s:TX Hardware time %llu nsec(%llu usec) for %d bytes with freq %d index:%d\n");
    v15 = *(_DWORD *)(v3 + 580);
    if ( (unsigned int)(v15 + 1) <= 4 )
      v16 = v15 + 1;
    else
      v16 = 0;
    *(_DWORD *)(v3 + 580) = v16;
  }
  v17 = *(_DWORD *)(v3 + 816);
  v18 = *(_DWORD *)(v3 + 236);
  v19 = *(unsigned __int8 *)(v3 + 2001);
  *(_QWORD *)(v3 + 808) = 0;
  *(_DWORD *)(v3 + 236) = v18 + v17;
  if ( v19 == 1 )
    *(_BYTE *)(v3 + 2001) = 0;
  *(_DWORD *)(v3 + 816) = 0;
  if ( *(_DWORD *)(v1 + 376) != *(_DWORD *)(v1 + 380) )
    return msm_geni_serial_prep_dma_tx(v3);
  v20 = *(_QWORD *)(v3 + 264);
  if ( !v20 || *(_DWORD *)(v3 + 316) != *(__int16 *)(v20 + 74) )
  {
    ipc_log_string(*(_QWORD *)(v3 + 960), "%s.Tx sent out, Power off\n", "msm_geni_serial_handle_dma_tx");
    _ftrace_dbg(*(_QWORD *)(v3 + 344), "%s.Tx sent out, Power off\n");
    v22 = *(_QWORD *)(v3 + 344);
    if ( *(_DWORD *)(v22 + 480) )
    {
      if ( (*(_WORD *)(v22 + 488) & 7) == 0 )
      {
        *(_QWORD *)(v22 + 520) = ktime_get_mono_fast_ns(v21);
        _pm_runtime_suspend(*(_QWORD *)(v3 + 344), 13);
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v3 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
      _ftrace_dbg(*(_QWORD *)(v3 + 344), "%s: Usage Count is already 0\n");
    }
  }
  return uart_write_wakeup(v3);
}
