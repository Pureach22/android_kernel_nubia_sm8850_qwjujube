__int64 __fastcall perf_trace_waltgov_util_update(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int a9,
        int a10,
        char a11)
{
  __int64 v11; // x30
  __int64 v12; // x27
  __int64 v14; // x19
  __int64 v20; // x28
  unsigned __int64 StatusReg; // x20
  _QWORD *v22; // x9
  __int64 v23; // x5
  __int64 v24; // x2
  int v25; // w11
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  int v27; // [xsp+8h] [xbp-18h]
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v27 = a8;
  v12 = v11;
  v14 = result;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v20 = *(_QWORD *)(result + 104);
  v28 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v20) )
  {
    result = perf_trace_buf_alloc(76, v29, &v28);
    if ( result )
    {
      v22 = (_QWORD *)v29[0];
      *(_QWORD *)(v29[0] + 232LL) = &vars0;
      v22[31] = &v26;
      v23 = v29[0];
      v25 = v27;
      v24 = v28;
      v22[32] = v12;
      v22[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_QWORD *)(result + 48) = a7;
      *(_DWORD *)(result + 56) = v25;
      *(_DWORD *)(result + 60) = a9;
      *(_DWORD *)(result + 64) = a10;
      *(_BYTE *)(result + 68) = a11 & 1;
      result = perf_trace_run_bpf_submit(result, 76, v24, v14, 1, v23, StatusReg + v20, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
