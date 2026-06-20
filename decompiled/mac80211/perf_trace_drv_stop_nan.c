size_t __fastcall perf_trace_drv_stop_nan(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x25
  size_t result; // x0
  __int64 v9; // x26
  unsigned __int64 StatusReg; // x27
  int v11; // w24
  unsigned int v12; // w21
  _QWORD *v13; // x9
  size_t v14; // x22
  __int64 v15; // x8
  const char *v16; // x23
  size_t v17; // x0
  unsigned __int64 v18; // x2
  int v19; // w9
  int v20; // w8
  void *v21; // x23
  size_t v22; // x24
  __int64 v23; // x0
  int v24; // w10
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v28; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v26 = 0;
  result = strlen((const char *)(a3 + 1640));
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v9) )
    goto LABEL_12;
  v12 = ((result + 76) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v12, v27, &v26);
  if ( !result )
    goto LABEL_12;
  v13 = (_QWORD *)v27[0];
  v14 = result;
  *(_QWORD *)(v27[0] + 232LL) = &v28;
  v13[31] = &v25;
  v13[32] = v5;
  v13[33] = 5;
  *(_DWORD *)(result + 60) = (v11 << 16) + 65600;
  v15 = *(_QWORD *)(a2 + 72);
  v16 = *(const char **)(v15 + 504);
  if ( !v16 )
    v16 = *(const char **)(v15 + 392);
  v17 = strnlen(v16, 0x20u);
  if ( v17 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v17 == 32 )
      v18 = 32;
    else
      v18 = v17 + 1;
    if ( v18 < 0x21 )
    {
      sized_strscpy(v14 + 8, v16);
      v19 = *(_DWORD *)(v14 + 60);
      v20 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v14 + 48) = a3;
      *(_DWORD *)(v14 + 40) = v20;
      v21 = (void *)(v14 + (unsigned __int16)v19);
      v22 = HIWORD(v19) - 1LL;
      *(_BYTE *)(v14 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v21, (const void *)(a3 + 1640), v22);
      *((_BYTE *)v21 + v22) = 0;
      result = perf_trace_run_bpf_submit(v14, v12, v26, a1, 1, v27[0], StatusReg + v9, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v23 = _fortify_panic(7);
  *(_DWORD *)(a3 + 144) = v24;
  *(_DWORD *)(a3 + 148) = v5;
  return trace_event_raw_event_drv_nan_change_conf(v23);
}
