__int64 __fastcall _carveout_heap_init(_QWORD *a1, _QWORD *a2)
{
  int v3; // w8
  size_t v4; // x20
  __int64 v5; // x21
  __int64 v6; // x2
  void *v7; // x0
  void *v8; // x22
  __int64 v9; // x0
  unsigned int v10; // w20

  v3 = arm64_use_ng_mappings;
  a2[10] = a1[4];
  v5 = a1[2];
  v4 = a1[3];
  if ( v3 )
    v6 = 0x68000000000F0BLL;
  else
    v6 = 0x6800000000070BLL;
  v7 = (void *)ioremap_prot(v5 & 0xFFFFFFFFFFFFF000LL, v4, v6);
  if ( v7 && (v8 = v7, memset(v7, 0, v4), iounmap(v8), v9 = gen_pool_create(12, 0xFFFFFFFFLL), (a2[9] = v9) != 0) )
  {
    a2[12] = v5;
    gen_pool_add_owner(v9, v5, -1, v4, 0xFFFFFFFFLL, 0);
    v10 = 0;
  }
  else
  {
    v10 = -12;
  }
  _init_rwsem(a2 + 1, "&carveout_heap->mem_sem", &_carveout_heap_init___key);
  return v10;
}
