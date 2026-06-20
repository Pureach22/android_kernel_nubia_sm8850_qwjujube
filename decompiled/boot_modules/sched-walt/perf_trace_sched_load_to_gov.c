__int64 __fastcall perf_trace_sched_load_to_gov(
        __int64 result,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        __int64 a6,
        unsigned __int64 a7,
        int a8,
        char a9,
        int a10,
        _QWORD *a11,
        int a12)
{
  __int64 v12; // x30
  __int64 v13; // x27
  __int64 v16; // x19
  __int64 v21; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v23; // x9
  __int64 v24; // x12
  int v25; // w12
  unsigned __int64 v26; // x13
  __int64 v27; // x2
  __int64 v28; // x5
  __int64 v29; // x9
  __int64 v30; // x9
  __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v32; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v33[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v31 = a6;
  v13 = v12;
  v16 = result;
  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v21 = *(_QWORD *)(result + 104);
  v32 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v21) )
  {
    result = perf_trace_buf_alloc(132, v33, &v32);
    if ( result )
    {
      v23 = (_QWORD *)v33[0];
      *(_QWORD *)(v33[0] + 232LL) = &vars0;
      v23[31] = &v31;
      v23[32] = v13;
      v23[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 3632);
      *(_DWORD *)(result + 12) = a8;
      v24 = a11[14];
      if ( v24 )
        v25 = *(_DWORD *)(v24 + 1800);
      else
        v25 = -1;
      *(_DWORD *)(result + 16) = v25;
      v26 = (unsigned int)walt_scale_demand_divisor;
      *(_QWORD *)(result + 24) = a3;
      v27 = v32;
      *(_DWORD *)(result + 32) = a5;
      v28 = v33[0];
      *(_QWORD *)(result + 40) = a4;
      *(_QWORD *)(result + 48) = a11[19];
      *(_QWORD *)(result + 56) = a11[23];
      *(_QWORD *)(result + 64) = a11[21];
      *(_QWORD *)(result + 72) = a11[25];
      v29 = a11[6];
      *(_BYTE *)(result + 104) = a9 & 1;
      *(_DWORD *)(result + 108) = a10;
      *(_DWORD *)(result + 112) = a12;
      *(_QWORD *)(result + 80) = v29;
      v30 = v31;
      *(_QWORD *)(result + 120) = a7 / v26;
      *(_QWORD *)(result + 88) = v30;
      *(_QWORD *)(result + 96) = a7;
      result = perf_trace_run_bpf_submit(result, 132, v27, v16, 1, v28, StatusReg + v21, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
