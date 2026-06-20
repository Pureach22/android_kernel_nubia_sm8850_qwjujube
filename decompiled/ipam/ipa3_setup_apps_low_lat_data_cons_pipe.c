__int64 __fastcall ipa3_setup_apps_low_lat_data_cons_pipe(_DWORD *a1, __int64 a2)
{
  __int64 v4; // x8
  unsigned int v5; // w4
  int v6; // w10
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 result; // x0
  __int64 v14; // x9
  unsigned int v15; // w19
  unsigned int v16; // w19
  __int64 v17; // x8
  void (__fastcall *v18)(_QWORD); // x9
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  int v22; // w9
  __int64 v23; // x8
  __int64 v24; // x0

  if ( (*(_BYTE *)(ipa3_ctx + 48859) & 1) != 0 )
  {
    if ( (unsigned int)ipa_get_ep_mapping(121) == -1 )
    {
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(
            v8,
            "ipa %s:%d Low lat datapath not supported\n",
            "ipa3_setup_apps_low_lat_data_cons_pipe",
            389);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(
            v9,
            "ipa %s:%d Low lat datapath not supported\n",
            "ipa3_setup_apps_low_lat_data_cons_pipe",
            389);
      }
    }
    else
    {
      v4 = rmnet_ll_ipa3_ctx;
      v5 = *(_DWORD *)(rmnet_ll_ipa3_ctx + 56);
      if ( v5 < 2 )
      {
        *(_DWORD *)(rmnet_ll_ipa3_ctx + 416) = 1;
        if ( a1 )
        {
          v6 = a1[2];
          *(_BYTE *)(v4 + 568) = 1;
          *(_DWORD *)(v4 + 472) = v6 != 0;
          *(_DWORD *)(v4 + 556) = a1[7];
          *(_DWORD *)(v4 + 560) = a1[8];
          *(_DWORD *)(v4 + 564) = a1[3];
          *(_DWORD *)(v4 + 424) = a1[4];
          *(_DWORD *)(v4 + 432) = a1[6];
          *(_DWORD *)(v4 + 428) = a1[5];
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
        *(_QWORD *)(v4 + 512) = 0x80000000079LL;
        *(_DWORD *)(v4 + 380) = 0;
        *(_BYTE *)(v4 + 376) = 1;
        *(_DWORD *)(v4 + 372) = 0;
        *(_QWORD *)(v4 + 528) = apps_rmnet_ll_receive_notify;
        *(_QWORD *)(v4 + 520) = a2;
        result = ipa_setup_sys_pipe(v4 + 320, (unsigned int *)(v4 + 580));
        if ( (_DWORD)result )
        {
          v14 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            if ( *(_QWORD *)(ipa3_ctx + 34152) )
            {
              v15 = result;
              ipc_log_string(
                *(_QWORD *)(ipa3_ctx + 34152),
                "ipa %s:%d Low lat data pipe setup fails\n",
                "ipa3_setup_apps_low_lat_data_cons_pipe",
                465);
              v14 = ipa3_ctx;
              result = v15;
            }
            if ( *(_QWORD *)(v14 + 34160) )
            {
              v16 = result;
              ipc_log_string(
                *(_QWORD *)(v14 + 34160),
                "ipa %s:%d Low lat data pipe setup fails\n",
                "ipa3_setup_apps_low_lat_data_cons_pipe",
                465);
              return v16;
            }
          }
          return result;
        }
        v17 = rmnet_ll_ipa3_ctx;
        v18 = *(void (__fastcall **)(_QWORD))(rmnet_ll_ipa3_ctx + 592);
        *(_BYTE *)(rmnet_ll_ipa3_ctx + 60) |= 2u;
        if ( v18 )
        {
          v19 = *(_QWORD *)(v17 + 616);
          if ( *((_DWORD *)v18 - 1) != 251140989 )
            __break(0x8229u);
          v18(v19);
          v17 = rmnet_ll_ipa3_ctx;
        }
        mutex_lock(v17 + 688);
        v20 = rmnet_ll_ipa3_ctx;
        v21 = rmnet_ll_ipa3_ctx + 688;
        if ( *(_DWORD *)(rmnet_ll_ipa3_ctx + 56) )
          v22 = 3;
        else
          v22 = 2;
        *(_DWORD *)(rmnet_ll_ipa3_ctx + 56) = v22;
        *(_DWORD *)(v20 + 640) = 0;
        mutex_unlock(v21);
        return 0;
      }
      v10 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v11 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d rmnet_ll in bad state %d\n", "ipa3_setup_apps_low_lat_data_cons_pipe", 395, v5);
          v10 = ipa3_ctx;
        }
        v12 = *(_QWORD *)(v10 + 34160);
        if ( v12 )
          ipc_log_string(
            v12,
            "ipa %s:%d rmnet_ll in bad state %d\n",
            "ipa3_setup_apps_low_lat_data_cons_pipe",
            395,
            *(_DWORD *)(rmnet_ll_ipa3_ctx + 56));
      }
    }
    return 4294967290LL;
  }
  printk(&unk_3AB129, "ipa3_setup_apps_low_lat_data_cons_pipe");
  v23 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v24 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v24 )
  {
    ipc_log_string(v24, "ipa %s:%d low lat data pipe is disabled", "ipa3_setup_apps_low_lat_data_cons_pipe", 383);
    v23 = ipa3_ctx;
  }
  result = *(_QWORD *)(v23 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d low lat data pipe is disabled", "ipa3_setup_apps_low_lat_data_cons_pipe", 383);
    return 0;
  }
  return result;
}
