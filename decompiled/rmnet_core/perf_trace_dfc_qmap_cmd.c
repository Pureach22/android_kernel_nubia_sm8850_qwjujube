__int64 __fastcall perf_trace_dfc_qmap_cmd(__int64 result, char a2, char a3, __int16 a4, char a5, int a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v14; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v16; // x9
  __int64 v17; // x2
  __int64 v18; // x5
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v22; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v20 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    result = perf_trace_buf_alloc(20, v21, &v20);
    if ( result )
    {
      v16 = (_QWORD *)v21[0];
      v17 = v20;
      *(_QWORD *)(v21[0] + 232LL) = &v22;
      v18 = v21[0];
      v16[31] = &v19;
      v16[32] = v7;
      v16[33] = 5;
      *(_BYTE *)(result + 8) = a2;
      *(_BYTE *)(result + 9) = a3;
      *(_WORD *)(result + 10) = a4;
      *(_BYTE *)(result + 12) = a5;
      *(_DWORD *)(result + 16) = a6;
      result = perf_trace_run_bpf_submit(result, 20, v17, v10, 1, v18, StatusReg + v14, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
