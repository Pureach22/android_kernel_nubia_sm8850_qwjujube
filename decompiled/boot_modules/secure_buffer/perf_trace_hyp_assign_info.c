__int64 __fastcall perf_trace_hyp_assign_info(__int64 result, const void *a2, int a3, void *a4, void *a5, int a6)
{
  __int64 v6; // x30
  __int64 v7; // x26
  __int64 v9; // x19
  __int64 v12; // x27
  unsigned __int64 StatusReg; // x28
  int v14; // w20
  int v15; // w21
  unsigned int v16; // w23
  _QWORD *v17; // x9
  size_t v18; // x2
  int v19; // w10
  __int64 v20; // x24
  size_t v21; // x22
  __int64 v22; // [xsp+0h] [xbp-30h] BYREF
  void *src; // [xsp+8h] [xbp-28h]
  void *v24; // [xsp+10h] [xbp-20h]
  unsigned int v25; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  src = a4;
  v24 = a5;
  v7 = v6;
  v9 = result;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v25 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    v14 = 4 * a3;
    v15 = 4 * a6 + 4 * a3;
    v16 = ((4 * a6 + v15 + 39) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v16, v26, &v25);
    if ( result )
    {
      v17 = (_QWORD *)v26[0];
      *(_QWORD *)(v26[0] + 248LL) = &v22;
      v18 = 4LL * a3;
      v17[29] = &vars0;
      v17[32] = v7;
      v17[33] = 5;
      v19 = (a3 << 18) | 0x1C;
      *(_DWORD *)(result + 8) = a3;
      *(_DWORD *)(result + 12) = a6;
      *(_DWORD *)(result + 24) = (v15 + 28) | (a6 << 18);
      v20 = result;
      *(_DWORD *)(result + 16) = v19;
      *(_DWORD *)(result + 20) = (a6 << 18) | (v14 + 28);
      memcpy((void *)(result + (unsigned __int16)v19), a2, v18);
      v21 = 4LL * a6;
      memcpy((void *)(v20 + *(unsigned __int16 *)(v20 + 20)), src, v21);
      memcpy((void *)(v20 + *(unsigned __int16 *)(v20 + 24)), v24, v21);
      result = perf_trace_run_bpf_submit(v20, v16, v25, v9, 1, v26[0], StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
