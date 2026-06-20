size_t __fastcall perf_trace_api_disconnect(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x30
  __int64 v5; // x24
  size_t result; // x0
  __int64 v9; // x25
  unsigned __int64 StatusReg; // x26
  int v11; // w23
  unsigned int v12; // w22
  _QWORD *v13; // x9
  const void *v14; // x1
  unsigned int v15; // w10
  size_t v16; // x23
  int v17; // w8
  size_t v18; // x24
  size_t v19; // x21
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v23 = 0;
  result = strlen((const char *)(a2 + 1640));
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v12, v24, &v23);
    if ( result )
    {
      v13 = (_QWORD *)v24[0];
      v14 = (const void *)(a2 + 1640);
      *(_QWORD *)(v24[0] + 232LL) = &vars0;
      v13[31] = &v22;
      v13[32] = v5;
      v13[33] = 5;
      v15 = (v11 << 16) + 65572;
      v16 = result + 36;
      *(_DWORD *)(result + 28) = v15;
      v17 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      v18 = HIWORD(v15) - 1LL;
      *(_DWORD *)(result + 8) = v17;
      LOBYTE(v17) = *(_BYTE *)(a2 + 5848);
      v19 = result;
      *(_BYTE *)(result + 24) = v17;
      memcpy((void *)(result + 36), v14, v18);
      *(_BYTE *)(v16 + v18) = 0;
      v20 = v23;
      v21 = v24[0];
      *(_DWORD *)(v19 + 32) = a3 & 1;
      result = perf_trace_run_bpf_submit(v19, v12, v20, a1, 1, v21, StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
