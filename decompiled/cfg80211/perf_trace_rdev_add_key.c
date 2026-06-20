__int64 __fastcall perf_trace_rdev_add_key(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        char a6,
        int *a7,
        int a8)
{
  __int64 v8; // x30
  __int64 v9; // x28
  __int64 v11; // x19
  __int64 v16; // x20
  unsigned __int64 StatusReg; // x21
  _QWORD *v18; // x9
  __int64 v19; // x24
  const char *v20; // x28
  size_t v21; // x0
  unsigned __int64 v22; // x2
  char v23; // w26
  __int64 v24; // x8
  int v25; // w9
  char v26; // w8
  char v27; // w9
  __int64 v28; // x2
  __int64 v29; // x5
  __int64 v30; // x0
  __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  int v32; // [xsp+8h] [xbp-18h]
  unsigned int v33; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  HIDWORD(v31) = a5;
  v32 = a8;
  v9 = v8;
  v11 = result;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v16 = *(_QWORD *)(result + 104);
  v33 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v16) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(76, v34, &v33);
  if ( !result )
    goto LABEL_15;
  v18 = (_QWORD *)v34[0];
  v19 = result;
  *(_QWORD *)(v34[0] + 232LL) = &vars0;
  v18[33] = 5;
  v18[31] = &v31;
  v18[32] = v9;
  v20 = *(const char **)(a2 + 504);
  if ( !v20 )
    v20 = *(const char **)(a2 + 392);
  v21 = strnlen(v20, 0x20u);
  if ( v21 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v21 == 32 )
      v22 = 32;
    else
      v22 = v21 + 1;
    if ( v22 < 0x21 )
    {
      v23 = a6 & 1;
      sized_strscpy(v19 + 8, v20);
      v24 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v19 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v19 + 48) = v24;
      *(_DWORD *)(v19 + 56) = *(_DWORD *)(a3 + 224);
      if ( a7 )
      {
        v25 = *a7;
        *(_WORD *)(v19 + 64) = *((_WORD *)a7 + 2);
        *(_DWORD *)(v19 + 60) = v25;
      }
      else
      {
        *(_WORD *)(v19 + 64) = 0;
        *(_DWORD *)(v19 + 60) = 0;
      }
      v27 = BYTE4(v31);
      v26 = v32;
      v28 = v33;
      v29 = v34[0];
      *(_DWORD *)(v19 + 68) = a4;
      *(_BYTE *)(v19 + 72) = v27;
      *(_BYTE *)(v19 + 73) = v23;
      *(_BYTE *)(v19 + 74) = v26;
      result = perf_trace_run_bpf_submit(v19, 76, v28, v11, 1, v29, StatusReg + v16, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v30 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_set_default_key(v30);
}
