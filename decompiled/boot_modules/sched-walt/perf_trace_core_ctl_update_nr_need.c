__int64 __fastcall perf_trace_core_ctl_update_nr_need(
        __int64 result,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  __int64 v13; // x30
  __int64 v14; // x27
  __int64 v16; // x19
  __int64 v22; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v24; // x9
  __int64 v25; // x5
  __int64 v26; // x2
  int v27; // w10
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  int v29; // [xsp+8h] [xbp-18h]
  unsigned int v30; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v29 = a8;
  v14 = v13;
  v16 = result;
  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = 0;
  v22 = *(_QWORD *)(result + 104);
  v30 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v22) )
  {
    result = perf_trace_buf_alloc(60, v31, &v30);
    if ( result )
    {
      v24 = (_QWORD *)v31[0];
      *(_QWORD *)(v31[0] + 232LL) = &vars0;
      v24[31] = &v28;
      v25 = v31[0];
      v24[32] = v14;
      v24[33] = 5;
      v27 = v29;
      v26 = v30;
      *(_DWORD *)(result + 36) = a9;
      *(_DWORD *)(result + 40) = a10;
      *(_DWORD *)(result + 32) = v27;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = a5;
      *(_DWORD *)(result + 24) = a6;
      *(_DWORD *)(result + 28) = a7;
      *(_DWORD *)(result + 44) = a11;
      *(_DWORD *)(result + 48) = a12;
      *(_DWORD *)(result + 52) = a13;
      result = perf_trace_run_bpf_submit(result, 60, v26, v16, 1, v25, StatusReg + v22, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
