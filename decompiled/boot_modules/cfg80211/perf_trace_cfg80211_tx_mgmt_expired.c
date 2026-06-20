__int64 __fastcall perf_trace_cfg80211_tx_mgmt_expired(__int64 result, unsigned __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v8; // x19
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v12; // x10
  int v13; // w8
  __int16 v14; // w8
  __int64 v15; // x2
  __int64 v16; // x5
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v20; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v18 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    result = perf_trace_buf_alloc(44, v19, &v18);
    if ( result )
    {
      v12 = (_QWORD *)v19[0];
      v13 = 0;
      *(_QWORD *)(v19[0] + 232LL) = &v20;
      v12[33] = 5;
      v12[31] = &v17;
      v12[32] = v5;
      if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
        v13 = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 8) = v13;
      *(_QWORD *)(result + 16) = a3;
      if ( a4 )
      {
        *(_DWORD *)(result + 24) = *(_DWORD *)a4;
        *(_DWORD *)(result + 28) = *(_DWORD *)(a4 + 4);
        v14 = *(_WORD *)(a4 + 8);
      }
      else
      {
        v14 = 0;
        *(_QWORD *)(result + 24) = 0;
      }
      v15 = v18;
      v16 = v19[0];
      *(_WORD *)(result + 32) = v14;
      result = perf_trace_run_bpf_submit(result, 44, v15, v8, 1, v16, StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
