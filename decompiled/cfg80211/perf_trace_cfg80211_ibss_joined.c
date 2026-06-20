__int64 __fastcall perf_trace_cfg80211_ibss_joined(__int64 result, __int64 a2, int *a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v8; // x19
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v12; // x9
  __int64 v13; // x8
  int v14; // w9
  __int16 v15; // w8
  __int64 v16; // x2
  __int64 v17; // x5
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v21; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    result = perf_trace_buf_alloc(52, v20, &v19);
    if ( result )
    {
      v12 = (_QWORD *)v20[0];
      *(_QWORD *)(v20[0] + 232LL) = &v21;
      v12[31] = &v18;
      v12[32] = v5;
      v12[33] = 5;
      v13 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v13;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( a3 )
      {
        v14 = *a3;
        *(_WORD *)(result + 32) = *((_WORD *)a3 + 2);
        *(_DWORD *)(result + 28) = v14;
        if ( a4 )
        {
LABEL_6:
          *(_DWORD *)(result + 36) = *(_DWORD *)a4;
          *(_DWORD *)(result + 40) = *(_DWORD *)(a4 + 4);
          v15 = *(_WORD *)(a4 + 8);
LABEL_9:
          v16 = v19;
          v17 = v20[0];
          *(_WORD *)(result + 44) = v15;
          result = perf_trace_run_bpf_submit(result, 52, v16, v8, 1, v17, StatusReg + v10, 0);
          goto LABEL_10;
        }
      }
      else
      {
        *(_WORD *)(result + 32) = 0;
        *(_DWORD *)(result + 28) = 0;
        if ( a4 )
          goto LABEL_6;
      }
      v15 = 0;
      *(_QWORD *)(result + 36) = 0;
      goto LABEL_9;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
