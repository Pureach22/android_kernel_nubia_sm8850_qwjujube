__int64 __fastcall perf_trace_rdev_auth(__int64 result, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v12; // x9
  __int64 v13; // x21
  const char *v14; // x24
  size_t v15; // x0
  unsigned __int64 v16; // x2
  __int64 v17; // x8
  __int64 v18; // x8
  __int16 v19; // w9
  int v20; // w8
  __int64 v21; // x2
  __int64 v22; // x5
  __int64 v23; // x0
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v25 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(76, v26, &v25);
  if ( !result )
    goto LABEL_15;
  v12 = (_QWORD *)v26[0];
  v13 = result;
  *(_QWORD *)(v26[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v24;
  v12[32] = v5;
  v14 = *(const char **)(a2 + 504);
  if ( !v14 )
    v14 = *(const char **)(a2 + 392);
  v15 = strnlen(v14, 0x20u);
  if ( v15 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v15 == 32 )
      v16 = 32;
    else
      v16 = v15 + 1;
    if ( v16 < 0x21 )
    {
      sized_strscpy(v13 + 8, v14);
      v17 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v13 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v13 + 48) = v17;
      *(_DWORD *)(v13 + 56) = *(_DWORD *)(a3 + 224);
      v18 = *a4;
      if ( *a4 )
      {
        v19 = *(_WORD *)(v18 + 76);
        v20 = *(_DWORD *)(v18 + 72);
        *(_WORD *)(v13 + 64) = v19;
        *(_DWORD *)(v13 + 60) = v20;
      }
      else
      {
        *(_WORD *)(v13 + 64) = 0;
        *(_DWORD *)(v13 + 60) = 0;
      }
      v21 = v25;
      v22 = v26[0];
      *(_DWORD *)(v13 + 68) = *((_DWORD *)a4 + 9);
      result = perf_trace_run_bpf_submit(v13, 76, v21, v8, 1, v22, StatusReg + v10, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v23 = _fortify_panic(7, 32);
  if ( (v13 & 0x200000000000000LL) == 0 )
    JUMPOUT(0x96568);
  return trace_event_raw_event_rdev_assoc(v23);
}
