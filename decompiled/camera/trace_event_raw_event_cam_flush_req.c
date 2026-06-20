__int64 __fastcall trace_event_raw_event_cam_flush_req(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  _QWORD v9[7]; // [xsp+8h] [xbp-38h] BYREF

  v5 = a1;
  v9[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v9, 0, 48);
  if ( (v6 & 0x2C0) == 0 || (v6 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v5 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v9, v5, 40);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a3 + 8);
      *(_QWORD *)(result + 16) = *(_QWORD *)(a3 + 16);
      *(_QWORD *)(result + 24) = a2;
      *(_QWORD *)(result + 32) = *(_QWORD *)(a2 + 33160);
      result = trace_event_buffer_commit(v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
