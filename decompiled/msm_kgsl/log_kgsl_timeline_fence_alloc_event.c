__int64 __fastcall log_kgsl_timeline_fence_alloc_event(__int64 result, __int64 a2)
{
  int v2; // w20
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x21
  int v9; // w26
  int v10; // w8
  __int64 v11; // x27
  __int64 v12; // x0
  __int64 v13; // x24
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  unsigned __int64 StatusReg; // x8

  if ( kgsl_eventlog )
  {
    v2 = result;
    v4 = raw_spin_lock_irqsave(&lock);
    v8 = v4;
    v9 = eventlog_wptr;
    v10 = eventlog_wptr + 36;
    if ( (unsigned int)(eventlog_wptr + 36) <= 0x17FE8 )
    {
      v13 = kgsl_eventlog + eventlog_wptr;
    }
    else
    {
      v11 = kgsl_eventlog + (unsigned int)eventlog_wptr;
      *(_DWORD *)v11 = -1413829702;
      v12 = sched_clock(v4, v5, v6, v7);
      *(_DWORD *)(v11 + 4) = 0;
      *(_QWORD *)(v11 + 8) = v12;
      *(_DWORD *)(v11 + 16) = 1;
      *(_DWORD *)(v11 + 20) = 98280 - v9;
      v10 = 36;
      v13 = kgsl_eventlog;
    }
    eventlog_wptr = v10;
    v14 = raw_spin_unlock_irqrestore(&lock, v8);
    *(_DWORD *)v13 = -1413829702;
    result = sched_clock(v14, v15, v16, v17);
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_QWORD *)(v13 + 8) = result;
    LODWORD(StatusReg) = *(_DWORD *)(StatusReg + 1800);
    *(_QWORD *)(v13 + 16) = 0xC00000007LL;
    *(_DWORD *)(v13 + 4) = StatusReg;
    if ( v13 != -24 )
    {
      *(_DWORD *)(v13 + 24) = v2;
      *(_QWORD *)(v13 + 28) = a2;
    }
  }
  return result;
}
