size_t __fastcall perf_trace_kgsl_clk(__int64 a1, __int64 a2, char a3, int a4)
{
  __int64 v4; // x30
  __int64 v6; // x23
  const char *v9; // x8
  const char *v10; // x22
  size_t result; // x0
  __int64 v12; // x25
  unsigned __int64 StatusReg; // x26
  int v14; // w24
  int v15; // w27
  __int64 v16; // x30
  _QWORD *v17; // x9
  unsigned int v18; // w10
  char v19; // w28
  size_t v20; // x21
  size_t v21; // x24
  size_t v22; // x23
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(const char **)(a2 + 8);
  v27[0] = 0;
  v26 = 0;
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
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 28, v27, &v26);
    if ( result )
    {
      v16 = v6;
      v17 = (_QWORD *)v27[0];
      v18 = (v14 << 16) + 65556;
      *(_QWORD *)(v27[0] + 248LL) = &v25;
      v19 = a3 & 1;
      v20 = result + 20;
      v17[29] = &vars0;
      v21 = result;
      v22 = HIWORD(v18) - 1LL;
      v17[32] = v16;
      v17[33] = 5;
      *(_DWORD *)(result + 8) = v18;
      memcpy((void *)(result + 20), v10, v22);
      *(_BYTE *)(v20 + v22) = 0;
      v23 = v26;
      v24 = v27[0];
      *(_BYTE *)(v21 + 12) = v19;
      *(_DWORD *)(v21 + 16) = a4;
      result = perf_trace_run_bpf_submit(v21, (unsigned int)(v15 + 28), v23, a1, 1, v24, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
