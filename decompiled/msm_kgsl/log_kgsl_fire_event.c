__int64 __fastcall log_kgsl_fire_event(__int64 result, int a2, int a3, int a4)
{
  int v4; // w22
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x23
  int v13; // w28
  int v14; // w8
  __int64 v15; // x24
  __int64 v16; // x0
  __int64 v17; // x26
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  unsigned __int64 StatusReg; // x8

  if ( kgsl_eventlog )
  {
    v4 = result;
    v8 = raw_spin_lock_irqsave(&lock);
    v12 = v8;
    v13 = eventlog_wptr;
    v14 = eventlog_wptr + 40;
    if ( (unsigned int)(eventlog_wptr + 40) <= 0x17FE8 )
    {
      v17 = kgsl_eventlog + eventlog_wptr;
    }
    else
    {
      v15 = kgsl_eventlog + (unsigned int)eventlog_wptr;
      *(_DWORD *)v15 = -1413829702;
      v16 = sched_clock(v8, v9, v10, v11);
      *(_DWORD *)(v15 + 4) = 0;
      *(_QWORD *)(v15 + 8) = v16;
      *(_DWORD *)(v15 + 16) = 1;
      *(_DWORD *)(v15 + 20) = 98280 - v13;
      v14 = 40;
      v17 = kgsl_eventlog;
    }
    eventlog_wptr = v14;
    v18 = raw_spin_unlock_irqrestore(&lock, v12);
    *(_DWORD *)v17 = -1413829702;
    result = sched_clock(v18, v19, v20, v21);
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_QWORD *)(v17 + 8) = result;
    LODWORD(StatusReg) = *(_DWORD *)(StatusReg + 1800);
    *(_QWORD *)(v17 + 16) = 0x1000000002LL;
    *(_DWORD *)(v17 + 4) = StatusReg;
    if ( v17 != -24 )
    {
      *(_DWORD *)(v17 + 24) = v4;
      *(_DWORD *)(v17 + 28) = a2;
      *(_DWORD *)(v17 + 32) = a3;
      *(_DWORD *)(v17 + 36) = a4;
    }
  }
  return result;
}
