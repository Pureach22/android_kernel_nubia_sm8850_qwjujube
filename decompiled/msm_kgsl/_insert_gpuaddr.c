__int64 __fastcall insert_gpuaddr(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 *v6; // x0
  unsigned __int64 v7; // x9
  _QWORD *v8; // x19
  unsigned __int64 v9; // t1
  unsigned __int64 v10; // x8
  _QWORD *v11; // x9
  __int64 v12; // x10
  unsigned __int64 v13; // x9
  _QWORD *v14; // x0
  unsigned __int64 *v16; // x19

  v6 = (unsigned __int64 *)kmem_cache_alloc_noprof(addr_entry_cache, 2080);
  if ( !v6 )
    return 4294967284LL;
  v9 = *(_QWORD *)(a1 + 120);
  v8 = (_QWORD *)(a1 + 120);
  v7 = v9;
  *v6 = a2;
  v6[1] = a3;
  if ( v9 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = v7;
        v13 = *(_QWORD *)(v7 - 16);
        if ( v13 <= a2 )
          break;
        v12 = 16;
        v7 = *(_QWORD *)(v10 + 16);
        if ( !v7 )
          goto LABEL_8;
      }
      if ( v13 >= a2 )
        break;
      v12 = 8;
      v7 = *(_QWORD *)(v10 + 8);
      if ( !v7 )
      {
LABEL_8:
        v11 = (_QWORD *)(v10 + v12);
        goto LABEL_9;
      }
    }
    v16 = v6;
    if ( (unsigned int)__ratelimit(&insert_gpuaddr__rs, "_insert_gpuaddr") )
    {
      _warn_printk("duplicate gpuaddr: 0x%llx\n", a2);
      __break(0x800u);
    }
    kmem_cache_free(addr_entry_cache, v16);
    return 4294967279LL;
  }
  else
  {
    v10 = 0;
    v11 = v8;
LABEL_9:
    v6[2] = v10;
    v6[3] = 0;
    v14 = v6 + 2;
    v14[2] = 0;
    *v11 = v14;
    rb_insert_color();
    return 0;
  }
}
