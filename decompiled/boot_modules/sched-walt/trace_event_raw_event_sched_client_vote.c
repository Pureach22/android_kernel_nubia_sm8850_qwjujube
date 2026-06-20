__int64 __fastcall trace_event_raw_event_sched_client_vote(__int64 a1, __int64 *a2, int a3, char a4, int a5)
{
  __int64 v8; // x8
  __int64 v10; // x9
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v8 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15, v8, 36);
    if ( result )
    {
      v13 = *a2;
      v12 = a2[1];
      *(_DWORD *)(result + 24) = a3;
      *(_DWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 8) = v13;
      *(_QWORD *)(result + 16) = v12;
      *(_BYTE *)(result + 28) = a4 & 1;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
