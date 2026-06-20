__int64 __fastcall trace_event_raw_event_core_ctl_notif_data(__int64 a1, int a2, int a3, _QWORD *a4, _QWORD *a5)
{
  __int64 v8; // x8
  __int64 v10; // x9
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x8
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v8 = a1;
  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v10 & 0x2C0) == 0
    || (v10 & 0x100) != 0
    || (result = _trace_trigger_soft_disabled(a1), v8 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v15, v8, 48);
    if ( result )
    {
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      v12 = a4[1];
      *(_QWORD *)(result + 16) = *a4;
      *(_QWORD *)(result + 24) = v12;
      v13 = a5[1];
      *(_QWORD *)(result + 32) = *a5;
      *(_QWORD *)(result + 40) = v13;
      result = trace_event_buffer_commit(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
