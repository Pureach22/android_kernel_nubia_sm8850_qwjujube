__int64 __fastcall perf_trace_sched_set_preferred_cluster(__int64 result, int *a2, __int64 a3, char a4, int a5, int a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v14; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v16; // x9
  __int64 v17; // x2
  __int64 v18; // x5
  int v19; // w8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    result = perf_trace_buf_alloc(76, v24, &v23);
    if ( result )
    {
      v16 = (_QWORD *)v24[0];
      v17 = v23;
      *(_QWORD *)(v24[0] + 232LL) = &v25;
      v16[31] = &v22;
      v18 = v24[0];
      v16[32] = v7;
      v16[33] = 5;
      v19 = *a2;
      *(_QWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 8) = v19;
      LOBYTE(v16) = *((_BYTE *)a2 + 40);
      *(_BYTE *)(result + 25) = a4 & 1;
      *(_BYTE *)(result + 24) = (_BYTE)v16;
      LODWORD(v16) = sysctl_sched_hyst_min_coloc_ns;
      *(_QWORD *)(result + 32) = *((_QWORD *)a2 + 10);
      v20 = *((_QWORD *)a2 + 8);
      *(_DWORD *)(result + 48) = (_DWORD)v16;
      *(_QWORD *)(result + 40) = v20;
      v21 = *((_QWORD *)a2 + 9);
      *(_DWORD *)(result + 64) = a5;
      *(_DWORD *)(result + 68) = a6;
      *(_QWORD *)(result + 56) = v21;
      result = perf_trace_run_bpf_submit(result, 76, v17, v10, 1, v18, StatusReg + v14, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
