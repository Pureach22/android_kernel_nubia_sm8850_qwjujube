__int64 __fastcall trace_event_raw_event_sched_update_busy_bitmap(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        __int64 a7,
        __int64 a8,
        int a9)
{
  __int64 v12; // x8
  __int64 v17; // x9
  __int64 result; // x0
  __int64 v19; // x8
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v12 = a1;
  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 72);
  memset(v21, 0, 48);
  if ( (v17 & 0x2C0) == 0
    || (v17 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v12 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v21, v12, 96);
    if ( result )
    {
      v19 = *(_QWORD *)(a2 + 2328);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 16) = v19;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 1800);
      LODWORD(v19) = *(_DWORD *)(a2 + 144);
      *(_QWORD *)(result + 32) = a7;
      *(_DWORD *)(result + 28) = v19;
      *(_QWORD *)(result + 40) = *(_QWORD *)(a4 + 8);
      *(_DWORD *)(result + 48) = *(_DWORD *)(a3 + 3632);
      *(_DWORD *)(result + 52) = *(_DWORD *)(a4 + 364);
      *(_DWORD *)(result + 56) = a6;
      *(_DWORD *)(result + 60) = *(unsigned __int16 *)(a4 + 388);
      LODWORD(v19) = *(_DWORD *)(a4 + 392);
      *(_QWORD *)(result + 72) = a8;
      *(_DWORD *)(result + 80) = a9;
      *(_DWORD *)(result + 64) = v19;
      *(_QWORD *)(result + 88) = *(_QWORD *)(a5 + 656);
      result = trace_event_buffer_commit(v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
