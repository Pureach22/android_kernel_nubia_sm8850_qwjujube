size_t __fastcall perf_trace_cam_context_state(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  const char *v7; // x21
  size_t result; // x0
  __int64 v9; // x25
  unsigned __int64 StatusReg; // x26
  int v11; // w24
  unsigned int v12; // w22
  _QWORD *v13; // x9
  unsigned int v14; // w10
  size_t v15; // x24
  int v16; // w8
  size_t v17; // x20
  size_t v18; // x23
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v7 = a2;
  else
    v7 = "(null)";
  v21[0] = 0;
  v20 = 0;
  result = strlen(v7);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = ((result + 36) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v12, v21, &v20);
    if ( result )
    {
      v13 = (_QWORD *)v21[0];
      *(_QWORD *)(v21[0] + 232LL) = &vars0;
      v13[31] = &v19;
      v13[32] = v5;
      v13[33] = 5;
      *(_QWORD *)(result + 8) = a3;
      v14 = (v11 << 16) + 65560;
      v15 = result;
      *(_DWORD *)(result + 20) = v14;
      v16 = *(_DWORD *)(a3 + 240);
      v17 = result + 24;
      v18 = HIWORD(v14) - 1LL;
      *(_DWORD *)(result + 16) = v16;
      memcpy((void *)(result + 24), v7, v18);
      *(_BYTE *)(v17 + v18) = 0;
      result = perf_trace_run_bpf_submit(v15, v12, v20, a1, 1, v21[0], StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
