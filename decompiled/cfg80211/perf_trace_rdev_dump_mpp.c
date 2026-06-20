__int64 __fastcall perf_trace_rdev_dump_mpp(__int64 result, __int64 a2, __int64 a3, int a4, int *a5, int *a6)
{
  __int64 v6; // x30
  __int64 v7; // x26
  __int64 v10; // x19
  __int64 v14; // x27
  unsigned __int64 StatusReg; // x28
  _QWORD *v16; // x9
  __int64 v17; // x22
  const char *v18; // x26
  size_t v19; // x0
  unsigned __int64 v20; // x2
  __int64 v21; // x8
  int v22; // w9
  int v23; // w9
  __int64 v24; // x2
  __int64 v25; // x5
  __int64 v26; // x0
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v28 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v14) )
    goto LABEL_17;
  result = perf_trace_buf_alloc(76, v29, &v28);
  if ( !result )
    goto LABEL_17;
  v16 = (_QWORD *)v29[0];
  v17 = result;
  *(_QWORD *)(v29[0] + 232LL) = &vars0;
  v16[33] = 5;
  v16[31] = &v27;
  v16[32] = v7;
  v18 = *(const char **)(a2 + 504);
  if ( !v18 )
    v18 = *(const char **)(a2 + 392);
  v19 = strnlen(v18, 0x20u);
  if ( v19 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v19 == 32 )
      v20 = 32;
    else
      v20 = v19 + 1;
    if ( v20 < 0x21 )
    {
      sized_strscpy(v17 + 8, v18);
      v21 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v17 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v17 + 48) = v21;
      *(_DWORD *)(v17 + 56) = *(_DWORD *)(a3 + 224);
      if ( a5 )
      {
        v22 = *a5;
        *(_WORD *)(v17 + 64) = *((_WORD *)a5 + 2);
        *(_DWORD *)(v17 + 60) = v22;
        if ( a6 )
        {
LABEL_13:
          v23 = *a6;
          *(_WORD *)(v17 + 70) = *((_WORD *)a6 + 2);
          *(_DWORD *)(v17 + 66) = v23;
LABEL_16:
          v24 = v28;
          v25 = v29[0];
          *(_DWORD *)(v17 + 72) = a4;
          result = perf_trace_run_bpf_submit(v17, 76, v24, v10, 1, v25, StatusReg + v14, 0);
LABEL_17:
          _ReadStatusReg(SP_EL0);
          return result;
        }
      }
      else
      {
        *(_WORD *)(v17 + 64) = 0;
        *(_DWORD *)(v17 + 60) = 0;
        if ( a6 )
          goto LABEL_13;
      }
      *(_WORD *)(v17 + 70) = 0;
      *(_DWORD *)(v17 + 66) = 0;
      goto LABEL_16;
    }
  }
  v26 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_return_int_mpath_info(v26);
}
