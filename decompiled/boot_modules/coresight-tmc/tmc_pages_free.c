__int64 __fastcall tmc_pages_free(int *a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x21
  __int64 v6; // x22
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x0
  char v11; // w8
  __int64 v12; // x0
  char v13; // w8
  __int64 v14; // x0
  __int64 result; // x0

  if ( *a1 >= 1 )
  {
    v4 = *(_QWORD *)(a2 + 96);
    v6 = 0;
    do
    {
      v7 = *((_QWORD *)a1 + 1);
      if ( v7 )
      {
        v8 = *(_QWORD *)(v7 + 8 * v6);
        if ( v8 )
          dma_unmap_page_attrs(v4, v8, 4096, a3, 0);
      }
      v9 = *((_QWORD *)a1 + 2);
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 8 * v6);
        if ( v10 )
          _free_pages(v10, 0);
      }
      ++v6;
    }
    while ( v6 < *a1 );
  }
  v11 = is_vmalloc_addr(*((_QWORD *)a1 + 2));
  v12 = *((_QWORD *)a1 + 2);
  if ( (v11 & 1) != 0 )
    vfree(v12);
  else
    kfree(v12);
  v13 = is_vmalloc_addr(*((_QWORD *)a1 + 1));
  v14 = *((_QWORD *)a1 + 1);
  if ( (v13 & 1) != 0 )
    result = vfree(v14);
  else
    result = kfree(v14);
  *a1 = 0;
  *((_QWORD *)a1 + 1) = 0;
  *((_QWORD *)a1 + 2) = 0;
  return result;
}
