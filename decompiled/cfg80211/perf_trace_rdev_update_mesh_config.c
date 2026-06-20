__int64 __fastcall perf_trace_rdev_update_mesh_config(__int64 result, __int64 a2, __int64 a3, int a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v14; // x9
  __int64 v15; // x22
  const char *v16; // x25
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x8
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // x0
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v26; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v24 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v12) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(132, v25, &v24);
  if ( !result )
    goto LABEL_12;
  v14 = (_QWORD *)v25[0];
  v15 = result;
  *(_QWORD *)(v25[0] + 232LL) = &v26;
  v14[33] = 5;
  v14[31] = &v23;
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
      v20 = v24;
      v21 = v25[0];
      *(_QWORD *)(v15 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v15 + 48) = v19;
      *(_DWORD *)(v15 + 56) = *(_DWORD *)(a3 + 224);
      *(_WORD *)(v15 + 60) = *(_WORD *)a5;
      *(_WORD *)(v15 + 62) = *(_WORD *)(a5 + 2);
      *(_WORD *)(v15 + 64) = *(_WORD *)(a5 + 4);
      *(_WORD *)(v15 + 66) = *(_WORD *)(a5 + 6);
      *(_BYTE *)(v15 + 68) = *(_BYTE *)(a5 + 8);
      *(_BYTE *)(v15 + 69) = *(_BYTE *)(a5 + 9);
      *(_BYTE *)(v15 + 70) = *(_BYTE *)(a5 + 10);
      *(_BYTE *)(v15 + 71) = *(_BYTE *)(a5 + 11);
      *(_DWORD *)(v15 + 72) = *(_DWORD *)(a5 + 12);
      *(_BYTE *)(v15 + 76) = *(_BYTE *)(a5 + 16);
      *(_DWORD *)(v15 + 80) = *(_DWORD *)(a5 + 20);
      *(_DWORD *)(v15 + 84) = *(_DWORD *)(a5 + 28);
      *(_WORD *)(v15 + 88) = *(_WORD *)(a5 + 24);
      *(_WORD *)(v15 + 90) = *(_WORD *)(a5 + 32);
      *(_WORD *)(v15 + 92) = *(_WORD *)(a5 + 34);
      *(_WORD *)(v15 + 94) = *(_WORD *)(a5 + 36);
      *(_BYTE *)(v15 + 96) = *(_BYTE *)(a5 + 38);
      *(_WORD *)(v15 + 98) = *(_WORD *)(a5 + 42);
      *(_BYTE *)(v15 + 100) = *(_BYTE *)(a5 + 44);
      *(_BYTE *)(v15 + 101) = *(_BYTE *)(a5 + 45);
      *(_DWORD *)(v15 + 104) = *(_DWORD *)(a5 + 48);
      *(_WORD *)(v15 + 108) = *(_WORD *)(a5 + 52);
      *(_DWORD *)(v15 + 112) = *(_DWORD *)(a5 + 56);
      *(_WORD *)(v15 + 116) = *(_WORD *)(a5 + 60);
      *(_WORD *)(v15 + 118) = *(_WORD *)(a5 + 62);
      LOBYTE(v19) = *(_BYTE *)(a5 + 76);
      *(_DWORD *)(v15 + 124) = a4;
      *(_BYTE *)(v15 + 120) = v19;
      result = perf_trace_run_bpf_submit(v15, 132, v20, v9, 1, v21, StatusReg + v12, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v22 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_join_mesh(v22);
}
