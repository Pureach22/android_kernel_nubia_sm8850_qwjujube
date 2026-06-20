__int64 __fastcall trace_event_raw_event_rdev_join_ibss(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  __int64 v17; // x20
  size_t v18; // x2
  size_t v19; // x21
  _QWORD v20[7]; // [xsp+8h] [xbp-38h] BYREF

  v20[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v20, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v20);
    if ( result )
    {
      v9 = *(const char **)(a2 + 504);
      v10 = result;
      if ( !v9 )
        v9 = *(const char **)(a2 + 392);
      v11 = strnlen(v9, 0x20u);
      if ( v11 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v11 == 32 )
          v12 = 32;
        else
          v12 = v11 + 1;
        if ( v12 < 0x21 )
        {
          sized_strscpy(v10 + 8, v9);
          v13 = *(_QWORD *)(a3 + 304);
          *(_QWORD *)(v10 + 40) = *(_QWORD *)(a3 + 296);
          *(_QWORD *)(v10 + 48) = v13;
          *(_DWORD *)(v10 + 56) = *(_DWORD *)(a3 + 224);
          v14 = *(int **)(a4 + 8);
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
          v17 = v10 + 66;
          *(_BYTE *)(v17 + 32) = 0;
          *(_QWORD *)(v17 + 16) = 0;
          *(_QWORD *)(v17 + 24) = 0;
          *(_QWORD *)(v17 + 8) = 0;
          v18 = *(unsigned __int8 *)(a4 + 56);
          if ( v18 >= 0x22 && (do_trace_event_raw_event_rdev_join_ibss___already_done_408 & 1) == 0 )
          {
            do_trace_event_raw_event_rdev_join_ibss___already_done_408 = 1;
            v19 = v18;
            _warn_printk(
              "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
              v18,
              "field \"entry->ssid\" at /proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/trace.h:1654",
              0x21u);
            v18 = v19;
            __break(0x800u);
          }
          memcpy((void *)v17, *(const void **)a4, v18);
          result = trace_event_buffer_commit(v20);
          goto LABEL_17;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0x979DC);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
