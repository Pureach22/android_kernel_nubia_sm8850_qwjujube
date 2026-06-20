size_t __fastcall perf_trace_ufs_qcom_clk_template(__int64 a1, const char *a2, int a3, char a4, int a5)
{
  __int64 v5; // x30
  __int64 v7; // x25
  const char *v11; // x24
  size_t result; // x0
  __int64 v13; // x27
  unsigned __int64 StatusReg; // x28
  int v15; // w26
  unsigned int v16; // w23
  __int64 v17; // x30
  _QWORD *v18; // x9
  unsigned int v19; // w10
  __int64 v20; // x28
  int v21; // w27
  char v22; // w20
  size_t v23; // x22
  size_t v24; // x26
  size_t v25; // x25
  __int64 v26; // x2
  __int64 v27; // x5
  __int64 v28; // x6
  unsigned __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v7 = v5;
  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v11 = a2;
  else
    v11 = "(null)";
  v31[0] = 0;
  v30 = 0;
  result = strlen(v11);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v16 = ((result + 36) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v16, v31, &v30);
    if ( result )
    {
      v17 = v7;
      v18 = (_QWORD *)v31[0];
      v19 = (v15 << 16) + 65560;
      *(_QWORD *)(v31[0] + 248LL) = &v29;
      v29 = StatusReg;
      v20 = v13;
      v21 = a5;
      v22 = a4 & 1;
      v23 = result + 24;
      v18[29] = &vars0;
      v24 = result;
      v25 = HIWORD(v19) - 1LL;
      v18[32] = v17;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = v19;
      memcpy((void *)(result + 24), v11, v25);
      *(_BYTE *)(v23 + v25) = 0;
      v26 = v30;
      v27 = v31[0];
      v28 = v29 + v20;
      *(_DWORD *)(v24 + 12) = a3;
      *(_BYTE *)(v24 + 16) = v22;
      *(_DWORD *)(v24 + 20) = v21;
      result = perf_trace_run_bpf_submit(v24, v16, v26, a1, 1, v27, v28, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
