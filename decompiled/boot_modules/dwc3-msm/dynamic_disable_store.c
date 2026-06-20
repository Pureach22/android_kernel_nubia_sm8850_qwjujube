__int64 __fastcall dynamic_disable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  unsigned int *v6; // x0
  __int64 v7; // x0
  unsigned __int64 v15; // x9
  unsigned __int64 v18; // x10
  _BYTE v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v19[0] = 0;
  if ( (unsigned int)kstrtobool(a3, v19) )
  {
    a4 = -22;
  }
  else if ( v19[0] == 1 )
  {
    if ( (*(_BYTE *)(v5 + 2582) & 1) != 0 )
    {
      ipc_log_string(*(_QWORD *)(v5 + 1256), "%s: USB already disabled\n", "dynamic_disable_store");
    }
    else
    {
      flush_work(v5 + 656);
      _X8 = (unsigned __int64 *)(v5 + 688);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 | 1, _X8) );
      _X8 = (unsigned __int64 *)(v5 + 688);
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      queue_work_on(32, *(_QWORD *)(v5 + 648), v5 + 656);
      flush_work(v5 + 656);
      while ( (*(_QWORD *)(v5 + 688) & 8) != 0 )
        msleep(20);
      *(_BYTE *)(v5 + 2582) = 1;
      ipc_log_string(*(_QWORD *)(v5 + 1256), "%s: Dynamic USB disable\n", "dynamic_disable_store");
    }
  }
  else if ( *(_BYTE *)(v5 + 2582) )
  {
    v6 = *(unsigned int **)(v5 + 16);
    if ( v6 && (unsigned int)readl(v6) != 15 )
    {
      ipc_log_string(*(_QWORD *)(v5 + 1256), "%s: Unable to enable USB\n", "dynamic_disable_store");
    }
    else
    {
      v7 = *(_QWORD *)v5;
      *(_BYTE *)(v5 + 2582) = 0;
      _pm_runtime_disable(v7, 1);
      _pm_runtime_set_status(*(_QWORD *)v5, 2);
      pm_runtime_enable(*(_QWORD *)v5);
      dwc3_ext_event_notify(v5);
      flush_work(v5 + 656);
      ipc_log_string(*(_QWORD *)(v5 + 1256), "%s: Dynamic USB enable\n", "dynamic_disable_store");
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(v5 + 1256), "%s: USB already enabled\n", "dynamic_disable_store");
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
