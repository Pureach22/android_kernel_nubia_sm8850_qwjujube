size_t __fastcall perf_trace_tlbsync_timeout(__int64 a1, const char **a2)
{
  __int64 v2; // x30
  __int64 v3; // x20
  const char *v6; // x23
  const char *v7; // x8
  const char *v8; // x0
  size_t result; // x0
  int v10; // w21
  __int64 v11; // x24
  unsigned __int64 StatusReg; // x25
  int v13; // w27
  __int64 v14; // x30
  _QWORD *v15; // x9
  size_t v16; // x20
  const char *v17; // x1
  size_t v18; // x22
  unsigned int v19; // w10
  size_t v20; // x21
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v24; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a2[14];
  v7 = v6;
  if ( !v6 )
    v7 = *a2;
  if ( v7 )
    v8 = v7;
  else
    v8 = "(null)";
  v23[0] = 0;
  v22 = 0;
  result = strlen(v8);
  v10 = result;
  if ( !v6 )
    v6 = *a2;
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v13 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 20, v23, &v22);
    if ( result )
    {
      v14 = v3;
      v15 = (_QWORD *)v23[0];
      *(_QWORD *)(v23[0] + 248LL) = &v21;
      v16 = result + 12;
      if ( v6 )
        v17 = v6;
      else
        v17 = "(null)";
      v15[29] = &v24;
      v18 = result;
      v15[32] = v14;
      v15[33] = 5;
      v19 = (v10 << 16) + 65548;
      *(_DWORD *)(result + 8) = v19;
      v20 = HIWORD(v19) - 1LL;
      memcpy((void *)(result + 12), v17, v20);
      *(_BYTE *)(v16 + v20) = 0;
      result = perf_trace_run_bpf_submit(v18, (unsigned int)(v13 + 20), v22, a1, 1, v23[0], StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
