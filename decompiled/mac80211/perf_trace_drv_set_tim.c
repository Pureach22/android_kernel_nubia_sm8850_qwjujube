__int64 __fastcall perf_trace_drv_set_tim(__int64 result, __int64 a2, int *a3, char a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v12; // x9
  __int64 v13; // x21
  __int64 v14; // x8
  const char *v15; // x23
  size_t v16; // x0
  unsigned __int64 v17; // x2
  char v18; // w22
  int v19; // w9
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // x0
  int v23; // w1
  int v24; // w16
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(52, v27, &v26);
  if ( !result )
    goto LABEL_15;
  v12 = (_QWORD *)v27[0];
  v13 = result;
  *(_QWORD *)(v27[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v25;
  v12[32] = v5;
  v14 = *(_QWORD *)(a2 + 72);
  v15 = *(const char **)(v14 + 504);
  if ( !v15 )
    v15 = *(const char **)(v14 + 392);
  v16 = strnlen(v15, 0x20u);
  if ( v16 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v16 == 32 )
      v17 = 32;
    else
      v17 = v16 + 1;
    if ( v17 < 0x21 )
    {
      v18 = a4 & 1;
      sized_strscpy(v13 + 8, v15);
      if ( a3 )
      {
        v19 = *a3;
        *(_WORD *)(v13 + 44) = *((_WORD *)a3 + 2);
        *(_DWORD *)(v13 + 40) = v19;
      }
      else
      {
        *(_WORD *)(v13 + 44) = 0;
        *(_DWORD *)(v13 + 40) = 0;
      }
      v20 = v26;
      v21 = v27[0];
      *(_BYTE *)(v13 + 46) = v18;
      result = perf_trace_run_bpf_submit(v13, 52, v20, v8, 1, v21, StatusReg + v10, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v22 = _fortify_panic(7);
  *(_DWORD *)(v8 + 208) = v23;
  *(_DWORD *)(v8 + 212) = v24;
  return trace_event_raw_event_drv_set_key(v22);
}
