__int64 __fastcall trace_event_raw_event_cfg80211_inform_bss_frame(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        const void *a4,
        size_t a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x22
  const char *v12; // x24
  size_t v13; // x0
  unsigned __int64 v14; // x2
  int v15; // w9
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v16);
    if ( result )
    {
      v11 = result;
      *(_DWORD *)(result + 52) = ((_DWORD)a5 << 16) | 0x56;
      v12 = *(const char **)(a2 + 504);
      if ( !v12 )
        v12 = *(const char **)(a2 + 392);
      v13 = strnlen(v12, 0x20u);
      if ( v13 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v13 == 32 )
          v14 = 32;
        else
          v14 = v13 + 1;
        if ( v14 < 0x21 )
        {
          sized_strscpy(v11 + 8, v12);
          if ( *(_QWORD *)a3 )
          {
            *(_DWORD *)(v11 + 40) = **(_DWORD **)a3;
            *(_DWORD *)(v11 + 44) = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
            *(_WORD *)(v11 + 48) = *(_WORD *)(*(_QWORD *)a3 + 8LL);
            if ( !a4 )
            {
LABEL_13:
              *(_DWORD *)(v11 + 56) = *(_DWORD *)(a3 + 8);
              *(_QWORD *)(v11 + 64) = *(_QWORD *)(a3 + 16);
              *(_QWORD *)(v11 + 72) = *(_QWORD *)(a3 + 24);
              v15 = *(_DWORD *)(a3 + 32);
              *(_WORD *)(v11 + 84) = *(_WORD *)(a3 + 36);
              *(_DWORD *)(v11 + 80) = v15;
              result = trace_event_buffer_commit(v16);
              goto LABEL_14;
            }
          }
          else
          {
            *(_QWORD *)(v11 + 40) = 0;
            *(_WORD *)(v11 + 48) = 0;
            if ( !a4 )
              goto LABEL_13;
          }
          memcpy((void *)(v11 + *(unsigned __int16 *)(v11 + 52)), a4, a5);
          goto LABEL_13;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0xA79FC);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
