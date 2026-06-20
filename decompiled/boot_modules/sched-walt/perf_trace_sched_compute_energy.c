__int64 __fastcall perf_trace_sched_compute_energy(
        __int64 result,
        __int64 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v9; // x27
  __int64 v12; // x19
  __int64 v17; // x21
  unsigned __int64 StatusReg; // x28
  _QWORD *v19; // x9
  __int64 v20; // x9
  unsigned __int16 *v21; // x8
  int v22; // w8
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // x8
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v26 = a6;
  v9 = v8;
  v12 = result;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  v17 = *(_QWORD *)(result + 104);
  v27 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v17) )
  {
    result = perf_trace_buf_alloc(180, v28, &v27);
    if ( result )
    {
      v19 = (_QWORD *)v28[0];
      *(_QWORD *)(v28[0] + 232LL) = &vars0;
      v19[31] = &v26;
      v19[32] = v9;
      v19[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 1800);
      v20 = *(_QWORD *)(a2 + 2320);
      *(_QWORD *)(result + 20) = *(_QWORD *)(a2 + 2328);
      v21 = (unsigned __int16 *)&vendor_data_pad;
      if ( (_UNKNOWN *)a2 != &init_task )
        v21 = (unsigned __int16 *)(a2 + 5184);
      *(_QWORD *)(result + 12) = v20;
      *(_QWORD *)(result + 32) = v21[79];
      v22 = *(_DWORD *)(a2 + 40);
      *(_QWORD *)(result + 48) = a5;
      v23 = v27;
      *(_DWORD *)(result + 56) = a3;
      v24 = v28[0];
      *(_DWORD *)(result + 40) = v22;
      v25 = v26;
      *(_QWORD *)(result + 64) = a4;
      *(_DWORD *)(result + 72) = a7;
      *(_QWORD *)(result + 80) = v25;
      *(_DWORD *)(result + 88) = *(_DWORD *)(a8 + 96);
      *(_DWORD *)(result + 92) = *(_DWORD *)(a8 + 100);
      *(_DWORD *)(result + 96) = *(_DWORD *)(a8 + 104);
      *(_QWORD *)(result + 104) = *(_QWORD *)a8;
      *(_QWORD *)(result + 112) = *(_QWORD *)(a8 + 8);
      *(_QWORD *)(result + 120) = *(_QWORD *)(a8 + 16);
      *(_QWORD *)(result + 128) = *(_QWORD *)(a8 + 32);
      *(_QWORD *)(result + 136) = *(_QWORD *)(a8 + 40);
      *(_QWORD *)(result + 144) = *(_QWORD *)(a8 + 48);
      *(_QWORD *)(result + 152) = *(_QWORD *)(a8 + 64);
      *(_QWORD *)(result + 160) = *(_QWORD *)(a8 + 72);
      *(_QWORD *)(result + 168) = *(_QWORD *)(a8 + 80);
      result = perf_trace_run_bpf_submit(result, 180, v23, v12, 1, v24, StatusReg + v17, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
