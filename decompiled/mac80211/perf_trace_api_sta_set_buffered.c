__int64 __fastcall perf_trace_api_sta_set_buffered(__int64 result, __int64 a2, int *a3, char a4, char a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v14; // x9
  __int64 v15; // x22
  __int64 v16; // x8
  const char *v17; // x24
  size_t v18; // x0
  unsigned __int64 v19; // x2
  char v20; // w23
  int v21; // w9
  __int64 v22; // x2
  __int64 v23; // x5
  __int64 v24; // x0
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v28; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v12) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(52, v27, &v26);
  if ( !result )
    goto LABEL_15;
  v14 = (_QWORD *)v27[0];
  v15 = result;
  *(_QWORD *)(v27[0] + 232LL) = &v28;
  v14[33] = 5;
  v14[31] = &v25;
  v14[32] = v6;
  v16 = *(_QWORD *)(a2 + 72);
  v17 = *(const char **)(v16 + 504);
  if ( !v17 )
    v17 = *(const char **)(v16 + 392);
  v18 = strnlen(v17, 0x20u);
  if ( v18 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v18 == 32 )
      v19 = 32;
    else
      v19 = v18 + 1;
    if ( v19 < 0x21 )
    {
      v20 = a5 & 1;
      sized_strscpy(v15 + 8, v17);
      if ( a3 )
      {
        v21 = *a3;
        *(_WORD *)(v15 + 44) = *((_WORD *)a3 + 2);
        *(_DWORD *)(v15 + 40) = v21;
      }
      else
      {
        *(_WORD *)(v15 + 44) = 0;
        *(_DWORD *)(v15 + 40) = 0;
      }
      v22 = v26;
      v23 = v27[0];
      *(_BYTE *)(v15 + 46) = a4;
      *(_BYTE *)(v15 + 47) = v20;
      result = perf_trace_run_bpf_submit(v15, 52, v22, v9, 1, v23, StatusReg + v12, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v24 = _fortify_panic(7);
  return trace_event_raw_event_api_radar_detected(v24);
}
