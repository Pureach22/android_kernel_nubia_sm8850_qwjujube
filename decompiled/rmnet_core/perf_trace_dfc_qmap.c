__int64 __fastcall perf_trace_dfc_qmap(__int64 result, const void *a2, size_t a3, char a4, char a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v9; // x19
  __int64 v12; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v14; // w23
  _QWORD *v15; // x9
  char v16; // w8
  __int64 v17; // x22
  __int64 v18; // x2
  __int64 v19; // x5
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v23; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v9 = result;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  v12 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    v14 = ((a3 + 43) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v22, &v21);
    if ( result )
    {
      v15 = (_QWORD *)v22[0];
      *(_QWORD *)(v22[0] + 248LL) = &v20;
      v16 = a4 & 1;
      v17 = result;
      v15[29] = &v23;
      v15[32] = v6;
      v15[33] = 5;
      *(_BYTE *)(result + 8) = v16;
      *(_QWORD *)(result + 16) = a3;
      *(_DWORD *)(result + 24) = ((_DWORD)a3 << 16) | 0x1D;
      memcpy((void *)(result + 29), a2, a3);
      v18 = v21;
      v19 = v22[0];
      *(_BYTE *)(v17 + 28) = a5;
      result = perf_trace_run_bpf_submit(v17, v14, v18, v9, 1, v19, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
