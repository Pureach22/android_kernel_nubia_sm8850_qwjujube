__int64 __fastcall perf_trace_cfg80211_bss_evt(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v8; // x9
  _DWORD *v9; // x8
  __int64 v10; // x2
  __int64 v11; // x5
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v13; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v15; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v6 = *(_QWORD *)(result + 104);
  v13 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v6) )
  {
    result = perf_trace_buf_alloc(28, v14, &v13);
    if ( result )
    {
      v8 = (_QWORD *)v14[0];
      *(_QWORD *)(v14[0] + 232LL) = &v15;
      v8[31] = &v12;
      v8[32] = v3;
      v8[33] = 5;
      LODWORD(v8) = *(_DWORD *)(a2 + 72);
      *(_WORD *)(result + 12) = *(_WORD *)(a2 + 76);
      *(_DWORD *)(result + 8) = (_DWORD)v8;
      v9 = *(_DWORD **)a2;
      if ( *(_QWORD *)a2 )
      {
        *(_DWORD *)(result + 16) = *v9;
        *(_DWORD *)(result + 20) = *(_DWORD *)(*(_QWORD *)a2 + 4LL);
        LOWORD(v9) = *(_WORD *)(*(_QWORD *)a2 + 8LL);
      }
      else
      {
        *(_QWORD *)(result + 16) = 0;
      }
      v10 = v13;
      v11 = v14[0];
      *(_WORD *)(result + 24) = (_WORD)v9;
      result = perf_trace_run_bpf_submit(result, 28, v10, v4, 1, v11, StatusReg + v6, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
