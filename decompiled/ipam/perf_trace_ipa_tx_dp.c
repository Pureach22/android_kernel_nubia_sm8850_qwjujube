size_t __fastcall perf_trace_ipa_tx_dp(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v6; // x24
  const char *v9; // x23
  size_t result; // x0
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x28
  int v13; // w25
  unsigned int v14; // w22
  __int64 v15; // x30
  _QWORD *v16; // x9
  unsigned int v17; // w10
  size_t v18; // x24
  size_t v19; // x26
  size_t v20; // x25
  __int64 v21; // x2
  __int64 v22; // x5
  int v23; // w8
  __int64 v24; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    v9 = a3;
  else
    v9 = "(null)";
  v26[0] = 0;
  v25 = 0;
  result = strlen(v9);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = ((result + 60) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v26, &v25);
    if ( result )
    {
      v15 = v6;
      v16 = (_QWORD *)v26[0];
      v17 = (v13 << 16) + 65584;
      *(_QWORD *)(v26[0] + 248LL) = &v24;
      v18 = result + 48;
      v16[29] = &vars0;
      v19 = result;
      v20 = HIWORD(v17) - 1LL;
      v16[32] = v15;
      v16[33] = 5;
      *(_DWORD *)(result + 8) = v17;
      memcpy((void *)(result + 48), v9, v20);
      *(_BYTE *)(v18 + v20) = 0;
      *(_QWORD *)(v19 + 16) = a2;
      v21 = v25;
      v22 = v26[0];
      *(_WORD *)(v19 + 24) = bswap32(*(unsigned __int16 *)(a2 + 180)) >> 16;
      *(_DWORD *)(v19 + 28) = *(_DWORD *)(a2 + 112);
      v23 = *(_DWORD *)(a2 + 116);
      *(_QWORD *)(v19 + 40) = a4;
      *(_DWORD *)(v19 + 32) = v23;
      result = perf_trace_run_bpf_submit(v19, v14, v21, a1, 1, v22, StatusReg + v11, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
