__int64 __fastcall perf_trace_adreno_cmdbatch_queued(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v7; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v9; // x9
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  int v11; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  v7 = *(_QWORD *)(result + 104);
  v11 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v7) )
  {
    result = perf_trace_buf_alloc(28, v12, &v11);
    if ( result )
    {
      v9 = (_QWORD *)v12[0];
      *(_QWORD *)(v12[0] + 232LL) = &vars0;
      v9[31] = &v10;
      v9[32] = v4;
      v9[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL);
      *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 20) = *(_QWORD *)(a2 + 24);
      *(_DWORD *)(result + 24) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 8LL);
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
