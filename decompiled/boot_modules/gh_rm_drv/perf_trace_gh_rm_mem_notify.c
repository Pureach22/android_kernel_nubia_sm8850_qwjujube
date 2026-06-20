__int64 __fastcall perf_trace_gh_rm_mem_notify(__int64 result, int a2, char a3, int a4, unsigned __int16 *a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  int v11; // w28
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v14; // x9
  int v15; // w8
  unsigned __int64 v16; // x8
  __int16 *v17; // x10
  __int16 v18; // t1
  unsigned __int64 v19; // x12
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 )
    v11 = 2 * *a5;
  else
    v11 = 0;
  v22[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    result = perf_trace_buf_alloc(((v11 + 39) & 0x3FFF8u) - 4, v22, &v21);
    if ( result )
    {
      v14 = (_QWORD *)v22[0];
      *(_QWORD *)(v22[0] + 232LL) = &vars0;
      v14[31] = &v20;
      v14[32] = v6;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = a2;
      *(_BYTE *)(result + 12) = a3;
      *(_DWORD *)(result + 24) = (v11 << 16) | 0x1C;
      *(_DWORD *)(result + 16) = a4;
      if ( a5 )
      {
        v15 = *a5;
        *(_WORD *)(result + 20) = v15;
        if ( v15 )
        {
          v16 = 0;
          v17 = (__int16 *)(a5 + 2);
          do
          {
            v18 = *v17;
            v17 += 2;
            v19 = *(unsigned __int16 *)(result + 20);
            *(_WORD *)(result + 28 + 2 * v16++) = v18;
          }
          while ( v16 < v19 );
        }
      }
      else
      {
        *(_WORD *)(result + 20) = 0;
      }
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
