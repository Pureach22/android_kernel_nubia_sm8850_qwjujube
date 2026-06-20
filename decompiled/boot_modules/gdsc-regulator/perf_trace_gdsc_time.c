size_t __fastcall perf_trace_gdsc_time(__int64 a1, const char *a2, int a3, int a4, int a5)
{
  __int64 v5; // x30
  __int64 v7; // x25
  const char *v11; // x24
  size_t result; // x0
  __int64 v13; // x28
  unsigned __int64 StatusReg; // x20
  int v15; // w26
  unsigned int v16; // w23
  __int64 v17; // x30
  _QWORD *v18; // x9
  unsigned int v19; // w10
  size_t v20; // x25
  __int64 v21; // x20
  int v22; // w28
  _DWORD *v23; // x27
  size_t v24; // x26
  __int64 v25; // x2
  __int64 v26; // x5
  __int64 v27; // x6
  unsigned __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v29; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v11 = a2;
  else
    v11 = "(null)";
  v30[0] = 0;
  v29 = 0;
  result = strlen(v11);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v16 = ((result + 36) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v16, v30, &v29);
    if ( result )
    {
      v17 = v7;
      v18 = (_QWORD *)v30[0];
      v19 = (v15 << 16) + 65560;
      *(_QWORD *)(v30[0] + 248LL) = &v28;
      v20 = result + 24;
      v18[29] = &vars0;
      v28 = StatusReg;
      v21 = v13;
      v22 = a5;
      v23 = (_DWORD *)result;
      v24 = HIWORD(v19) - 1LL;
      v18[32] = v17;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = v19;
      memcpy((void *)(result + 24), v11, v24);
      *(_BYTE *)(v20 + v24) = 0;
      v25 = v29;
      v26 = v30[0];
      v27 = v28 + v21;
      v23[3] = a3;
      v23[4] = a4;
      v23[5] = v22;
      result = perf_trace_run_bpf_submit(v23, v16, v25, a1, 1, v26, v27, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
