size_t __fastcall perf_trace_mhi_tryset_pm_state(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  __int64 v7; // x8
  const char *v8; // x8
  const char *v9; // x22
  size_t result; // x0
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  int v13; // w24
  unsigned int v14; // w21
  __int64 v15; // x30
  _QWORD *v16; // x9
  unsigned int v17; // w10
  size_t v18; // x23
  size_t v19; // x25
  size_t v20; // x24
  __int64 v21; // x2
  __int64 v22; // x5
  int v23; // w8
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v27; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 16);
  v26[0] = 0;
  v25 = 0;
  v8 = *(const char **)(v7 + 8);
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
    v14 = ((result + 28) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v26, &v25);
    if ( result )
    {
      v15 = v5;
      v16 = (_QWORD *)v26[0];
      v17 = (v13 << 16) + 65552;
      *(_QWORD *)(v26[0] + 248LL) = &v24;
      v18 = result + 16;
      v16[29] = &v27;
      v19 = result;
      v20 = HIWORD(v17) - 1LL;
      v16[32] = v15;
      v16[33] = 5;
      *(_DWORD *)(result + 8) = v17;
      memcpy((void *)(result + 16), v9, v20);
      *(_BYTE *)(v18 + v20) = 0;
      v21 = v25;
      v22 = v26[0];
      v23 = 63 - __clz(a3);
      if ( !a3 )
        v23 = 0;
      *(_DWORD *)(v19 + 12) = v23;
      result = perf_trace_run_bpf_submit(v19, v14, v21, a1, 1, v22, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
