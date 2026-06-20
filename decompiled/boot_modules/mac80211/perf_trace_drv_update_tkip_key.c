size_t __fastcall perf_trace_drv_update_tkip_key(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int *a5, int a6)
{
  __int64 v6; // x30
  __int64 v8; // x26
  size_t result; // x0
  __int64 v13; // x28
  unsigned __int64 StatusReg; // x20
  int v15; // w27
  unsigned int v16; // w22
  _QWORD *v17; // x9
  size_t v18; // x24
  __int64 v19; // x8
  const char *v20; // x25
  size_t v21; // x0
  unsigned __int64 v22; // x2
  int v23; // w9
  int v24; // w8
  void *v25; // x25
  size_t v26; // x26
  int v27; // w9
  __int64 v28; // x2
  __int64 v29; // x5
  __int64 v30; // x0
  __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  int v32; // [xsp+8h] [xbp-18h]
  unsigned int v33; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v32 = a6;
  v8 = v6;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v33 = 0;
  result = strlen((const char *)(a3 + 1640));
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v13) )
    goto LABEL_15;
  v16 = ((result + 92) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v16, v34, &v33);
  if ( !result )
    goto LABEL_15;
  v17 = (_QWORD *)v34[0];
  v18 = result;
  *(_QWORD *)(v34[0] + 232LL) = &vars0;
  v17[31] = &v31;
  v17[32] = v8;
  v17[33] = 5;
  *(_DWORD *)(result + 60) = (v15 << 16) + 65612;
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
      sized_strscpy(v18 + 8, v20);
      v23 = *(_DWORD *)(v18 + 60);
      v24 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v18 + 48) = a3;
      *(_DWORD *)(v18 + 40) = v24;
      v25 = (void *)(v18 + (unsigned __int16)v23);
      v26 = HIWORD(v23) - 1LL;
      *(_BYTE *)(v18 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v25, (const void *)(a3 + 1640), v26);
      *((_BYTE *)v25 + v26) = 0;
      if ( a5 )
      {
        v27 = *a5;
        *(_WORD *)(v18 + 68) = *((_WORD *)a5 + 2);
        *(_DWORD *)(v18 + 64) = v27;
      }
      else
      {
        *(_WORD *)(v18 + 68) = 0;
        *(_DWORD *)(v18 + 64) = 0;
      }
      v28 = v33;
      v29 = v34[0];
      *(_DWORD *)(v18 + 72) = v32;
      result = perf_trace_run_bpf_submit(v18, v16, v28, a1, 1, v29, StatusReg + v13, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v30 = _fortify_panic(7);
  return trace_event_raw_event_drv_sw_scan_start(v30);
}
