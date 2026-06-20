__int64 __fastcall perf_trace_wiphy_id_evt(__int64 result, __int64 a2, unsigned __int64 a3)
{
  int v3; // w18
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v7; // x19
  __int64 v9; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v11; // x9
  __int64 v12; // x21
  const char *v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int64 v16; // x2
  __int64 v17; // x5
  long double v18; // q0
  int v19; // w8
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v7 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v9 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v9) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(52, v24, &v23);
  if ( !result )
    goto LABEL_12;
  v11 = (_QWORD *)v24[0];
  v12 = result;
  *(_QWORD *)(v24[0] + 232LL) = &v25;
  v11[33] = 5;
  v11[31] = &v22;
  v11[32] = v5;
  v13 = *(const char **)(a2 + 504);
  if ( !v13 )
    v13 = *(const char **)(a2 + 392);
  v14 = strnlen(v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v14 == 32 )
      v15 = 32;
    else
      v15 = v14 + 1;
    if ( v15 < 0x21 )
    {
      sized_strscpy(v12 + 8, v13);
      v16 = v23;
      v17 = v24[0];
      *(_QWORD *)(v12 + 40) = a3;
      result = perf_trace_run_bpf_submit(v12, 52, v16, v7, 1, v17, StatusReg + v9, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v18 = _fortify_panic(7, 32);
  if ( (v3 & 0x4000000) != 0 )
    return trace_event_raw_event_cfg80211_get_bss(v18);
  v19 = 0;
  if ( a3 )
  {
    if ( a3 <= 0xFFFFFFFFFFFFF000LL )
      v19 = *(_DWORD *)(a3 + 40);
  }
  v20 = v23;
  v21 = v24[0];
  *(_DWORD *)(v12 + 40) = v19;
  result = perf_trace_run_bpf_submit(v12, 44, v20, v7, 1, v21, StatusReg + v9, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
