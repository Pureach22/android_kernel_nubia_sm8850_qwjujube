__int64 __fastcall trace_event_raw_event_adreno_sp_tp(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  _QWORD v5[7]; // [xsp+8h] [xbp-38h] BYREF

  v5[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v5, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v5);
    if ( result )
    {
      *(_QWORD *)(result + 8) = a2;
      result = trace_event_buffer_commit(v5);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
