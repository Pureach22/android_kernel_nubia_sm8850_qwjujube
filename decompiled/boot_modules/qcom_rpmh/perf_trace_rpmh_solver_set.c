size_t __fastcall perf_trace_rpmh_solver_set(__int64 a1, const char *a2, char a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  const char *v7; // x21
  size_t result; // x0
  __int64 v9; // x25
  unsigned __int64 StatusReg; // x26
  int v11; // w24
  unsigned int v12; // w22
  __int64 v13; // x30
  _QWORD *v14; // x9
  unsigned int v15; // w10
  char v16; // w27
  size_t v17; // x20
  size_t v18; // x24
  size_t v19; // x23
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v7 = a2;
  else
    v7 = "(null)";
  v24[0] = 0;
  v23 = 0;
  result = strlen(v7);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = ((result + 28) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v12, v24, &v23);
    if ( result )
    {
      v13 = v5;
      v14 = (_QWORD *)v24[0];
      v15 = (v11 << 16) + 65549;
      *(_QWORD *)(v24[0] + 248LL) = &v22;
      v16 = a3 & 1;
      v17 = result + 13;
      v14[29] = &v25;
      v18 = result;
      v19 = HIWORD(v15) - 1LL;
      v14[32] = v13;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = v15;
      memcpy((void *)(result + 13), v7, v19);
      *(_BYTE *)(v17 + v19) = 0;
      v20 = v23;
      v21 = v24[0];
      *(_BYTE *)(v18 + 12) = v16;
      result = perf_trace_run_bpf_submit(v18, v12, v20, a1, 1, v21, StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
