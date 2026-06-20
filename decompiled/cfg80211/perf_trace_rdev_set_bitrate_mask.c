__int64 __fastcall perf_trace_rdev_set_bitrate_mask(__int64 result, __int64 a2, __int64 a3, int a4, int *a5)
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
  int v20; // w9
  __int64 v21; // x0
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v12) )
    goto LABEL_15;
  result = perf_trace_buf_alloc(76, v24, &v23);
  if ( !result )
    goto LABEL_15;
  v14 = (_QWORD *)v24[0];
  v15 = result;
  *(_QWORD *)(v24[0] + 232LL) = &v25;
  v14[33] = 5;
  v14[31] = &v22;
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
      *(_QWORD *)(v15 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v15 + 48) = v19;
      *(_DWORD *)(v15 + 56) = *(_DWORD *)(a3 + 224);
      *(_DWORD *)(v15 + 60) = a4;
      if ( a5 )
      {
        v20 = *a5;
        *(_WORD *)(v15 + 68) = *((_WORD *)a5 + 2);
        *(_DWORD *)(v15 + 64) = v20;
      }
      else
      {
        *(_WORD *)(v15 + 68) = 0;
        *(_DWORD *)(v15 + 64) = 0;
      }
      result = perf_trace_run_bpf_submit(v15, 76, v23, v9, 1, v24[0], StatusReg + v12, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v21 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_update_mgmt_frame_registrations(v21);
}
