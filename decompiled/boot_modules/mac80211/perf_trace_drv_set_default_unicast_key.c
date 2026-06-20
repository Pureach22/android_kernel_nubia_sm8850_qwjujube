size_t __fastcall perf_trace_drv_set_default_unicast_key(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x30
  __int64 v6; // x26
  __int64 v7; // x20
  size_t result; // x0
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x28
  int v13; // w25
  unsigned int v14; // w22
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
  __int64 v25; // x2
  __int64 v26; // x5
  __int64 v27; // x0
  int v28; // w12
  int v29; // w24
  size_t v30; // x22
  __int64 v31; // x8
  const char *v32; // x23
  size_t v33; // x0
  unsigned __int64 v34; // x2
  int v35; // w9
  int v36; // w8
  void *v37; // x23
  size_t v38; // x24
  __int64 v39; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v40[4]; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v41; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v42[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v7 = a4;
  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42[0] = 0;
  v41 = 0;
  result = strlen((const char *)(a3 + 1640));
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v11) )
    goto LABEL_25;
  v14 = ((result + 84) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v14, v42, &v41);
  if ( !result )
    goto LABEL_25;
  v15 = (_QWORD *)v42[0];
  v16 = result;
  *(_QWORD *)(v42[0] + 232LL) = &vars0;
  v15[31] = &v39;
  v15[32] = v6;
  v15[33] = 5;
  *(_DWORD *)(result + 60) = (v13 << 16) + 65604;
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
      v25 = v41;
      v26 = v42[0];
      *(_DWORD *)(v16 + 64) = v7;
      result = perf_trace_run_bpf_submit(v16, v14, v25, a1, 1, v26, StatusReg + v11, 0);
      goto LABEL_25;
    }
  }
  v27 = _fortify_panic(7);
  if ( (v28 & 0x20000) == 0 )
    return trace_event_raw_event_drv_channel_switch_beacon(v27);
  v29 = strlen((const char *)(a3 + 1640)) + 1;
  result = trace_event_buffer_reserve(v40);
  if ( result )
  {
    v30 = result;
    *(_DWORD *)(result + 60) = (v29 << 16) | 0x48;
    v31 = *(_QWORD *)(v16 + 72);
    v32 = *(const char **)(v31 + 504);
    if ( !v32 )
      v32 = *(const char **)(v31 + 392);
    v33 = strnlen(v32, 0x20u);
    if ( v33 == -1 )
    {
      _fortify_panic(2);
    }
    else
    {
      if ( v33 == 32 )
        v34 = 32;
      else
        v34 = v33 + 1;
      if ( v34 < 0x21 )
      {
        sized_strscpy(v30 + 8, v32);
        v35 = *(_DWORD *)(v30 + 60);
        v36 = *(_DWORD *)(a3 + 4720);
        *(_QWORD *)(v30 + 48) = a3;
        *(_DWORD *)(v30 + 40) = v36;
        v37 = (void *)(v30 + (unsigned __int16)v35);
        v38 = HIWORD(v35) - 1LL;
        *(_BYTE *)(v30 + 56) = *(_BYTE *)(a3 + 5848);
        memcpy(v37, (const void *)(a3 + 1640), v38);
        *((_BYTE *)v37 + v38) = 0;
        *(_DWORD *)(v30 + 64) = *(_DWORD *)(v7 + 8);
        *(_DWORD *)(v30 + 68) = a1;
        result = trace_event_buffer_commit(v40);
        goto LABEL_25;
      }
    }
    _fortify_panic(7);
    JUMPOUT(0x9B9B0);
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
