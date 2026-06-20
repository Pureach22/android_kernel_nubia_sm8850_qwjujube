__int64 __fastcall ipa3_setup_apps_low_lat_prod_pipe(char a1, _DWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x22
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  unsigned int v19; // w19
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0

  if ( (*(_BYTE *)(ipa3_ctx + 48858) & 1) != 0 )
  {
    if ( (unsigned int)ipa_get_ep_mapping(104) == -1 )
    {
      printk(&unk_3B604E, "ipa3_setup_apps_low_lat_prod_pipe");
      v4 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967282LL;
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d low lat pipe not supported\n", "ipa3_setup_apps_low_lat_prod_pipe", 345);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d low lat pipe not supported\n", "ipa3_setup_apps_low_lat_prod_pipe", 345);
        return 4294967282LL;
      }
      else
      {
        return 4294967282LL;
      }
    }
    else
    {
      v10 = rmnet_ctl_ipa3_ctx;
      if ( a2 && (a1 & 1) != 0 )
      {
        printk(&unk_3E4885, "ipa3_setup_apps_low_lat_prod_pipe");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(
              v12,
              "ipa %s:%d Configuring low lat prod with rmnet config\n",
              "ipa3_setup_apps_low_lat_prod_pipe",
              352);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(
              v13,
              "ipa %s:%d Configuring low lat prod with rmnet config\n",
              "ipa3_setup_apps_low_lat_prod_pipe",
              352);
        }
        v14 = 1;
        *(_BYTE *)(v10 + 312) = 1;
        *(_DWORD *)(v10 + 300) = a2[6];
        *(_DWORD *)(v10 + 304) = a2[7];
        if ( a2[2] )
        {
          *(_BYTE *)(v10 + 220) = 1;
          *(_DWORD *)(v10 + 84) = 0;
          *(_QWORD *)(v10 + 76) = 0x100000008LL;
        }
        else
        {
          v14 = 0;
        }
        *(_DWORD *)(v10 + 216) = v14;
        if ( !a2[3] )
          *(_DWORD *)(v10 + 160) = 0;
      }
      else
      {
        printk(&unk_3D6AD7, "ipa3_setup_apps_low_lat_prod_pipe");
        v15 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v16 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v16 )
          {
            ipc_log_string(
              v16,
              "ipa %s:%d Configuring low lat prod without rmnet config\n",
              "ipa3_setup_apps_low_lat_prod_pipe",
              377);
            v15 = ipa3_ctx;
          }
          v17 = *(_QWORD *)(v15 + 34160);
          if ( v17 )
            ipc_log_string(
              v17,
              "ipa %s:%d Configuring low lat prod without rmnet config\n",
              "ipa3_setup_apps_low_lat_prod_pipe",
              377);
        }
        *(_BYTE *)(v10 + 312) = 0;
        *(_DWORD *)(v10 + 76) = 8;
        *(_DWORD *)(v10 + 216) = 1;
        *(_DWORD *)(v10 + 160) = 0;
        *(_BYTE *)(v10 + 220) = 1;
        *(_QWORD *)(v10 + 80) = 1;
      }
      *(_QWORD *)(v10 + 264) = 0;
      *(_QWORD *)(v10 + 272) = apps_rmnet_ctl_tx_complete_notify;
      *(_QWORD *)(v10 + 152) = 0x3500000003LL;
      v18 = rmnet_ctl_ipa3_ctx;
      *(_QWORD *)(v10 + 256) = 0x200000000068LL;
      result = ipa_setup_sys_pipe(v10 + 64, (unsigned int *)(v18 + 576));
      if ( (_DWORD)result )
      {
        v19 = result;
        printk(&unk_3BEF50, "ipa3_setup_apps_low_lat_prod_pipe");
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v21 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v21 )
          {
            ipc_log_string(
              v21,
              "ipa %s:%d failed to config apps low lat prod pipe\n",
              "ipa3_setup_apps_low_lat_prod_pipe",
              406);
            v20 = ipa3_ctx;
          }
          v22 = *(_QWORD *)(v20 + 34160);
          if ( v22 )
            ipc_log_string(
              v22,
              "ipa %s:%d failed to config apps low lat prod pipe\n",
              "ipa3_setup_apps_low_lat_prod_pipe",
              406);
        }
        return v19;
      }
      else
      {
        *(_BYTE *)(rmnet_ctl_ipa3_ctx + 60) |= 1u;
      }
    }
  }
  else
  {
    printk(&unk_3F0242, "ipa3_setup_apps_low_lat_prod_pipe");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Low lat pipe is disabled", "ipa3_setup_apps_low_lat_prod_pipe", 339);
        v8 = ipa3_ctx;
      }
      result = *(_QWORD *)(v8 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d Low lat pipe is disabled", "ipa3_setup_apps_low_lat_prod_pipe", 339);
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
