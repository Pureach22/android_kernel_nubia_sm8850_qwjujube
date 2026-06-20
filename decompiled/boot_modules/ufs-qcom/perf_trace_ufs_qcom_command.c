size_t __fastcall perf_trace_ufs_qcom_command(__int64 a1, const char *a2, int a3, char a4, int a5, int a6, int a7)
{
  __int64 v7; // x30
  __int64 v9; // x27
  const char *v14; // x26
  size_t result; // x0
  __int64 v17; // x25
  int v18; // w28
  __int64 v19; // x30
  _QWORD *v20; // x9
  unsigned int v21; // w10
  size_t v22; // x27
  int v23; // w25
  size_t v24; // x20
  size_t v25; // x28
  __int64 v26; // x2
  _QWORD *v27; // x5
  __int64 v28; // x1
  __int64 v29; // x6
  __int64 v30; // [xsp+0h] [xbp-30h] BYREF
  unsigned int v31; // [xsp+Ch] [xbp-24h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-20h]
  unsigned int v33; // [xsp+1Ch] [xbp-14h]
  _QWORD *v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v9 = v7;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v14 = a2;
  else
    v14 = "(null)";
  v34 = nullptr;
  v33 = 0;
  result = strlen(v14);
  v17 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v18 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v17) )
  {
    v31 = ((result + 44) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc();
    if ( result )
    {
      v19 = v9;
      v20 = v34;
      v21 = (v18 << 16) + 65568;
      v34[31] = &v30;
      v22 = result + 32;
      v20[29] = &vars0;
      v30 = v17;
      v23 = a7;
      v24 = result;
      v25 = HIWORD(v21) - 1LL;
      v20[32] = v19;
      v20[33] = 5;
      *(_DWORD *)(result + 8) = v21;
      memcpy((void *)(result + 32), v14, v25);
      *(_BYTE *)(v22 + v25) = 0;
      v26 = v33;
      v27 = v34;
      v28 = v31;
      v29 = StatusReg + v30;
      *(_DWORD *)(v24 + 12) = a3;
      *(_BYTE *)(v24 + 16) = a4;
      *(_DWORD *)(v24 + 20) = a5;
      *(_DWORD *)(v24 + 24) = a6;
      *(_DWORD *)(v24 + 28) = v23;
      result = perf_trace_run_bpf_submit(v24, v28, v26, a1, 1, v27, v29, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
