__int64 ipa_mhi_resume()
{
  __int64 ipc_logbuf; // x0
  long double v1; // q0
  __int64 ipc_logbuf_low; // x0
  int v3; // w0
  unsigned int v4; // w0
  unsigned int v5; // w0
  unsigned int v6; // w0
  unsigned int v7; // w0
  long double v8; // q0
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x0
  int v12; // w19
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w19
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_resume", 1981);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v1 = ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_resume", 1981);
  }
  v3 = ((__int64 (__fastcall *)(__int64, long double))ipa_mhi_set_state)(5, v1);
  if ( !v3 )
  {
    v4 = ipa_pm_activate_sync(*(_DWORD *)(ipa_mhi_client_ctx + 1308));
    if ( v4 )
    {
      v15 = v4;
      printk(&unk_3C86E5, "ipa_mhi_resume");
      if ( ipa3_get_ipc_logbuf() )
      {
        v16 = ipa3_get_ipc_logbuf();
        ipc_log_string(v16, "ipa_mhi_client %s:%d fail to activate client %d\n", "ipa_mhi_resume", 1991, v15);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v17 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v17, "ipa_mhi_client %s:%d fail to activate client %d\n", "ipa_mhi_resume", 1991, v15);
      }
    }
    else
    {
      v5 = ipa_pm_activate_sync(*(_DWORD *)(ipa_mhi_client_ctx + 1312));
      if ( v5 )
      {
        v15 = v5;
        printk(&unk_3C86E5, "ipa_mhi_resume");
        if ( ipa3_get_ipc_logbuf() )
        {
          v18 = ipa3_get_ipc_logbuf();
          ipc_log_string(v18, "ipa_mhi_client %s:%d fail to activate client %d\n", "ipa_mhi_resume", 1997, v15);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v19 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v19, "ipa_mhi_client %s:%d fail to activate client %d\n", "ipa_mhi_resume", 1997, v15);
        }
      }
      else
      {
        v6 = ipa_mhi_resume_channels(0, ipa_mhi_client_ctx + 40, 2);
        if ( v6 )
        {
          v15 = v6;
          printk(&unk_3C8718, "ipa_mhi_resume");
          if ( ipa3_get_ipc_logbuf() )
          {
            v20 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v20,
              "ipa_mhi_client %s:%d ipa_mhi_resume_ul_channels failed %d\n",
              "ipa_mhi_resume",
              2006,
              v15);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v21 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v21,
              "ipa_mhi_client %s:%d ipa_mhi_resume_ul_channels failed %d\n",
              "ipa_mhi_resume",
              2006,
              v15);
          }
        }
        else
        {
          v7 = ipa_mhi_resume_channels(0, ipa_mhi_client_ctx + 440, 4);
          if ( v7 )
          {
            v15 = v7;
            printk(&unk_3F9969, "ipa_mhi_resume");
            if ( ipa3_get_ipc_logbuf() )
            {
              v22 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v22,
                "ipa_mhi_client %s:%d ipa_mhi_resume_dl_channels failed %d\n",
                "ipa_mhi_resume",
                2015,
                v15);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v23 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v23,
                "ipa_mhi_client %s:%d ipa_mhi_resume_dl_channels failed %d\n",
                "ipa_mhi_resume",
                2015,
                v15);
            }
          }
          else
          {
            ipa_mhi_update_host_ch_state(0, v8);
            if ( !(unsigned int)((__int64 (__fastcall *)(__int64))ipa_mhi_set_state)(2) )
            {
              if ( ipa3_get_ipc_logbuf() )
              {
                v9 = ipa3_get_ipc_logbuf();
                ipc_log_string(v9, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_resume", 2027);
              }
              result = ipa3_get_ipc_logbuf_low();
              if ( result )
              {
                v11 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v11, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_resume", 2027);
                return 0;
              }
              return result;
            }
            printk(&unk_3F64F3, "ipa_mhi_resume");
            if ( ipa3_get_ipc_logbuf() )
            {
              v24 = ipa3_get_ipc_logbuf();
              ipc_log_string(v24, "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n", "ipa_mhi_resume", 2023, -1);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v25 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v25, "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n", "ipa_mhi_resume", 2023, -1);
            }
            ipa_mhi_suspend_channels(ipa_mhi_client_ctx + 440, 4);
            v15 = -1;
          }
          ipa_mhi_suspend_channels(ipa_mhi_client_ctx + 40, 2);
        }
        ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_mhi_client_ctx + 1312));
      }
      ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_mhi_client_ctx + 1308));
    }
    ((void (__fastcall *)(__int64))ipa_mhi_set_state)(4);
    return v15;
  }
  v12 = v3;
  printk(&unk_3F64F3, "ipa_mhi_resume");
  if ( ipa3_get_ipc_logbuf() )
  {
    v13 = ipa3_get_ipc_logbuf();
    ipc_log_string(v13, "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n", "ipa_mhi_resume", 1985, v12);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v14, "ipa_mhi_client %s:%d ipa_mhi_set_state failed %d\n", "ipa_mhi_resume", 1985, v12);
  }
  return 0xFFFFFFFFLL;
}
