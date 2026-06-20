__int64 __fastcall cnss_tcdev_set_cur_state(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x21
  unsigned __int64 v9; // x22
  __int64 v10; // x19
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  unsigned int v18; // w0
  unsigned int v19; // w20
  const char *v20; // x1
  char v21; // [xsp+0h] [xbp+0h]
  char v22; // [xsp+0h] [xbp+0h]

  if ( !a1 || (v8 = *(_QWORD *)(a1 + 944)) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(StatusReg + 16);
      v16 = (const char *)(StatusReg + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_tcdev_set_cur_state",
      3u,
      3u,
      "tcdev or tcdev->devdata is null!\n",
      a7,
      a8,
      v21);
    return 4294967274LL;
  }
  if ( *(_QWORD *)(v8 + 32) < a2 )
    return 4294967274LL;
  v9 = _ReadStatusReg(SP_EL0);
  v10 = plat_env;
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v12 = "soft_irq";
  }
  else
  {
    v12 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v12,
    "cnss_tcdev_set_cur_state",
    7u,
    7u,
    "Cooling device set current state: %ld,for cdev id %d",
    a2,
    *(unsigned int *)(v8 + 16),
    v21);
  mutex_lock(v10 + 592);
  v18 = cnss_bus_set_therm_cdev_state(v10);
  if ( v18 )
  {
    v19 = v18;
    mutex_unlock(v10 + 592);
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v20 = "soft_irq";
    }
    else
    {
      v20 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v20,
      "cnss_tcdev_set_cur_state",
      3u,
      3u,
      "Setting Current Thermal State Failed: %d,for cdev id %d",
      v19,
      *(unsigned int *)(v8 + 16),
      v22);
    return v19;
  }
  else
  {
    *(_QWORD *)(v8 + 24) = a2;
    mutex_unlock(v10 + 592);
    return 0;
  }
}
