__int64 __fastcall perf_trace_rdev_set_power_mgmt(__int64 result, __int64 a2, __int64 a3, char a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v14; // x9
  __int64 v15; // x23
  const char *v16; // x25
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x8
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // x0
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v26; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v24 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v12) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(68, v25, &v24);
  if ( !result )
    goto LABEL_12;
  v14 = (_QWORD *)v25[0];
  v15 = result;
  *(_QWORD *)(v25[0] + 232LL) = &v26;
  v14[33] = 5;
  v14[31] = &v23;
  v14[32] = v6;
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
      v20 = v24;
      v21 = v25[0];
      *(_QWORD *)(v15 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v15 + 48) = v19;
      LODWORD(v19) = *(_DWORD *)(a3 + 224);
      *(_BYTE *)(v15 + 60) = a4 & 1;
      *(_DWORD *)(v15 + 64) = a5;
      *(_DWORD *)(v15 + 56) = v19;
      result = perf_trace_run_bpf_submit(v15, 68, v20, v9, 1, v21, StatusReg + v12, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v22 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_connect(v22);
}
