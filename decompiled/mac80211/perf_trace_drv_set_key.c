size_t __fastcall perf_trace_drv_set_key(__int64 a1, __int64 a2, int a3, __int64 a4, int *a5, __int64 a6)
{
  __int64 v6; // x30
  __int64 v8; // x27
  size_t result; // x0
  int v14; // w28
  unsigned __int64 StatusReg; // x21
  unsigned int v16; // w22
  _QWORD *v17; // x9
  size_t v18; // x24
  __int64 v19; // x8
  const char *v20; // x26
  size_t v21; // x0
  unsigned __int64 v22; // x2
  int v23; // w9
  int v24; // w8
  void *v25; // x26
  size_t v26; // x27
  int v27; // w9
  __int64 v28; // x2
  __int64 v29; // x5
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // [xsp+0h] [xbp-30h] BYREF
  int v33; // [xsp+Ch] [xbp-24h]
  __int64 v34; // [xsp+10h] [xbp-20h]
  unsigned int v35; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v36[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v33 = a3;
  v8 = v6;
  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36[0] = 0;
  v35 = 0;
  result = strlen((const char *)(a4 + 1640));
  v14 = result;
  v34 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v34) )
    goto LABEL_15;
  v16 = ((result + 100) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v16, v36, &v35);
  if ( !result )
    goto LABEL_15;
  v17 = (_QWORD *)v36[0];
  v18 = result;
  *(_QWORD *)(v36[0] + 232LL) = &vars0;
  v17[31] = &v32;
  v17[32] = v8;
  v17[33] = 5;
  *(_DWORD *)(result + 60) = (v14 << 16) + 65619;
  v19 = *(_QWORD *)(a2 + 72);
  v20 = *(const char **)(v19 + 504);
  if ( !v20 )
    v20 = *(const char **)(v19 + 392);
  v21 = strnlen(v20, 0x20u);
  if ( v21 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v21 == 32 )
      v22 = 32;
    else
      v22 = v21 + 1;
    if ( v22 < 0x21 )
    {
      sized_strscpy(v18 + 8, v20);
      v23 = *(_DWORD *)(v18 + 60);
      v24 = *(_DWORD *)(a4 + 4720);
      *(_QWORD *)(v18 + 48) = a4;
      *(_DWORD *)(v18 + 40) = v24;
      v25 = (void *)(v18 + (unsigned __int16)v23);
      v26 = HIWORD(v23) - 1LL;
      *(_BYTE *)(v18 + 56) = *(_BYTE *)(a4 + 5848);
      memcpy(v25, (const void *)(a4 + 1640), v26);
      *((_BYTE *)v25 + v26) = 0;
      if ( a5 )
      {
        v27 = *a5;
        *(_WORD *)(v18 + 68) = *((_WORD *)a5 + 2);
        *(_DWORD *)(v18 + 64) = v27;
      }
      else
      {
        *(_WORD *)(v18 + 68) = 0;
        *(_DWORD *)(v18 + 64) = 0;
      }
      v28 = v35;
      v29 = v36[0];
      *(_DWORD *)(v18 + 72) = v33;
      *(_DWORD *)(v18 + 76) = *(_DWORD *)(a6 + 8);
      *(_BYTE *)(v18 + 81) = *(_BYTE *)(a6 + 16);
      *(_BYTE *)(v18 + 82) = *(_BYTE *)(a6 + 15);
      *(_BYTE *)(v18 + 80) = *(_BYTE *)(a6 + 14);
      result = perf_trace_run_bpf_submit(v18, v16, v28, a1, 1, v29, StatusReg + v34, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v30 = _fortify_panic(7);
  v31 = MEMORY[0x721CA60](v30);
  return trace_event_raw_event_drv_update_tkip_key(v31);
}
