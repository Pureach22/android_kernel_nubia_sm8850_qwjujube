__int64 __fastcall gh_rm_core_notifier_call(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x8
  size_t v7; // x21
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned __int64 v10; // x8
  __int64 *v11; // x0
  __int64 *v12; // x22
  void *v13; // x0
  _QWORD *v14; // x22
  __int64 v15; // x1

  result = 0;
  if ( a2 > 1443889159 )
  {
    if ( a2 <= 1443889169 )
    {
      if ( a2 == 1443889160 )
      {
        v7 = 8;
        goto LABEL_24;
      }
      if ( a2 != 1443889169 )
        return result;
LABEL_18:
      v7 = 12;
      goto LABEL_24;
    }
    if ( a2 == 1443889170 || a2 == 1443889171 )
    {
LABEL_12:
      v7 = 4;
      goto LABEL_24;
    }
    if ( a2 != 1443889280 )
      return result;
    v6 = *(unsigned __int16 *)(a3 + 2);
LABEL_20:
    v7 = v6 + 4;
    goto LABEL_24;
  }
  if ( a2 > 1360003090 )
  {
    if ( a2 != 1360003091 )
    {
      if ( a2 != 1443889153 )
      {
        if ( a2 != 1443889154 )
          return result;
        goto LABEL_12;
      }
      v10 = *(unsigned __int16 *)(a3 + 2);
      if ( v10 >= 8 )
        return 0;
      v7 = qword_140C8[v10];
LABEL_24:
      v11 = (__int64 *)_kmalloc_cache_noprof(trace_event_buffer_reserve, 3520, 48);
      v12 = v11;
      if ( v11 )
      {
        *v11 = a2;
        v13 = (void *)vmalloc_noprof(v7);
        v12[1] = (__int64)v13;
        if ( v13 )
        {
          memcpy(v13, (const void *)a3, v7);
          v12[2] = 0xFFFFFFFE00000LL;
          v14 = v12 + 2;
          v14[1] = v14 + 1;
          v14[2] = v14 + 1;
          v15 = system_wq;
          v14[3] = gh_rm_notif_work;
          queue_work_on(32, v15, v14);
          return 0;
        }
        kfree(v12);
      }
      return 32781;
    }
    goto LABEL_18;
  }
  if ( a2 == 1360003089 )
  {
    v8 = 4LL * *(unsigned int *)(a3 + 20) + 24;
    v9 = v8 + 8LL * *(unsigned __int16 *)(a3 + v8) + 4;
    v6 = v9 + 4LL * *(unsigned __int16 *)(a3 + v9);
    goto LABEL_20;
  }
  if ( a2 == 1360003090 )
    goto LABEL_18;
  return result;
}
