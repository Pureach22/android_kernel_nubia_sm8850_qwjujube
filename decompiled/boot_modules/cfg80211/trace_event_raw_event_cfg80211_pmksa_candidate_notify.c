__int64 __fastcall trace_event_raw_event_cfg80211_pmksa_candidate_notify(
        __int64 a1,
        __int64 a2,
        int a3,
        int *a4,
        char a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x8
  int v12; // w10
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13);
    if ( result )
    {
      v11 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v11;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      *(_DWORD *)(result + 28) = a3;
      if ( a4 )
      {
        v12 = *a4;
        *(_WORD *)(result + 36) = *((_WORD *)a4 + 2);
        *(_DWORD *)(result + 32) = v12;
      }
      else
      {
        *(_WORD *)(result + 36) = 0;
        *(_DWORD *)(result + 32) = 0;
      }
      *(_BYTE *)(result + 38) = a5 & 1;
      result = trace_event_buffer_commit(v13);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
