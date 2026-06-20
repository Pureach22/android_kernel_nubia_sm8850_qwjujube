__int64 cam_mem_trace_query_mass_mem()
{
  __int64 v0; // x19
  void *v1; // x20
  __int64 v2; // x0
  __int64 *v3; // x25
  char *v4; // x0
  char *v5; // x6
  __int64 v6; // x25
  unsigned __int64 v7; // x8
  const char *v8; // x9
  unsigned __int64 v9; // x7
  int v10; // w8
  __int64 result; // x0
  __int64 i; // [xsp+18h] [xbp-18h]
  char *stringp[2]; // [xsp+20h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  stringp[0] = nullptr;
  v0 = ktime_get_with_offset(1);
  v1 = (void *)vzalloc_noprof(0x2000);
  v2 = raw_spin_lock_irqsave(&dword_2FDB40);
  v3 = (__int64 *)qword_2FDB30;
  for ( i = v2; v3 != &qword_2FDB30; v3 = (__int64 *)*v3 )
  {
    memcpy(v1, v3 + 5, 0x2000u);
    stringp[0] = (char *)v1;
    v4 = strsep(stringp, "$");
    if ( v4 )
    {
      v5 = v4;
      do
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          3,
          "cam_mem_trace_query_mass_mem",
          607,
          "%s",
          v5);
        v5 = strsep(stringp, "$");
      }
      while ( v5 );
    }
    memset(v1, 0, 0x2000u);
  }
  v6 = g_trace;
  if ( (__int64 *)g_trace != &g_trace )
  {
    v7 = (unsigned int)mass_mem_threshold;
    do
    {
      v9 = *(_QWORD *)(v6 + 16);
      if ( v9 <= v7 )
        goto LABEL_12;
      v10 = *(_DWORD *)(v6 + 24);
      if ( v10 > 3263 )
      {
        if ( v10 == 3264 )
        {
          v8 = "(GFP_KERNEL)";
          goto LABEL_11;
        }
        if ( v10 == 1051840 )
        {
          v8 = "(GFP_USER)";
          goto LABEL_11;
        }
      }
      else
      {
        if ( v10 == 1 )
        {
          v8 = "(GFP_DMA)";
          goto LABEL_11;
        }
        if ( v10 == 2080 )
        {
          v8 = "(GFP_ATOMIC)";
          goto LABEL_11;
        }
      }
      v8 = (const char *)&unk_3E455A;
LABEL_11:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        3,
        "cam_mem_trace_query_mass_mem",
        622,
        "In-use mem: owner %s, size %lu bytes, flags %#x%s, kept_time %llds\n",
        (const char *)(v6 + 28),
        v9,
        *(_DWORD *)(v6 + 24),
        v8,
        (v0 - *(_QWORD *)(v6 + 136)) / 1000000000);
      v7 = (unsigned int)mass_mem_threshold;
LABEL_12:
      v6 = *(_QWORD *)v6;
    }
    while ( (__int64 *)v6 != &g_trace );
  }
  raw_spin_unlock_irqrestore(&dword_2FDB40, i);
  result = vfree(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
