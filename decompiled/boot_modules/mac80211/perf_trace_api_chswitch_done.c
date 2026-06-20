size_t __fastcall perf_trace_api_chswitch_done(__int64 a1, __int64 a2, char a3, int a4)
{
  __int64 v4; // x30
  __int64 v6; // x25
  size_t result; // x0
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  int v13; // w24
  unsigned int v14; // w22
  __int64 v15; // x30
  _QWORD *v16; // x9
  char v17; // w25
  size_t v18; // x23
  const void *v19; // x1
  unsigned int v20; // w10
  int v21; // w8
  size_t v22; // x24
  size_t v23; // x21
  __int64 v24; // x2
  __int64 v25; // x5
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v29; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  v27 = 0;
  result = strlen((const char *)(a2 + 1640));
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v28, &v27);
    if ( result )
    {
      v15 = v6;
      v16 = (_QWORD *)v28[0];
      v17 = a3 & 1;
      *(_QWORD *)(v28[0] + 232LL) = &v29;
      v18 = result + 40;
      v19 = (const void *)(a2 + 1640);
      v16[31] = &v26;
      v16[32] = v15;
      v16[33] = 5;
      v20 = (v13 << 16) + 65576;
      *(_DWORD *)(result + 28) = v20;
      v21 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      v22 = HIWORD(v20) - 1LL;
      *(_DWORD *)(result + 8) = v21;
      LOBYTE(v21) = *(_BYTE *)(a2 + 5848);
      v23 = result;
      *(_BYTE *)(result + 24) = v21;
      memcpy((void *)(result + 40), v19, v22);
      *(_BYTE *)(v18 + v22) = 0;
      v24 = v27;
      v25 = v28[0];
      *(_BYTE *)(v23 + 32) = v17;
      *(_DWORD *)(v23 + 36) = a4;
      result = perf_trace_run_bpf_submit(v23, v14, v24, a1, 1, v25, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
