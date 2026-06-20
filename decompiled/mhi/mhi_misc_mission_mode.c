__int64 __fastcall mhi_misc_mission_mode(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x22
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x20
  __int64 v10; // x20
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  v11 = 0;
  v12[0] = 0;
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 192) + 96LL);
  result = mhi_get_remote_time_sync(v2, v12, &v11);
  if ( !(_DWORD)result )
  {
    v7 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 24) <= 1u )
        result = ipc_log_string(
                   *(_QWORD *)(v7 + 32),
                   "[I][%s] Timesync: local: %llx, remote: %llx\n",
                   "mhi_misc_mission_mode",
                   v12[0],
                   v11);
    }
  }
  if ( *(_DWORD *)(a1 + 208) >= 0x14u )
  {
    result = *(_QWORD *)(*(_QWORD *)(a1 + 176) + 7872LL);
    if ( result )
      result = mhi_notify(result);
  }
  if ( v3 )
  {
    memset(*(void **)(v3 + 24), 0, *(_QWORD *)(v3 + 16));
    v5 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), *(_QWORD *)(v3 + 16), v3 + 8, &print_fmt_mhi_intvec_states[936], 0);
    *(_QWORD *)v3 = v5;
    if ( v5 )
    {
      *(_DWORD *)(v3 + 40) = 0;
      _init_swait_queue_head(v3 + 48, "&x->wait", &init_completion___key_0);
      if ( (unsigned int)mhi_send_cmd(a1, 0, 73) )
      {
        v10 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        result = dev_err(v2 + 40, "[E][%s] Failed to send sfr cfg cmd\n", "mhi_misc_mission_mode");
        if ( v10 && *(_DWORD *)(v10 + 24) < 3u )
          result = ipc_log_string(
                     *(_QWORD *)(v10 + 32),
                     "[E][%s] Failed to send sfr cfg cmd\n",
                     "mhi_misc_mission_mode");
      }
      else
      {
        v6 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
        result = wait_for_completion_timeout(v3 + 40, v6);
        if ( !(_DWORD)result || *(_DWORD *)(v3 + 32) != 1 )
        {
          v8 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
          result = dev_err(v2 + 40, "[E][%s] Failed to get sfr cfg cmd completion\n", "mhi_misc_mission_mode");
          if ( v8 && *(_DWORD *)(v8 + 24) <= 2u )
            result = ipc_log_string(
                       *(_QWORD *)(v8 + 32),
                       "[E][%s] Failed to get sfr cfg cmd completion\n",
                       "mhi_misc_mission_mode");
        }
      }
    }
    else
    {
      v9 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      result = dev_err(v2 + 40, "[E][%s] Failed to allocate memory for sfr\n", "mhi_misc_mission_mode");
      if ( v9 && *(_DWORD *)(v9 + 24) < 3u )
        result = ipc_log_string(
                   *(_QWORD *)(v9 + 32),
                   "[E][%s] Failed to allocate memory for sfr\n",
                   "mhi_misc_mission_mode");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
