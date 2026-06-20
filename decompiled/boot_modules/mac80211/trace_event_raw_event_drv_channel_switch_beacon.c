__int64 __fastcall trace_event_raw_event_drv_channel_switch_beacon(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x25
  int v5; // w27
  __int64 v6; // x28
  __int64 v10; // x8
  unsigned int v11; // w23
  __int64 result; // x0
  __int64 v13; // x20
  __int64 v14; // x8
  __int64 v15; // x22
  size_t v16; // x0
  unsigned __int64 v17; // x2
  int v18; // w9
  int v19; // w8
  void *v20; // x22
  size_t v21; // x23
  __int64 v22; // x8
  __int64 v23; // x8
  int v24; // w8
  __int64 v25; // x0
  _QWORD *v26; // x9
  __int64 v27; // x10
  __int64 v28; // x30
  int v29; // w12
  __int64 v30; // x24
  __int64 v31; // x8
  const char *v32; // x25
  size_t v33; // x0
  unsigned __int64 v34; // x2
  int v35; // w9
  int v36; // w8
  void *v37; // x25
  size_t v38; // x26
  __int64 v39; // x2
  int v40; // w8
  __int64 v41; // x5
  __int64 v42; // [xsp+0h] [xbp-40h] BYREF
  __int64 v43; // [xsp+8h] [xbp-38h] BYREF
  __int64 v44; // [xsp+10h] [xbp-30h]
  __int64 v45; // [xsp+18h] [xbp-28h]
  __int64 v46; // [xsp+20h] [xbp-20h]
  __int64 v47; // [xsp+28h] [xbp-18h]
  __int64 v48; // [xsp+30h] [xbp-10h]
  __int64 v49; // [xsp+38h] [xbp-8h]
  __int64 v50; // [xsp+40h] [xbp+0h] BYREF

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  if ( (v10 & 0x2C0) != 0 && (v10 & 0x100) == 0 && (result = _trace_trigger_soft_disabled(a1), (result & 1) != 0)
    || (v11 = strlen((const char *)(a3 + 1640)) + 1, (result = trace_event_buffer_reserve(&v43)) == 0) )
  {
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v13 = result;
  *(_DWORD *)(result + 60) = (v11 << 16) | 0x58;
  v14 = *(_QWORD *)(a2 + 72);
  v15 = *(_QWORD *)(v14 + 504);
  if ( !v15 )
    v15 = *(_QWORD *)(v14 + 392);
  v16 = strnlen((const char *)v15, 0x20u);
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
      v18 = *(_DWORD *)(v13 + 60);
      v19 = *(_DWORD *)(a3 + 4720);
      *(_QWORD *)(v13 + 48) = a3;
      *(_DWORD *)(v13 + 40) = v19;
      v20 = (void *)(v13 + (unsigned __int16)v18);
      v21 = HIWORD(v18) - 1LL;
      *(_BYTE *)(v13 + 56) = *(_BYTE *)(a3 + 5848);
      memcpy(v20, (const void *)(a3 + 1640), v21);
      *((_BYTE *)v20 + v21) = 0;
      if ( a4 )
      {
        v22 = *a4;
        if ( *a4 )
          LODWORD(v22) = *(_DWORD *)(v22 + 4);
        *(_DWORD *)(v13 + 64) = v22;
        v23 = *a4;
        if ( *a4 )
          LODWORD(v23) = *(unsigned __int16 *)(v23 + 8);
        *(_DWORD *)(v13 + 68) = v23;
        *(_DWORD *)(v13 + 72) = *((_DWORD *)a4 + 2);
        *(_DWORD *)(v13 + 76) = *((_DWORD *)a4 + 3);
        *(_DWORD *)(v13 + 80) = *((unsigned __int16 *)a4 + 14);
        v24 = *((_DWORD *)a4 + 4);
      }
      else
      {
        v24 = 0;
        *(_DWORD *)(v13 + 80) = 0;
        *(_QWORD *)(v13 + 64) = 0;
        *(_QWORD *)(v13 + 72) = 0;
      }
      *(_DWORD *)(v13 + 84) = v24;
      result = trace_event_buffer_commit(&v43);
      goto LABEL_18;
    }
  }
  v25 = _fortify_panic(7);
  if ( (v29 & 0x20000) == 0 )
    JUMPOUT(0x95A28);
  v30 = v25;
  v26[29] = &v50;
  v26[31] = &v42;
  v26[32] = v28;
  v26[33] = v27;
  *(_DWORD *)(v25 + 60) = (v5 << 16) + 65608;
  v31 = *(_QWORD *)(v4 + 72);
  v32 = *(const char **)(v31 + 504);
  if ( !v32 )
    v32 = *(const char **)(v31 + 392);
  v33 = strnlen(v32, 0x20u);
  if ( v33 == -1 )
  {
    _fortify_panic(2);
    goto LABEL_34;
  }
  if ( v33 == 32 )
    v34 = 32;
  else
    v34 = v33 + 1;
  if ( v34 >= 0x21 )
  {
LABEL_34:
    _fortify_panic(7);
    JUMPOUT(0x9BB80);
  }
  sized_strscpy(v30 + 8, v32);
  v35 = *(_DWORD *)(v30 + 60);
  v36 = *(_DWORD *)(v15 + 4720);
  *(_QWORD *)(v30 + 48) = v15;
  *(_DWORD *)(v30 + 40) = v36;
  v37 = (void *)(v30 + (unsigned __int16)v35);
  v38 = HIWORD(v35) - 1LL;
  *(_BYTE *)(v30 + 56) = *(_BYTE *)(v15 + 5848);
  memcpy(v37, (const void *)(v15 + 1640), v38);
  *((_BYTE *)v37 + v38) = 0;
  v40 = v43;
  v39 = HIDWORD(v43);
  v41 = v44;
  *(_DWORD *)(v30 + 64) = *(_DWORD *)(a3 + 8);
  *(_DWORD *)(v30 + 68) = v40;
  result = perf_trace_run_bpf_submit(v30, v11, v39, a4, 1, v41, v13 + v6, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
