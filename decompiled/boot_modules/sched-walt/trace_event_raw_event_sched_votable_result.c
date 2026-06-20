__int64 __fastcall trace_event_raw_event_sched_votable_result(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x9
  _QWORD v8[7]; // [xsp+8h] [xbp-38h] BYREF

  v3 = a1;
  v8[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v8, 0, 48);
  if ( (v4 & 0x2C0) == 0 || (v4 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v3 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v8, v3, 96);
    if ( result )
    {
      v6 = *(_QWORD *)(*(_QWORD *)a2 + 8LL);
      *(_QWORD *)(result + 8) = **(_QWORD **)a2;
      *(_QWORD *)(result + 16) = v6;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 96);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a2 + 100);
      *(_DWORD *)(result + 32) = *(unsigned __int8 *)(a2 + 24);
      *(_DWORD *)(result + 64) = *(_DWORD *)(a2 + 28);
      *(_DWORD *)(result + 36) = *(unsigned __int8 *)(a2 + 32);
      *(_DWORD *)(result + 68) = *(_DWORD *)(a2 + 36);
      *(_DWORD *)(result + 40) = *(unsigned __int8 *)(a2 + 40);
      *(_DWORD *)(result + 72) = *(_DWORD *)(a2 + 44);
      *(_DWORD *)(result + 44) = *(unsigned __int8 *)(a2 + 48);
      *(_DWORD *)(result + 76) = *(_DWORD *)(a2 + 52);
      *(_DWORD *)(result + 48) = *(unsigned __int8 *)(a2 + 56);
      *(_DWORD *)(result + 80) = *(_DWORD *)(a2 + 60);
      *(_DWORD *)(result + 52) = *(unsigned __int8 *)(a2 + 64);
      *(_DWORD *)(result + 84) = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(result + 56) = *(unsigned __int8 *)(a2 + 72);
      *(_DWORD *)(result + 88) = *(_DWORD *)(a2 + 76);
      *(_DWORD *)(result + 60) = *(unsigned __int8 *)(a2 + 80);
      *(_DWORD *)(result + 92) = *(_DWORD *)(a2 + 84);
      result = trace_event_buffer_commit(v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
