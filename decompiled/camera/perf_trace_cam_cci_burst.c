size_t __fastcall perf_trace_cam_cci_burst(__int64 a1, int a2, int a3, int a4, const char *a5, int a6)
{
  __int64 v6; // x30
  __int64 v8; // x25
  const char *v12; // x23
  size_t result; // x0
  __int64 v14; // x27
  unsigned __int64 StatusReg; // x28
  int v16; // w26
  int v17; // w20
  _QWORD *v18; // x9
  size_t v19; // x24
  unsigned int v20; // w10
  size_t v21; // x21
  size_t v22; // x22
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  int v26; // [xsp+8h] [xbp-18h]
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v26 = a6;
  v8 = v6;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 )
    v12 = a5;
  else
    v12 = "(null)";
  v28[0] = 0;
  v27 = 0;
  result = strlen(v12);
  v14 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v16 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    v17 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 36, v28, &v27);
    if ( result )
    {
      v18 = (_QWORD *)v28[0];
      *(_QWORD *)(v28[0] + 248LL) = &v25;
      v18[29] = &vars0;
      v18[32] = v8;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 12) = a3;
      v19 = result;
      v20 = (v16 << 16) + 65564;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = v20;
      v21 = result + 28;
      v22 = HIWORD(v20) - 1LL;
      memcpy((void *)(result + 28), v12, v22);
      *(_BYTE *)(v21 + v22) = 0;
      v23 = v27;
      v24 = v28[0];
      *(_DWORD *)(v19 + 24) = v26;
      result = perf_trace_run_bpf_submit(v19, (unsigned int)(v17 + 36), v23, a1, 1, v24, StatusReg + v14, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
