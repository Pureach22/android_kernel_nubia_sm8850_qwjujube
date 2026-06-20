__int64 __fastcall perf_trace_cfg80211_get_bss(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int *a4,
        void *a5,
        size_t a6,
        int a7,
        int a8)
{
  __int64 v8; // x30
  __int64 v9; // x20
  __int64 v10; // x19
  __int64 v15; // x21
  unsigned __int64 StatusReg; // x23
  unsigned int v17; // w24
  _QWORD *v18; // x9
  __int64 v19; // x26
  const char *v20; // x20
  size_t v21; // x0
  unsigned __int64 v22; // x2
  int v23; // w9
  int v24; // w8
  __int64 v25; // x2
  __int64 v26; // x5
  long double v27; // q0
  __int64 v28; // [xsp+0h] [xbp-30h] BYREF
  void *src; // [xsp+8h] [xbp-28h]
  int v30; // [xsp+14h] [xbp-1Ch]
  int v31; // [xsp+18h] [xbp-18h]
  unsigned int v32; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v33[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v30 = a7;
  v31 = a8;
  v9 = v8;
  v10 = result;
  src = a5;
  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v15 = *(_QWORD *)(result + 104);
  v32 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v15) )
    goto LABEL_17;
  v17 = ((a6 + 79) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v17, v33, &v32);
  if ( !result )
    goto LABEL_17;
  v18 = (_QWORD *)v33[0];
  *(_QWORD *)(v33[0] + 232LL) = &vars0;
  v19 = result;
  v18[31] = &v28;
  v18[32] = v9;
  v18[33] = 5;
  *(_DWORD *)(result + 56) = ((_DWORD)a6 << 16) | 0x44;
  v20 = *(const char **)(a2 + 504);
  if ( !v20 )
    v20 = *(const char **)(a2 + 392);
  v21 = strnlen(v20, 0x20u);
  if ( v21 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v21 == 32 )
      v22 = 32;
    else
      v22 = v21 + 1;
    if ( v22 < 0x21 )
    {
      sized_strscpy(v19 + 8, v20);
      if ( a3 )
      {
        *(_DWORD *)(v19 + 40) = *(_DWORD *)a3;
        *(_DWORD *)(v19 + 44) = *(_DWORD *)(a3 + 4);
        *(_WORD *)(v19 + 48) = *(_WORD *)(a3 + 8);
        if ( a4 )
        {
LABEL_13:
          v23 = *a4;
          *(_WORD *)(v19 + 54) = *((_WORD *)a4 + 2);
          *(_DWORD *)(v19 + 50) = v23;
LABEL_16:
          memcpy((void *)(v19 + *(unsigned __int16 *)(v19 + 56)), src, a6);
          v24 = v31;
          v25 = v32;
          v26 = v33[0];
          *(_DWORD *)(v19 + 60) = v30;
          *(_DWORD *)(v19 + 64) = v24;
          result = perf_trace_run_bpf_submit(v19, v17, v25, v10, 1, v26, StatusReg + v15, 0);
LABEL_17:
          _ReadStatusReg(SP_EL0);
          return result;
        }
      }
      else
      {
        *(_QWORD *)(v19 + 40) = 0;
        *(_WORD *)(v19 + 48) = 0;
        if ( a4 )
          goto LABEL_13;
      }
      *(_WORD *)(v19 + 54) = 0;
      *(_DWORD *)(v19 + 50) = 0;
      goto LABEL_16;
    }
  }
  v27 = _fortify_panic(7, 32);
  return trace_event_raw_event_cfg80211_inform_bss_frame(v27);
}
