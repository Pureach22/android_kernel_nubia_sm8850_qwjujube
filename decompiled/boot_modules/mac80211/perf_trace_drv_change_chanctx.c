__int64 __fastcall perf_trace_drv_change_chanctx(__int64 result, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v12; // x9
  __int64 v13; // x22
  __int64 v14; // x8
  const char *v15; // x23
  size_t v16; // x0
  unsigned __int64 v17; // x2
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x2
  __int64 v29; // x5
  char v30; // w8
  __int64 v31; // x0
  __int64 v32; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v33; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v33 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10)
    || (result = perf_trace_buf_alloc(124, v34, &v33)) == 0 )
  {
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v12 = (_QWORD *)v34[0];
  v13 = result;
  *(_QWORD *)(v34[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v32;
  v12[32] = v5;
  v14 = *(_QWORD *)(a2 + 72);
  v15 = *(const char **)(v14 + 504);
  if ( !v15 )
    v15 = *(const char **)(v14 + 392);
  v16 = strnlen(v15, 0x20u);
  if ( v16 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v16 == 32 )
      v17 = 32;
    else
      v17 = v16 + 1;
    if ( v17 < 0x21 )
    {
      sized_strscpy(v13 + 8, v15);
      v18 = *(_QWORD *)(a3 + 152);
      if ( v18 )
        LODWORD(v18) = *(_DWORD *)(v18 + 4);
      *(_DWORD *)(v13 + 40) = v18;
      v19 = *(_QWORD *)(a3 + 152);
      if ( v19 )
        LODWORD(v19) = *(unsigned __int16 *)(v19 + 8);
      *(_DWORD *)(v13 + 44) = v19;
      *(_DWORD *)(v13 + 48) = *(_DWORD *)(a3 + 160);
      *(_DWORD *)(v13 + 52) = *(_DWORD *)(a3 + 164);
      *(_DWORD *)(v13 + 56) = *(unsigned __int16 *)(a3 + 180);
      *(_DWORD *)(v13 + 60) = *(_DWORD *)(a3 + 168);
      v20 = *(_QWORD *)(a3 + 184);
      if ( v20 )
        LODWORD(v20) = *(_DWORD *)(v20 + 4);
      *(_DWORD *)(v13 + 64) = v20;
      v21 = *(_QWORD *)(a3 + 184);
      if ( v21 )
        LODWORD(v21) = *(unsigned __int16 *)(v21 + 8);
      *(_DWORD *)(v13 + 68) = v21;
      *(_DWORD *)(v13 + 72) = *(_DWORD *)(a3 + 192);
      *(_DWORD *)(v13 + 76) = *(_DWORD *)(a3 + 196);
      *(_DWORD *)(v13 + 80) = *(unsigned __int16 *)(a3 + 212);
      *(_DWORD *)(v13 + 84) = *(_DWORD *)(a3 + 200);
      v22 = *(_QWORD *)(a3 + 216);
      if ( v22 )
        LODWORD(v22) = *(_DWORD *)(v22 + 4);
      *(_DWORD *)(v13 + 88) = v22;
      v23 = *(_QWORD *)(a3 + 216);
      if ( v23 )
        LODWORD(v23) = *(unsigned __int16 *)(v23 + 8);
      *(_DWORD *)(v13 + 92) = v23;
      v24 = *(_QWORD *)(a3 + 216);
      if ( v24 )
        LODWORD(v24) = *(_DWORD *)(a3 + 224);
      *(_DWORD *)(v13 + 96) = v24;
      v25 = *(_QWORD *)(a3 + 216);
      if ( v25 )
        LODWORD(v25) = *(_DWORD *)(a3 + 228);
      *(_DWORD *)(v13 + 100) = v25;
      v26 = *(_QWORD *)(a3 + 216);
      if ( v26 )
        LODWORD(v26) = *(unsigned __int16 *)(a3 + 244);
      *(_DWORD *)(v13 + 104) = v26;
      v27 = *(_QWORD *)(a3 + 216);
      if ( v27 )
        LODWORD(v27) = *(_DWORD *)(a3 + 232);
      *(_DWORD *)(v13 + 108) = v27;
      v28 = v33;
      v29 = v34[0];
      *(_BYTE *)(v13 + 112) = *(_BYTE *)(a3 + 252);
      v30 = *(_BYTE *)(a3 + 253);
      *(_DWORD *)(v13 + 116) = a4;
      *(_BYTE *)(v13 + 113) = v30;
      result = perf_trace_run_bpf_submit(v13, 124, v28, v8, 1, v29, StatusReg + v10, 0);
      goto LABEL_32;
    }
  }
  v31 = _fortify_panic(7);
  return trace_event_raw_event_drv_switch_vif_chanctx(v31);
}
