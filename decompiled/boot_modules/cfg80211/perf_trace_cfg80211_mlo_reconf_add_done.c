__int64 __fastcall perf_trace_cfg80211_mlo_reconf_add_done(
        __int64 result,
        __int64 a2,
        __int16 a3,
        const void *a4,
        size_t a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v14; // w23
  _QWORD *v15; // x9
  __int64 v16; // x8
  __int64 v17; // x22
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v21; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    v14 = ((a5 + 47) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v20, &v19);
    if ( result )
    {
      v15 = (_QWORD *)v20[0];
      *(_QWORD *)(v20[0] + 232LL) = &v21;
      v15[31] = &v18;
      v15[32] = v6;
      v15[33] = 5;
      *(_DWORD *)(result + 32) = ((_DWORD)a5 << 16) | 0x24;
      v16 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v16;
      LODWORD(v15) = *(_DWORD *)(a2 + 224);
      *(_WORD *)(result + 28) = a3;
      v17 = result;
      *(_DWORD *)(result + 24) = (_DWORD)v15;
      memcpy((void *)(result + 36), a4, a5);
      result = perf_trace_run_bpf_submit(v17, v14, v19, v9, 1, v20[0], StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
