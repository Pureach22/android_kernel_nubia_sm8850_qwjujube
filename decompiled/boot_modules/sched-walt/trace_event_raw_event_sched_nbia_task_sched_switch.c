__int64 __fastcall trace_event_raw_event_sched_nbia_task_sched_switch(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x8
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v11, v5, 72);
    if ( result )
    {
      v8 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v8;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      *(_QWORD *)(result + 32) = **(_QWORD **)(a2 + 1376);
      v9 = *(_QWORD *)(a3 + 2328);
      *(_QWORD *)(result + 40) = *(_QWORD *)(a3 + 2320);
      *(_QWORD *)(result + 48) = v9;
      *(_DWORD *)(result + 56) = *(_DWORD *)(a3 + 1800);
      *(_QWORD *)(result + 64) = **(_QWORD **)(a3 + 1376);
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
