__int64 __fastcall trace_event_raw_event_cfg80211_reg_can_beacon(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        int a6)
{
  __int64 v11; // x8
  __int64 result; // x0
  const char *v13; // x25
  __int64 v14; // x23
  size_t v15; // x0
  unsigned __int64 v16; // x2
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v11 & 0x2C0) != 0 && (v11 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_15;
  }
  result = trace_event_buffer_reserve(v17);
  if ( !result )
    goto LABEL_15;
  v13 = *(const char **)(a2 + 504);
  v14 = result;
  if ( !v13 )
    v13 = *(const char **)(a2 + 392);
  v15 = strnlen(v13, 0x20u);
  if ( v15 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_20;
  }
  if ( v15 == 32 )
    v16 = 32;
  else
    v16 = v15 + 1;
  if ( v16 >= 0x21 )
  {
LABEL_20:
    _fortify_panic(7, 32);
    JUMPOUT(0xA503C);
  }
  sized_strscpy(v14 + 8, v13);
  if ( a3 && *(_QWORD *)a3 )
  {
    *(_DWORD *)(v14 + 40) = **(_DWORD **)a3;
    *(_DWORD *)(v14 + 44) = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
    *(_DWORD *)(v14 + 48) = *(unsigned __int16 *)(*(_QWORD *)a3 + 8LL);
    *(_DWORD *)(v14 + 52) = *(_DWORD *)(a3 + 8);
    *(_DWORD *)(v14 + 56) = *(_DWORD *)(a3 + 12);
    *(_DWORD *)(v14 + 60) = *(unsigned __int16 *)(a3 + 28);
    *(_DWORD *)(v14 + 64) = *(_DWORD *)(a3 + 16);
    *(_WORD *)(v14 + 68) = *(_WORD *)(a3 + 30);
  }
  else
  {
    *(_QWORD *)(v14 + 62) = 0;
    *(_QWORD *)(v14 + 48) = 0;
    *(_QWORD *)(v14 + 56) = 0;
    *(_QWORD *)(v14 + 40) = 0;
  }
  *(_DWORD *)(v14 + 72) = a4;
  *(_DWORD *)(v14 + 76) = a5;
  *(_DWORD *)(v14 + 80) = a6;
  result = trace_event_buffer_commit(v17);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
