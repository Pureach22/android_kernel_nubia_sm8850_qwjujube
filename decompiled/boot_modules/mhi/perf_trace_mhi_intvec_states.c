size_t __fastcall perf_trace_mhi_intvec_states(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x30
  __int64 v6; // x24
  __int64 v10; // x8
  const char *v11; // x8
  const char *v12; // x23
  size_t result; // x0
  __int64 v14; // x27
  unsigned __int64 StatusReg; // x28
  int v16; // w25
  int v17; // w20
  __int64 v18; // x30
  _QWORD *v19; // x9
  unsigned int v20; // w10
  size_t v21; // x24
  int v22; // w27
  _DWORD *v23; // x26
  size_t v24; // x25
  __int64 v25; // x2
  __int64 v26; // x5
  int v27; // w8
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v29; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 16);
  v30[0] = 0;
  v29 = 0;
  v11 = *(const char **)(v10 + 8);
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
    v17 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 36, v30, &v29);
    if ( result )
    {
      v18 = v6;
      v19 = (_QWORD *)v30[0];
      v20 = (v16 << 16) + 65564;
      *(_QWORD *)(v30[0] + 248LL) = &v28;
      v21 = result + 28;
      v19[29] = &vars0;
      v28 = v14;
      v22 = a4;
      v23 = (_DWORD *)result;
      v24 = HIWORD(v20) - 1LL;
      v19[32] = v18;
      v19[33] = 5;
      *(_DWORD *)(result + 8) = v20;
      memcpy((void *)(result + 28), v12, v24);
      *(_BYTE *)(v21 + v24) = 0;
      v25 = v29;
      v26 = v30[0];
      v23[3] = *(_DWORD *)(a2 + 344);
      v27 = *(_DWORD *)(a2 + 348);
      v23[6] = v22;
      v23[4] = v27;
      v23[5] = a3;
      result = perf_trace_run_bpf_submit(v23, (unsigned int)(v17 + 36), v25, a1, 1, v26, StatusReg + v28, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
