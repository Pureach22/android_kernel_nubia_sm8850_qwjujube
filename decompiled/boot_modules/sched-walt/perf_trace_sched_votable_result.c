__int64 __fastcall perf_trace_sched_votable_result(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v8; // x9
  __int64 v9; // x8
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v11; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v13; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  v6 = *(_QWORD *)(result + 104);
  v11 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v6) )
  {
    result = perf_trace_buf_alloc(100, v12, &v11);
    if ( result )
    {
      v8 = (_QWORD *)v12[0];
      *(_QWORD *)(v12[0] + 232LL) = &v13;
      v8[31] = &v10;
      v8[32] = v3;
      v8[33] = 5;
      v9 = *(_QWORD *)(*(_QWORD *)a2 + 8LL);
      *(_QWORD *)(result + 8) = **(_QWORD **)a2;
      *(_QWORD *)(result + 16) = v9;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 96);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a2 + 100);
      *(_DWORD *)(result + 32) = *(unsigned __int8 *)(a2 + 24);
      *(_DWORD *)(result + 64) = *(_DWORD *)(a2 + 28);
      *(_DWORD *)(result + 36) = *(unsigned __int8 *)(a2 + 32);
      *(_DWORD *)(result + 68) = *(_DWORD *)(a2 + 36);
      *(_DWORD *)(result + 40) = *(unsigned __int8 *)(a2 + 40);
      *(_DWORD *)(result + 72) = *(_DWORD *)(a2 + 44);
      *(_DWORD *)(result + 44) = *(unsigned __int8 *)(a2 + 48);
      *(_DWORD *)(result + 76) = *(_DWORD *)(a2 + 52);
      *(_DWORD *)(result + 48) = *(unsigned __int8 *)(a2 + 56);
      *(_DWORD *)(result + 80) = *(_DWORD *)(a2 + 60);
      *(_DWORD *)(result + 52) = *(unsigned __int8 *)(a2 + 64);
      *(_DWORD *)(result + 84) = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(result + 56) = *(unsigned __int8 *)(a2 + 72);
      *(_DWORD *)(result + 88) = *(_DWORD *)(a2 + 76);
      *(_DWORD *)(result + 60) = *(unsigned __int8 *)(a2 + 80);
      *(_DWORD *)(result + 92) = *(_DWORD *)(a2 + 84);
      result = perf_trace_run_bpf_submit(result, 100, v11, v4, 1, v12[0], StatusReg + v6, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
