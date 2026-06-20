size_t __fastcall perf_trace_sta_flag_evt(__int64 a1, __int64 a2, __int64 a3, int *a4, char a5)
{
  __int64 v5; // x30
  __int64 v7; // x26
  size_t result; // x0
  int v13; // w27
  unsigned __int64 StatusReg; // x28
  unsigned int v15; // w21
  _QWORD *v16; // x9
  size_t v17; // x23
  __int64 v18; // x8
  const char *v19; // x25
  size_t v20; // x0
  unsigned __int64 v21; // x2
  char v22; // w26
  int v23; // w9
  int v24; // w8
  void *v25; // x24
  size_t v26; // x25
  int v27; // w9
  __int64 v28; // x2
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x0
  __int64 v32; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v33; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v33 = 0;
  result = strlen((const char *)(a3 + 1640));
  v13 = result;
  v32 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v32) )
    goto LABEL_15;
  v15 = ((result + 84) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v15, v34, &v33);
  if ( !result )
    goto LABEL_15;
  v16 = (_QWORD *)v34[0];
  v17 = result;
  *(_QWORD *)(v34[0] + 232LL) = &vars0;
  v16[31] = &v32;
  v16[32] = v7;
  v16[33] = 5;
  *(_DWORD *)(result + 60) = (v13 << 16) + 65607;
  v18 = *(_QWORD *)(a2 + 72);
  v19 = *(const char **)(v18 + 504);
  if ( !v19 )
    v19 = *(const char **)(v18 + 392);
  v20 = strnlen(v19, 0x20u);
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
      v22 = a5 & 1;
      sized_strscpy(v17 + 8, v19);
      v23 = *(_DWORD *)(v17 + 60);
      v24 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v17 + 48) = a3;
      *(_DWORD *)(v17 + 40) = v24;
      v25 = (void *)(v17 + (unsigned __int16)v23);
      v26 = HIWORD(v23) - 1LL;
      *(_BYTE *)(v17 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v25, (const void *)(a3 + 1640), v26);
      *((_BYTE *)v25 + v26) = 0;
      if ( a4 )
      {
        v27 = *a4;
        *(_WORD *)(v17 + 68) = *((_WORD *)a4 + 2);
        *(_DWORD *)(v17 + 64) = v27;
      }
      else
      {
        *(_WORD *)(v17 + 68) = 0;
        *(_DWORD *)(v17 + 64) = 0;
      }
      v28 = v33;
      v29 = v34[0];
      v30 = StatusReg + v32;
      *(_BYTE *)(v17 + 70) = v22;
      result = perf_trace_run_bpf_submit(v17, v15, v28, a1, 1, v29, v30, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v31 = _fortify_panic(7);
  return trace_event_raw_event_drv_add_twt_setup(v31);
}
