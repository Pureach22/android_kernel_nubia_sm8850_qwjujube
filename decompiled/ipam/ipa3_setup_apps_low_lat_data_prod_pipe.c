__int64 __fastcall ipa3_setup_apps_low_lat_data_prod_pipe(_DWORD *a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x23
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w8
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x9
  unsigned int v25; // w19
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0

  if ( (*(_BYTE *)(ipa3_ctx + 48859) & 1) != 0 )
  {
    if ( (unsigned int)ipa_get_ep_mapping(120) == -1 )
    {
      printk(&unk_3F9685, "ipa3_setup_apps_low_lat_data_prod_pipe");
      v4 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 4294967282LL;
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d low lat data pipe not supported\n", "ipa3_setup_apps_low_lat_data_prod_pipe", 506);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d low lat data pipe not supported\n", "ipa3_setup_apps_low_lat_data_prod_pipe", 506);
        return 4294967282LL;
      }
      else
      {
        return 4294967282LL;
      }
    }
    else
    {
      v10 = rmnet_ll_ipa3_ctx;
      if ( a1 )
      {
        printk(&unk_3C84F0, "ipa3_setup_apps_low_lat_data_prod_pipe");
        v14 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v15 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v15 )
          {
            ipc_log_string(
              v15,
              "ipa %s:%d Configuring low lat data prod with rmnet config\n",
              "ipa3_setup_apps_low_lat_data_prod_pipe",
              513);
            v14 = ipa3_ctx;
          }
          v16 = *(_QWORD *)(v14 + 34160);
          if ( v16 )
            ipc_log_string(
              v16,
              "ipa %s:%d Configuring low lat data prod with rmnet config\n",
              "ipa3_setup_apps_low_lat_data_prod_pipe",
              513);
        }
        v17 = 1;
        *(_BYTE *)(v10 + 312) = 1;
        *(_DWORD *)(v10 + 300) = a1[6];
        *(_DWORD *)(v10 + 304) = a1[7];
        if ( a1[2] )
        {
          *(_BYTE *)(v10 + 220) = 1;
          *(_DWORD *)(v10 + 84) = 0;
          *(_QWORD *)(v10 + 76) = 0x100000008LL;
        }
        else
        {
          v17 = 0;
        }
        *(_DWORD *)(v10 + 216) = v17;
        if ( a1[3] )
        {
          printk(&unk_3B0D06, "ipa3_setup_apps_low_lat_data_prod_pipe");
          v21 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v22 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v22 )
            {
              ipc_log_string(
                v22,
                "ipa %s:%d Enabling deaggr on low_lat_prod\n",
                "ipa3_setup_apps_low_lat_data_prod_pipe",
                534);
              v21 = ipa3_ctx;
            }
            v23 = *(_QWORD *)(v21 + 34160);
            if ( v23 )
              ipc_log_string(
                v23,
                "ipa %s:%d Enabling deaggr on low_lat_prod\n",
                "ipa3_setup_apps_low_lat_data_prod_pipe",
                534);
          }
          *(_BYTE *)(v10 + 193) = 0;
          *(_QWORD *)(v10 + 160) = 0x600000002LL;
        }
        else
        {
          printk(&unk_3A4EBB, "ipa3_setup_apps_low_lat_data_prod_pipe");
          v18 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v19 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v19 )
            {
              ipc_log_string(
                v19,
                "ipa %s:%d Not enabling deaggr on low_lat_prod\n",
                "ipa3_setup_apps_low_lat_data_prod_pipe",
                541);
              v18 = ipa3_ctx;
            }
            v20 = *(_QWORD *)(v18 + 34160);
            if ( v20 )
              ipc_log_string(
                v20,
                "ipa %s:%d Not enabling deaggr on low_lat_prod\n",
                "ipa3_setup_apps_low_lat_data_prod_pipe",
                541);
          }
          *(_DWORD *)(v10 + 160) = 0;
        }
      }
      else
      {
        printk(&unk_3E7AFD, "ipa3_setup_apps_low_lat_data_prod_pipe");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(
              v12,
              "ipa %s:%d Configuring low lat data prod without rmnet config\n",
              "ipa3_setup_apps_low_lat_data_prod_pipe",
              546);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(
              v13,
              "ipa %s:%d Configuring low lat data prod without rmnet config\n",
              "ipa3_setup_apps_low_lat_data_prod_pipe",
              546);
        }
        *(_BYTE *)(v10 + 312) = 0;
        *(_DWORD *)(v10 + 216) = 1;
        *(_QWORD *)(v10 + 76) = 0x100000008LL;
        *(_DWORD *)(v10 + 160) = 0;
        *(_BYTE *)(v10 + 220) = 1;
      }
      *(_BYTE *)(v10 + 192) = 1;
      *(_DWORD *)(v10 + 84) = 0x10000;
      *(_QWORD *)(v10 + 264) = a2;
      *(_QWORD *)(v10 + 272) = apps_rmnet_ll_tx_complete_notify;
      v24 = rmnet_ll_ipa3_ctx;
      *(_DWORD *)(v10 + 156) = 120;
      *(_DWORD *)(v10 + 224) = 0;
      *(_QWORD *)(v10 + 256) = 0x200000000078LL;
      result = ipa_setup_sys_pipe(v10 + 64, (unsigned int *)(v24 + 576));
      if ( (_DWORD)result )
      {
        v25 = result;
        printk(&unk_3F3A4C, "ipa3_setup_apps_low_lat_data_prod_pipe");
        v26 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v27 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v27 )
          {
            ipc_log_string(
              v27,
              "ipa %s:%d failed to config apps low lat dtaa prod pipe\n",
              "ipa3_setup_apps_low_lat_data_prod_pipe",
              578);
            v26 = ipa3_ctx;
          }
          v28 = *(_QWORD *)(v26 + 34160);
          if ( v28 )
            ipc_log_string(
              v28,
              "ipa %s:%d failed to config apps low lat dtaa prod pipe\n",
              "ipa3_setup_apps_low_lat_data_prod_pipe",
              578);
        }
        return v25;
      }
      else
      {
        *(_BYTE *)(rmnet_ll_ipa3_ctx + 60) |= 1u;
      }
    }
  }
  else
  {
    printk(&unk_3F0242, "ipa3_setup_apps_low_lat_data_prod_pipe");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Low lat pipe is disabled", "ipa3_setup_apps_low_lat_data_prod_pipe", 500);
        v8 = ipa3_ctx;
      }
      result = *(_QWORD *)(v8 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d Low lat pipe is disabled", "ipa3_setup_apps_low_lat_data_prod_pipe", 500);
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
