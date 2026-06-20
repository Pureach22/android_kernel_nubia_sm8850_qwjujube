__int64 __fastcall perf_trace_hyp_assign_batch_start(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v8; // x24
  unsigned __int64 StatusReg; // x25
  unsigned int v10; // w20
  _QWORD *v11; // x10
  int v12; // w8
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 *v15; // x10
  __int64 v16; // x11
  __int64 v17; // t1
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v21; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    v10 = ((16 * a3 + 43) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v10, v20, &v19);
    if ( result )
    {
      v11 = (_QWORD *)v20[0];
      v12 = 8 * a3 + 32;
      *(_QWORD *)(v20[0] + 248LL) = &v18;
      v11[29] = &v21;
      v11[32] = v4;
      v11[33] = 5;
      *(_DWORD *)(result + 8) = a3;
      *(_QWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 24) = ((unsigned __int16)a3 << 19) | 0x20;
      *(_DWORD *)(result + 28) = v12 | (a3 << 19);
      if ( a3 )
      {
        v13 = (unsigned __int16)v12 & 0xFFF8;
        v14 = a3;
        v15 = (__int64 *)(a2 + 8);
        v16 = result;
        do
        {
          --v14;
          *(_QWORD *)(v16 + 32) = *(v15 - 1);
          v17 = *v15;
          v15 += 2;
          *(_QWORD *)(v16 + v13) = v17;
          v16 += 8;
          *(_QWORD *)(result + 16) += v17;
        }
        while ( v14 );
      }
      result = perf_trace_run_bpf_submit(result, v10, v19, v6, 1, v20[0], StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
