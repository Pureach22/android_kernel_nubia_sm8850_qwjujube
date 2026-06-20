__int64 __fastcall peek_event(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 v4; // x20
  unsigned int v5; // w21

  v2 = raw_spin_lock_irqsave(a1 + 520);
  v3 = *(unsigned __int8 *)(a1 + 516);
  v4 = v2;
  if ( v3 == *(unsigned __int8 *)(a1 + 517) )
  {
    if ( a1 != 304 )
      ipc_log_string(*(_QWORD *)(a1 + 1040), "%s: event queue empty", "peek_event");
    v5 = 0;
  }
  else
  {
    v5 = *(unsigned __int8 *)(a1 + (((_BYTE)v3 + 1) & 0x7F) + 388);
  }
  raw_spin_unlock_irqrestore(a1 + 520, v4);
  return v5;
}
