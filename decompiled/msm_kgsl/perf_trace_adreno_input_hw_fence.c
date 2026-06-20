size_t __fastcall perf_trace_adreno_input_hw_fence(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        const char *a6)
{
  __int64 v6; // x30
  __int64 v8; // x26
  const char *v12; // x23
  size_t result; // x0
  __int64 v14; // x28
  unsigned __int64 StatusReg; // x25
  int v16; // w27
  unsigned int v17; // w24
  _QWORD *v18; // x9
  size_t v19; // x21
  unsigned int v20; // w10
  size_t v21; // x20
  size_t v22; // x22
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v23 = a5;
  v8 = v6;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a6 )
    v12 = a6;
  else
    v12 = "(null)";
  v25[0] = 0;
  v24 = 0;
  result = strlen(v12);
  v14 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v16 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    v17 = ((result + 60) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v17, v25, &v24);
    if ( result )
    {
      v18 = (_QWORD *)v25[0];
      *(_QWORD *)(v25[0] + 248LL) = &v23;
      v18[29] = &vars0;
      v18[32] = v8;
      v18[33] = 5;
      *(_QWORD *)(result + 16) = a3;
      *(_QWORD *)(result + 24) = a4;
      v19 = result + 44;
      v20 = (v16 << 16) + 65580;
      *(_DWORD *)(result + 8) = a2;
      v21 = result;
      *(_DWORD *)(result + 40) = v20;
      v22 = HIWORD(v20) - 1LL;
      *(_QWORD *)(result + 32) = v23;
      memcpy((void *)(result + 44), v12, v22);
      *(_BYTE *)(v19 + v22) = 0;
      result = perf_trace_run_bpf_submit(v21, v17, v24, a1, 1, v25[0], StatusReg + v14, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
