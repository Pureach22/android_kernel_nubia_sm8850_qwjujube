size_t __fastcall perf_trace_drv_change_vif_links(__int64 a1, __int64 a2, __int64 a3, __int16 a4, int a5)
{
  __int64 v5; // x30
  __int64 v7; // x26
  size_t result; // x0
  __int64 v12; // x28
  unsigned __int64 StatusReg; // x20
  int v14; // w27
  unsigned int v15; // w23
  _QWORD *v16; // x9
  size_t v17; // x24
  __int64 v18; // x8
  const char *v19; // x25
  size_t v20; // x0
  unsigned __int64 v21; // x2
  int v22; // w9
  int v23; // w8
  void *v24; // x25
  size_t v25; // x26
  __int64 v26; // x2
  __int16 v27; // w8
  __int64 v28; // x5
  __int64 v29; // x0
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  int v31; // [xsp+8h] [xbp-18h]
  unsigned int v32; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v33[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v31 = a5;
  v7 = v5;
  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v32 = 0;
  result = strlen((const char *)(a3 + 1640));
  v12 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v14 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v12) )
    goto LABEL_12;
  v15 = ((result + 84) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v15, v33, &v32);
  if ( !result )
    goto LABEL_12;
  v16 = (_QWORD *)v33[0];
  v17 = result;
  *(_QWORD *)(v33[0] + 232LL) = &vars0;
  v16[31] = &v30;
  v16[32] = v7;
  v16[33] = 5;
  *(_DWORD *)(result + 60) = (v14 << 16) + 65604;
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
      v27 = v31;
      v26 = v32;
      v28 = v33[0];
      *(_WORD *)(v17 + 64) = a4;
      *(_WORD *)(v17 + 66) = v27;
      result = perf_trace_run_bpf_submit(v17, v15, v26, a1, 1, v28, StatusReg + v12, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v29 = _fortify_panic(7);
  return trace_event_raw_event_drv_change_sta_links(v29);
}
