__int64 __fastcall trace_event_raw_event_cache_alloc_timestamp(__int64 a1, __int64 a2, int a3)
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
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 16) = a3;
      result = trace_event_buffer_commit(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
