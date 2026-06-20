size_t __fastcall perf_trace_kgsl_waittimestamp_exit(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x30
  __int64 v6; // x23
  const char *v9; // x8
  const char *v10; // x22
  size_t result; // x0
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  int v14; // w24
  int v15; // w28
  __int64 v16; // x30
  _QWORD *v17; // x9
  unsigned int v18; // w10
  size_t v19; // x23
  size_t v20; // x25
  size_t v21; // x24
  __int64 v22; // x2
  __int64 v23; // x5
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(const char **)(a2 + 8);
  v26[0] = 0;
  v25 = 0;
  if ( v9 )
    v10 = v9;
  else
    v10 = "(null)";
  result = strlen(v10);
  v12 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v14 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    v15 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 28, v26, &v25);
    if ( result )
    {
      v16 = v6;
      v17 = (_QWORD *)v26[0];
      v18 = (v14 << 16) + 65556;
      *(_QWORD *)(v26[0] + 248LL) = &v24;
      v19 = result + 20;
      v17[29] = &vars0;
      v20 = result;
      v21 = HIWORD(v18) - 1LL;
      v17[32] = v16;
      v17[33] = 5;
      *(_DWORD *)(result + 8) = v18;
      memcpy((void *)(result + 20), v10, v21);
      *(_BYTE *)(v19 + v21) = 0;
      v22 = v25;
      v23 = v26[0];
      *(_DWORD *)(v20 + 12) = a3;
      *(_DWORD *)(v20 + 16) = a4;
      result = perf_trace_run_bpf_submit(v20, (unsigned int)(v15 + 28), v22, a1, 1, v23, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
