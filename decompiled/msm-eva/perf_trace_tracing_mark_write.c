size_t __fastcall perf_trace_tracing_mark_write(__int64 a1, char a2, __int64 a3, const char *a4, int a5)
{
  __int64 v5; // x30
  __int64 v7; // x25
  const char *v11; // x21
  size_t result; // x0
  __int64 v13; // x27
  unsigned __int64 StatusReg; // x28
  int v15; // w26
  unsigned int v16; // w22
  _QWORD *v17; // x10
  unsigned int v18; // w8
  int v19; // w9
  size_t v20; // x23
  size_t v21; // x25
  size_t v22; // x24
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 )
    v11 = a4;
  else
    v11 = "(null)";
  v27[0] = 0;
  v26 = 0;
  result = strlen(v11);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v16 = ((result + 36) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v16, v27, &v26);
    if ( result )
    {
      v17 = (_QWORD *)v27[0];
      *(_QWORD *)(v27[0] + 232LL) = &vars0;
      v17[31] = &v25;
      v17[32] = v7;
      v17[33] = 5;
      v18 = (v15 << 16) + 65560;
      *(_BYTE *)(result + 8) = a2;
      *(_DWORD *)(result + 16) = v18;
      if ( a3 )
        v19 = *(_DWORD *)(a3 + 1804);
      else
        v19 = 0;
      v20 = result + 24;
      *(_DWORD *)(result + 12) = v19;
      v21 = result;
      v22 = HIWORD(v18) - 1LL;
      memcpy((void *)(result + 24), v11, v22);
      *(_BYTE *)(v20 + v22) = 0;
      v23 = v26;
      v24 = v27[0];
      *(_DWORD *)(v21 + 20) = a5;
      result = perf_trace_run_bpf_submit(v21, v16, v23, a1, 1, v24, StatusReg + v13, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
