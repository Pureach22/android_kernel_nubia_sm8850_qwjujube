__int64 __fastcall trace_event_raw_event_cfg80211_bss_evt(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  int v5; // w9
  _DWORD *v6; // x8
  _QWORD v7[7]; // [xsp+8h] [xbp-38h] BYREF

  v7[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v7, 0, 48);
  if ( (v3 & 0x2C0) == 0 || (v3 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v7);
    if ( result )
    {
      v5 = *(_DWORD *)(a2 + 72);
      *(_WORD *)(result + 12) = *(_WORD *)(a2 + 76);
      *(_DWORD *)(result + 8) = v5;
      v6 = *(_DWORD **)a2;
      if ( *(_QWORD *)a2 )
      {
        *(_DWORD *)(result + 16) = *v6;
        *(_DWORD *)(result + 20) = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
        LOWORD(v6) = *(_WORD *)(*(_QWORD *)a2 + 8LL);
      }
      else
      {
        *(_QWORD *)(result + 16) = 0;
      }
      *(_WORD *)(result + 24) = (_WORD)v6;
      result = trace_event_buffer_commit(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
