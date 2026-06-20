__int64 __fastcall post_event(__int64 a1, char a2)
{
  __int64 v4; // x0
  int v5; // w9
  __int64 v6; // x20
  __int64 v7; // x8

  v4 = raw_spin_lock_irqsave(a1 + 520);
  v5 = *(unsigned __int8 *)(a1 + 516);
  v6 = v4;
  v7 = (*(_BYTE *)(a1 + 517) + 1) & 0x7F;
  *(_BYTE *)(a1 + 517) = v7;
  if ( (_DWORD)v7 == v5 )
  {
    if ( a1 != 304 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 1040), "%s: event queue overflow error", "post_event");
      printk(&unk_10379, "post_event");
    }
  }
  else
  {
    *(_BYTE *)(a1 + v7 + 388) = a2;
  }
  return raw_spin_unlock_irqrestore(a1 + 520, v6);
}
