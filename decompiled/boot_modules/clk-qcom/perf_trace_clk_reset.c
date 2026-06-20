size_t __fastcall perf_trace_clk_reset(__int64 a1, int **a2, __int64 a3, char a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  const char **v10; // x23
  const char *v11; // x26
  const char *v12; // x8
  const char *v13; // x0
  size_t result; // x0
  int v15; // w25
  __int64 v16; // x27
  unsigned __int64 StatusReg; // x28
  unsigned int v18; // w23
  _QWORD *v19; // x9
  char v20; // w27
  size_t v21; // x22
  unsigned int v22; // w10
  size_t v23; // x25
  void *v24; // x0
  __int64 v25; // x24
  const char *v26; // x1
  __int64 v27; // x2
  __int64 v28; // x5
  int v29; // w8
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v31; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (const char **)a2[14];
  v32[0] = 0;
  v11 = v10[14];
  v12 = v11;
  if ( !v11 )
    v12 = *v10;
  if ( v12 )
    v13 = v12;
  else
    v13 = "(null)";
  v31 = 0;
  result = strlen(v13);
  v15 = result;
  if ( !v11 )
    v11 = *v10;
  v16 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    v18 = ((result + 44) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v18, v32, &v31);
    if ( result )
    {
      v19 = (_QWORD *)v32[0];
      v30 = v16;
      *(_QWORD *)(v32[0] + 248LL) = &v30;
      v20 = a4 & 1;
      v21 = result + 25;
      v19[29] = &vars0;
      v19[32] = v5;
      v19[33] = 5;
      v22 = (v15 << 16) + 65561;
      v23 = result;
      *(_DWORD *)(result + 8) = v22;
      v24 = (void *)(result + 25);
      v25 = HIWORD(v22) - 1LL;
      if ( v11 )
        v26 = v11;
      else
        v26 = "(null)";
      memcpy(v24, v26, HIWORD(v22) - 1LL);
      *(_BYTE *)(v21 + v25) = 0;
      v27 = v31;
      v28 = v32[0];
      v29 = **a2;
      *(_QWORD *)(v23 + 16) = a3;
      *(_BYTE *)(v23 + 24) = v20;
      *(_DWORD *)(v23 + 12) = v29;
      result = perf_trace_run_bpf_submit(v23, v18, v27, a1, 1, v28, StatusReg + v30, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
