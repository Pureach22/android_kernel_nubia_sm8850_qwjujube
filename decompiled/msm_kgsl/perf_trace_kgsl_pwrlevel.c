size_t __fastcall perf_trace_kgsl_pwrlevel(__int64 a1, __int64 a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  __int64 v7; // x30
  __int64 v9; // x27
  const char *v15; // x8
  const char *v16; // x26
  size_t result; // x0
  __int64 v18; // x25
  int v19; // w28
  __int64 v20; // x30
  _QWORD *v21; // x9
  unsigned int v22; // w10
  size_t v23; // x27
  __int64 v24; // x25
  size_t v25; // x20
  size_t v26; // x28
  __int64 v27; // x2
  __int64 v28; // x5
  __int64 v29; // x1
  __int64 v30; // x6
  __int64 v31; // [xsp+0h] [xbp-30h] BYREF
  unsigned int v32; // [xsp+Ch] [xbp-24h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-20h]
  unsigned int v34; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v35[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v9 = v7;
  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(const char **)(a2 + 8);
  v35[0] = 0;
  v34 = 0;
  if ( v15 )
    v16 = v15;
  else
    v16 = "(null)";
  result = strlen(v16);
  v18 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v19 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    v32 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v32, v35, &v34);
    if ( result )
    {
      v20 = v9;
      v21 = (_QWORD *)v35[0];
      v22 = (v19 << 16) + 65576;
      *(_QWORD *)(v35[0] + 248LL) = &v31;
      v23 = result + 40;
      v21[29] = &vars0;
      v31 = v18;
      v24 = a7;
      v25 = result;
      v26 = HIWORD(v22) - 1LL;
      v21[32] = v20;
      v21[33] = 5;
      *(_DWORD *)(result + 8) = v22;
      memcpy((void *)(result + 40), v16, v26);
      *(_BYTE *)(v23 + v26) = 0;
      v27 = v34;
      v28 = v35[0];
      v29 = v32;
      v30 = StatusReg + v31;
      *(_DWORD *)(v25 + 12) = a3;
      *(_DWORD *)(v25 + 16) = a4;
      *(_DWORD *)(v25 + 20) = a5;
      *(_DWORD *)(v25 + 24) = a6;
      *(_QWORD *)(v25 + 32) = v24;
      result = perf_trace_run_bpf_submit(v25, v29, v27, a1, 1, v28, v30, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
