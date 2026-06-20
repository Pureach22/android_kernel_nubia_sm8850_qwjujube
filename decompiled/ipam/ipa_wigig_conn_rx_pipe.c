__int64 __fastcall ipa_wigig_conn_rx_pipe(_QWORD *a1, _DWORD *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w19
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  _QWORD v29[5]; // [xsp+8h] [xbp-28h] BYREF

  v29[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_conn_rx_pipe", 620);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_conn_rx_pipe", 620);
  }
  if ( !a1 || !a2 )
  {
    printk(&unk_3D458B, "ipa_wigig_conn_rx_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n", "ipa_wigig_conn_rx_pipe", 623, a1, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipa_wigig %s:%d empty parameters. in=%pK out=%pK\n", "ipa_wigig_conn_rx_pipe", 623, a1, a2);
      result = 4294967274LL;
      goto LABEL_60;
    }
    goto LABEL_10;
  }
  if ( ipa_wigig_ctx )
  {
    v6 = ipa3_uc_state_check();
    if ( !v6 )
    {
      if ( (unsigned int)ipa_wigig_init_smmu_params() )
      {
LABEL_10:
        result = 4294967274LL;
        goto LABEL_60;
      }
      if ( *(_BYTE *)(ipa_wigig_ctx + 908) == 1 )
      {
        printk(&unk_3B3AAB, "ipa_wigig_conn_rx_pipe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v21 = ipa3_get_ipc_logbuf();
          ipc_log_string(v21, "ipa_wigig %s:%d IPA SMMU is enabled, wrong API used\n", "ipa_wigig_conn_rx_pipe", 642);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v22 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v22, "ipa_wigig %s:%d IPA SMMU is enabled, wrong API used\n", "ipa_wigig_conn_rx_pipe", 642);
        }
      }
      else
      {
        v29[0] = "wigig";
        v29[1] = ipa_wigig_pm_cb;
        v29[2] = 0;
        v29[3] = 0;
        if ( (unsigned int)ipa_pm_register((__int64)v29, (unsigned int *)(ipa_wigig_ctx + 64)) )
        {
          printk(&unk_3B3AE2, "ipa_wigig_conn_rx_pipe");
          if ( ipa3_get_ipc_logbuf() )
          {
            v23 = ipa3_get_ipc_logbuf();
            ipc_log_string(v23, "ipa_wigig %s:%d fail to register ipa pm\n", "ipa_wigig_conn_rx_pipe", 652);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v24 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v24, "ipa_wigig %s:%d fail to register ipa pm\n", "ipa_wigig_conn_rx_pipe", 652);
          }
        }
        else
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v8 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v8,
              "ipa_wigig %s:%d pm hdl %d\n",
              "ipa_wigig_conn_rx_pipe",
              656,
              *(_DWORD *)(ipa_wigig_ctx + 64));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v9 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v9,
              "ipa_wigig %s:%d pm hdl %d\n",
              "ipa_wigig_conn_rx_pipe",
              656,
              *(_DWORD *)(ipa_wigig_ctx + 64));
          }
          if ( (unsigned int)ipa3_wigig_uc_msi_init(
                               1,
                               *(_QWORD *)(ipa_wigig_ctx + 72),
                               *(_QWORD *)(ipa_wigig_ctx + 80),
                               *(_QWORD *)(ipa_wigig_ctx + 88),
                               *(_QWORD *)(ipa_wigig_ctx + 96),
                               *(_QWORD *)(ipa_wigig_ctx + 104)) )
          {
            printk(&unk_3F0D59, "ipa_wigig_conn_rx_pipe");
            if ( ipa3_get_ipc_logbuf() )
            {
              v25 = ipa3_get_ipc_logbuf();
              ipc_log_string(v25, "ipa_wigig %s:%d failed configuring msi regs at uC\n", "ipa_wigig_conn_rx_pipe", 665);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v26 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v26, "ipa_wigig %s:%d failed configuring msi regs at uC\n", "ipa_wigig_conn_rx_pipe", 665);
            }
          }
          else
          {
            if ( !(unsigned int)ipa3_conn_wigig_rx_pipe_i((__int64)a1, a2, (_QWORD *)(ipa_wigig_ctx + 912)) )
            {
              v10 = ipa_wigig_ctx;
              *(_QWORD *)(ipa_wigig_ctx + 112) = *a1;
              v11 = *(_QWORD *)(v10 + 912);
              *(_QWORD *)(v10 + 120) = a1[1];
              if ( v11 )
              {
                ipa_wigig_init_debugfs();
                v10 = ipa_wigig_ctx;
              }
              ipa_wigig_store_pipe_info(v10 + 128, 0);
              *(_BYTE *)(ipa_wigig_ctx + 910) |= 1u;
              if ( ipa3_get_ipc_logbuf() )
              {
                v12 = ipa3_get_ipc_logbuf();
                ipc_log_string(v12, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_rx_pipe", 688);
              }
              result = ipa3_get_ipc_logbuf_low();
              if ( result )
              {
                v13 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v13, "ipa_wigig %s:%d exit\n", "ipa_wigig_conn_rx_pipe", 688);
                result = 0;
              }
              goto LABEL_60;
            }
            printk(&unk_3DD15A, "ipa_wigig_conn_rx_pipe");
            if ( ipa3_get_ipc_logbuf() )
            {
              v27 = ipa3_get_ipc_logbuf();
              ipc_log_string(v27, "ipa_wigig %s:%d fail to connect rx pipe\n", "ipa_wigig_conn_rx_pipe", 671);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v28 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v28, "ipa_wigig %s:%d fail to connect rx pipe\n", "ipa_wigig_conn_rx_pipe", 671);
            }
            ipa3_wigig_uc_msi_init(
              0,
              *(_QWORD *)(ipa_wigig_ctx + 72),
              *(_QWORD *)(ipa_wigig_ctx + 80),
              *(_QWORD *)(ipa_wigig_ctx + 88),
              *(_QWORD *)(ipa_wigig_ctx + 96),
              *(_QWORD *)(ipa_wigig_ctx + 104));
          }
          ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_wigig_ctx + 64));
        }
      }
      result = 4294967282LL;
      goto LABEL_60;
    }
    v18 = v6;
    printk(&unk_3FFB88, "ipa_wigig_conn_rx_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_rx_pipe", 634);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_wigig %s:%d uC not ready\n", "ipa_wigig_conn_rx_pipe", 634);
    }
    result = v18;
  }
  else
  {
    printk(&unk_3CE6D1, "ipa_wigig_conn_rx_pipe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(v16, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_rx_pipe", 628);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v17, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_conn_rx_pipe", 628);
    }
    result = 0xFFFFFFFFLL;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
