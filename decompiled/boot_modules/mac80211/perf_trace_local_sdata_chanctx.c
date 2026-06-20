size_t __fastcall perf_trace_local_sdata_chanctx(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x26
  size_t result; // x0
  __int64 v12; // x28
  unsigned __int64 StatusReg; // x20
  int v14; // w27
  unsigned int v15; // w22
  _QWORD *v16; // x9
  size_t v17; // x23
  __int64 v18; // x8
  const char *v19; // x25
  size_t v20; // x0
  unsigned __int64 v21; // x2
  int v22; // w9
  int v23; // w8
  void *v24; // x25
  size_t v25; // x26
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x2
  __int64 v37; // x5
  __int64 v38; // x0
  __int64 v39; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v40; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v41[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v39 = a4;
  v7 = v5;
  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41[0] = 0;
  v40 = 0;
  result = strlen((const char *)(a3 + 1640));
  v12 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v14 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v12)
    || (v15 = ((result + 156) & 0xFFFFFFF8) - 4, (result = perf_trace_buf_alloc(v15, v41, &v40)) == 0) )
  {
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v16 = (_QWORD *)v41[0];
  v17 = result;
  *(_QWORD *)(v41[0] + 232LL) = &vars0;
  v16[31] = &v39;
  v16[32] = v7;
  v16[33] = 5;
  *(_DWORD *)(result + 60) = (v14 << 16) + 65680;
  v18 = *(_QWORD *)(a2 + 72);
  v19 = *(const char **)(v18 + 504);
  if ( !v19 )
    v19 = *(const char **)(v18 + 392);
  v20 = strnlen(v19, 0x20u);
  if ( v20 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v20 == 32 )
      v21 = 32;
    else
      v21 = v20 + 1;
    if ( v21 < 0x21 )
    {
      sized_strscpy(v17 + 8, v19);
      v22 = *(_DWORD *)(v17 + 60);
      v23 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v17 + 48) = a3;
      *(_DWORD *)(v17 + 40) = v23;
      v24 = (void *)(v17 + (unsigned __int16)v22);
      v25 = HIWORD(v22) - 1LL;
      *(_BYTE *)(v17 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v24, (const void *)(a3 + 1640), v25);
      *((_BYTE *)v24 + v25) = 0;
      v26 = *(_QWORD *)(a5 + 152);
      if ( v26 )
        LODWORD(v26) = *(_DWORD *)(v26 + 4);
      *(_DWORD *)(v17 + 64) = v26;
      v27 = *(_QWORD *)(a5 + 152);
      if ( v27 )
        LODWORD(v27) = *(unsigned __int16 *)(v27 + 8);
      *(_DWORD *)(v17 + 68) = v27;
      *(_DWORD *)(v17 + 72) = *(_DWORD *)(a5 + 160);
      *(_DWORD *)(v17 + 76) = *(_DWORD *)(a5 + 164);
      *(_DWORD *)(v17 + 80) = *(unsigned __int16 *)(a5 + 180);
      *(_DWORD *)(v17 + 84) = *(_DWORD *)(a5 + 168);
      v28 = *(_QWORD *)(a5 + 184);
      if ( v28 )
        LODWORD(v28) = *(_DWORD *)(v28 + 4);
      *(_DWORD *)(v17 + 88) = v28;
      v29 = *(_QWORD *)(a5 + 184);
      if ( v29 )
        LODWORD(v29) = *(unsigned __int16 *)(v29 + 8);
      *(_DWORD *)(v17 + 92) = v29;
      *(_DWORD *)(v17 + 96) = *(_DWORD *)(a5 + 192);
      *(_DWORD *)(v17 + 100) = *(_DWORD *)(a5 + 196);
      *(_DWORD *)(v17 + 104) = *(unsigned __int16 *)(a5 + 212);
      *(_DWORD *)(v17 + 108) = *(_DWORD *)(a5 + 200);
      v30 = *(_QWORD *)(a5 + 216);
      if ( v30 )
        LODWORD(v30) = *(_DWORD *)(v30 + 4);
      *(_DWORD *)(v17 + 112) = v30;
      v31 = *(_QWORD *)(a5 + 216);
      if ( v31 )
        LODWORD(v31) = *(unsigned __int16 *)(v31 + 8);
      *(_DWORD *)(v17 + 116) = v31;
      v32 = *(_QWORD *)(a5 + 216);
      if ( v32 )
        LODWORD(v32) = *(_DWORD *)(a5 + 224);
      *(_DWORD *)(v17 + 120) = v32;
      v33 = *(_QWORD *)(a5 + 216);
      if ( v33 )
        LODWORD(v33) = *(_DWORD *)(a5 + 228);
      *(_DWORD *)(v17 + 124) = v33;
      v34 = *(_QWORD *)(a5 + 216);
      if ( v34 )
        LODWORD(v34) = *(unsigned __int16 *)(a5 + 244);
      *(_DWORD *)(v17 + 128) = v34;
      v35 = *(_QWORD *)(a5 + 216);
      if ( v35 )
        LODWORD(v35) = *(_DWORD *)(a5 + 232);
      *(_DWORD *)(v17 + 132) = v35;
      v36 = v40;
      v37 = v41[0];
      *(_BYTE *)(v17 + 136) = *(_BYTE *)(a5 + 252);
      *(_BYTE *)(v17 + 137) = *(_BYTE *)(a5 + 253);
      *(_DWORD *)(v17 + 140) = *(_DWORD *)(v39 + 24);
      result = perf_trace_run_bpf_submit(v17, v15, v36, a1, 1, v37, StatusReg + v12, 0);
      goto LABEL_32;
    }
  }
  v38 = _fortify_panic(7);
  return trace_event_raw_event_drv_start_ap(v38);
}
