__int64 __fastcall gsi_disable(__int64 a1)
{
  int v2; // w8
  _QWORD *v3; // x0
  __int64 result; // x0
  char v5; // w8
  __int64 v6; // x0
  int v7; // w9
  __int64 v8; // x20
  __int64 v9; // x8

  *(_DWORD *)(a1 + 272) = 0;
  v2 = *(_DWORD *)(a1 + 224);
  if ( v2 )
  {
    if ( v2 != 2 )
      goto LABEL_3;
  }
  else
  {
    rndis_uninit(*(_QWORD *)(a1 + 264));
    if ( *(_DWORD *)(a1 + 224) != 2 )
    {
LABEL_3:
      v3 = *(_QWORD **)(a1 + 1208);
      if ( !v3 )
        goto LABEL_9;
      goto LABEL_7;
    }
  }
  *(_BYTE *)(a1 + 1352) = 0;
  v3 = *(_QWORD **)(a1 + 1208);
  if ( !v3 )
    goto LABEL_9;
LABEL_7:
  if ( *v3 )
  {
    usb_ep_disable(v3);
    **(_QWORD **)(a1 + 1208) = 0;
  }
LABEL_9:
  gsi_ctrl_clear_cpkt_queues(a1, 0);
  result = gsi_ctrl_send_cpkt_tomodem(a1, 0, 0);
  v5 = *(_BYTE *)(a1 + 276);
  *(_BYTE *)(a1 + 1224) = 0;
  if ( (v5 & 1) != 0 )
  {
    *(_BYTE *)(a1 + 276) = 0;
    *(_BYTE *)(a1 + 1404) = 0;
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 1344), "%s deactivated", *(const char **)a1);
    *(_BYTE *)(a1 + 561) = 0;
    v6 = raw_spin_lock_irqsave(a1 + 824);
    v7 = *(unsigned __int8 *)(a1 + 820);
    v8 = v6;
    v9 = (*(_BYTE *)(a1 + 821) + 1) & 0x7F;
    *(_BYTE *)(a1 + 821) = v9;
    if ( (_DWORD)v9 == v7 )
    {
      if ( a1 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: event queue overflow error", "post_event");
        printk(&unk_10379, "post_event");
      }
    }
    else
    {
      *(_BYTE *)(a1 + v9 + 692) = 7;
    }
    raw_spin_unlock_irqrestore(a1 + 824, v8);
    return queue_delayed_work_on(32, *(_QWORD *)(a1 + 680), a1 + 576, 0);
  }
  else if ( a1 )
  {
    return ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: data intf is closed", "gsi_disable");
  }
  return result;
}
