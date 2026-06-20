__int64 __fastcall log_kgsl_cx_wait_timeout_event(__int64 result)
{
  int v1; // w19
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x20
  int v7; // w25
  int v8; // w8
  __int64 v9; // x26
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  int v16; // w9

  if ( kgsl_eventlog )
  {
    v1 = result;
    v2 = raw_spin_lock_irqsave(&lock);
    v6 = v2;
    v7 = eventlog_wptr;
    v8 = eventlog_wptr + 28;
    if ( (unsigned int)(eventlog_wptr + 28) <= 0x17FE8 )
    {
      v11 = kgsl_eventlog + eventlog_wptr;
    }
    else
    {
      v9 = kgsl_eventlog + (unsigned int)eventlog_wptr;
      *(_DWORD *)v9 = -1413829702;
      v10 = sched_clock(v2, v3, v4, v5);
      *(_DWORD *)(v9 + 4) = 0;
      *(_QWORD *)(v9 + 8) = v10;
      *(_DWORD *)(v9 + 16) = 1;
      *(_DWORD *)(v9 + 20) = 98280 - v7;
      v8 = 28;
      v11 = kgsl_eventlog;
    }
    eventlog_wptr = v8;
    v12 = raw_spin_unlock_irqrestore(&lock, v6);
    *(_DWORD *)v11 = -1413829702;
    result = sched_clock(v12, v13, v14, v15);
    *(_QWORD *)(v11 + 8) = result;
    v16 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    *(_QWORD *)(v11 + 16) = 0x400000009LL;
    *(_DWORD *)(v11 + 4) = v16;
    if ( v11 != -24 )
      *(_DWORD *)(v11 + 24) = v1;
  }
  return result;
}
