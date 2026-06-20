__int64 __fastcall trace_event_raw_event_cfg80211_ch_switch_started_notify(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x8
  _QWORD v10[7]; // [xsp+8h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v10, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v10);
    if ( result )
    {
      v9 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v9;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( a3 && *(_QWORD *)a3 )
      {
        *(_DWORD *)(result + 28) = **(_DWORD **)a3;
        *(_DWORD *)(result + 32) = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
        *(_DWORD *)(result + 36) = *(unsigned __int16 *)(*(_QWORD *)a3 + 8LL);
        *(_DWORD *)(result + 40) = *(_DWORD *)(a3 + 8);
        *(_DWORD *)(result + 44) = *(_DWORD *)(a3 + 12);
        *(_DWORD *)(result + 48) = *(unsigned __int16 *)(a3 + 28);
        *(_DWORD *)(result + 52) = *(_DWORD *)(a3 + 16);
        *(_WORD *)(result + 56) = *(_WORD *)(a3 + 30);
      }
      else
      {
        *(_QWORD *)(result + 50) = 0;
        *(_QWORD *)(result + 44) = 0;
        *(_QWORD *)(result + 36) = 0;
        *(_QWORD *)(result + 28) = 0;
      }
      *(_DWORD *)(result + 60) = a4;
      result = trace_event_buffer_commit(v10);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
