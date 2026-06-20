__int64 __fastcall trace_event_raw_event_rdev_connect(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  const char *v9; // x23
  __int64 v10; // x20
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x8
  int *v14; // x8
  __int16 v15; // w9
  int v16; // w8
  void *v17; // x0
  size_t v18; // x2
  int *v19; // x8
  __int16 v20; // w9
  int v21; // w8
  __int64 v22; // x1
  size_t v23; // x22
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v24, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_20;
  }
  result = trace_event_buffer_reserve(v24);
  if ( !result )
    goto LABEL_20;
  v9 = *(const char **)(a2 + 504);
  v10 = result;
  if ( !v9 )
    v9 = *(const char **)(a2 + 392);
  v11 = strnlen(v9, 0x20u);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_25;
  }
  if ( v11 == 32 )
    v12 = 32;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x21 )
  {
LABEL_25:
    _fortify_panic(7, 32);
    JUMPOUT(0x968DC);
  }
  sized_strscpy(v10 + 8, v9);
  v13 = *(_QWORD *)(a3 + 304);
  *(_QWORD *)(v10 + 40) = *(_QWORD *)(a3 + 296);
  *(_QWORD *)(v10 + 48) = v13;
  *(_DWORD *)(v10 + 56) = *(_DWORD *)(a3 + 224);
  v14 = *(int **)(a4 + 16);
  if ( v14 )
  {
    v15 = *((_WORD *)v14 + 2);
    v16 = *v14;
    *(_WORD *)(v10 + 64) = v15;
    *(_DWORD *)(v10 + 60) = v16;
  }
  else
  {
    *(_WORD *)(v10 + 64) = 0;
    *(_DWORD *)(v10 + 60) = 0;
  }
  *(_QWORD *)(v10 + 66) = 0;
  v17 = (void *)(v10 + 66);
  *(_BYTE *)(v10 + 98) = 0;
  *(_QWORD *)(v10 + 82) = 0;
  *(_QWORD *)(v10 + 90) = 0;
  *(_QWORD *)(v10 + 74) = 0;
  v18 = *(_QWORD *)(a4 + 40);
  if ( v18 >= 0x22 && (do_trace_event_raw_event_rdev_connect___already_done_375 & 1) == 0 )
  {
    v22 = *(_QWORD *)(a4 + 40);
    do_trace_event_raw_event_rdev_connect___already_done_375 = 1;
    v23 = v18;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v22,
      "field \"entry->ssid\" at /proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/trace.h:1520",
      0x21u);
    v18 = v23;
    v17 = (void *)(v10 + 66);
    __break(0x800u);
  }
  memcpy(v17, *(const void **)(a4 + 32), v18);
  *(_DWORD *)(v10 + 100) = *(_DWORD *)(a4 + 48);
  *(_BYTE *)(v10 + 104) = *(_BYTE *)(a4 + 72);
  *(_DWORD *)(v10 + 108) = *(_DWORD *)(a4 + 80);
  *(_DWORD *)(v10 + 112) = *(_DWORD *)(a4 + 212);
  v19 = *(int **)(a4 + 312);
  if ( v19 )
  {
    v20 = *((_WORD *)v19 + 2);
    v21 = *v19;
    *(_WORD *)(v10 + 120) = v20;
    *(_DWORD *)(v10 + 116) = v21;
  }
  else
  {
    *(_WORD *)(v10 + 120) = 0;
    *(_DWORD *)(v10 + 116) = 0;
  }
  result = trace_event_buffer_commit(v24);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
