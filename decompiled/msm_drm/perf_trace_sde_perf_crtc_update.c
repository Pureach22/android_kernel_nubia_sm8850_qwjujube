__int64 __fastcall perf_trace_sde_perf_crtc_update(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9,
        char a10,
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
  __int64 v25; // x2
  __int64 v26; // x5
  __int64 v27; // x10
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v29; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v28 = a8;
  v14 = v13;
  v16 = result;
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30[0] = 0;
  v22 = *(_QWORD *)(result + 104);
  v29 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v22) )
  {
    result = perf_trace_buf_alloc(92, v30, &v29);
    if ( result )
    {
      v24 = (_QWORD *)v30[0];
      v25 = v29;
      *(_QWORD *)(v30[0] + 232LL) = &vars0;
      v24[31] = &v28;
      v26 = v30[0];
      v24[32] = v14;
      v24[33] = 5;
      v27 = v28;
      *(_DWORD *)(result + 64) = a9;
      *(_QWORD *)(result + 48) = a7;
      *(_QWORD *)(result + 56) = v27;
      *(_BYTE *)(result + 68) = a10 & 1;
      *(_DWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      *(_QWORD *)(result + 32) = a5;
      *(_QWORD *)(result + 40) = a6;
      *(_DWORD *)(result + 72) = a11;
      *(_DWORD *)(result + 76) = a12;
      *(_DWORD *)(result + 80) = a13;
      result = perf_trace_run_bpf_submit(result, 92, v25, v16, 1, v26, StatusReg + v22, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
