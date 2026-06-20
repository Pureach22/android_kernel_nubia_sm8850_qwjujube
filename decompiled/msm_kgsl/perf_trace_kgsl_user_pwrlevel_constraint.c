size_t __fastcall perf_trace_kgsl_user_pwrlevel_constraint(__int64 a1, __int64 a2, int a3, int a4, int a5)
{
  __int64 v5; // x30
  __int64 v7; // x25
  const char *v11; // x8
  const char *v12; // x24
  size_t result; // x0
  __int64 v14; // x28
  unsigned __int64 StatusReg; // x20
  int v16; // w26
  unsigned int v17; // w23
  __int64 v18; // x30
  _QWORD *v19; // x9
  unsigned int v20; // w10
  size_t v21; // x25
  __int64 v22; // x20
  int v23; // w28
  _DWORD *v24; // x27
  size_t v25; // x26
  __int64 v26; // x2
  __int64 v27; // x5
  __int64 v28; // x6
  unsigned __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(const char **)(a2 + 8);
  v31[0] = 0;
  v30 = 0;
  if ( v11 )
    v12 = v11;
  else
    v12 = "(null)";
  result = strlen(v12);
  v14 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v16 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    v17 = ((result + 36) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v17, v31, &v30);
    if ( result )
    {
      v18 = v7;
      v19 = (_QWORD *)v31[0];
      v20 = (v16 << 16) + 65560;
      *(_QWORD *)(v31[0] + 248LL) = &v29;
      v21 = result + 24;
      v19[29] = &vars0;
      v29 = StatusReg;
      v22 = v14;
      v23 = a5;
      v24 = (_DWORD *)result;
      v25 = HIWORD(v20) - 1LL;
      v19[32] = v18;
      v19[33] = 5;
      *(_DWORD *)(result + 8) = v20;
      memcpy((void *)(result + 24), v12, v25);
      *(_BYTE *)(v21 + v25) = 0;
      v26 = v30;
      v27 = v31[0];
      v28 = v29 + v22;
      v24[3] = a3;
      v24[4] = a4;
      v24[5] = v23;
      result = perf_trace_run_bpf_submit(v24, v17, v26, a1, 1, v27, v28, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
