__int64 __fastcall dynamic_page_pool_create_pools(int a1, __int64 a2)
{
  __int64 *v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned __int64 v7; // x9
  bool v8; // cc
  char v9; // w22
  __int64 v10; // x0
  unsigned __int64 v11; // x8
  __int64 v12; // x0

  v4 = (__int64 *)_kmalloc_cache_noprof(of_platform_device_create, 3264, 24);
  if ( !v4 )
    return -12;
  v5 = dynamic_page_pool_create(1384898, 9);
  *v4 = v5;
  *(_DWORD *)(v5 + 96) = a1;
  *(_QWORD *)(*v4 + 104) = a2;
  *(_DWORD *)(*v4 + 8) = 0;
  *(_QWORD *)(*v4 + 48) = 0;
  if ( !*v4 || (unsigned __int64)*v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_DC62, "dynamic_page_pool_create_pools");
    goto LABEL_18;
  }
  v6 = dynamic_page_pool_create(1384898, 4);
  v4[1] = v6;
  *(_DWORD *)(v6 + 96) = a1;
  *(_QWORD *)(v4[1] + 104) = a2;
  *(_DWORD *)(v4[1] + 8) = 0;
  *(_QWORD *)(v4[1] + 48) = 0;
  v7 = v4[1];
  if ( v7 )
    v8 = v7 > 0xFFFFFFFFFFFFF000LL;
  else
    v8 = 1;
  v9 = v8;
  if ( v8 )
  {
    printk(&unk_DC62, "dynamic_page_pool_create_pools");
    v12 = *v4;
    goto LABEL_17;
  }
  v10 = dynamic_page_pool_create(1314242, 0);
  v4[2] = v10;
  *(_DWORD *)(v10 + 96) = a1;
  *(_QWORD *)(v4[2] + 104) = a2;
  *(_DWORD *)(v4[2] + 8) = 0;
  *(_QWORD *)(v4[2] + 48) = 0;
  v11 = v4[2];
  if ( !v11 || v11 > 0xFFFFFFFFFFFFF000LL )
  {
    printk(&unk_DC62, "dynamic_page_pool_create_pools");
    dynamic_page_pool_destroy(*v4);
    if ( (v9 & 1) == 0 )
    {
      v12 = v4[1];
LABEL_17:
      dynamic_page_pool_destroy(v12);
    }
LABEL_18:
    kfree(v4);
    return -12;
  }
  return (__int64)v4;
}
