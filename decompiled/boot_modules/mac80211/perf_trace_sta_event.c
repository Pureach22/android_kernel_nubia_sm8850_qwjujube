size_t __fastcall perf_trace_sta_event(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  __int64 v4; // x30
  __int64 v6; // x26
  size_t result; // x0
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x28
  int v13; // w25
  unsigned int v14; // w21
  _QWORD *v15; // x9
  size_t v16; // x23
  __int64 v17; // x8
  const char *v18; // x24
  size_t v19; // x0
  unsigned __int64 v20; // x2
  int v21; // w9
  int v22; // w8
  void *v23; // x24
  size_t v24; // x25
  int v25; // w9
  __int64 v26; // x0
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v28 = 0;
  result = strlen((const char *)(a3 + 1640));
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v11) )
    goto LABEL_15;
  v14 = ((result + 84) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v14, v29, &v28);
  if ( !result )
    goto LABEL_15;
  v15 = (_QWORD *)v29[0];
  v16 = result;
  *(_QWORD *)(v29[0] + 232LL) = &vars0;
  v15[31] = &v27;
  v15[32] = v6;
  v15[33] = 5;
  *(_DWORD *)(result + 60) = (v13 << 16) + 65606;
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
      if ( a4 )
      {
        v25 = *a4;
        *(_WORD *)(v16 + 68) = *((_WORD *)a4 + 2);
        *(_DWORD *)(v16 + 64) = v25;
      }
      else
      {
        *(_WORD *)(v16 + 68) = 0;
        *(_DWORD *)(v16 + 64) = 0;
      }
      result = perf_trace_run_bpf_submit(v16, v14, v28, a1, 1, v29[0], StatusReg + v11, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v26 = _fortify_panic(7);
  return trace_event_raw_event_drv_conf_tx(v26);
}
