__int64 __fastcall trace_event_raw_event_sched_task_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v13; // x8
  __int64 v18; // x9
  __int64 result; // x0
  __int64 v20; // x8
  _QWORD v22[7]; // [xsp+8h] [xbp-38h] BYREF

  v13 = a1;
  v22[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, 48);
  if ( (v18 & 0x2C0) == 0
    || (v18 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v13 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v22, v13, 88);
    if ( result )
    {
      v20 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v20;
      LODWORD(v20) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 28) = a3;
      *(_DWORD *)(result + 32) = a4;
      *(_QWORD *)(result + 40) = a5;
      *(_QWORD *)(result + 48) = a6;
      *(_DWORD *)(result + 24) = v20;
      *(_QWORD *)(result + 56) = a7;
      *(_QWORD *)(result + 64) = a8;
      *(_QWORD *)(result + 72) = a9;
      *(_QWORD *)(result + 80) = a10;
      result = trace_event_buffer_commit(v22);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
