__int64 __fastcall sysmon_stop(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x2
  int v6; // w3
  __int64 result; // x0
  __int64 v8; // x20
  char v9; // w20
  __int64 v10; // x0
  __int64 v11; // x0
  const char *v12; // x1
  const char *v13; // x1
  const char *v14; // x1
  _QWORD v15[9]; // [xsp+8h] [xbp-58h] BYREF
  int v16; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+58h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 425) = 0;
  mutex_lock(a1 + 64);
  v4 = *(_QWORD *)(a1 + 224);
  v5 = *(_QWORD *)(a1 + 128);
  v6 = *(_DWORD *)(a1 + 232) + 1;
  *(_DWORD *)(a1 + 56) = 2;
  *(_DWORD *)(a1 + 232) = v6;
  dev_info(v4, "Incrementing tid for %s to %d\n", v5);
  blocking_notifier_call_chain(&sysmon_notifiers, 0, a1);
  result = mutex_unlock(a1 + 64);
  if ( (a2 & 1) == 0 )
  {
    *(_QWORD *)(a1 + 184) = sysmon_shutdown_notif_timeout_handler;
    v8 = jiffies;
    if ( *(_DWORD *)(a1 + 144) != -22 && !wait_for_completion_timeout(a1 + 344, 125) )
      dev_err(*(_QWORD *)(a1 + 224), "timeout waiting for ssctl service\n");
    mod_timer(a1 + 160, v8 + 2500);
    if ( *(_DWORD *)(a1 + 140) )
    {
      if ( *(_DWORD *)(a1 + 144) == -22 )
        goto LABEL_15;
      v16 = 0;
      memset(v15, 0, sizeof(v15));
      *(_DWORD *)(a1 + 280) = 0;
      *(_DWORD *)(a1 + 312) = 0;
      if ( (qmi_txn_init(a1 + 432, v15, &ssctl_shutdown_resp_ei, &v16) & 0x80000000) != 0 )
      {
        v11 = *(_QWORD *)(a1 + 224);
        v12 = "failed to allocate QMI txn\n";
LABEL_26:
        dev_err(v11, v12);
LABEL_28:
        v9 = 0;
        goto LABEL_22;
      }
      if ( (qmi_send_request(a1 + 432, a1 + 736, v15, 33, 0, 0, 0) & 0x80000000) != 0 )
      {
        dev_err(*(_QWORD *)(a1 + 224), "failed to send shutdown request\n");
        qmi_txn_cancel(v15);
        goto LABEL_28;
      }
      if ( (qmi_txn_wait(v15, 1250) & 0x80000000) != 0 )
      {
        v13 = "timeout waiting for shutdown response\n";
      }
      else
      {
        if ( !(_WORD)v16 )
        {
          v9 = 1;
LABEL_12:
          if ( *(int *)(a1 + 136) < 1 )
          {
LABEL_22:
            *(_BYTE *)(a1 + 425) = v9;
            goto LABEL_23;
          }
          if ( (unsigned int)wait_for_completion_timeout(a1 + 312, 2500) || (try_wait_for_completion(a1 + 280) & 1) != 0 )
          {
LABEL_15:
            v9 = 1;
            goto LABEL_22;
          }
          v11 = *(_QWORD *)(a1 + 224);
          v12 = "timeout waiting for shutdown ack\n";
          goto LABEL_26;
        }
        v13 = "shutdown request rejected\n";
      }
      dev_err(*(_QWORD *)(a1 + 224), v13);
      v9 = 0;
      goto LABEL_12;
    }
    if ( !*(_QWORD *)(a1 + 240) )
    {
LABEL_23:
      result = timer_delete_sync(a1 + 160);
      goto LABEL_24;
    }
    mutex_lock(a1 + 376);
    *(_DWORD *)(a1 + 248) = 0;
    v10 = *(_QWORD *)(a1 + 240);
    *(_BYTE *)(a1 + 424) = 0;
    if ( (rpmsg_send(v10, "ssr:shutdown", 13) & 0x80000000) != 0 )
    {
      v14 = "send sysmon shutdown request failed\n";
    }
    else if ( (unsigned int)wait_for_completion_timeout(a1 + 248, 1250) )
    {
      if ( (*(_BYTE *)(a1 + 424) & 1) != 0 )
      {
        v9 = 1;
LABEL_21:
        mutex_unlock(a1 + 376);
        goto LABEL_22;
      }
      v14 = "unexpected response to sysmon shutdown request\n";
    }
    else
    {
      v14 = "timeout waiting for sysmon ack\n";
    }
    dev_err(*(_QWORD *)(a1 + 224), v14);
    v9 = 0;
    goto LABEL_21;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
