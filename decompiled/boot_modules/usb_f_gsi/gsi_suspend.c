__int64 __fastcall gsi_suspend(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0
  int v4; // w9
  __int64 v5; // x20
  __int64 v6; // x8
  char v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v1 = result;
  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 284) == 1 )
  {
    if ( result )
      result = ipc_log_string(*(_QWORD *)(result + 1344), "%s: func already suspended, return\n", "gsi_suspend");
  }
  else
  {
    v2 = *(_QWORD *)(result + 304);
    v7[0] = 1;
    usb_gsi_ep_op(v2, v7, 11);
    v3 = raw_spin_lock_irqsave(v1 + 824);
    v4 = *(unsigned __int8 *)(v1 + 820);
    v5 = v3;
    v6 = (*(_BYTE *)(v1 + 821) + 1) & 0x7F;
    *(_BYTE *)(v1 + 821) = v6;
    if ( (_DWORD)v6 == v4 )
    {
      if ( v1 )
      {
        ipc_log_string(*(_QWORD *)(v1 + 1344), "%s: event queue overflow error", "post_event");
        printk(&unk_10379, "post_event");
      }
    }
    else
    {
      *(_BYTE *)(v1 + v6 + 692) = 8;
    }
    raw_spin_unlock_irqrestore(v1 + 824, v5);
    result = queue_delayed_work_on(32, *(_QWORD *)(v1 + 680), v1 + 576, 0);
    if ( v1 )
      result = ipc_log_string(*(_QWORD *)(v1 + 1344), "gsi suspended");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
