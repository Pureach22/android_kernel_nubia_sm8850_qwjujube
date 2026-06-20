size_t __fastcall perf_trace_kgsl_pwr_template(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  const char *v7; // x8
  const char *v8; // x21
  size_t result; // x0
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  int v12; // w24
  unsigned int v13; // w22
  __int64 v14; // x30
  _QWORD *v15; // x9
  unsigned int v16; // w10
  char v17; // w27
  size_t v18; // x20
  size_t v19; // x24
  size_t v20; // x23
  __int64 v21; // x2
  __int64 v22; // x5
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v26; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(const char **)(a2 + 8);
  v25[0] = 0;
  v24 = 0;
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
    result = perf_trace_buf_alloc(v13, v25, &v24);
    if ( result )
    {
      v14 = v5;
      v15 = (_QWORD *)v25[0];
      v16 = (v12 << 16) + 65549;
      *(_QWORD *)(v25[0] + 248LL) = &v23;
      v17 = a3 & 1;
      v18 = result + 13;
      v15[29] = &v26;
      v19 = result;
      v20 = HIWORD(v16) - 1LL;
      v15[32] = v14;
      v15[33] = 5;
      *(_DWORD *)(result + 8) = v16;
      memcpy((void *)(result + 13), v8, v20);
      *(_BYTE *)(v18 + v20) = 0;
      v21 = v24;
      v22 = v25[0];
      *(_BYTE *)(v19 + 12) = v17;
      result = perf_trace_run_bpf_submit(v19, v13, v21, a1, 1, v22, StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
