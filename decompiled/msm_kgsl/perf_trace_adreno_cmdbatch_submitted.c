__int64 __fastcall perf_trace_adreno_cmdbatch_submitted(
        __int64 result,
        __int64 a2,
        _DWORD *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7)
{
  __int64 v7; // x30
  __int64 v8; // x26
  __int64 v11; // x19
  __int64 v16; // x27
  unsigned __int64 StatusReg; // x28
  _QWORD *v18; // x9
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // x8
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v8 = v7;
  v11 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v16 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    result = perf_trace_buf_alloc(76, v24, &v23);
    if ( result )
    {
      v18 = (_QWORD *)v24[0];
      v19 = v23;
      *(_QWORD *)(v24[0] + 232LL) = &vars0;
      v18[31] = &v22;
      v20 = v24[0];
      v18[32] = v8;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL);
      *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(result + 16) = *a3;
      v21 = *(_QWORD *)(a2 + 24);
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_DWORD *)(result + 20) = v21;
      *(_DWORD *)(result + 48) = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 8LL);
      *(_DWORD *)(result + 52) = a3[1];
      *(_DWORD *)(result + 56) = a3[2];
      *(_DWORD *)(result + 60) = a3[3];
      *(_DWORD *)(result + 64) = a7;
      *(_DWORD *)(result + 68) = a3[4];
      result = perf_trace_run_bpf_submit(result, 76, v19, v11, 1, v20, StatusReg + v16, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
