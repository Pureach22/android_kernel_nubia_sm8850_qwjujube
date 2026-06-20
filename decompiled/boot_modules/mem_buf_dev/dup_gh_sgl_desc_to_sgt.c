__int64 __fastcall dup_gh_sgl_desc_to_sgt(_DWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x1
  __int64 v6; // x0
  unsigned int v7; // w21
  char *v8; // x20
  char *v9; // x8
  __int64 v10; // x8
  unsigned __int64 v11; // x9
  __int64 v12; // x10

  if ( !a1 || !*a1 )
    return -22;
  v2 = _kmalloc_cache_noprof(class_for_each_device, 3520, 16);
  v3 = v2;
  if ( !v2 )
    return -12;
  if ( (unsigned int)sg_alloc_table(v2, (unsigned int)*a1, 3264) )
  {
    kfree(v3);
    return -12;
  }
  if ( *(_DWORD *)(v3 + 8) )
  {
    v6 = *(_QWORD *)v3;
    v7 = 0;
    v8 = (char *)a1 + 6;
    do
    {
      v9 = &v8[16 * v7++];
      v11 = *(_QWORD *)v9;
      v10 = *((_QWORD *)v9 + 1);
      v12 = (__int64)memstart_addr >> 12;
      *(_QWORD *)(v6 + 16) = 0;
      *(_DWORD *)(v6 + 24) = 0;
      *(_DWORD *)(v6 + 8) = 0;
      *(_DWORD *)(v6 + 12) = v10;
      *(_QWORD *)v6 = ((((v11 >> 6) & 0x3FFFFFFFFFFFFC0LL) - (v12 << 6)) & 0xFFFFFFFFFFFFFFFCLL | *(_QWORD *)v6 & 3LL)
                    - 0x140000000LL;
      v6 = sg_next(v6, v4);
    }
    while ( v7 < *(_DWORD *)(v3 + 8) );
  }
  return v3;
}
