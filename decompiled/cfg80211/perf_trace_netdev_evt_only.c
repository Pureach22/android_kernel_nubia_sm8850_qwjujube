__int64 __fastcall perf_trace_netdev_evt_only(__int64 result, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v8; // x9
  __int64 v9; // x2
  __int64 v10; // x5
  __int64 v11; // x8
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v13; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v15; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v4 = result;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v6 = *(_QWORD *)(result + 104);
  v13 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v6) )
  {
    result = perf_trace_buf_alloc(28, v14, &v13);
    if ( result )
    {
      v8 = (_QWORD *)v14[0];
      v9 = v13;
      *(_QWORD *)(v14[0] + 232LL) = &v15;
      v8[31] = &v12;
      v10 = v14[0];
      v8[32] = v3;
      v8[33] = 5;
      v11 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v11;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      result = perf_trace_run_bpf_submit(result, 28, v9, v4, 1, v10, StatusReg + v6, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
