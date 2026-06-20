__int64 __fastcall gsi_resume(__int64 a1)
{
  __int64 *v2; // x20
  __int64 result; // x0
  __int64 v4; // x2
  char v5; // w20
  const char *v6; // x3
  __int64 v7; // x8
  __int64 v8; // x22
  __int64 v9; // x0
  int v10; // w9
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 v13; // x1
  __int64 v14; // x0
  int v15; // w9
  __int64 v16; // x20
  __int64 v17; // x8

  v2 = *(__int64 **)(*(_QWORD *)(a1 + 48) + 48LL);
  if ( a1 )
    ipc_log_string(*(_QWORD *)(a1 + 1344), "%s for prot_id:%d", "gsi_resume", *(_DWORD *)(a1 + 224));
  result = *v2;
  if ( *(_DWORD *)(*v2 + 72) >= 5u && (*(_BYTE *)(a1 + 284) & 1) != 0 )
    return result;
  v4 = *(_QWORD *)(a1 + 1208);
  if ( v4 && !*(_QWORD *)(v4 + 24) )
    config_ep_by_speed(result, a1);
  gsi_ctrl_send_notification(a1);
  if ( !*(_DWORD *)(a1 + 224) )
  {
    if ( *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(a1 + 48) + 48LL) + 72LL) < 5u )
    {
      v5 = 1;
      if ( !a1 )
        goto LABEL_17;
    }
    else
    {
      v5 = *(_BYTE *)(a1 + 285);
      if ( !a1 )
        goto LABEL_17;
    }
    if ( (v5 & 1) != 0 )
      v6 = "true";
    else
      v6 = "false";
    ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: remote_wakeup_allowed:%s", "usb_gsi_remote_wakeup_allowed", v6);
LABEL_17:
    if ( (v5 & 1) == 0 && *(_BYTE *)(a1 + 1404) == 1 )
    {
      v7 = *(_QWORD *)(a1 + 264);
      if ( v7 )
      {
        if ( *(_DWORD *)(v7 + 8) != 2 )
        {
          v8 = *(_QWORD *)(v7 + 72);
          if ( v8 )
          {
            ipc_log_string(*(_QWORD *)(v8 + 1344), "%s: posting HOST_READY\n", "gsi_rndis_flow_ctrl_enable");
            v9 = raw_spin_lock_irqsave(v8 + 824);
            v10 = *(unsigned __int8 *)(v8 + 820);
            v11 = v9;
            v12 = (*(_BYTE *)(v8 + 821) + 1) & 0x7F;
            *(_BYTE *)(v8 + 821) = v12;
            if ( (_DWORD)v12 == v10 )
            {
              ipc_log_string(*(_QWORD *)(v8 + 1344), "%s: event queue overflow error", "post_event");
              printk(&unk_10379, "post_event");
            }
            else
            {
              *(_BYTE *)(v8 + v12 + 692) = 6;
            }
            raw_spin_unlock_irqrestore(v8 + 824, v11);
            v13 = *(_QWORD *)(v8 + 680);
            *(_BYTE *)(v8 + 1404) = 1;
            queue_delayed_work_on(32, v13, v8 + 576, 0);
          }
          else
          {
            printk(&unk_101F0, "gsi_rndis_flow_ctrl_enable");
          }
        }
        *(_DWORD *)(*(_QWORD *)(a1 + 264) + 8LL) = 2;
      }
    }
  }
  v14 = raw_spin_lock_irqsave(a1 + 824);
  v15 = *(unsigned __int8 *)(a1 + 820);
  v16 = v14;
  v17 = (*(_BYTE *)(a1 + 821) + 1) & 0x7F;
  *(_BYTE *)(a1 + 821) = v17;
  if ( (_DWORD)v17 == v15 )
  {
    if ( !a1 )
    {
      raw_spin_unlock_irqrestore(824, v14);
      return queue_delayed_work_on(32, off_2A8, 576, 0);
    }
    ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: event queue overflow error", "post_event");
    printk(&unk_10379, "post_event");
  }
  else
  {
    *(_BYTE *)(a1 + v17 + 692) = 10;
  }
  raw_spin_unlock_irqrestore(a1 + 824, v16);
  result = queue_delayed_work_on(32, *(_QWORD *)(a1 + 680), a1 + 576, 0);
  if ( a1 )
    return ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: for prot_id:%d completed", "gsi_resume", *(_DWORD *)(a1 + 224));
  return result;
}
