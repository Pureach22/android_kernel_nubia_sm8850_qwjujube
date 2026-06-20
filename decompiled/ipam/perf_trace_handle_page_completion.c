__int64 __fastcall perf_trace_handle_page_completion(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int16 a4,
        char a5,
        int a6)
{
  __int64 v6; // x30
  __int64 v7; // x25
  __int64 v10; // x19
  __int64 v14; // x26
  unsigned __int64 StatusReg; // x27
  _QWORD *v16; // x9
  __int64 v17; // x2
  __int64 v18; // x10
  __int64 v19; // x5
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v23; // [xsp+20h] [xbp+0h] BYREF

  v7 = v6;
  v10 = result;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v14 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v14) )
  {
    result = perf_trace_buf_alloc(52, v22, &v21);
    if ( result )
    {
      v16 = (_QWORD *)v22[0];
      *(_QWORD *)(v22[0] + 232LL) = &v23;
      v17 = v21;
      v18 = memstart_addr;
      v16[31] = &v20;
      v19 = v22[0];
      v16[32] = v7;
      v16[33] = 5;
      *(_QWORD *)(result + 8) = a2;
      *(_QWORD *)(result + 16) = a3;
      *(_WORD *)(result + 24) = a4;
      *(_DWORD *)(result + 40) = a6;
      *(_BYTE *)(result + 26) = a5 & 1;
      *(_QWORD *)(result + 32) = (a2 - -64 * (v18 >> 12) + 0x140000000LL) >> 6;
      result = perf_trace_run_bpf_submit(result, 52, v17, v10, 1, v19, StatusReg + v14, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
