size_t __fastcall perf_trace_drv_tdls_recv_channel_switch(__int64 a1, __int64 a2, __int64 a3, int **a4)
{
  __int64 v4; // x30
  __int64 v6; // x26
  size_t result; // x0
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x28
  int v13; // w25
  unsigned int v14; // w21
  _QWORD *v15; // x9
  size_t v16; // x22
  __int64 v17; // x8
  const char *v18; // x24
  size_t v19; // x0
  unsigned __int64 v20; // x2
  int v21; // w9
  int v22; // w8
  void *v23; // x24
  size_t v24; // x25
  int v25; // w8
  int *v26; // x8
  int *v27; // x8
  int *v28; // x8
  int *v29; // x8
  int *v30; // x8
  int *v31; // x8
  __int64 v32; // x2
  __int64 v33; // x5
  __int64 v34; // x0
  void *v35; // x3
  __int64 v36; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v37; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v38[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38[0] = 0;
  v37 = 0;
  result = strlen((const char *)(a3 + 1640));
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v11)
    || (v14 = ((result + 124) & 0xFFFFFFF8) - 4, (result = perf_trace_buf_alloc(v14, v38, &v37)) == 0) )
  {
LABEL_26:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v15 = (_QWORD *)v38[0];
  v16 = result;
  *(_QWORD *)(v38[0] + 232LL) = &vars0;
  v15[31] = &v36;
  v15[32] = v6;
  v15[33] = 5;
  *(_DWORD *)(result + 60) = (v13 << 16) + 65648;
  v17 = *(_QWORD *)(a2 + 72);
  v18 = *(const char **)(v17 + 504);
  if ( !v18 )
    v18 = *(const char **)(v17 + 392);
  v19 = strnlen(v18, 0x20u);
  if ( v19 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v19 == 32 )
      v20 = 32;
    else
      v20 = v19 + 1;
    if ( v20 < 0x21 )
    {
      sized_strscpy(v16 + 8, v18);
      v21 = *(_DWORD *)(v16 + 60);
      v22 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v16 + 48) = a3;
      *(_DWORD *)(v16 + 40) = v22;
      v23 = (void *)(v16 + (unsigned __int16)v21);
      v24 = HIWORD(v21) - 1LL;
      *(_BYTE *)(v16 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v23, (const void *)(a3 + 1640), v24);
      *((_BYTE *)v23 + v24) = 0;
      v25 = **a4;
      *(_WORD *)(v16 + 69) = *((_WORD *)*a4 + 2);
      *(_DWORD *)(v16 + 65) = v25;
      v26 = a4[1];
      if ( v26 )
      {
        v26 = *(int **)v26;
        if ( v26 )
          LODWORD(v26) = v26[1];
      }
      *(_DWORD *)(v16 + 72) = (_DWORD)v26;
      v27 = a4[1];
      if ( v27 )
      {
        v27 = *(int **)v27;
        if ( v27 )
          LODWORD(v27) = *((unsigned __int16 *)v27 + 4);
      }
      *(_DWORD *)(v16 + 76) = (_DWORD)v27;
      v28 = a4[1];
      if ( v28 )
        LODWORD(v28) = v28[2];
      *(_DWORD *)(v16 + 80) = (_DWORD)v28;
      v29 = a4[1];
      if ( v29 )
        LODWORD(v29) = v29[3];
      *(_DWORD *)(v16 + 84) = (_DWORD)v29;
      v30 = a4[1];
      if ( v30 )
        LODWORD(v30) = *((unsigned __int16 *)v30 + 14);
      *(_DWORD *)(v16 + 88) = (_DWORD)v30;
      v31 = a4[1];
      if ( v31 )
        LODWORD(v31) = v31[4];
      *(_DWORD *)(v16 + 92) = (_DWORD)v31;
      v32 = v37;
      v33 = v38[0];
      *(_BYTE *)(v16 + 100) = *((_BYTE *)*a4 + 25);
      *(_BYTE *)(v16 + 64) = *((_BYTE *)a4 + 16);
      *(_DWORD *)(v16 + 96) = *((_DWORD *)a4 + 5);
      *(_DWORD *)(v16 + 104) = *((_DWORD *)a4 + 6);
      *(_WORD *)(v16 + 108) = *((_WORD *)a4 + 14);
      *(_WORD *)(v16 + 110) = *((_WORD *)a4 + 15);
      result = perf_trace_run_bpf_submit(v16, v14, v32, a1, 1, v33, StatusReg + v11, 0);
      goto LABEL_26;
    }
  }
  v34 = _fortify_panic(7);
  __arm_mte_set_tag(&STACK[0xCA0], v35);
  return trace_event_raw_event_drv_wake_tx_queue(v34);
}
