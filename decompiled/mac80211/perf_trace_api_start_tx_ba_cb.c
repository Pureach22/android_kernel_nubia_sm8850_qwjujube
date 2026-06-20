size_t __fastcall perf_trace_api_start_tx_ba_cb(__int64 a1, __int64 a2, __int64 a3, __int16 a4)
{
  __int64 v4; // x30
  __int64 v6; // x25
  size_t result; // x0
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  int v13; // w24
  unsigned int v14; // w22
  _QWORD *v15; // x9
  const void *v16; // x1
  unsigned int v17; // w10
  size_t v18; // x24
  int v19; // w8
  size_t v20; // x25
  size_t v21; // x23
  __int16 v22; // w9
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v28; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v26 = 0;
  result = strlen((const char *)(a2 + 1640));
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v27, &v26);
    if ( result )
    {
      v15 = (_QWORD *)v27[0];
      v16 = (const void *)(a2 + 1640);
      *(_QWORD *)(v27[0] + 232LL) = &v28;
      v15[31] = &v25;
      v15[32] = v6;
      v15[33] = 5;
      v17 = (v13 << 16) + 65576;
      v18 = result + 40;
      *(_DWORD *)(result + 28) = v17;
      v19 = *(_DWORD *)(a2 + 4720);
      *(_QWORD *)(result + 16) = a2;
      v20 = HIWORD(v17) - 1LL;
      *(_DWORD *)(result + 8) = v19;
      LOBYTE(v19) = *(_BYTE *)(a2 + 5848);
      v21 = result;
      *(_BYTE *)(result + 24) = v19;
      memcpy((void *)(result + 40), v16, v20);
      *(_BYTE *)(v18 + v20) = 0;
      v22 = *(_WORD *)(a3 + 4);
      v23 = v26;
      v24 = v27[0];
      *(_DWORD *)(v21 + 32) = *(_DWORD *)a3;
      *(_WORD *)(v21 + 36) = v22;
      *(_WORD *)(v21 + 38) = a4;
      result = perf_trace_run_bpf_submit(v21, v14, v23, a1, 1, v24, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
