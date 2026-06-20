__int64 __fastcall trace_event_raw_event_adreno_hw_preempt_template(__int64 a1, __int64 a2, __int64 a3, int a4, int a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  int v11; // w8
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 28);
      v11 = *(_DWORD *)(a3 + 28);
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 12) = v11;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a3 + 20);
      *(_DWORD *)(result + 32) = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL);
      *(_DWORD *)(result + 36) = *(_QWORD *)(*(_QWORD *)(a3 + 8) + 24LL);
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
