size_t __fastcall perf_trace_kgsl_gen7_irq_status(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  const char *v7; // x8
  const char *v8; // x21
  size_t result; // x0
  __int64 v10; // x26
  unsigned __int64 StatusReg; // x27
  int v12; // w24
  unsigned int v13; // w22
  __int64 v14; // x30
  _QWORD *v15; // x9
  unsigned int v16; // w10
  size_t v17; // x23
  size_t v18; // x25
  size_t v19; // x24
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(const char **)(a2 + 8);
  v24[0] = 0;
  v23 = 0;
  if ( v7 )
    v8 = v7;
  else
    v8 = "(null)";
  result = strlen(v8);
  v10 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v12 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    v13 = ((result + 28) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v13, v24, &v23);
    if ( result )
    {
      v14 = v5;
      v15 = (_QWORD *)v24[0];
      v16 = (v12 << 16) + 65552;
      *(_QWORD *)(v24[0] + 248LL) = &v22;
      v17 = result + 16;
      v15[29] = &v25;
      v18 = result;
      v19 = HIWORD(v16) - 1LL;
      v15[32] = v14;
      v15[33] = 5;
      *(_DWORD *)(result + 8) = v16;
      memcpy((void *)(result + 16), v8, v19);
      *(_BYTE *)(v17 + v19) = 0;
      v20 = v23;
      v21 = v24[0];
      *(_DWORD *)(v18 + 12) = a3;
      result = perf_trace_run_bpf_submit(v18, v13, v20, a1, 1, v21, StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
