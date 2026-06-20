__int64 __fastcall tsens_irq_thread(int a1, __int64 a2)
{
  __int64 v4; // x0
  int v5; // w2
  const char *v6; // x3
  unsigned int v7; // w21
  __int64 v8; // x24
  __int64 v9; // x0
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 48);
  if ( a2 )
  {
    v4 = *(_QWORD *)(a2 + 2592);
    if ( v4 )
    {
      v5 = *(_DWORD *)(a2 + 12) + 1;
      v6 = (const char *)(_ReadStatusReg(SP_EL0) + 2320);
      *(_DWORD *)(a2 + 12) = v5;
      ipc_log_string(v4, "irq count:%d [%s]\n", v5, v6);
    }
  }
  if ( *(_DWORD *)(a2 + 8) )
  {
    v7 = 0;
    do
    {
      v8 = a2 + 2600 + 88LL * (int)v7;
      if ( *(_QWORD *)(v8 + 8) )
      {
        if ( (unsigned int)tsens_threshold_violated(a2, *(unsigned int *)(v8 + 68), v11) )
        {
          thermal_zone_device_update(*(_QWORD *)(v8 + 8), 0);
          if ( !**(_DWORD **)(a2 + 2544) )
            break;
        }
      }
      ++v7;
    }
    while ( v7 < *(_DWORD *)(a2 + 8) );
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 2544) + 12LL) & 1) != 0 )
  {
    tsens_dump_persist_data(a2, 0);
  }
  else if ( a2 )
  {
    v9 = *(_QWORD *)(a2 + 2592);
    if ( v9 )
      ipc_log_string(v9, "irq[%d] exit [%s]\n", a1, (const char *)(_ReadStatusReg(SP_EL0) + 2320));
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
