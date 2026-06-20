__int64 __fastcall trace_event_raw_event_cfg80211_send_assoc_failure(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x9
  __int16 v10; // w10
  int v11; // w8
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12);
    if ( result )
    {
      v7 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v7;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      v8 = *(_QWORD *)a3;
      if ( *(_QWORD *)a3 )
      {
        v9 = result + 28;
      }
      else
      {
        v9 = result + 28;
        if ( *(_QWORD *)(a3 + 8) == -72 )
        {
          *(_WORD *)(result + 32) = 0;
          *(_DWORD *)v9 = 0;
LABEL_9:
          *(_BYTE *)(result + 34) = *(_BYTE *)(a3 + 128);
          result = trace_event_buffer_commit(v12);
          goto LABEL_10;
        }
      }
      if ( !v8 )
        v8 = *(_QWORD *)(a3 + 8) + 72LL;
      v10 = *(_WORD *)(v8 + 4);
      v11 = *(_DWORD *)v8;
      *(_WORD *)(v9 + 4) = v10;
      *(_DWORD *)v9 = v11;
      goto LABEL_9;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
