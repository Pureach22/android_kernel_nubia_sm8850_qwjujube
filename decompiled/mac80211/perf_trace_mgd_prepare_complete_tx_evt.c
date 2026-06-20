size_t __fastcall perf_trace_mgd_prepare_complete_tx_evt(__int64 a1, __int64 a2, __int64 a3, int a4, int a5, char a6)
{
  __int64 v6; // x30
  __int64 v8; // x27
  size_t result; // x0
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x21
  int v15; // w28
  unsigned int v16; // w23
  _QWORD *v17; // x9
  size_t v18; // x24
  __int64 v19; // x8
  const char *v20; // x26
  size_t v21; // x0
  unsigned __int64 v22; // x2
  char v23; // w27
  int v24; // w9
  int v25; // w8
  void *v26; // x25
  size_t v27; // x26
  unsigned __int16 v28; // w8
  __int64 v29; // x5
  __int64 v30; // x2
  __int16 v31; // w8
  __int64 v32; // x0
  __int64 v33; // x14
  __int64 v34; // d20
  __int64 v35; // d21
  __int64 v36; // [xsp+0h] [xbp-20h] BYREF
  int v37; // [xsp+8h] [xbp-18h]
  unsigned int v38; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  HIDWORD(v36) = a4;
  v37 = a5;
  v8 = v6;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  v38 = 0;
  result = strlen((const char *)(a3 + 1640));
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v13) )
    goto LABEL_12;
  v16 = ((result + 84) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v16, v39, &v38);
  if ( !result )
    goto LABEL_12;
  v17 = (_QWORD *)v39[0];
  v18 = result;
  *(_QWORD *)(v39[0] + 232LL) = &vars0;
  v17[31] = &v36;
  v17[32] = v8;
  v17[33] = 5;
  *(_DWORD *)(result + 60) = (v15 << 16) + 65607;
  v19 = *(_QWORD *)(a2 + 72);
  v20 = *(const char **)(v19 + 504);
  if ( !v20 )
    v20 = *(const char **)(v19 + 392);
  v21 = strnlen(v20, 0x20u);
  if ( v21 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v21 == 32 )
      v22 = 32;
    else
      v22 = v21 + 1;
    if ( v22 < 0x21 )
    {
      v23 = a6 & 1;
      sized_strscpy(v18 + 8, v20);
      v24 = *(_DWORD *)(v18 + 60);
      v25 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v18 + 48) = a3;
      *(_DWORD *)(v18 + 40) = v25;
      v26 = (void *)(v18 + (unsigned __int16)v24);
      v27 = HIWORD(v24) - 1LL;
      *(_BYTE *)(v18 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v26, (const void *)(a3 + 1640), v27);
      v28 = WORD2(v36);
      *((_BYTE *)v26 + v27) = 0;
      v29 = v39[0];
      *(_DWORD *)(v18 + 64) = v28;
      v31 = v37;
      v30 = v38;
      *(_BYTE *)(v18 + 70) = v23;
      *(_WORD *)(v18 + 68) = v31;
      result = perf_trace_run_bpf_submit(v18, v16, v30, a1, 1, v29, StatusReg + v13, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v32 = _fortify_panic(7);
  *(_QWORD *)(v33 + 104) = v34;
  *(_QWORD *)(v33 + 112) = v35;
  return trace_event_raw_event_local_chanctx(v32);
}
