size_t __fastcall perf_trace_mhi_gen_tre(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v6; // x24
  __int64 v9; // x8
  const char *v10; // x8
  const char *v11; // x23
  size_t result; // x0
  __int64 v13; // x27
  unsigned __int64 StatusReg; // x28
  int v15; // w25
  unsigned int v16; // w22
  __int64 v17; // x30
  _QWORD *v18; // x9
  unsigned int v19; // w10
  size_t v20; // x24
  size_t v21; // x26
  size_t v22; // x25
  int v23; // w8
  __int64 v24; // x2
  __int64 v25; // x5
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a2 + 16);
  v28[0] = 0;
  v27 = 0;
  v10 = *(const char **)(v9 + 8);
  if ( v10 )
    v11 = v10;
  else
    v11 = "(null)";
  result = strlen(v11);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v16 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v16, v28, &v27);
    if ( result )
    {
      v17 = v6;
      v18 = (_QWORD *)v28[0];
      v19 = (v15 << 16) + 65576;
      *(_QWORD *)(v28[0] + 248LL) = &v26;
      v20 = result + 40;
      v18[29] = &vars0;
      v21 = result;
      v22 = HIWORD(v19) - 1LL;
      v18[32] = v17;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = v19;
      memcpy((void *)(result + 40), v11, v22);
      *(_BYTE *)(v20 + v22) = 0;
      v23 = *(_DWORD *)(a3 + 200);
      *(_QWORD *)(v21 + 16) = a4;
      v24 = v27;
      v25 = v28[0];
      *(_DWORD *)(v21 + 12) = v23;
      *(_QWORD *)(v21 + 24) = *(_QWORD *)a4;
      *(_DWORD *)(v21 + 32) = *(_DWORD *)(a4 + 8);
      *(_DWORD *)(v21 + 36) = *(_DWORD *)(a4 + 12);
      result = perf_trace_run_bpf_submit(v21, v16, v24, a1, 1, v25, StatusReg + v13, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
