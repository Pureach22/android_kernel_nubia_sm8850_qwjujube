__int64 __fastcall trace_event_raw_event_qcom_dcvs_boost(
        __int64 a1,
        int a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v9; // x8
  __int64 v12; // x9
  __int64 result; // x0
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v9 = a1;
  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v12 & 0x2C0) == 0
    || (v12 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v9 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15, v9, 40);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_QWORD *)(result + 16) = a4;
      *(_QWORD *)(result + 24) = a5;
      *(_QWORD *)(result + 32) = a6;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
