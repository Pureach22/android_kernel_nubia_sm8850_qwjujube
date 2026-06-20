size_t __fastcall perf_trace_qcom_dcvs_update(
        __int64 a1,
        const char *a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // x30
  __int64 v11; // x28
  const char *v15; // x27
  size_t result; // x0
  __int64 v19; // x26
  int v20; // w20
  _QWORD *v21; // x9
  unsigned int v22; // w10
  size_t v23; // x20
  __int64 v24; // x26
  size_t v25; // x21
  size_t v26; // x28
  __int64 v27; // x1
  int v28; // w8
  __int64 v29; // x2
  _QWORD *v30; // x5
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // [xsp+0h] [xbp-40h] BYREF
  __int64 v34; // [xsp+8h] [xbp-38h]
  __int64 v35; // [xsp+10h] [xbp-30h]
  unsigned int v36; // [xsp+18h] [xbp-28h]
  int v37; // [xsp+1Ch] [xbp-24h]
  unsigned __int64 StatusReg; // [xsp+20h] [xbp-20h]
  unsigned int v39; // [xsp+2Ch] [xbp-14h]
  _QWORD *v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v37 = a3;
  v11 = v9;
  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v15 = a2;
  else
    v15 = "(null)";
  v40 = nullptr;
  v39 = 0;
  result = strlen(v15);
  v19 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v20 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v19) )
  {
    v36 = ((result + 76) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc();
    if ( result )
    {
      v21 = v40;
      v22 = (v20 << 16) + 65600;
      v23 = result + 64;
      v40[31] = &v33;
      v21[29] = &vars0;
      v34 = a9;
      v35 = v19;
      v24 = a8;
      v25 = result;
      v21[32] = v11;
      v21[33] = 5;
      *(_DWORD *)(result + 8) = v22;
      v26 = HIWORD(v22) - 1LL;
      memcpy((void *)(result + 64), v15, v26);
      v27 = v36;
      v28 = v37;
      *(_BYTE *)(v23 + v26) = 0;
      v29 = v39;
      v30 = v40;
      *(_DWORD *)(v25 + 12) = v28;
      *(_DWORD *)(v25 + 16) = a4;
      v31 = v34;
      v32 = v35;
      *(_QWORD *)(v25 + 24) = a5;
      *(_QWORD *)(v25 + 32) = a6;
      *(_QWORD *)(v25 + 40) = a7;
      *(_QWORD *)(v25 + 48) = v24;
      *(_QWORD *)(v25 + 56) = v31;
      result = perf_trace_run_bpf_submit(v25, v27, v29, a1, 1, v30, StatusReg + v32, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
