__int64 __fastcall trace_event_raw_event_adreno_cmdbatch_sync(__int64 a1, int a2, int a3, int a4, __int64 a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v11);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a4;
      *(_QWORD *)(result + 16) = a5;
      *(_DWORD *)(result + 24) = a3;
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
