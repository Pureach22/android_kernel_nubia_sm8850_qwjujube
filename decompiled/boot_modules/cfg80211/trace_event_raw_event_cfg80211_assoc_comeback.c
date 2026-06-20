__int64 __fastcall trace_event_raw_event_cfg80211_assoc_comeback(__int64 a1, unsigned __int64 a2, int *a3, int a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  int v9; // w8
  int v10; // w9
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v11, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v11);
    if ( result )
    {
      v9 = 0;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v9 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v9;
      if ( a3 )
      {
        v10 = *a3;
        *(_WORD *)(result + 16) = *((_WORD *)a3 + 2);
        *(_DWORD *)(result + 12) = v10;
      }
      else
      {
        *(_WORD *)(result + 16) = 0;
        *(_DWORD *)(result + 12) = 0;
      }
      *(_DWORD *)(result + 20) = a4;
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
