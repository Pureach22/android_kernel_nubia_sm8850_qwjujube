__int64 __fastcall perf_trace_cfg80211_rx_control_port(__int64 result, __int64 a2, __int64 a3, char a4, int a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  __int64 v9; // x19
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v14; // x9
  __int64 v15; // x8
  int v16; // w9
  __int64 v17; // x2
  __int64 v18; // x5
  unsigned int v19; // w9
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(52, v22, &v21);
    if ( result )
    {
      v14 = (_QWORD *)v22[0];
      *(_QWORD *)(v22[0] + 232LL) = &vars0;
      v14[31] = &v20;
      v14[32] = v6;
      v14[33] = 5;
      v15 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v15;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      *(_DWORD *)(result + 28) = *(_DWORD *)(a3 + 112);
      if ( *(_QWORD *)(a3 + 216) + *(unsigned __int16 *)(a3 + 186) == -6 )
      {
        *(_WORD *)(result + 36) = 0;
        *(_DWORD *)(result + 32) = 0;
      }
      else
      {
        v16 = *(_DWORD *)(*(_QWORD *)(a3 + 216) + *(unsigned __int16 *)(a3 + 186) + 6LL);
        *(_WORD *)(result + 36) = *(_WORD *)(*(_QWORD *)(a3 + 216) + *(unsigned __int16 *)(a3 + 186) + 10LL);
        *(_DWORD *)(result + 32) = v16;
      }
      v17 = v21;
      v18 = v22[0];
      v19 = bswap32(*(unsigned __int16 *)(a3 + 180)) >> 16;
      *(_BYTE *)(result + 40) = a4 & 1;
      *(_DWORD *)(result + 44) = a5;
      *(_WORD *)(result + 38) = v19;
      result = perf_trace_run_bpf_submit(result, 52, v17, v9, 1, v18, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
