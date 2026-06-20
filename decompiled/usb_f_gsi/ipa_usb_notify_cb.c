__int64 __fastcall ipa_usb_notify_cb(int a1, __int64 a2)
{
  __int64 v4; // x20
  __int64 v6; // x0
  int v7; // w9
  __int64 v8; // x21
  __int64 v9; // x8
  int v10; // w8
  unsigned __int64 v11; // x0
  _QWORD *v12; // x21
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x22

  if ( !a2 )
    return 4294967274LL;
  v4 = raw_spin_lock_irqsave(a2 + 572);
  if ( a1 == 2 )
  {
    v6 = raw_spin_lock_irqsave(a2 + 824);
    v7 = *(unsigned __int8 *)(a2 + 820);
    v8 = v6;
    v9 = (*(_BYTE *)(a2 + 821) + 1) & 0x7F;
    *(_BYTE *)(a2 + 821) = v9;
    if ( (_DWORD)v9 == v7 )
    {
      ipc_log_string(*(_QWORD *)(a2 + 1344), "%s: event queue overflow error", "post_event");
      printk(&unk_10379, "post_event");
    }
    else
    {
      *(_BYTE *)(a2 + v9 + 692) = 9;
    }
    raw_spin_unlock_irqrestore(a2 + 824, v8);
    goto LABEL_12;
  }
  if ( a1 == 1 )
  {
    gsi_wakeup_host(a2);
    goto LABEL_13;
  }
  if ( a1 )
  {
LABEL_13:
    raw_spin_unlock_irqrestore(a2 + 572, v4);
    return 1;
  }
  if ( *(_BYTE *)(a2 + 561) != 1 )
  {
    ipc_log_string(*(_QWORD *)(a2 + 1344), "%s: Set net_ready_trigger", "ipa_usb_notify_cb");
    printk(&unk_10ACE, "ipa_usb_notify_cb");
    v10 = *(_DWORD *)(a2 + 224);
    *(_BYTE *)(a2 + 561) = 1;
    if ( v10 == 1 )
    {
      v11 = gsi_ctrl_pkt_alloc(0, 0x820u);
      if ( v11 >= 0xFFFFFFFFFFFFF001LL )
      {
        raw_spin_unlock_irqrestore(a2 + 572, v4);
        ipc_log_string(*(_QWORD *)(a2 + 1344), "%s: err cpkt_notify_connect\n", "ipa_usb_notify_cb");
        return 4294967284LL;
      }
      v12 = (_QWORD *)v11;
      *(_DWORD *)(v11 + 12) = 1;
      v13 = gsi_ctrl_pkt_alloc(0, 0x820u);
      if ( v13 >= 0xFFFFFFFFFFFFF001LL )
      {
        raw_spin_unlock_irqrestore(a2 + 572, v4);
        gsi_ctrl_pkt_free(v12);
        ipc_log_string(*(_QWORD *)(a2 + 1344), "%s: err cpkt_notify_speed\n", "ipa_usb_notify_cb");
        return 4294967284LL;
      }
      v14 = v13;
      *(_DWORD *)(v13 + 12) = 2;
      raw_spin_lock(a2 + 1304);
      list_add_tail(v12 + 2, (_QWORD *)(a2 + 1280));
      list_add_tail((_QWORD *)(v14 + 16), (_QWORD *)(a2 + 1280));
      raw_spin_unlock(a2 + 1304);
      gsi_ctrl_send_notification(a2);
      v10 = *(_DWORD *)(a2 + 224);
    }
    if ( v10 )
    {
      post_event(a2 + 304, 4);
LABEL_12:
      queue_delayed_work_on(32, *(_QWORD *)(a2 + 680), a2 + 576, 0);
      goto LABEL_13;
    }
    goto LABEL_13;
  }
  raw_spin_unlock_irqrestore(a2 + 572, v4);
  ipc_log_string(*(_QWORD *)(a2 + 1344), "%s: Already triggered", "ipa_usb_notify_cb");
  return 1;
}
