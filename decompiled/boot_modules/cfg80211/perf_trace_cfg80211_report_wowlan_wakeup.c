__int64 __fastcall perf_trace_cfg80211_report_wowlan_wakeup(
        __int64 result,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4)
{
  __int64 v4; // x30
  int v5; // s8
  __int64 v6; // x25
  __int64 v10; // x19
  int v11; // w28
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v14; // w21
  _QWORD *v15; // x9
  __int64 v16; // x22
  const char *v17; // x25
  size_t v18; // x0
  unsigned __int64 v19; // x2
  int v20; // w8
  size_t v21; // x2
  long double v22; // q0
  __int64 v23; // x9
  int v24; // s2
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v10 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 )
    v11 = *(_DWORD *)(a4 + 16);
  else
    v11 = 0;
  v27[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v12)
    || (v14 = ((v11 + 75) & 0xFFFFFFF8) - 4, (result = perf_trace_buf_alloc(v14, v27, &v26)) == 0) )
  {
LABEL_23:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v15 = (_QWORD *)v27[0];
  *(_QWORD *)(v27[0] + 232LL) = &vars0;
  v16 = result;
  v15[31] = &v25;
  v15[32] = v6;
  v15[33] = 5;
  *(_DWORD *)(result + 60) = (v11 << 16) | 0x40;
  v17 = *(const char **)(a2 + 504);
  if ( !v17 )
    v17 = *(const char **)(a2 + 392);
  v18 = strnlen(v17, 0x20u);
  if ( v18 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v18 == 32 )
      v19 = 32;
    else
      v19 = v18 + 1;
    if ( v19 < 0x21 )
    {
      sized_strscpy(v16 + 8, v17);
      v20 = 0;
      if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
        v20 = *(_DWORD *)(a3 + 40);
      *(_DWORD *)(v16 + 40) = v20;
      *(_BYTE *)(v16 + 44) = a4 == 0;
      if ( a4 )
      {
        *(_BYTE *)(v16 + 45) = *(_BYTE *)a4;
        *(_BYTE *)(v16 + 46) = *(_BYTE *)(a4 + 1);
        *(_BYTE *)(v16 + 47) = *(_BYTE *)(a4 + 2);
        *(_BYTE *)(v16 + 48) = *(_BYTE *)(a4 + 3);
        *(_BYTE *)(v16 + 49) = *(_BYTE *)(a4 + 4);
        *(_BYTE *)(v16 + 50) = *(_BYTE *)(a4 + 5);
        *(_DWORD *)(v16 + 52) = *(_DWORD *)(a4 + 12);
        *(_DWORD *)(v16 + 56) = *(_DWORD *)(a4 + 20);
        if ( *(_QWORD *)(a4 + 24) )
        {
          v21 = *(unsigned int *)(a4 + 16);
          if ( (_DWORD)v21 )
            memcpy((void *)(v16 + *(unsigned __int16 *)(v16 + 60)), *(const void **)(a4 + 24), v21);
        }
      }
      else
      {
        *(_QWORD *)(v16 + 52) = 0;
        *(_DWORD *)(v16 + 45) = 0;
        *(_WORD *)(v16 + 49) = 0;
      }
      result = perf_trace_run_bpf_submit(v16, v14, v26, v10, 1, v27[0], StatusReg + v12, 0);
      goto LABEL_23;
    }
  }
  v22 = _fortify_panic(7, 32);
  *(_DWORD *)(v23 + 184) = v5;
  *(_DWORD *)(v23 + 188) = v24;
  return trace_event_raw_event_cfg80211_ft_event(v22);
}
