__int64 __fastcall trace_event_raw_event_cfg80211_ibss_joined(__int64 a1, __int64 a2, int *a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x8
  int v10; // w9
  __int16 v11; // w8
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12);
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
        if ( a4 )
        {
LABEL_5:
          *(_DWORD *)(result + 36) = *(_DWORD *)a4;
          *(_DWORD *)(result + 40) = *(_DWORD *)(a4 + 4);
          v11 = *(_WORD *)(a4 + 8);
LABEL_8:
          *(_WORD *)(result + 44) = v11;
          result = trace_event_buffer_commit(v12);
          goto LABEL_9;
        }
      }
      else
      {
        *(_WORD *)(result + 32) = 0;
        *(_DWORD *)(result + 28) = 0;
        if ( a4 )
          goto LABEL_5;
      }
      v11 = 0;
      *(_QWORD *)(result + 36) = 0;
      goto LABEL_8;
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
