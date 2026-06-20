__int64 __fastcall perf_trace_adreno_hw_preempt_comp_to_clear(__int64 result, __int64 a2, __int64 a3, int a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v14; // x9
  __int64 v15; // x2
  __int64 v16; // x5
  int v17; // w8
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(44, v20, &v19);
    if ( result )
    {
      v14 = (_QWORD *)v20[0];
      v15 = v19;
      *(_QWORD *)(v20[0] + 232LL) = &vars0;
      v14[31] = &v18;
      v16 = v20[0];
      v14[32] = v6;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 28);
      v17 = *(_DWORD *)(a3 + 28);
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 12) = v17;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a3 + 1280);
      *(_DWORD *)(result + 32) = *(_DWORD *)(a3 + 20);
      *(_DWORD *)(result + 36) = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 24LL);
      *(_DWORD *)(result + 40) = *(_QWORD *)(*(_QWORD *)(a3 + 8) + 24LL);
      result = perf_trace_run_bpf_submit(result, 44, v15, v9, 1, v16, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
