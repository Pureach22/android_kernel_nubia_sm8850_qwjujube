__int64 __fastcall perf_trace_rdev_channel_switch(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x25
  __int64 v8; // x19
  __int64 v10; // x8
  int v11; // w26
  int v12; // w28
  unsigned __int64 StatusReg; // x27
  unsigned int v14; // w21
  _QWORD *v15; // x9
  __int64 v16; // x22
  const char *v17; // x25
  size_t v18; // x0
  unsigned __int64 v19; // x2
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x2
  __int64 v23; // x5
  long double v24; // q0
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(result + 104);
  v27[0] = 0;
  v26 = 0;
  v11 = *(_DWORD *)(a4 + 224);
  v12 = *(_DWORD *)(a4 + 228);
  v25 = v10;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v25)
    || (v14 = ((2 * (v12 + v11) + 119) & 0xFFFFFFF8) - 4, (result = perf_trace_buf_alloc(v14, v27, &v26)) == 0) )
  {
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v15 = (_QWORD *)v27[0];
  *(_QWORD *)(v27[0] + 232LL) = &vars0;
  v16 = result;
  v15[31] = &v25;
  v15[32] = v5;
  v15[33] = 5;
  *(_DWORD *)(result + 96) = (v11 << 17) | 0x69;
  *(_DWORD *)(result + 100) = (2 * v11 + 105) | (v12 << 17);
  v17 = *(const char **)(a2 + 504);
  if ( !v17 )
    v17 = *(const char **)(a2 + 392);
  v18 = strnlen(v17, 0x20u);
  if ( v18 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v18 == 32 )
      v19 = 32;
    else
      v19 = v18 + 1;
    if ( v19 < 0x21 )
    {
      sized_strscpy(v16 + 8, v17);
      v20 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v16 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v16 + 48) = v20;
      *(_DWORD *)(v16 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 && *(_QWORD *)a4 )
      {
        *(_DWORD *)(v16 + 60) = **(_DWORD **)a4;
        *(_DWORD *)(v16 + 64) = *(_DWORD *)(*(_QWORD *)a4 + 4LL);
        *(_DWORD *)(v16 + 68) = *(unsigned __int16 *)(*(_QWORD *)a4 + 8LL);
        *(_DWORD *)(v16 + 72) = *(_DWORD *)(a4 + 8);
        *(_DWORD *)(v16 + 76) = *(_DWORD *)(a4 + 12);
        *(_DWORD *)(v16 + 80) = *(unsigned __int16 *)(a4 + 28);
        *(_DWORD *)(v16 + 84) = *(_DWORD *)(a4 + 16);
        *(_WORD *)(v16 + 88) = *(_WORD *)(a4 + 30);
      }
      else
      {
        *(_QWORD *)(v16 + 82) = 0;
        *(_QWORD *)(v16 + 76) = 0;
        *(_QWORD *)(v16 + 68) = 0;
        *(_QWORD *)(v16 + 60) = 0;
      }
      *(_BYTE *)(v16 + 90) = *(_BYTE *)(a4 + 408);
      *(_BYTE *)(v16 + 91) = *(_BYTE *)(a4 + 409);
      *(_BYTE *)(v16 + 92) = *(_BYTE *)(a4 + 410);
      memcpy(
        (void *)(v16 + *(unsigned __int16 *)(v16 + 96)),
        *(const void **)(a4 + 208),
        2LL * *(unsigned int *)(a4 + 224));
      v21 = *(unsigned int *)(a4 + 228);
      if ( (_DWORD)v21 )
        memcpy((void *)(v16 + *(unsigned __int16 *)(v16 + 100)), *(const void **)(a4 + 216), 2 * v21);
      v22 = v26;
      v23 = v27[0];
      *(_BYTE *)(v16 + 104) = *(_BYTE *)(a4 + 411);
      result = perf_trace_run_bpf_submit(v16, v14, v22, v8, 1, v23, StatusReg + v25, 0);
      goto LABEL_18;
    }
  }
  v24 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_set_qos_map(v24);
}
