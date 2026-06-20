__int64 __fastcall ipa3_setup_apps_low_lat_cons_pipe(char a1, _DWORD *a2)
{
  __int64 v4; // x8
  unsigned int v5; // w4
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x9
  unsigned int v14; // w19
  unsigned int v15; // w19
  __int64 v16; // x8
  void (__fastcall *v17)(_QWORD); // x9
  __int64 v18; // x0
  __int64 v19; // x0
  int v20; // w9
  __int64 v21; // x8
  __int64 v22; // x0

  if ( (*(_BYTE *)(ipa3_ctx + 48858) & 1) != 0 )
  {
    if ( (unsigned int)ipa_get_ep_mapping(105) == -1 )
    {
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          ipc_log_string(v7, "ipa %s:%d Low lat datapath not supported\n", "ipa3_setup_apps_low_lat_cons_pipe", 231);
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
          ipc_log_string(v8, "ipa %s:%d Low lat datapath not supported\n", "ipa3_setup_apps_low_lat_cons_pipe", 231);
      }
    }
    else
    {
      v4 = rmnet_ctl_ipa3_ctx;
      v5 = *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56);
      if ( v5 < 2 )
      {
        *(_DWORD *)(rmnet_ctl_ipa3_ctx + 416) = 0;
        if ( a2 && (a1 & 1) != 0 )
        {
          *(_DWORD *)(v4 + 472) = a2[2] != 0;
          *(_BYTE *)(v4 + 568) = 1;
          *(_DWORD *)(v4 + 556) = a2[7];
          *(_DWORD *)(v4 + 560) = a2[8];
          *(_DWORD *)(v4 + 564) = a2[3];
          *(_DWORD *)(v4 + 424) = a2[4];
          *(_DWORD *)(v4 + 432) = a2[6];
          *(_DWORD *)(v4 + 428) = a2[5];
        }
        else
        {
          *(_BYTE *)(v4 + 568) = 0;
          *(_DWORD *)(v4 + 472) = 1;
          *(_DWORD *)(v4 + 424) = 0;
          *(_DWORD *)(v4 + 432) = 0;
        }
        *(_QWORD *)(v4 + 332) = 0x100000008LL;
        *(_DWORD *)(v4 + 340) = 1;
        *(_QWORD *)(v4 + 348) = 0x200000001LL;
        *(_DWORD *)(v4 + 480) = -16777216;
        *(_WORD *)(v4 + 384) = 1;
        *(_QWORD *)(v4 + 512) = 0x80000000069LL;
        *(_DWORD *)(v4 + 380) = 0;
        *(_BYTE *)(v4 + 376) = 1;
        *(_DWORD *)(v4 + 372) = 0;
        *(_QWORD *)(v4 + 528) = apps_rmnet_ctl_receive_notify;
        *(_QWORD *)(v4 + 520) = 0;
        result = ipa_setup_sys_pipe(v4 + 320, (unsigned int *)(v4 + 580));
        if ( (_DWORD)result )
        {
          v13 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            if ( *(_QWORD *)(ipa3_ctx + 34152) )
            {
              v14 = result;
              ipc_log_string(
                *(_QWORD *)(ipa3_ctx + 34152),
                "ipa %s:%d Low lat pipe setup fails\n",
                "ipa3_setup_apps_low_lat_cons_pipe",
                306);
              v13 = ipa3_ctx;
              result = v14;
            }
            if ( *(_QWORD *)(v13 + 34160) )
            {
              v15 = result;
              ipc_log_string(
                *(_QWORD *)(v13 + 34160),
                "ipa %s:%d Low lat pipe setup fails\n",
                "ipa3_setup_apps_low_lat_cons_pipe",
                306);
              return v15;
            }
          }
          return result;
        }
        v16 = rmnet_ctl_ipa3_ctx;
        v17 = *(void (__fastcall **)(_QWORD))(rmnet_ctl_ipa3_ctx + 592);
        *(_BYTE *)(rmnet_ctl_ipa3_ctx + 60) |= 2u;
        if ( v17 )
        {
          v18 = *(_QWORD *)(v16 + 616);
          if ( *((_DWORD *)v17 - 1) != 251140989 )
            __break(0x8229u);
          v17(v18);
          v16 = rmnet_ctl_ipa3_ctx;
        }
        mutex_lock(v16 + 672);
        v19 = rmnet_ctl_ipa3_ctx + 672;
        if ( *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56) )
          v20 = 3;
        else
          v20 = 2;
        *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56) = v20;
        mutex_unlock(v19);
        return 0;
      }
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d rmnet_ctl in bad state %d\n", "ipa3_setup_apps_low_lat_cons_pipe", 237, v5);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(
            v11,
            "ipa %s:%d rmnet_ctl in bad state %d\n",
            "ipa3_setup_apps_low_lat_cons_pipe",
            237,
            *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56));
      }
    }
    return 4294967290LL;
  }
  printk(&unk_3E1D62, "ipa3_setup_apps_low_lat_cons_pipe");
  v21 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v22 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v22 )
  {
    ipc_log_string(v22, "ipa %s:%d low lat pipe is disabled", "ipa3_setup_apps_low_lat_cons_pipe", 225);
    v21 = ipa3_ctx;
  }
  result = *(_QWORD *)(v21 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d low lat pipe is disabled", "ipa3_setup_apps_low_lat_cons_pipe", 225);
    return 0;
  }
  return result;
}
