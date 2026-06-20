__int64 __fastcall perf_trace_drv_get_expected_throughput(__int64 result, int *a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v6; // x22
  unsigned __int64 StatusReg; // x23
  _QWORD *v8; // x9
  int v9; // w9
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
    result = perf_trace_buf_alloc(20, v12, &v11);
    if ( result )
    {
      v8 = (_QWORD *)v12[0];
      *(_QWORD *)(v12[0] + 232LL) = &v13;
      v8[33] = 5;
      v8[31] = &v10;
      v8[32] = v3;
      if ( a2 )
      {
        v9 = *a2;
        *(_WORD *)(result + 12) = *((_WORD *)a2 + 2);
        *(_DWORD *)(result + 8) = v9;
      }
      else
      {
        *(_WORD *)(result + 12) = 0;
        *(_DWORD *)(result + 8) = 0;
      }
      result = perf_trace_run_bpf_submit(result, 20, v11, v4, 1, v12[0], StatusReg + v6, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
