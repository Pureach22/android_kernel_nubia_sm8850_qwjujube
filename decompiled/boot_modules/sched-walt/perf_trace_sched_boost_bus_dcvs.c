__int64 __fastcall perf_trace_sched_boost_bus_dcvs(__int64 result, char a2, char a3, char a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v8; // x19
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v12; // x9
  __int64 v13; // x2
  __int64 v14; // x5
  int v15; // w10
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v17; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v19; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v17 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    result = perf_trace_buf_alloc(12, v18, &v17);
    if ( result )
    {
      v12 = (_QWORD *)v18[0];
      *(_QWORD *)(v18[0] + 232LL) = &v19;
      v13 = v17;
      v14 = v18[0];
      v12[31] = &v16;
      v12[32] = v5;
      v12[33] = 5;
      v15 = sched_boost_type;
      *(_BYTE *)(result + 10) = a3 & 1;
      *(_BYTE *)(result + 8) = a2 & 1;
      *(_BYTE *)(result + 9) = v15 == 4;
      *(_BYTE *)(result + 11) = a4 & 1;
      result = perf_trace_run_bpf_submit(result, 12, v13, v8, 1, v14, StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
