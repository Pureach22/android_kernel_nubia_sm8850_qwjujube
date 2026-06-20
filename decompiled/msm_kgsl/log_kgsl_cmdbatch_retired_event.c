__int64 __fastcall log_kgsl_cmdbatch_retired_event(__int64 result, int a2, int a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v6; // w27
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  int v16; // w19
  int v17; // w8
  __int64 v18; // x25
  int v19; // w26
  int v20; // w27
  int v21; // w24
  __int64 v22; // x23
  __int64 v23; // x22
  __int64 v24; // x21
  __int64 v25; // x20
  __int64 v26; // x0
  __int64 v27; // x28
  __int64 v28; // x0
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  unsigned __int64 StatusReg; // x8

  if ( kgsl_eventlog )
  {
    v6 = result;
    v12 = raw_spin_lock_irqsave(&lock);
    v16 = eventlog_wptr;
    v17 = eventlog_wptr + 60;
    v18 = v12;
    if ( (unsigned int)(eventlog_wptr + 60) > 0x17FE8 )
    {
      v19 = v6;
      v20 = a2;
      v21 = a3;
      v22 = a4;
      v23 = a5;
      v24 = a6;
      v25 = kgsl_eventlog + (unsigned int)eventlog_wptr;
      *(_DWORD *)v25 = -1413829702;
      v26 = sched_clock(v12, v13, v14, v15);
      *(_DWORD *)(v25 + 4) = 0;
      *(_QWORD *)(v25 + 8) = v26;
      *(_DWORD *)(v25 + 16) = 1;
      *(_DWORD *)(v25 + 20) = 98280 - v16;
      a6 = v24;
      a5 = v23;
      a4 = v22;
      a3 = v21;
      a2 = v20;
      v6 = v19;
      v27 = kgsl_eventlog;
      v17 = 60;
    }
    else
    {
      v27 = kgsl_eventlog + eventlog_wptr;
    }
    eventlog_wptr = v17;
    v28 = raw_spin_unlock_irqrestore(&lock, v18);
    *(_DWORD *)v27 = -1413829702;
    result = sched_clock(v28, v29, v30, v31);
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_QWORD *)(v27 + 8) = result;
    LODWORD(StatusReg) = *(_DWORD *)(StatusReg + 1800);
    *(_QWORD *)(v27 + 16) = 0x2400000004LL;
    *(_DWORD *)(v27 + 4) = StatusReg;
    if ( v27 != -24 )
    {
      *(_DWORD *)(v27 + 24) = v6;
      *(_DWORD *)(v27 + 28) = a2;
      *(_DWORD *)(v27 + 32) = a3;
      *(_QWORD *)(v27 + 36) = a4;
      *(_QWORD *)(v27 + 44) = a5;
      *(_QWORD *)(v27 + 52) = a6;
    }
  }
  return result;
}
