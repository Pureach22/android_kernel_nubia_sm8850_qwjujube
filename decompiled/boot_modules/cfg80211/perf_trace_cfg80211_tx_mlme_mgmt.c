__int64 __fastcall perf_trace_cfg80211_tx_mlme_mgmt(__int64 result, __int64 a2, const void *a3, int a4, char a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v14; // w22
  _QWORD *v15; // x9
  size_t v16; // x2
  int v17; // w10
  __int64 v18; // x23
  __int64 v19; // x8
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    v14 = ((a4 + 47) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v24, &v23);
    if ( result )
    {
      v15 = (_QWORD *)v24[0];
      v16 = a4;
      *(_QWORD *)(v24[0] + 232LL) = &v25;
      v15[31] = &v22;
      v15[32] = v6;
      v15[33] = 5;
      v17 = (a4 << 16) | 0x24;
      v18 = result;
      *(_DWORD *)(result + 28) = v17;
      v19 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v19;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      memcpy((void *)(result + (unsigned __int16)v17), a3, v16);
      v20 = v23;
      v21 = v24[0];
      *(_DWORD *)(v18 + 32) = a5 & 1;
      result = perf_trace_run_bpf_submit(v18, v14, v20, v9, 1, v21, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
