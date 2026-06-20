__int64 __fastcall cnss_thermal_cdev_unregister(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  _QWORD *v9; // x19
  _QWORD **v10; // x21
  _QWORD *v11; // x8
  __int64 v12; // x9
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = plat_env;
  if ( plat_env )
  {
    mutex_lock(plat_env + 592);
    v9 = *(_QWORD **)(v8 + 576);
    v10 = (_QWORD **)(v8 + 576);
    if ( v9 != (_QWORD *)(v8 + 576) )
    {
      do
      {
        thermal_cooling_device_unregister(v9[6]);
        v11 = (_QWORD *)v9[1];
        if ( (_QWORD *)*v11 == v9 && (v12 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
        {
          *(_QWORD *)(v12 + 8) = v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v9);
        }
        *v9 = 0xDEAD000000000100LL;
        v9[1] = 0xDEAD000000000122LL;
        kfree(v9);
        v9 = *v10;
      }
      while ( *v10 != v10 );
    }
    return mutex_unlock(v8 + 592);
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(StatusReg + 16);
      v17 = (const char *)(StatusReg + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v17;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v15,
             "cnss_thermal_cdev_unregister",
             3u,
             3u,
             "Platform driver is not initialized!\n",
             a7,
             a8,
             vars0);
  }
}
