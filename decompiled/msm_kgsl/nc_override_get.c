__int64 __fastcall nc_override_get(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x25
  int *v5; // x26
  __int64 v11; // x0
  __int64 v12; // x22
  int v13; // w3
  unsigned int v14; // w28
  unsigned int v15; // w27
  int *v16; // x8
  __int64 v17; // x23
  int v18; // w0
  __int64 v19; // x19

  v4 = *(_QWORD *)(a1 + 32);
  v5 = *(int **)(v4 + 24552);
  if ( *(_BYTE *)(v4 + 24608) != 1 || v5 == nullptr )
    return 0;
  v11 = _kmalloc_cache_noprof(socinfo_get_partinfo_vulkan_id, 3520, 4096);
  v12 = v11;
  if ( !v11 )
    return -12;
  mutex_lock(v4 + 24560);
  v13 = *v5;
  if ( !*v5 )
  {
    v17 = v12;
    goto LABEL_16;
  }
  v14 = 4096;
  v15 = 1;
  v16 = v5;
  v17 = v12;
  while ( *((_BYTE *)v16 + 12) != 1 )
  {
LABEL_10:
    v16 = &v5[5 * v15++];
    v13 = *v16;
    if ( !*v16 )
      goto LABEL_16;
  }
  v18 = scnprintf(v17, v14, "0x%x:0x%8.8x\n", v13, v16[2]);
  if ( v18 )
  {
    a3 = v18;
    v14 -= v18;
    v17 += v18;
    goto LABEL_10;
  }
  a3 = 0;
LABEL_16:
  mutex_unlock(v4 + 24560);
  v19 = simple_read_from_buffer(a2, a3, a4, v12, v17 - v12);
  kfree(v12);
  return v19;
}
