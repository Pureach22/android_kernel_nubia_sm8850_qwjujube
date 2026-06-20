__int64 __fastcall perf_trace_cfg80211_send_assoc_failure(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v8; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v10; // x9
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x9
  __int16 v14; // w10
  int v15; // w9
  __int64 v16; // x2
  __int64 v17; // x5
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    result = perf_trace_buf_alloc(36, v20, &v19);
    if ( result )
    {
      v10 = (_QWORD *)v20[0];
      *(_QWORD *)(v20[0] + 232LL) = &vars0;
      v10[31] = &v18;
      v10[32] = v4;
      v10[33] = 5;
      v11 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v11;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      if ( *(_QWORD *)a3 )
      {
        v12 = result + 28;
      }
      else
      {
        v12 = result + 28;
        if ( *(_QWORD *)(a3 + 8) == -72 )
        {
          *(_WORD *)(result + 32) = 0;
          *(_DWORD *)v12 = 0;
LABEL_10:
          v16 = v19;
          v17 = v20[0];
          *(_BYTE *)(result + 34) = *(_BYTE *)(a3 + 128);
          result = perf_trace_run_bpf_submit(result, 36, v16, v6, 1, v17, StatusReg + v8, 0);
          goto LABEL_11;
        }
      }
      v13 = *(_QWORD *)a3;
      if ( !*(_QWORD *)a3 )
        v13 = *(_QWORD *)(a3 + 8) + 72LL;
      v14 = *(_WORD *)(v13 + 4);
      v15 = *(_DWORD *)v13;
      *(_WORD *)(v12 + 4) = v14;
      *(_DWORD *)v12 = v15;
      goto LABEL_10;
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
