__int64 __fastcall perf_trace_key_handle(__int64 result, __int64 a2, __int64 a3, int a4, int a5, char a6, int *a7)
{
  __int64 v7; // x30
  __int64 v8; // x27
  __int64 v11; // x19
  __int64 v15; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v17; // x9
  __int64 v18; // x23
  const char *v19; // x27
  size_t v20; // x0
  unsigned __int64 v21; // x2
  char v22; // w25
  __int64 v23; // x8
  int v24; // w9
  __int64 v25; // x2
  char v26; // w8
  __int64 v27; // x5
  __int64 v28; // x0
  __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  int v30; // [xsp+8h] [xbp-18h]
  unsigned int v31; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v30 = a5;
  v8 = v7;
  v11 = result;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v15 = *(_QWORD *)(result + 104);
  v31 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v15) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(76, v32, &v31);
  if ( !result )
    goto LABEL_15;
  v17 = (_QWORD *)v32[0];
  v18 = result;
  *(_QWORD *)(v32[0] + 232LL) = &vars0;
  v17[33] = 5;
  v17[31] = &v29;
  v17[32] = v8;
  v19 = *(const char **)(a2 + 504);
  if ( !v19 )
    v19 = *(const char **)(a2 + 392);
  v20 = strnlen(v19, 0x20u);
  if ( v20 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v20 == 32 )
      v21 = 32;
    else
      v21 = v20 + 1;
    if ( v21 < 0x21 )
    {
      v22 = a6 & 1;
      sized_strscpy(v18 + 8, v19);
      v23 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v18 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v18 + 48) = v23;
      *(_DWORD *)(v18 + 56) = *(_DWORD *)(a3 + 224);
      if ( a7 )
      {
        v24 = *a7;
        *(_WORD *)(v18 + 64) = *((_WORD *)a7 + 2);
        *(_DWORD *)(v18 + 60) = v24;
      }
      else
      {
        *(_WORD *)(v18 + 64) = 0;
        *(_DWORD *)(v18 + 60) = 0;
      }
      v26 = v30;
      v25 = v31;
      v27 = v32[0];
      *(_DWORD *)(v18 + 68) = a4;
      *(_BYTE *)(v18 + 72) = v26;
      *(_BYTE *)(v18 + 73) = v22;
      result = perf_trace_run_bpf_submit(v18, 76, v25, v11, 1, v27, StatusReg + v15, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v28 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_add_key(v28);
}
