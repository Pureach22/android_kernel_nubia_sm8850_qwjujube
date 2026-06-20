size_t __fastcall perf_trace_cam_notify_frame_skip(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  const char *v7; // x21
  size_t result; // x0
  __int64 v9; // x26
  unsigned __int64 StatusReg; // x27
  int v11; // w24
  unsigned int v12; // w22
  __int64 v13; // x30
  _QWORD *v14; // x9
  unsigned int v15; // w10
  size_t v16; // x23
  size_t v17; // x25
  size_t v18; // x24
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v24; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v7 = a2;
  else
    v7 = "(null)";
  v23[0] = 0;
  v22 = 0;
  result = strlen(v7);
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = ((result + 36) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v12, v23, &v22);
    if ( result )
    {
      v13 = v5;
      v14 = (_QWORD *)v23[0];
      v15 = (v11 << 16) + 65560;
      *(_QWORD *)(v23[0] + 248LL) = &v21;
      v16 = result + 24;
      v14[29] = &v24;
      v17 = result;
      v18 = HIWORD(v15) - 1LL;
      v14[32] = v13;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = v15;
      memcpy((void *)(result + 24), v7, v18);
      *(_BYTE *)(v16 + v18) = 0;
      v19 = v22;
      v20 = v23[0];
      *(_QWORD *)(v17 + 16) = a3;
      result = perf_trace_run_bpf_submit(v17, v12, v19, a1, 1, v20, StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
