__int64 __fastcall perf_trace_map_mem_s2(__int64 result, int a2, unsigned int *a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  int v8; // w26
  __int64 v9; // x24
  unsigned __int64 StatusReg; // x25
  unsigned int v11; // w21
  _QWORD *v12; // x10
  int v13; // w9
  unsigned __int64 v14; // x8
  __int64 *v15; // x11
  __int64 v16; // t1
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v8 = *a3;
  v9 = *(_QWORD *)(result + 104);
  v18 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v11 = ((16 * v8 + 35) & 0xFFFFFFF0) - 4;
    result = perf_trace_buf_alloc(v11, v19, &v18);
    if ( result )
    {
      v12 = (_QWORD *)v19[0];
      *(_QWORD *)(v19[0] + 248LL) = &v17;
      v12[29] = &vars0;
      v12[32] = v4;
      v12[33] = 5;
      v13 = 8 * v8 + 24;
      *(_DWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 16) = ((unsigned __int16)v8 << 19) | 0x18;
      *(_DWORD *)(result + 20) = v13 | (v8 << 19);
      *(_WORD *)(result + 12) = *a3;
      if ( *a3 )
      {
        v14 = 0;
        v15 = (__int64 *)((char *)a3 + 14);
        do
        {
          *(_QWORD *)(result + 24 + 8 * v14) = *(v15 - 1);
          v16 = *v15;
          v15 += 2;
          *(_QWORD *)(result + ((unsigned __int16)v13 & 0xFFF8) + 8 * v14++) = v16;
        }
        while ( v14 < *a3 );
      }
      result = perf_trace_run_bpf_submit(result, v11, v18, v6, 1, v19[0], StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
