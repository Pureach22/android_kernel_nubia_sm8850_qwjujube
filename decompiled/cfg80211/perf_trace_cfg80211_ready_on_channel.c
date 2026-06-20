__int64 __fastcall perf_trace_cfg80211_ready_on_channel(
        __int64 result,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v14; // x10
  int v15; // w8
  __int16 v16; // w8
  __int64 v17; // x2
  __int64 v18; // x5
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v20 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(44, v21, &v20);
    if ( result )
    {
      v14 = (_QWORD *)v21[0];
      v15 = 0;
      *(_QWORD *)(v21[0] + 232LL) = &vars0;
      v14[33] = 5;
      v14[31] = &v19;
      v14[32] = v6;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v15 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v15;
      *(_QWORD *)(result + 16) = a3;
      if ( a4 )
      {
        *(_DWORD *)(result + 24) = *(_DWORD *)a4;
        *(_DWORD *)(result + 28) = *(_DWORD *)(a4 + 4);
        v16 = *(_WORD *)(a4 + 8);
      }
      else
      {
        v16 = 0;
        *(_QWORD *)(result + 24) = 0;
      }
      v17 = v20;
      v18 = v21[0];
      *(_WORD *)(result + 32) = v16;
      *(_DWORD *)(result + 36) = a5;
      result = perf_trace_run_bpf_submit(result, 44, v17, v9, 1, v18, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
