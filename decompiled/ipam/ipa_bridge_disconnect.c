__int64 __fastcall ipa_bridge_disconnect(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v4; // w21
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w19
  __int64 v22; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0

  if ( ipa_gsb_ctx )
  {
    if ( a1 < 5 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_disconnect", 952, a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_disconnect", 952, a1);
      }
      v4 = a1;
      mutex_lock(ipa_gsb_ctx + 48LL * a1 + 136);
      v5 = ipa_gsb_ctx;
      v6 = ipa_gsb_ctx + 8LL * a1;
      *(_DWORD *)(ipa_gsb_ctx + 400) = 1;
      v7 = *(_QWORD *)(v6 + 96);
      if ( !v7 )
      {
        printk(&unk_3AB2AC, "ipa_bridge_disconnect");
        if ( ipa3_get_ipc_logbuf() )
        {
          v28 = ipa3_get_ipc_logbuf();
          ipc_log_string(v28, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_disconnect", 958, a1);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v29 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v29, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_disconnect", 958, a1);
        }
        goto LABEL_66;
      }
      if ( (*(_BYTE *)(v7 + 104) & 1) == 0 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v19 = ipa3_get_ipc_logbuf();
          ipc_log_string(v19, "ipa_gsb %s:%d iface was not connected\n", "ipa_bridge_disconnect", 964);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v20 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v20, "ipa_gsb %s:%d iface was not connected\n", "ipa_bridge_disconnect", 964);
        }
        goto LABEL_31;
      }
      mutex_lock(v5 + 16);
      v8 = ipa_gsb_ctx;
      if ( *(_DWORD *)(ipa_gsb_ctx + 88) != 1 )
      {
LABEL_18:
        *(_BYTE *)(*(_QWORD *)(v8 + 8LL * a1 + 96) + 104LL) = 0;
        --*(_DWORD *)(v8 + 88);
        if ( ipa3_get_ipc_logbuf() )
        {
          v13 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v13,
            "ipa_gsb %s:%d connected iface: %d\n",
            "ipa_bridge_disconnect",
            990,
            *(_DWORD *)(ipa_gsb_ctx + 88));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v14,
            "ipa_gsb %s:%d connected iface: %d\n",
            "ipa_bridge_disconnect",
            990,
            *(_DWORD *)(ipa_gsb_ctx + 88));
        }
        v15 = ipa_gsb_ctx;
        v16 = *(_QWORD *)(ipa_gsb_ctx + 8LL * a1 + 96);
        if ( *(_BYTE *)(v16 + 105) == 1 )
        {
          *(_BYTE *)(v16 + 105) = 0;
          --*(_DWORD *)(v15 + 92);
          if ( ipa3_get_ipc_logbuf() )
          {
            v17 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v17,
              "ipa_gsb %s:%d num resumed iface: %d\n",
              "ipa_bridge_disconnect",
              996,
              *(_DWORD *)(ipa_gsb_ctx + 92));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v18 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v18,
              "ipa_gsb %s:%d num resumed iface: %d\n",
              "ipa_bridge_disconnect",
              996,
              *(_DWORD *)(ipa_gsb_ctx + 92));
          }
        }
LABEL_31:
        v21 = 0;
LABEL_32:
        mutex_unlock(ipa_gsb_ctx + 16);
        v22 = ipa_gsb_ctx + 48LL * v4;
        *(_DWORD *)(ipa_gsb_ctx + 400) = 0;
        mutex_unlock(v22 + 136);
        return v21;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v9 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v9,
          "ipa_gsb %s:%d prod_hdl = %d, cons_hdl = %d\n",
          "ipa_gsb_disconnect_sys_pipe",
          919,
          *(_DWORD *)(ipa_gsb_ctx + 64),
          *(_DWORD *)(ipa_gsb_ctx + 68));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v10,
          "ipa_gsb %s:%d prod_hdl = %d, cons_hdl = %d\n",
          "ipa_gsb_disconnect_sys_pipe",
          919,
          *(_DWORD *)(ipa_gsb_ctx + 64),
          *(_DWORD *)(ipa_gsb_ctx + 68));
      }
      if ( (unsigned int)ipa_teardown_sys_pipe(*(_DWORD *)(ipa_gsb_ctx + 64)) )
      {
        printk(&unk_3E2386, "ipa_gsb_disconnect_sys_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v30 = ipa3_get_ipc_logbuf();
          ipc_log_string(v30, "ipa_gsb %s:%d failed to tear down prod pipe\n", "ipa_gsb_disconnect_sys_pipe", 923);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v31 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v31, "ipa_gsb %s:%d failed to tear down prod pipe\n", "ipa_gsb_disconnect_sys_pipe", 923);
        }
      }
      else
      {
        v11 = *(_DWORD *)(ipa_gsb_ctx + 68);
        *(_DWORD *)(ipa_gsb_ctx + 64) = 0;
        if ( !(unsigned int)ipa_teardown_sys_pipe(v11) )
        {
          v12 = *(unsigned int *)(ipa_gsb_ctx + 396);
          *(_DWORD *)(ipa_gsb_ctx + 68) = 0;
          if ( !(unsigned int)((__int64 (__fastcall *)(__int64))ipa_pm_deactivate_sync)(v12) )
          {
            v8 = ipa_gsb_ctx;
            goto LABEL_18;
          }
          printk(&unk_3DCC76, "ipa_bridge_disconnect");
          if ( ipa3_get_ipc_logbuf() )
          {
            v36 = ipa3_get_ipc_logbuf();
            ipc_log_string(v36, "ipa_gsb %s:%d failed to deactivate ipa pm\n", "ipa_bridge_disconnect", 980);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v37 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v37, "ipa_gsb %s:%d failed to deactivate ipa pm\n", "ipa_bridge_disconnect", 980);
          }
LABEL_66:
          v21 = -14;
          goto LABEL_32;
        }
        printk(&unk_3AB2F8, "ipa_gsb_disconnect_sys_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v32 = ipa3_get_ipc_logbuf();
          ipc_log_string(v32, "ipa_gsb %s:%d failed to tear down cons pipe\n", "ipa_gsb_disconnect_sys_pipe", 930);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v33 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v33, "ipa_gsb %s:%d failed to tear down cons pipe\n", "ipa_gsb_disconnect_sys_pipe", 930);
        }
      }
      printk(&unk_3EAA67, "ipa_bridge_disconnect");
      if ( ipa3_get_ipc_logbuf() )
      {
        v34 = ipa3_get_ipc_logbuf();
        ipc_log_string(v34, "ipa_gsb %s:%d fail to discon pipes\n", "ipa_bridge_disconnect", 973);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v35 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v35, "ipa_gsb %s:%d fail to discon pipes\n", "ipa_bridge_disconnect", 973);
      }
      goto LABEL_66;
    }
    printk(&unk_3E7C9B, "ipa_bridge_disconnect");
    if ( ipa3_get_ipc_logbuf() )
    {
      v26 = ipa3_get_ipc_logbuf();
      ipc_log_string(v26, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_disconnect", 948, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v27 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v27, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_disconnect", 948, a1);
    }
    return (unsigned int)-22;
  }
  else
  {
    printk(&unk_3C85BE, "ipa_bridge_disconnect");
    if ( ipa3_get_ipc_logbuf() )
    {
      v24 = ipa3_get_ipc_logbuf();
      ipc_log_string(v24, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_disconnect", 943);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v25 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v25, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_disconnect", 943);
    }
    return (unsigned int)-14;
  }
}
