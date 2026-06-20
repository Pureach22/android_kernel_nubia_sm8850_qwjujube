__int64 __fastcall perf_trace_cfg80211_chandef_dfs_required(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v8; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v10; // x9
  __int64 v11; // x21
  const char *v12; // x23
  size_t v13; // x0
  unsigned __int64 v14; // x2
  long double v15; // q0
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v17; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v19; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v17 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v8) || (result = perf_trace_buf_alloc(76, v18, &v17)) == 0 )
  {
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = (_QWORD *)v18[0];
  v11 = result;
  *(_QWORD *)(v18[0] + 232LL) = &v19;
  v10[33] = 5;
  v10[31] = &v16;
  v10[32] = v4;
  v12 = *(const char **)(a2 + 504);
  if ( !v12 )
    v12 = *(const char **)(a2 + 392);
  v13 = strnlen(v12, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v13 == 32 )
      v14 = 32;
    else
      v14 = v13 + 1;
    if ( v14 < 0x21 )
    {
      sized_strscpy(v11 + 8, v12);
      if ( a3 && *(_QWORD *)a3 )
      {
        *(_DWORD *)(v11 + 40) = **(_DWORD **)a3;
        *(_DWORD *)(v11 + 44) = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
        *(_DWORD *)(v11 + 48) = *(unsigned __int16 *)(*(_QWORD *)a3 + 8LL);
        *(_DWORD *)(v11 + 52) = *(_DWORD *)(a3 + 8);
        *(_DWORD *)(v11 + 56) = *(_DWORD *)(a3 + 12);
        *(_DWORD *)(v11 + 60) = *(unsigned __int16 *)(a3 + 28);
        *(_DWORD *)(v11 + 64) = *(_DWORD *)(a3 + 16);
        *(_WORD *)(v11 + 68) = *(_WORD *)(a3 + 30);
      }
      else
      {
        *(_QWORD *)(v11 + 62) = 0;
        *(_QWORD *)(v11 + 48) = 0;
        *(_QWORD *)(v11 + 56) = 0;
        *(_QWORD *)(v11 + 40) = 0;
      }
      result = perf_trace_run_bpf_submit(v11, 76, v17, v6, 1, v18[0], StatusReg + v8, 0);
      goto LABEL_16;
    }
  }
  v15 = _fortify_panic(7, 32);
  return trace_event_raw_event_cfg80211_ch_switch_notify(v15);
}
