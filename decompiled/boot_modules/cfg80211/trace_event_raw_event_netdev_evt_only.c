__int64 __fastcall trace_event_raw_event_netdev_evt_only(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x8
  _QWORD v6[7]; // [xsp+8h] [xbp-38h] BYREF

  v6[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v6, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v6);
    if ( result )
    {
      v5 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v5;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      result = trace_event_buffer_commit(v6);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
