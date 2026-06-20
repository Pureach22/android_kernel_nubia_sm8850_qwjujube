size_t __fastcall perf_trace_api_beacon_loss(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v4; // x23
  size_t result; // x0
  __int64 v7; // x24
  unsigned __int64 StatusReg; // x25
  int v9; // w22
  unsigned int v10; // w21
  _QWORD *v11; // x9
  const void *v12; // x1
  unsigned int v13; // w10
  size_t v14; // x22
  int v15; // w8
  size_t v16; // x23
  size_t v17; // x20
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v21; // [xsp+20h] [xbp+0h] BYREF

  v4 = v2;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v19 = 0;
  result = strlen((const char *)(a2 + 1640));
  v7 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v9 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v7) )
  {
    v10 = ((result + 44) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v10, v20, &v19);
    if ( result )
    {
      v11 = (_QWORD *)v20[0];
      v12 = (const void *)(a2 + 1640);
      *(_QWORD *)(v20[0] + 232LL) = &v21;
      v11[31] = &v18;
      v11[32] = v4;
      v11[33] = 5;
      v13 = (v9 << 16) + 65568;
      v14 = result + 32;
      *(_DWORD *)(result + 28) = v13;
      v15 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      v16 = HIWORD(v13) - 1LL;
      *(_DWORD *)(result + 8) = v15;
      LOBYTE(v15) = *(_BYTE *)(a2 + 5848);
      v17 = result;
      *(_BYTE *)(result + 24) = v15;
      memcpy((void *)(result + 32), v12, v16);
      *(_BYTE *)(v14 + v16) = 0;
      result = perf_trace_run_bpf_submit(v17, v10, v19, a1, 1, v20[0], StatusReg + v7, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
