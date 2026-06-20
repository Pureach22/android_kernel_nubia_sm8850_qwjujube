__int64 __fastcall perf_trace_rdev_start_ap(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v12; // x9
  __int64 v13; // x21
  const char *v14; // x24
  size_t v15; // x0
  unsigned __int64 v16; // x2
  __int64 v17; // x8
  int v18; // w8
  void *v19; // x0
  size_t v20; // x2
  __int64 v21; // x2
  __int64 v22; // x5
  __int64 v23; // x1
  size_t v24; // x23
  __int64 v25; // x0
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v27 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v10)
    || (result = perf_trace_buf_alloc(164, v28, &v27)) == 0 )
  {
LABEL_19:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v12 = (_QWORD *)v28[0];
  v13 = result;
  *(_QWORD *)(v28[0] + 232LL) = &vars0;
  v12[33] = 5;
  v12[31] = &v26;
  v12[32] = v5;
  v14 = *(const char **)(a2 + 504);
  if ( !v14 )
    v14 = *(const char **)(a2 + 392);
  v15 = strnlen(v14, 0x20u);
  if ( v15 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v15 == 32 )
      v16 = 32;
    else
      v16 = v15 + 1;
    if ( v16 < 0x21 )
    {
      sized_strscpy(v13 + 8, v14);
      v17 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v13 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v13 + 48) = v17;
      *(_DWORD *)(v13 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 && *(_QWORD *)a4 )
      {
        *(_DWORD *)(v13 + 60) = **(_DWORD **)a4;
        *(_DWORD *)(v13 + 64) = *(_DWORD *)(*(_QWORD *)a4 + 4LL);
        *(_DWORD *)(v13 + 68) = *(unsigned __int16 *)(*(_QWORD *)a4 + 8LL);
        *(_DWORD *)(v13 + 72) = *(_DWORD *)(a4 + 8);
        *(_DWORD *)(v13 + 76) = *(_DWORD *)(a4 + 12);
        *(_DWORD *)(v13 + 80) = *(unsigned __int16 *)(a4 + 28);
        *(_DWORD *)(v13 + 84) = *(_DWORD *)(a4 + 16);
        *(_WORD *)(v13 + 88) = *(_WORD *)(a4 + 30);
      }
      else
      {
        *(_QWORD *)(v13 + 82) = 0;
        *(_QWORD *)(v13 + 76) = 0;
        *(_QWORD *)(v13 + 68) = 0;
        *(_QWORD *)(v13 + 60) = 0;
      }
      *(_DWORD *)(v13 + 92) = *(_DWORD *)(a4 + 208);
      *(_DWORD *)(v13 + 96) = *(_DWORD *)(a4 + 212);
      *(_DWORD *)(v13 + 136) = *(_DWORD *)(a4 + 232);
      *(_DWORD *)(v13 + 140) = *(_DWORD *)(a4 + 240);
      *(_BYTE *)(v13 + 144) = *(_BYTE *)(a4 + 360);
      *(_DWORD *)(v13 + 148) = *(_DWORD *)(a4 + 364);
      v18 = *(_DWORD *)(a4 + 372);
      *(_QWORD *)(v13 + 100) = 0;
      v19 = (void *)(v13 + 100);
      *(_QWORD *)(v13 + 108) = 0;
      *(_QWORD *)(v13 + 116) = 0;
      *(_QWORD *)(v13 + 124) = 0;
      *(_DWORD *)(v13 + 152) = v18;
      *(_BYTE *)(v13 + 132) = 0;
      v20 = *(_QWORD *)(a4 + 224);
      if ( v20 >= 0x22 && (perf_trace_rdev_start_ap___already_done_976 & 1) == 0 )
      {
        v23 = *(_QWORD *)(a4 + 224);
        perf_trace_rdev_start_ap___already_done_976 = 1;
        v24 = v20;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v23,
          "field \"entry->ssid\" at /proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/trace.h:684",
          0x21u);
        v20 = v24;
        v19 = (void *)(v13 + 100);
        __break(0x800u);
      }
      memcpy(v19, *(const void **)(a4 + 216), v20);
      v21 = v27;
      v22 = v28[0];
      *(_DWORD *)(v13 + 156) = *(_DWORD *)(a4 + 32);
      result = perf_trace_run_bpf_submit(v13, 164, v21, v8, 1, v22, StatusReg + v10, 0);
      goto LABEL_19;
    }
  }
  v25 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_change_beacon(v25);
}
