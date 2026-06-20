size_t __fastcall perf_trace_mhi_update_channel_state(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x25
  __int64 v11; // x8
  const char *v12; // x8
  const char *v13; // x24
  size_t result; // x0
  __int64 v15; // x28
  unsigned __int64 StatusReg; // x20
  int v17; // w26
  unsigned int v18; // w23
  __int64 v19; // x30
  _QWORD *v20; // x9
  unsigned int v21; // w10
  size_t v22; // x25
  __int64 v23; // x20
  __int64 v24; // x28
  size_t v25; // x27
  size_t v26; // x26
  __int64 v27; // x2
  __int64 v28; // x5
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v31; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 16);
  v32[0] = 0;
  v31 = 0;
  v12 = *(const char **)(v11 + 8);
  if ( v12 )
    v13 = v12;
  else
    v13 = "(null)";
  result = strlen(v13);
  v15 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v17 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v15) )
  {
    v18 = ((result + 44) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v18, v32, &v31);
    if ( result )
    {
      v19 = v7;
      v20 = (_QWORD *)v32[0];
      v21 = (v17 << 16) + 65568;
      *(_QWORD *)(v32[0] + 248LL) = &v30;
      v22 = result + 32;
      v20[29] = &vars0;
      v30 = StatusReg;
      v23 = v15;
      v24 = a5;
      v25 = result;
      v26 = HIWORD(v21) - 1LL;
      v20[32] = v19;
      v20[33] = 5;
      *(_DWORD *)(result + 8) = v21;
      memcpy((void *)(result + 32), v13, v26);
      *(_BYTE *)(v22 + v26) = 0;
      v27 = v31;
      v28 = v32[0];
      *(_DWORD *)(v25 + 12) = *(_DWORD *)(a3 + 200);
      *(_DWORD *)(v25 + 16) = a4;
      v29 = v30;
      *(_QWORD *)(v25 + 24) = v24;
      result = perf_trace_run_bpf_submit(v25, v18, v27, a1, 1, v28, v29 + v23, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
