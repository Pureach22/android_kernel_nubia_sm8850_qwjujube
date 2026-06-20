_DWORD *__fastcall perf_trace_syncpoint_fence_template(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  const char *v7; // x21
  _DWORD *result; // x0
  __int64 v9; // x25
  unsigned __int64 StatusReg; // x26
  int v11; // w24
  unsigned int v12; // w22
  _QWORD *v13; // x9
  unsigned int v14; // w10
  _DWORD *v15; // x24
  __int64 v16; // x8
  _DWORD *v17; // x20
  size_t v18; // x23
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    v7 = a3;
  else
    v7 = "(null)";
  v21[0] = 0;
  v20 = 0;
  result = (_DWORD *)strlen(v7);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = (int)result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = (((_DWORD)result + 28) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v12, v21, &v20);
    if ( result )
    {
      v13 = (_QWORD *)v21[0];
      *(_QWORD *)(v21[0] + 232LL) = &vars0;
      v13[31] = &v19;
      v13[32] = v5;
      v13[33] = 5;
      v14 = (v11 << 16) + 65552;
      v15 = result;
      result[2] = v14;
      v16 = *(_QWORD *)(a2 + 8);
      v17 = result + 4;
      v18 = HIWORD(v14) - 1LL;
      result[3] = *(_DWORD *)(v16 + 4);
      memcpy(result + 4, v7, v18);
      *((_BYTE *)v17 + v18) = 0;
      result = (_DWORD *)perf_trace_run_bpf_submit(v15, v12, v20, a1, 1, v21[0], StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
