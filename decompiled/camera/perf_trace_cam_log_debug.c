__int64 __fastcall perf_trace_cam_log_debug(__int64 result, const char *a2, __int64 *a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x9
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x21
  __int64 v16; // x12
  __int64 v17; // [xsp+0h] [xbp-60h] BYREF
  _QWORD arg[8]; // [xsp+8h] [xbp-58h] BYREF
  unsigned int v19; // [xsp+4Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+50h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+60h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(524, v20, &v19);
    if ( result )
    {
      v10 = (_QWORD *)v20[0];
      *(_QWORD *)(v20[0] + 232LL) = &vars0;
      v10[31] = &v17;
      v10[32] = v4;
      v10[33] = 5;
      *(_DWORD *)(result + 8) = 33554444;
      v11 = a3[2];
      v12 = a3[3];
      v14 = *a3;
      v13 = a3[1];
      v15 = result;
      arg[6] = v11;
      arg[7] = v12;
      arg[4] = v14;
      arg[5] = v13;
      v16 = *(unsigned __int16 *)(result + 8);
      arg[0] = v14;
      arg[1] = v13;
      arg[2] = v11;
      arg[3] = v12;
      vsnprintf((char *)(result + v16), 0x200u, a2, arg);
      result = perf_trace_run_bpf_submit(v15, 524, v19, v6, 1, v20[0], StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
