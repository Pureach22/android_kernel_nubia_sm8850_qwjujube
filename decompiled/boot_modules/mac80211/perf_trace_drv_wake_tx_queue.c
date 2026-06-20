size_t __fastcall perf_trace_drv_wake_tx_queue(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v6; // x26
  size_t result; // x0
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x28
  int v13; // w25
  unsigned int v14; // w21
  _QWORD *v15; // x9
  size_t v16; // x23
  __int64 v17; // x8
  const char *v18; // x24
  int *v19; // x26
  size_t v20; // x0
  unsigned __int64 v21; // x2
  int v22; // w9
  int v23; // w8
  void *v24; // x24
  size_t v25; // x25
  int v26; // w9
  __int64 v27; // x2
  __int64 v28; // x5
  __int64 v29; // x0
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v31; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v31 = 0;
  result = strlen((const char *)(a3 + 1640));
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v11) )
    goto LABEL_15;
  v14 = ((result + 84) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v14, v32, &v31);
  if ( !result )
    goto LABEL_15;
  v15 = (_QWORD *)v32[0];
  v16 = result;
  *(_QWORD *)(v32[0] + 232LL) = &vars0;
  v15[31] = &v30;
  v15[32] = v6;
  v15[33] = 5;
  *(_DWORD *)(result + 60) = (v13 << 16) + 65608;
  v17 = *(_QWORD *)(a2 + 72);
  v18 = *(const char **)(v17 + 504);
  if ( !v18 )
    v18 = *(const char **)(v17 + 392);
  v19 = *(int **)(a4 + 240);
  v20 = strnlen(v18, 0x20u);
  if ( v20 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v20 == 32 )
      v21 = 32;
    else
      v21 = v20 + 1;
    if ( v21 < 0x21 )
    {
      sized_strscpy(v16 + 8, v18);
      v22 = *(_DWORD *)(v16 + 60);
      v23 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v16 + 48) = a3;
      *(_DWORD *)(v16 + 40) = v23;
      v24 = (void *)(v16 + (unsigned __int16)v22);
      v25 = HIWORD(v22) - 1LL;
      *(_BYTE *)(v16 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v24, (const void *)(a3 + 1640), v25);
      *((_BYTE *)v24 + v25) = 0;
      if ( v19 )
      {
        v26 = *v19;
        *(_WORD *)(v16 + 68) = *((_WORD *)v19 + 2);
        *(_DWORD *)(v16 + 64) = v26;
      }
      else
      {
        *(_WORD *)(v16 + 68) = 0;
        *(_DWORD *)(v16 + 64) = 0;
      }
      v27 = v31;
      v28 = v32[0];
      *(_BYTE *)(v16 + 70) = *(_BYTE *)(a4 + 249);
      *(_BYTE *)(v16 + 71) = *(_BYTE *)(a4 + 248);
      result = perf_trace_run_bpf_submit(v16, v14, v27, a1, 1, v28, StatusReg + v11, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v29 = _fortify_panic(7);
  return trace_event_raw_event_drv_get_ftm_responder_stats(v29);
}
