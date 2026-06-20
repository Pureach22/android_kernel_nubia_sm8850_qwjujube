__int64 __fastcall wcnss_check_pool_lists(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v3; // w8
  int v4; // w9
  int v5; // w25
  __int64 v6; // x10
  __int64 v7; // x26
  __int64 v8; // x27
  __int64 i; // x21
  __int64 v10; // x1

  result = printk(&unk_6A84, a2);
  v3 = cnss_prealloc_pool_size;
  if ( cnss_prealloc_pool_size )
  {
    v4 = 0;
    do
    {
      v5 = v4;
      v6 = cnss_pools + 96LL * v4;
      v7 = *(int *)(v6 + 88);
      if ( (_DWORD)v7 )
      {
        v8 = *(_QWORD *)(v6 + 80);
        for ( i = 0; i != v7; ++i )
        {
          v10 = *(_QWORD *)(v8 + 8 * i);
          if ( v10 )
          {
            printk(&unk_6A9E, v10);
            result = printk(&unk_6A5C, 285);
            __break(0x800u);
          }
        }
        v3 = cnss_prealloc_pool_size;
      }
      v4 = v5 + 1;
    }
    while ( v5 + 1 < v3 );
  }
  return result;
}
