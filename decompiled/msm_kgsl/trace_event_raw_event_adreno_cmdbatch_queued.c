__int64 __fastcall trace_event_raw_event_adreno_cmdbatch_queued(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  _QWORD v7[7]; // [xsp+8h] [xbp-38h] BYREF

  v7[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v7, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v7);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL);
      *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 20) = *(_QWORD *)(a2 + 24);
      *(_DWORD *)(result + 24) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 8LL);
      result = trace_event_buffer_commit(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
