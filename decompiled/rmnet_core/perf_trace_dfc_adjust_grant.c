__int64 __fastcall perf_trace_dfc_adjust_grant(__int64 result, char a2, char a3, int a4, int a5, int a6, int a7)
{
  __int64 v7; // x30
  __int64 v8; // x26
  __int64 v11; // x19
  __int64 v16; // x27
  unsigned __int64 StatusReg; // x28
  _QWORD *v18; // x9
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v8 = v7;
  v11 = result;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v16 = *(_QWORD *)(result + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    result = perf_trace_buf_alloc(28, v23, &v22);
    if ( result )
    {
      v18 = (_QWORD *)v23[0];
      v19 = v22;
      *(_QWORD *)(v23[0] + 232LL) = &vars0;
      v20 = v23[0];
      v18[31] = &v21;
      v18[32] = v8;
      v18[33] = 5;
      *(_BYTE *)(result + 8) = a2;
      *(_BYTE *)(result + 9) = a3;
      *(_DWORD *)(result + 12) = a4;
      *(_DWORD *)(result + 16) = a5;
      *(_DWORD *)(result + 20) = a6;
      *(_DWORD *)(result + 24) = a7;
      result = perf_trace_run_bpf_submit(result, 28, v19, v11, 1, v20, StatusReg + v16, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
