__int64 __fastcall perf_trace_rdev_return_int_station_info(__int64 result, __int64 a2, int a3, __int64 a4)
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
  __int64 v17; // x2
  __int64 v18; // x5
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(100, v23, &v22);
  if ( !result )
    goto LABEL_12;
  v12 = (_QWORD *)v23[0];
  v13 = result;
  *(_QWORD *)(v23[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v21;
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
      *(_DWORD *)(v13 + 40) = a3;
      v17 = v22;
      v18 = v23[0];
      *(_DWORD *)(v13 + 44) = *(_DWORD *)(a4 + 116);
      *(_DWORD *)(v13 + 48) = *(_DWORD *)(a4 + 8);
      *(_DWORD *)(v13 + 52) = *(_DWORD *)(a4 + 12);
      *(_DWORD *)(v13 + 56) = *(_QWORD *)(a4 + 24);
      *(_DWORD *)(v13 + 60) = *(_QWORD *)(a4 + 32);
      *(_DWORD *)(v13 + 64) = *(_DWORD *)(a4 + 84);
      *(_DWORD *)(v13 + 68) = *(_DWORD *)(a4 + 88);
      *(_DWORD *)(v13 + 72) = *(_DWORD *)(a4 + 92);
      *(_DWORD *)(v13 + 76) = *(_DWORD *)(a4 + 96);
      *(_DWORD *)(v13 + 80) = *(_DWORD *)(a4 + 100);
      *(_DWORD *)(v13 + 84) = *(_DWORD *)(a4 + 136);
      *(_WORD *)(v13 + 88) = *(_WORD *)(a4 + 40);
      *(_WORD *)(v13 + 90) = *(_WORD *)(a4 + 42);
      *(_BYTE *)(v13 + 92) = *(_BYTE *)(a4 + 44);
      result = perf_trace_run_bpf_submit(v13, 100, v17, v8, 1, v18, StatusReg + v10, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v19 = _fortify_panic(7, 32);
  return trace_event_raw_event_mpath_evt(v19, v20 - 1024, *(_QWORD *)(v20 - 1024));
}
