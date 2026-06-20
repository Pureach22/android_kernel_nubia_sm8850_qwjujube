__int64 __fastcall log_kgsl_syncpoint_fence_expire_event(__int64 result, const char *a2)
{
  int v2; // w20
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x22
  int v9; // w26
  int v10; // w8
  __int64 v11; // x27
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x21
  size_t v20; // x0
  unsigned __int64 v21; // x2
  __int64 v22; // x0
  int v23; // w3

  if ( kgsl_eventlog )
  {
    v2 = result;
    v4 = raw_spin_lock_irqsave(&lock);
    v8 = v4;
    v9 = eventlog_wptr;
    v10 = eventlog_wptr + 102;
    if ( (unsigned int)(eventlog_wptr + 102) <= 0x17FE8 )
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
      v10 = 102;
      v13 = kgsl_eventlog;
    }
    eventlog_wptr = v10;
    v14 = raw_spin_unlock_irqrestore(&lock, v8);
    *(_DWORD *)v13 = -1413829702;
    result = sched_clock(v14, v15, v16, v17);
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_QWORD *)(v13 + 8) = result;
    LODWORD(StatusReg) = *(_DWORD *)(StatusReg + 1800);
    *(_QWORD *)(v13 + 16) = 0x4E00000006LL;
    *(_DWORD *)(v13 + 4) = StatusReg;
    if ( v13 != -24 )
    {
      *(_QWORD *)(v13 + 28) = 0;
      v19 = v13 + 28;
      *(_DWORD *)(v19 - 4) = v2;
      *(_QWORD *)(v19 + 8) = 0;
      *(_QWORD *)(v19 + 16) = 0;
      *(_QWORD *)(v19 + 24) = 0;
      *(_QWORD *)(v19 + 32) = 0;
      *(_QWORD *)(v19 + 40) = 0;
      *(_QWORD *)(v19 + 48) = 0;
      *(_QWORD *)(v19 + 56) = 0;
      *(_QWORD *)(v19 + 64) = 0;
      *(_WORD *)(v19 + 72) = 0;
      v20 = strnlen(a2, 0x4Au);
      if ( v20 == -1 )
      {
        _fortify_panic(2, -1, 0);
      }
      else
      {
        if ( v20 == 74 )
          v21 = 74;
        else
          v21 = v20 + 1;
        if ( v21 < 0x4B )
          return sized_strscpy(v19, a2);
      }
      v22 = _fortify_panic(7, 74, v21);
      if ( (v23 & 0x100000) == 0 )
        JUMPOUT(0x101AF4);
      return log_kgsl_timeline_fence_alloc_event(v22);
    }
  }
  return result;
}
