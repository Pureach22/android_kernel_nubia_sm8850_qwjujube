__int64 __fastcall perf_trace_print_pfn(__int64 result, __int64 a2, const void *a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v12; // w22
  _QWORD *v13; // x9
  size_t v14; // x2
  __int64 v15; // x21
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v17; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v17 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    v12 = ((8 * a4 + 35) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v12, v18, &v17);
    if ( result )
    {
      v13 = (_QWORD *)v18[0];
      v14 = 8LL * a4;
      *(_QWORD *)(v18[0] + 248LL) = &v16;
      v13[29] = &vars0;
      v13[32] = v5;
      v13[33] = 5;
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 16) = a4;
      *(_DWORD *)(result + 20) = (a4 << 19) | 0x18;
      v15 = result;
      memcpy((void *)(result + 24), a3, v14);
      result = perf_trace_run_bpf_submit(v15, v12, v17, v8, 1, v18[0], StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
