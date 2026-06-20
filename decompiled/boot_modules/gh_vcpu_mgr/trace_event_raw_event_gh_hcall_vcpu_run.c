__int64 __fastcall trace_event_raw_event_gh_hcall_vcpu_run(
        __int64 a1,
        int a2,
        __int16 a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v10; // x8
  __int64 v14; // x9
  __int64 result; // x0
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v10 = a1;
  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v14 & 0x2C0) == 0
    || (v14 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v10 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v17, v10, 48);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_WORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_QWORD *)(result + 24) = a5;
      *(_QWORD *)(result + 32) = a6;
      *(_QWORD *)(result + 40) = a7;
      result = trace_event_buffer_commit(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
