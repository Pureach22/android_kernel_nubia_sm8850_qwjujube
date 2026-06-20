__int64 __fastcall perf_trace_lookup_sgl(__int64 result, unsigned int *a2, int a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  int v10; // w27
  __int64 v11; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v13; // w22
  _QWORD *v14; // x10
  int v15; // w9
  unsigned __int64 v16; // x8
  __int64 *v17; // x11
  __int64 v18; // t1
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v24; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v10 = *a2;
  v11 = *(_QWORD *)(result + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v13 = ((16 * v10 + 39) & 0xFFFFFFF0) - 4;
    result = perf_trace_buf_alloc(v13, v23, &v22);
    if ( result )
    {
      v14 = (_QWORD *)v23[0];
      *(_QWORD *)(v23[0] + 248LL) = &v21;
      v14[29] = &v24;
      v14[32] = v5;
      v14[33] = 5;
      v15 = 8 * v10 + 28;
      *(_DWORD *)(result + 12) = ((unsigned __int16)v10 << 19) | 0x1C;
      *(_DWORD *)(result + 16) = v15 | (v10 << 19);
      *(_WORD *)(result + 8) = *a2;
      if ( *a2 )
      {
        v16 = 0;
        v17 = (__int64 *)((char *)a2 + 14);
        do
        {
          *(_QWORD *)(result + 28 + 8 * v16) = *(v17 - 1);
          v18 = *v17;
          v17 += 2;
          *(_QWORD *)(result + ((unsigned __int16)v15 & 0xFFFC) + 8 * v16++) = v18;
        }
        while ( v16 < *a2 );
      }
      v19 = v22;
      v20 = v23[0];
      *(_DWORD *)(result + 20) = a3;
      *(_DWORD *)(result + 24) = a4;
      result = perf_trace_run_bpf_submit(result, v13, v19, v8, 1, v20, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
