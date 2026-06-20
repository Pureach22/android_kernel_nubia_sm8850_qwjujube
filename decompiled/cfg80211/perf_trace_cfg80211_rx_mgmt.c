__int64 __fastcall perf_trace_cfg80211_rx_mgmt(__int64 result, unsigned __int64 a2, _DWORD *a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x10
  int v11; // w8
  __int64 v12; // x2
  __int64 v13; // x5
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v15; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v15 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(20, v16, &v15);
    if ( result )
    {
      v10 = (_QWORD *)v16[0];
      v11 = 0;
      *(_QWORD *)(v16[0] + 232LL) = &vars0;
      v10[33] = 5;
      v10[31] = &v14;
      v10[32] = v4;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v11 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v11;
      v12 = v15;
      v13 = v16[0];
      *(_DWORD *)(result + 12) = *a3;
      *(_DWORD *)(result + 16) = a3[1];
      result = perf_trace_run_bpf_submit(result, 20, v12, v6, 1, v13, StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
