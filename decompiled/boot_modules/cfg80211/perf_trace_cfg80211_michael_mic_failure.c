__int64 __fastcall perf_trace_cfg80211_michael_mic_failure(
        __int64 result,
        __int64 a2,
        int *a3,
        int a4,
        int a5,
        int *a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v14; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v16; // x9
  __int64 v17; // x8
  int v18; // w9
  int v19; // w9
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v23; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    result = perf_trace_buf_alloc(52, v22, &v21);
    if ( result )
    {
      v16 = (_QWORD *)v22[0];
      *(_QWORD *)(v22[0] + 232LL) = &v23;
      v16[31] = &v20;
      v16[32] = v7;
      v16[33] = 5;
      v17 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v17;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( a3 )
      {
        v18 = *a3;
        *(_WORD *)(result + 32) = *((_WORD *)a3 + 2);
        *(_DWORD *)(result + 28) = v18;
        *(_DWORD *)(result + 36) = a4;
        *(_DWORD *)(result + 40) = a5;
        if ( !a6 )
        {
LABEL_7:
          result = perf_trace_run_bpf_submit(result, 52, v21, v10, 1, v22[0], StatusReg + v14, 0);
          goto LABEL_8;
        }
      }
      else
      {
        *(_WORD *)(result + 32) = 0;
        *(_DWORD *)(result + 28) = 0;
        *(_DWORD *)(result + 36) = a4;
        *(_DWORD *)(result + 40) = a5;
        if ( !a6 )
          goto LABEL_7;
      }
      v19 = *a6;
      *(_WORD *)(result + 48) = *((_WORD *)a6 + 2);
      *(_DWORD *)(result + 44) = v19;
      goto LABEL_7;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
