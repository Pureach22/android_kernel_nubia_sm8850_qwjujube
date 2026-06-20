__int64 ipa_pm_remove_dummy_clients()
{
  unsigned int v0; // w0
  unsigned int v1; // w0
  unsigned int v2; // w0
  unsigned int v3; // w0
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w19
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w19
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int v22; // w19
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w19
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0

  v0 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)((unsigned int)dummy_hdl_1);
  if ( v0 )
  {
    v10 = v0;
    printk(&unk_3D007F, "ipa_pm_remove_dummy_clients");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d fail to deactivate client 1 rc = %d\n", "ipa_pm_remove_dummy_clients", 1687, v10);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d fail to deactivate client 1 rc = %d\n", "ipa_pm_remove_dummy_clients", 1687, v10);
    }
  }
  else
  {
    v1 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)((unsigned int)dummy_hdl_2);
    if ( v1 )
    {
      v14 = v1;
      printk(&unk_3D30E6, "ipa_pm_remove_dummy_clients");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(
            v16,
            "ipa %s:%d fail to deactivate client 2 rc = %d\n",
            "ipa_pm_remove_dummy_clients",
            1693,
            v14);
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
          ipc_log_string(
            v17,
            "ipa %s:%d fail to deactivate client 2 rc = %d\n",
            "ipa_pm_remove_dummy_clients",
            1693,
            v14);
      }
    }
    else
    {
      v2 = ((__int64 (__fastcall *)(_QWORD, _QWORD))ipa_pm_set_throughput)(
             (unsigned int)dummy_hdl_1,
             (unsigned int)tput_modem);
      if ( v2 )
      {
        v18 = v2;
        printk(&unk_3D3117, "ipa_pm_remove_dummy_clients");
        v19 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v20 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v20 )
          {
            ipc_log_string(
              v20,
              "ipa %s:%d fail to reset tput for client 1 rc = %d\n",
              "ipa_pm_remove_dummy_clients",
              1700,
              v18);
            v19 = ipa3_ctx;
          }
          v21 = *(_QWORD *)(v19 + 34160);
          if ( v21 )
            ipc_log_string(
              v21,
              "ipa %s:%d fail to reset tput for client 1 rc = %d\n",
              "ipa_pm_remove_dummy_clients",
              1700,
              v18);
        }
      }
      else
      {
        v3 = ((__int64 (__fastcall *)(_QWORD, _QWORD))ipa_pm_set_throughput)(
               (unsigned int)dummy_hdl_2,
               (unsigned int)tput_apps);
        if ( v3 )
        {
          v22 = v3;
          printk(&unk_3D314C, "ipa_pm_remove_dummy_clients");
          v23 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v24 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v24 )
            {
              ipc_log_string(
                v24,
                "ipa %s:%d fail to reset tput for client 2 rc = %d\n",
                "ipa_pm_remove_dummy_clients",
                1706,
                v22);
              v23 = ipa3_ctx;
            }
            v25 = *(_QWORD *)(v23 + 34160);
            if ( v25 )
              ipc_log_string(
                v25,
                "ipa %s:%d fail to reset tput for client 2 rc = %d\n",
                "ipa_pm_remove_dummy_clients",
                1706,
                v22);
          }
        }
        else
        {
          v4 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)((unsigned int)dummy_hdl_1);
          if ( v4 )
          {
            v26 = v4;
            printk(&unk_3B866A, "ipa_pm_remove_dummy_clients");
            v27 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v28 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v28 )
              {
                ipc_log_string(
                  v28,
                  "ipa %s:%d fail to deregister client 1 rc = %d\n",
                  "ipa_pm_remove_dummy_clients",
                  1712,
                  v26);
                v27 = ipa3_ctx;
              }
              v29 = *(_QWORD *)(v27 + 34160);
              if ( v29 )
                ipc_log_string(
                  v29,
                  "ipa %s:%d fail to deregister client 1 rc = %d\n",
                  "ipa_pm_remove_dummy_clients",
                  1712,
                  v26);
            }
          }
          else
          {
            result = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)((unsigned int)dummy_hdl_2);
            if ( !(_DWORD)result )
              return result;
            v6 = result;
            printk(&unk_3D3181, "ipa_pm_remove_dummy_clients");
            v7 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v8 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v8 )
              {
                ipc_log_string(
                  v8,
                  "ipa %s:%d fail to deregister client 2 rc = %d\n",
                  "ipa_pm_remove_dummy_clients",
                  1718,
                  v6);
                v7 = ipa3_ctx;
              }
              v9 = *(_QWORD *)(v7 + 34160);
              if ( v9 )
                ipc_log_string(
                  v9,
                  "ipa %s:%d fail to deregister client 2 rc = %d\n",
                  "ipa_pm_remove_dummy_clients",
                  1718,
                  v6);
            }
          }
        }
      }
    }
  }
  return 4294967282LL;
}
