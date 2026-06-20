__int64 __fastcall trace_event_raw_event_cfg80211_new_sta(__int64 a1, __int64 a2, int *a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x8
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
      v9 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v9;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( a3 )
      {
        v10 = *a3;
        *(_WORD *)(result + 32) = *((_WORD *)a3 + 2);
        *(_DWORD *)(result + 28) = v10;
      }
      else
      {
        *(_WORD *)(result + 32) = 0;
        *(_DWORD *)(result + 28) = 0;
      }
      *(_DWORD *)(result + 36) = *(_DWORD *)(a4 + 116);
      *(_DWORD *)(result + 40) = *(_DWORD *)(a4 + 8);
      *(_DWORD *)(result + 44) = *(_DWORD *)(a4 + 12);
      *(_DWORD *)(result + 48) = *(_QWORD *)(a4 + 24);
      *(_DWORD *)(result + 52) = *(_QWORD *)(a4 + 32);
      *(_DWORD *)(result + 56) = *(_DWORD *)(a4 + 84);
      *(_DWORD *)(result + 60) = *(_DWORD *)(a4 + 88);
      *(_DWORD *)(result + 64) = *(_DWORD *)(a4 + 92);
      *(_DWORD *)(result + 68) = *(_DWORD *)(a4 + 96);
      *(_DWORD *)(result + 72) = *(_DWORD *)(a4 + 100);
      *(_DWORD *)(result + 76) = *(_DWORD *)(a4 + 136);
      *(_WORD *)(result + 80) = *(_WORD *)(a4 + 40);
      *(_WORD *)(result + 82) = *(_WORD *)(a4 + 42);
      *(_BYTE *)(result + 84) = *(_BYTE *)(a4 + 44);
      result = trace_event_buffer_commit(v11);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
