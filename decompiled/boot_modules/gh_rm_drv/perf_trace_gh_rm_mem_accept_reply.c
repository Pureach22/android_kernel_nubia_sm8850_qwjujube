__int64 __fastcall perf_trace_gh_rm_mem_accept_reply(__int64 result, unsigned int *a2)
{
  __int64 v2; // x30
  __int64 v3; // x22
  int v5; // w25
  unsigned int v6; // w26
  __int64 v7; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v9; // x10
  unsigned int v10; // w8
  int v11; // w10
  unsigned __int64 v12; // x8
  __int64 *v13; // x11
  __int64 v14; // t1
  __int64 v15; // [xsp+0h] [xbp-20h] BYREF
  int v16; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v5 = 25;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( *a2 <= 4 )
      v6 = 8 * *a2;
    else
      v6 = 32;
    v5 = (((v6 >> 3) & 0xFFF) << 19) | 0x19;
  }
  else
  {
    v6 = 0;
  }
  v17[0] = 0;
  v7 = *(_QWORD *)(result + 104);
  v16 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v7) )
  {
    result = perf_trace_buf_alloc(((2 * (_BYTE)v6 + 39) & 0xF8u) - 4, v17, &v16);
    if ( result )
    {
      v9 = (_QWORD *)v17[0];
      *(_QWORD *)(v17[0] + 248LL) = &v15;
      v9[29] = &vars0;
      v9[32] = v3;
      v9[33] = 5;
      *(_BYTE *)(result + 24) = (unsigned __int64)a2 > 0xFFFFFFFFFFFFF000LL;
      *(_DWORD *)(result + 12) = v5;
      *(_DWORD *)(result + 16) = (v6 + 25) | (v6 << 16);
      if ( a2 && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL )
      {
        v10 = *a2;
        *(_DWORD *)(result + 8) = *a2;
        if ( v10 >= 4 )
          v11 = 4;
        else
          v11 = v10;
        *(_DWORD *)(result + 20) = v11;
        if ( v10 )
        {
          v12 = 0;
          v13 = (__int64 *)((char *)a2 + 14);
          do
          {
            *(_QWORD *)(result + 25 + 8 * v12) = *(v13 - 1);
            v14 = *v13;
            v13 += 2;
            *(_QWORD *)(result + (unsigned __int16)(v6 + 25) + 8 * v12++) = v14;
          }
          while ( v12 < *(unsigned int *)(result + 20) );
        }
      }
      else
      {
        *(_DWORD *)(result + 8) = 0;
        *(_DWORD *)(result + 20) = 0;
      }
      result = perf_trace_run_bpf_submit();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
