__int64 __fastcall mhi_get_remote_time_sync(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 v3; // x19
  __int64 v4; // x23
  __int64 v5; // x24
  __int64 v6; // x22
  unsigned int v7; // w0
  __int64 v10; // x24
  __int64 v11; // x0
  int v12; // w0
  __int64 result; // x0
  unsigned int sync; // w25
  void (__fastcall *v15)(_QWORD); // x8
  __int64 (__fastcall *v16)(_QWORD); // x8
  unsigned __int64 StatusReg; // x24
  __int64 (__fastcall *v23)(__int64); // x8
  __int64 v25; // x8
  void (__fastcall *v26)(_QWORD); // x8
  void (__fastcall *v27)(_QWORD); // x8
  __int64 v28; // x19
  __int64 v29; // x25
  __int64 v30; // x25
  __int64 v31; // x26
  const char *v32; // x0
  __int64 v33; // x20
  const char *v34; // x0

  _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(_QWORD *)(v3 + 16);
  v5 = *(_QWORD *)(v4 + 192);
  v6 = *(_QWORD *)(v5 + 104);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v3 + 336);
    if ( v7 >= 0x80 )
    {
      v32 = to_mhi_pm_state_str(v7);
      dev_err(v4 + 40, "[E][%s] MHI is not in active state, pm_state:%s\n", "mhi_get_remote_time_sync", v32);
      if ( v5 && *(_DWORD *)(v5 + 24) <= 2u )
      {
        v33 = *(_QWORD *)(v5 + 32);
        v34 = to_mhi_pm_state_str(*(_DWORD *)(v3 + 336));
        ipc_log_string(v33, "[E][%s] MHI is not in active state, pm_state:%s\n", "mhi_get_remote_time_sync", v34);
      }
      result = 4294967291LL;
    }
    else
    {
      mutex_lock(v6 + 128);
      if ( *(_BYTE *)(v6 + 64) == 1 )
      {
        v10 = *(_QWORD *)(v6 + 48);
        mutex_unlock(v6 + 128);
        v11 = _msecs_to_jiffies(*(unsigned int *)(v3 + 328));
        v12 = wait_for_completion_timeout(v6 + 72, v11);
        if ( *(_DWORD *)(v3 + 336) <= 0x7Fu && v12 )
        {
          *a2 = v10;
          result = 0;
          *a3 = *(_QWORD *)(v6 + 56);
        }
        else
        {
          v28 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
          dev_err(v4 + 40, "[E][%s] Pending DB request did not complete, abort\n", "mhi_get_remote_time_sync");
          if ( v28 && *(_DWORD *)(v28 + 24) <= 2u )
            ipc_log_string(
              *(_QWORD *)(v28 + 32),
              "[E][%s] Pending DB request did not complete, abort\n",
              "mhi_get_remote_time_sync");
          result = 4294967285LL;
        }
      }
      else
      {
        sync = mhi_device_get_sync(*(_QWORD *)(v3 + 16));
        if ( !sync )
        {
          v15 = *(void (__fastcall **)(_QWORD))(v3 + 512);
          if ( *((_DWORD *)v15 - 1) != -700558418 )
            __break(0x8228u);
          v15(v3);
          v16 = *(__int64 (__fastcall **)(_QWORD))(v6 + 8);
          if ( *((_DWORD *)v16 - 1) != -700558418 )
            __break(0x8228u);
          sync = v16(v3);
          if ( !sync )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(StatusReg + 16);
            __asm { MSR             DAIFSet, #3 }
            if ( (unsigned int)mhi_read_reg(v3) )
            {
              v29 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
              dev_err(v4 + 40, "[E][%s] Time HIGH register read error\n", "mhi_get_remote_time_sync");
              if ( v29 )
              {
                if ( *(_DWORD *)(v29 + 24) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(v29 + 32),
                    "[E][%s] Time HIGH register read error\n",
                    "mhi_get_remote_time_sync");
              }
            }
            if ( (unsigned int)mhi_read_reg(v3) )
            {
              v30 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
              dev_err(v4 + 40, "[E][%s] Time LOW register read error\n", "mhi_get_remote_time_sync");
              if ( v30 )
              {
                if ( *(_DWORD *)(v30 + 24) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(v30 + 32),
                    "[E][%s] Time LOW register read error\n",
                    "mhi_get_remote_time_sync");
              }
            }
            sync = mhi_read_reg(v3);
            if ( sync )
            {
              v31 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
              dev_err(v4 + 40, "[E][%s] Time HIGH register read error\n", "mhi_get_remote_time_sync");
              if ( v31 )
              {
                if ( *(_DWORD *)(v31 + 24) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(v31 + 32),
                    "[E][%s] Time HIGH register read error\n",
                    "mhi_get_remote_time_sync");
              }
            }
            *a3 = -1;
            v23 = *(__int64 (__fastcall **)(__int64))v6;
            if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != 2083580006 )
              __break(0x8228u);
            *a2 = v23(v3);
            __asm { MSR             DAIFClr, #3 }
            v25 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v25;
            if ( !v25 || !*(_QWORD *)(StatusReg + 16) )
              preempt_schedule();
            v26 = *(void (__fastcall **)(_QWORD))(v6 + 16);
            if ( *((_DWORD *)v26 - 1) != -700558418 )
              __break(0x8228u);
            v26(v3);
          }
          v27 = *(void (__fastcall **)(_QWORD))(v3 + 528);
          if ( *((_DWORD *)v27 - 1) != -2145957670 )
            __break(0x8228u);
          v27(v3);
          mhi_device_put(*(_QWORD *)(v3 + 16));
        }
        mutex_unlock(v6 + 128);
        result = sync;
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
