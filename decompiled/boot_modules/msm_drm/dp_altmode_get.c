__int64 __fastcall dp_altmode_get(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x19
  __int64 v5; // x0
  int v6; // w20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  int v9; // w2
  _QWORD *v10; // x19
  __int64 v11; // x0

  if ( a2 )
  {
    v4 = (_QWORD *)_kmalloc_cache_noprof(_drm_dev_dbg, 3520, 112);
    if ( v4 )
    {
      v4[1] = a1;
      v4[2] = a2;
      v4[6] = 0;
      v4[9] = dp_altmode_simulate_connect;
      v4[10] = dp_altmode_simulate_attention;
      v5 = altmode_register_notifier(a1, dp_altmode_register, v4);
      v6 = v5;
      ipc_log_context = get_ipc_log_context(v5);
      StatusReg = _ReadStatusReg(SP_EL0);
      v9 = *(_DWORD *)(StatusReg + 1800);
      if ( v6 < 0 )
      {
        ipc_log_string(ipc_log_context, "[e][%-4d]altmode probe notifier registration failed: %d\n", v9, v6);
        printk(&unk_255C92, "dp_altmode_get");
        kfree(v4);
        return v6;
      }
      else
      {
        v10 = v4 + 3;
        ipc_log_string(ipc_log_context, "[d][%-4d]success\n", v9);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]success\n", *(_DWORD *)(StatusReg + 1800));
      }
    }
    else
    {
      return -12;
    }
  }
  else
  {
    v11 = get_ipc_log_context(a1);
    ipc_log_string(v11, "[e][%-4d]invalid cb data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_23E030, "dp_altmode_get");
    return -22;
  }
  return (__int64)v10;
}
