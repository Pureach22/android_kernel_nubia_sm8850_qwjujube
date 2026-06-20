__int64 __fastcall gsi_rndis_flow_ctrl_enable(char a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x0
  int v4; // w9
  __int64 v5; // x19
  __int64 v6; // x8

  v2 = *(_QWORD *)(a2 + 72);
  if ( !v2 )
    return printk(&unk_101F0, "gsi_rndis_flow_ctrl_enable");
  if ( (a1 & 1) != 0 )
  {
    ipc_log_string(*(_QWORD *)(v2 + 1344), "%s: posting HOST_NRDY\n", "gsi_rndis_flow_ctrl_enable");
    v3 = raw_spin_lock_irqsave(v2 + 824);
    v4 = *(unsigned __int8 *)(v2 + 820);
    v5 = v3;
    v6 = (*(_BYTE *)(v2 + 821) + 1) & 0x7F;
    *(_BYTE *)(v2 + 821) = v6;
    if ( (_DWORD)v6 == v4 )
    {
      ipc_log_string(*(_QWORD *)(v2 + 1344), "%s: event queue overflow error", "post_event");
      printk(&unk_10379, "post_event");
    }
    else
    {
      *(_BYTE *)(v2 + v6 + 692) = 5;
    }
    raw_spin_unlock_irqrestore(v2 + 824, v5);
  }
  else
  {
    ipc_log_string(*(_QWORD *)(v2 + 1344), "%s: posting HOST_READY\n", "gsi_rndis_flow_ctrl_enable");
    post_event(v2 + 304, 6);
    *(_BYTE *)(v2 + 1404) = 1;
  }
  return queue_delayed_work_on(32, *(_QWORD *)(v2 + 680), v2 + 576, 0);
}
