__int64 __fastcall zs_destroy_pool(_QWORD *a1)
{
  __int64 i; // x22
  __int64 v3; // x21

  shrinker_free(a1[260]);
  flush_work(a1 + 261);
  for ( i = 0; i != 255; ++i )
  {
    v3 = a1[i + 1];
    if ( v3 && i == *(_DWORD *)(v3 + 212) )
    {
      if ( *(_QWORD *)(v3 + 8) != v3 + 8 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 0);
      if ( *(_QWORD *)(v3 + 24) != v3 + 24 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 1);
      if ( *(_QWORD *)(v3 + 40) != v3 + 40 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 2);
      if ( *(_QWORD *)(v3 + 56) != v3 + 56 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 3);
      if ( *(_QWORD *)(v3 + 72) != v3 + 72 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 4);
      if ( *(_QWORD *)(v3 + 88) != v3 + 88 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 5);
      if ( *(_QWORD *)(v3 + 104) != v3 + 104 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 6);
      if ( *(_QWORD *)(v3 + 120) != v3 + 120 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 7);
      if ( *(_QWORD *)(v3 + 136) != v3 + 136 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 8);
      if ( *(_QWORD *)(v3 + 152) != v3 + 152 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 9);
      if ( *(_QWORD *)(v3 + 168) != v3 + 168 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 10);
      if ( *(_QWORD *)(v3 + 184) != v3 + 184 )
        printk(&unk_9A71, *(unsigned int *)(v3 + 200), 11);
      kfree(v3);
    }
  }
  kmem_cache_destroy(a1[256]);
  kmem_cache_destroy(a1[257]);
  kfree(*a1);
  return kfree(a1);
}
