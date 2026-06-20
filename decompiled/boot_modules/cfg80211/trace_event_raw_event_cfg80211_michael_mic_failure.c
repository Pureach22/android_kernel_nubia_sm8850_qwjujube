__int64 __fastcall trace_event_raw_event_cfg80211_michael_mic_failure(
        __int64 a1,
        __int64 a2,
        int *a3,
        int a4,
        int a5,
        int *a6)
{
  __int64 v11; // x9
  __int64 result; // x0
  __int64 v13; // x8
  int v14; // w9
  int v15; // w9
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v11 & 0x2C0) == 0 || (v11 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v16);
    if ( result )
    {
      v13 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v13;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( a3 )
      {
        v14 = *a3;
        *(_WORD *)(result + 32) = *((_WORD *)a3 + 2);
        *(_DWORD *)(result + 28) = v14;
        *(_DWORD *)(result + 36) = a4;
        *(_DWORD *)(result + 40) = a5;
        if ( !a6 )
        {
LABEL_6:
          result = trace_event_buffer_commit(v16);
          goto LABEL_7;
        }
      }
      else
      {
        *(_WORD *)(result + 32) = 0;
        *(_DWORD *)(result + 28) = 0;
        *(_DWORD *)(result + 36) = a4;
        *(_DWORD *)(result + 40) = a5;
        if ( !a6 )
          goto LABEL_6;
      }
      v15 = *a6;
      *(_WORD *)(result + 48) = *((_WORD *)a6 + 2);
      *(_DWORD *)(result + 44) = v15;
      goto LABEL_6;
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
