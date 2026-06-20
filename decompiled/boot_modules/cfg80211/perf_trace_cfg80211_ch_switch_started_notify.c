__int64 __fastcall perf_trace_cfg80211_ch_switch_started_notify(__int64 result, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v8; // x19
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v12; // x9
  __int64 v13; // x8
  __int64 v14; // x2
  __int64 v15; // x5
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v17; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v19; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v17 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    result = perf_trace_buf_alloc(68, v18, &v17);
    if ( result )
    {
      v12 = (_QWORD *)v18[0];
      *(_QWORD *)(v18[0] + 232LL) = &v19;
      v12[31] = &v16;
      v12[32] = v5;
      v12[33] = 5;
      v13 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v13;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( a3 && *(_QWORD *)a3 )
      {
        *(_DWORD *)(result + 28) = **(_DWORD **)a3;
        *(_DWORD *)(result + 32) = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
        *(_DWORD *)(result + 36) = *(unsigned __int16 *)(*(_QWORD *)a3 + 8LL);
        *(_DWORD *)(result + 40) = *(_DWORD *)(a3 + 8);
        *(_DWORD *)(result + 44) = *(_DWORD *)(a3 + 12);
        *(_DWORD *)(result + 48) = *(unsigned __int16 *)(a3 + 28);
        *(_DWORD *)(result + 52) = *(_DWORD *)(a3 + 16);
        *(_WORD *)(result + 56) = *(_WORD *)(a3 + 30);
      }
      else
      {
        *(_QWORD *)(result + 50) = 0;
        *(_QWORD *)(result + 44) = 0;
        *(_QWORD *)(result + 36) = 0;
        *(_QWORD *)(result + 28) = 0;
      }
      v14 = v17;
      v15 = v18[0];
      *(_DWORD *)(result + 60) = a4;
      result = perf_trace_run_bpf_submit(result, 68, v14, v8, 1, v15, StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
