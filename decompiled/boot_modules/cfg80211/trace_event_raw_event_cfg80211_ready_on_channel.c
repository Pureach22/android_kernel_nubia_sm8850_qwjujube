__int64 __fastcall trace_event_raw_event_cfg80211_ready_on_channel(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  int v11; // w8
  __int16 v12; // w8
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13);
    if ( result )
    {
      v11 = 0;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v11 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v11;
      *(_QWORD *)(result + 16) = a3;
      if ( a4 )
      {
        *(_DWORD *)(result + 24) = *(_DWORD *)a4;
        *(_DWORD *)(result + 28) = *(_DWORD *)(a4 + 4);
        v12 = *(_WORD *)(a4 + 8);
      }
      else
      {
        v12 = 0;
        *(_QWORD *)(result + 24) = 0;
      }
      *(_WORD *)(result + 32) = v12;
      *(_DWORD *)(result + 36) = a5;
      result = trace_event_buffer_commit(v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
