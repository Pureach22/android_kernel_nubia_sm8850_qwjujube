__int64 __fastcall kgsl_context_debug_info(_QWORD *a1)
{
  __int64 result; // x0
  __int64 *i; // x25
  __int64 next; // x0
  int v5; // w22
  int v6; // w21
  __int64 v7; // x8
  int v8; // w2
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  result = __ratelimit(&kgsl_context_debug_info__rs, "kgsl_context_debug_info");
  if ( (_DWORD)result )
  {
    dev_info(*a1, "KGSL active contexts:\n");
    dev_info(*a1, "pid      process         total    attached   detached\n");
    raw_read_lock(&unk_3A870);
    raw_read_lock(a1 + 1401);
    for ( i = (__int64 *)qword_3A800; i != &qword_3A800; i = (__int64 *)*i )
    {
      v9 = 0;
      next = idr_get_next(a1 + 1398, &v9);
      v5 = 0;
      v6 = 0;
      if ( next )
      {
        v6 = 0;
        v5 = 0;
        do
        {
          if ( *(__int64 **)(next + 24) == i - 9 )
          {
            ++v5;
            v6 += ((unsigned int)*(_QWORD *)(next + 32) >> 1) & 1;
          }
          ++v9;
          next = idr_get_next(a1 + 1398, &v9);
        }
        while ( next );
      }
      v7 = *(i - 8);
      if ( v7 )
        v8 = *(_DWORD *)(v7 + 112);
      else
        v8 = 0;
      dev_info(*a1, "%-8u %-15.15s %-8d %-10d %-10d\n", v8, (const char *)i - 56, v5, v5 - v6, v6);
    }
    raw_read_unlock(a1 + 1401);
    result = raw_read_unlock(&unk_3A870);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
