__int64 __fastcall perf_trace_halt_cpus_start(__int64 result, __int64 *a2, char a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x9
  __int64 v11; // x2
  __int64 v12; // x5
  int v13; // w8
  __int64 v14; // x10
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v16; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v16 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(28, v17, &v16);
    if ( result )
    {
      v10 = (_QWORD *)v17[0];
      v11 = v16;
      *(_QWORD *)(v17[0] + 232LL) = &vars0;
      v10[31] = &v15;
      v12 = v17[0];
      v10[32] = v4;
      v10[33] = 5;
      v13 = _cpu_partial_halt_mask[0];
      v14 = *a2;
      LODWORD(v10) = _cpu_halt_mask[0];
      *(_BYTE *)(result + 20) = a3;
      *(_DWORD *)(result + 12) = (_DWORD)v10;
      *(_DWORD *)(result + 16) = v13;
      *(_DWORD *)(result + 8) = v14;
      result = perf_trace_run_bpf_submit(result, 28, v11, v6, 1, v12, StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
