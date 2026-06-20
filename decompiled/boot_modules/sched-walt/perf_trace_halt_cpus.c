__int64 __fastcall perf_trace_halt_cpus(__int64 result, __int64 *a2, __int64 a3, char a4, int a5, int a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v14; // x26
  unsigned __int64 StatusReg; // x27
  __int64 v16; // x1
  _QWORD *v17; // x9
  int v18; // w8
  __int64 v19; // x9
  int v20; // w10
  __int64 v21; // x24
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v28; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v26 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    result = perf_trace_buf_alloc(36, v27, &v26);
    if ( result )
    {
      v17 = (_QWORD *)v27[0];
      *(_QWORD *)(v27[0] + 232LL) = &v28;
      v17[31] = &v25;
      v18 = _cpu_halt_mask[0];
      v17[32] = v7;
      v17[33] = 5;
      v19 = *a2;
      v20 = _cpu_partial_halt_mask[0];
      v21 = result;
      *(_DWORD *)(result + 8) = v19;
      *(_DWORD *)(result + 12) = v18;
      *(_DWORD *)(result + 16) = v20;
      v22 = sched_clock(result, v16);
      v23 = v26;
      v24 = v27[0];
      *(_BYTE *)(v21 + 24) = a4;
      *(_DWORD *)(v21 + 28) = a6;
      *(_BYTE *)(v21 + 25) = a5 >= 0;
      *(_DWORD *)(v21 + 20) = (v22 - a3) / 0x3E8uLL;
      result = perf_trace_run_bpf_submit(v21, 36, v23, v10, 1, v24, StatusReg + v14, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
