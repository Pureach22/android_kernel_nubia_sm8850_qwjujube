size_t __fastcall perf_trace_kgsl_active_count(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x24
  const char *v8; // x8
  const char *v9; // x23
  size_t result; // x0
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x28
  int v13; // w25
  unsigned int v14; // w22
  __int64 v15; // x30
  _QWORD *v16; // x9
  unsigned int v17; // w10
  size_t v18; // x24
  size_t v19; // x26
  size_t v20; // x25
  __int64 v21; // x2
  __int64 v22; // x5
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(const char **)(a2 + 8);
  v25[0] = 0;
  v24 = 0;
  if ( v8 )
    v9 = v8;
  else
    v9 = "(null)";
  result = strlen(v9);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = ((result + 36) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v25, &v24);
    if ( result )
    {
      v15 = v5;
      v16 = (_QWORD *)v25[0];
      v17 = (v13 << 16) + 65560;
      *(_QWORD *)(v25[0] + 248LL) = &v23;
      v18 = result + 24;
      v16[29] = &vars0;
      v19 = result;
      v20 = HIWORD(v17) - 1LL;
      v16[32] = v15;
      v16[33] = 5;
      *(_DWORD *)(result + 8) = v17;
      memcpy((void *)(result + 24), v9, v20);
      *(_BYTE *)(v18 + v20) = 0;
      v21 = v24;
      v22 = v25[0];
      *(_DWORD *)(v19 + 12) = *(_DWORD *)(a2 + 11128);
      *(_QWORD *)(v19 + 16) = a3;
      result = perf_trace_run_bpf_submit(v19, v14, v21, a1, 1, v22, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
