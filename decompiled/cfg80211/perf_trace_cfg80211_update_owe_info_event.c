__int64 __fastcall perf_trace_cfg80211_update_owe_info_event(__int64 result, __int64 a2, __int64 a3, int *a4)
{
  __int64 v4; // x30
  __int64 v5; // x25
  __int64 v8; // x19
  int v10; // w28
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v13; // w21
  _QWORD *v14; // x9
  __int64 v15; // x22
  const char *v16; // x25
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x8
  int v20; // w9
  __int64 v21; // x2
  __int64 v22; // x5
  int v23; // w9
  long double v24; // q0
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v10 = a4[4];
  v11 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v11) )
    goto LABEL_15;
  v13 = ((v10 + 95) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v13, v27, &v26);
  if ( !result )
    goto LABEL_15;
  v14 = (_QWORD *)v27[0];
  *(_QWORD *)(v27[0] + 232LL) = &vars0;
  v15 = result;
  v14[31] = &v25;
  v14[32] = v5;
  v14[33] = 5;
  *(_DWORD *)(result + 68) = (v10 << 16) | 0x52;
  v16 = *(const char **)(a2 + 504);
  if ( !v16 )
    v16 = *(const char **)(a2 + 392);
  v17 = strnlen(v16, 0x20u);
  if ( v17 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v17 == 32 )
      v18 = 32;
    else
      v18 = v17 + 1;
    if ( v18 < 0x21 )
    {
      sized_strscpy(v15 + 8, v16);
      v19 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v15 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v15 + 48) = v19;
      *(_DWORD *)(v15 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 )
      {
        v20 = *a4;
        *(_WORD *)(v15 + 64) = *((_WORD *)a4 + 2);
        *(_DWORD *)(v15 + 60) = v20;
      }
      else
      {
        *(_WORD *)(v15 + 64) = 0;
        *(_DWORD *)(v15 + 60) = 0;
      }
      memcpy((void *)(v15 + *(unsigned __int16 *)(v15 + 68)), *((const void **)a4 + 1), *((_QWORD *)a4 + 2));
      v21 = v26;
      v22 = v27[0];
      *(_DWORD *)(v15 + 72) = a4[6];
      v23 = a4[7];
      *(_WORD *)(v15 + 80) = *((_WORD *)a4 + 16);
      *(_DWORD *)(v15 + 76) = v23;
      result = perf_trace_run_bpf_submit(v15, v13, v21, v8, 1, v22, StatusReg + v11, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v24 = _fortify_panic(7, 32);
  return trace_event_raw_event_cfg80211_bss_color_notify(v24);
}
