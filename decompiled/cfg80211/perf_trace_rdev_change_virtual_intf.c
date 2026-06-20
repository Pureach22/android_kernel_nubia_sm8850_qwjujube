__int64 __fastcall perf_trace_rdev_change_virtual_intf(__int64 result, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v12; // x9
  __int64 v13; // x22
  const char *v14; // x24
  size_t v15; // x0
  unsigned __int64 v16; // x2
  __int64 v17; // x8
  __int64 v18; // x2
  __int64 v19; // x5
  __int64 v20; // x0
  int v21; // w11
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(68, v24, &v23);
  if ( !result )
    goto LABEL_12;
  v12 = (_QWORD *)v24[0];
  v13 = result;
  *(_QWORD *)(v24[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v22;
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
      v18 = v23;
      v19 = v24[0];
      *(_QWORD *)(v13 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v13 + 48) = v17;
      *(_DWORD *)(v13 + 56) = *(_DWORD *)(a3 + 224);
      *(_DWORD *)(v13 + 60) = a4;
      result = perf_trace_run_bpf_submit(v13, 68, v18, v8, 1, v19, StatusReg + v10, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v20 = _fortify_panic(7, 32);
  if ( !v21 )
    JUMPOUT(0x691E0);
  return trace_event_raw_event_key_handle(v20);
}
