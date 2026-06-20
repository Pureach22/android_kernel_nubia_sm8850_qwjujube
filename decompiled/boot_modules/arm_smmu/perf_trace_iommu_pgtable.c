size_t __fastcall perf_trace_iommu_pgtable(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x24
  const char **v10; // x23
  const char *v11; // x26
  const char *v12; // x8
  const char *v13; // x0
  size_t result; // x0
  int v15; // w25
  __int64 v16; // x27
  unsigned __int64 StatusReg; // x28
  unsigned int v18; // w23
  __int64 v19; // x30
  _QWORD *v20; // x9
  size_t v21; // x24
  const char *v22; // x1
  _QWORD *v23; // x26
  unsigned int v24; // w10
  size_t v25; // x25
  __int64 v26; // x8
  __int64 v27; // x2
  __int64 v28; // x5
  __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v30; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v29 = a5;
  v6 = v5;
  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(const char ***)(a2 + 8);
  v31[0] = 0;
  v11 = v10[14];
  v12 = v11;
  if ( !v11 )
    v12 = *v10;
  if ( v12 )
    v13 = v12;
  else
    v13 = "(null)";
  v30 = 0;
  result = strlen(v13);
  v15 = result;
  if ( !v11 )
    v11 = *v10;
  v16 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v16) )
  {
    v18 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v18, v31, &v30);
    if ( result )
    {
      v19 = v6;
      v20 = (_QWORD *)v31[0];
      *(_QWORD *)(v31[0] + 248LL) = &v29;
      v21 = result + 40;
      if ( v11 )
        v22 = v11;
      else
        v22 = "(null)";
      v20[29] = &vars0;
      v23 = (_QWORD *)result;
      v20[32] = v19;
      v20[33] = 5;
      v24 = (v15 << 16) + 65576;
      *(_DWORD *)(result + 8) = v24;
      v25 = HIWORD(v24) - 1LL;
      memcpy((void *)(result + 40), v22, v25);
      *(_BYTE *)(v21 + v25) = 0;
      v26 = v29;
      v27 = v30;
      v28 = v31[0];
      v23[2] = a3;
      v23[3] = a4;
      v23[4] = v26;
      result = perf_trace_run_bpf_submit(v23, v18, v27, a1, 1, v28, StatusReg + v16, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
