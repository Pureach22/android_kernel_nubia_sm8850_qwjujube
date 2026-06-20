size_t __fastcall perf_trace_rmnet_ipa_netif_rcv_skb3(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x24
  __int64 v8; // x8
  const char *v9; // x8
  const char *v10; // x23
  size_t result; // x0
  __int64 v12; // x27
  unsigned __int64 StatusReg; // x28
  int v14; // w25
  unsigned int v15; // w22
  __int64 v16; // x30
  _QWORD *v17; // x9
  unsigned int v18; // w10
  size_t v19; // x24
  size_t v20; // x26
  size_t v21; // x25
  __int64 v22; // x2
  __int64 v23; // x5
  int v24; // w8
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 16);
  v27[0] = 0;
  v26 = 0;
  v9 = (const char *)(v8 + 296);
  if ( v9 )
    v10 = v9;
  else
    v10 = "(null)";
  result = strlen(v10);
  v12 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v14 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v12) )
  {
    v15 = ((result + 60) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v15, v27, &v26);
    if ( result )
    {
      v16 = v5;
      v17 = (_QWORD *)v27[0];
      v18 = (v14 << 16) + 65584;
      *(_QWORD *)(v27[0] + 248LL) = &v25;
      v19 = result + 48;
      v17[29] = &vars0;
      v20 = result;
      v21 = HIWORD(v18) - 1LL;
      v17[32] = v16;
      v17[33] = 5;
      *(_DWORD *)(result + 8) = v18;
      memcpy((void *)(result + 48), v10, v21);
      *(_BYTE *)(v19 + v21) = 0;
      *(_QWORD *)(v20 + 16) = a2;
      v22 = v26;
      v23 = v27[0];
      *(_WORD *)(v20 + 24) = bswap32(*(unsigned __int16 *)(a2 + 180)) >> 16;
      *(_DWORD *)(v20 + 28) = *(_DWORD *)(a2 + 112);
      v24 = *(_DWORD *)(a2 + 116);
      *(_QWORD *)(v20 + 40) = a3;
      *(_DWORD *)(v20 + 32) = v24;
      result = perf_trace_run_bpf_submit(v20, v15, v22, a1, 1, v23, StatusReg + v12, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
