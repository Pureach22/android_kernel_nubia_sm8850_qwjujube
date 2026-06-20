__int64 __fastcall trace_event_raw_event_cfg80211_report_wowlan_wakeup(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4)
{
  __int64 v7; // x8
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x21
  const char *v11; // x23
  size_t v12; // x0
  unsigned __int64 v13; // x2
  int v14; // w8
  size_t v15; // x2
  long double v16; // q0
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 && (result = _trace_trigger_soft_disabled(a1), (result & 1) != 0)
    || (!a4 ? (v8 = 0) : (v8 = *(_DWORD *)(a4 + 16)), (result = trace_event_buffer_reserve(v17)) == 0) )
  {
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = result;
  *(_DWORD *)(result + 60) = (v8 << 16) | 0x40;
  v11 = *(const char **)(a2 + 504);
  if ( !v11 )
    v11 = *(const char **)(a2 + 392);
  v12 = strnlen(v11, 0x20u);
  if ( v12 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v12 == 32 )
      v13 = 32;
    else
      v13 = v12 + 1;
    if ( v13 < 0x21 )
    {
      sized_strscpy(v10 + 8, v11);
      v14 = 0;
      if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
        v14 = *(_DWORD *)(a3 + 40);
      *(_DWORD *)(v10 + 40) = v14;
      *(_BYTE *)(v10 + 44) = a4 == 0;
      if ( a4 )
      {
        *(_BYTE *)(v10 + 45) = *(_BYTE *)a4;
        *(_BYTE *)(v10 + 46) = *(_BYTE *)(a4 + 1);
        *(_BYTE *)(v10 + 47) = *(_BYTE *)(a4 + 2);
        *(_BYTE *)(v10 + 48) = *(_BYTE *)(a4 + 3);
        *(_BYTE *)(v10 + 49) = *(_BYTE *)(a4 + 4);
        *(_BYTE *)(v10 + 50) = *(_BYTE *)(a4 + 5);
        *(_DWORD *)(v10 + 52) = *(_DWORD *)(a4 + 12);
        *(_DWORD *)(v10 + 56) = *(_DWORD *)(a4 + 20);
        if ( *(_QWORD *)(a4 + 24) )
        {
          v15 = *(unsigned int *)(a4 + 16);
          if ( (_DWORD)v15 )
            memcpy((void *)(v10 + *(unsigned __int16 *)(v10 + 60)), *(const void **)(a4 + 24), v15);
        }
      }
      else
      {
        *(_QWORD *)(v10 + 52) = 0;
        *(_DWORD *)(v10 + 45) = 0;
        *(_WORD *)(v10 + 49) = 0;
      }
      result = trace_event_buffer_commit(v17);
      goto LABEL_22;
    }
  }
  v16 = _fortify_panic(7, 32);
  return perf_trace_cfg80211_report_wowlan_wakeup(v16);
}
