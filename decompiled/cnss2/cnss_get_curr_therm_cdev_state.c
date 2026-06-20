__int64 __fastcall cnss_get_curr_therm_cdev_state(
        __int64 a1,
        _QWORD *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x22
  __int64 v11; // x21
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  unsigned __int64 v14; // x8
  const char *v15; // x1
  __int64 v16; // x7
  unsigned __int64 v17; // x8
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  __int16 v22; // w9
  const char *v23; // x8
  __int16 v24; // w9
  const char *v25; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = plat_env;
  if ( plat_env )
  {
    mutex_lock(plat_env + 592);
    v11 = v8 + 576;
    while ( 1 )
    {
      v11 = *(_QWORD *)v11;
      if ( v11 == v8 + 576 )
        break;
      if ( *(_DWORD *)(v11 + 16) == a3 )
      {
        *a2 = *(_QWORD *)(v11 + 24);
        mutex_unlock(v8 + 592);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v13 = "irq";
        }
        else
        {
          v24 = *(_DWORD *)(StatusReg + 16);
          v25 = (const char *)(StatusReg + 2320);
          if ( (v24 & 0xFF00) != 0 )
            v13 = "soft_irq";
          else
            v13 = v25;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v13,
          "cnss_get_curr_therm_cdev_state",
          7u,
          7u,
          "Cooling device current state: %ld, for cdev id %d",
          *(_QWORD *)(v11 + 24),
          a3,
          vars0);
        return 0;
      }
    }
    mutex_unlock(v8 + 592);
    v17 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v17 + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(v17 + 16);
      v23 = (const char *)(v17 + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v23;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v18,
      "cnss_get_curr_therm_cdev_state",
      7u,
      7u,
      "Cooling device ID not found: %d",
      a3,
      v16,
      vars0);
    return 4294967274LL;
  }
  else
  {
    v14 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(v14 + 16);
      v20 = (const char *)(v14 + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v20;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_get_curr_therm_cdev_state",
      3u,
      3u,
      "Platform driver is not initialized!\n",
      a7,
      a8,
      vars0);
    return 4294967277LL;
  }
}
