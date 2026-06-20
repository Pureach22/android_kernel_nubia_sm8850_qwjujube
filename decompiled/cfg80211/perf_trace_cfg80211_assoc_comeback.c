__int64 __fastcall perf_trace_cfg80211_assoc_comeback(__int64 result, unsigned __int64 a2, int *a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v8; // x19
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v12; // x10
  int v13; // w8
  int v14; // w9
  __int64 v15; // x2
  __int64 v16; // x5
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v20; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v18 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    result = perf_trace_buf_alloc(28, v19, &v18);
    if ( result )
    {
      v12 = (_QWORD *)v19[0];
      v13 = 0;
      *(_QWORD *)(v19[0] + 232LL) = &v20;
      v12[33] = 5;
      v12[31] = &v17;
      v12[32] = v5;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v13 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v13;
      if ( a3 )
      {
        v14 = *a3;
        *(_WORD *)(result + 16) = *((_WORD *)a3 + 2);
        *(_DWORD *)(result + 12) = v14;
      }
      else
      {
        *(_WORD *)(result + 16) = 0;
        *(_DWORD *)(result + 12) = 0;
      }
      v15 = v18;
      v16 = v19[0];
      *(_DWORD *)(result + 20) = a4;
      result = perf_trace_run_bpf_submit(result, 28, v15, v8, 1, v16, StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
