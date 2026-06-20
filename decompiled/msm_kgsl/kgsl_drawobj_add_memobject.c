__int64 __fastcall kgsl_drawobj_add_memobject(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x11
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 *v9; // x1
  __int64 v10; // x8
  unsigned int v11; // w8

  v4 = kmem_cache_alloc_noprof(memobjs_cache, 3264);
  if ( v4 )
  {
    v6 = *((unsigned int *)a2 + 6);
    v5 = *((_DWORD *)a2 + 7);
    v8 = *a2;
    v7 = a2[1];
    v9 = *(__int64 **)(a1 + 8);
    *(_QWORD *)(v4 + 56) = 0;
    *(_DWORD *)(v4 + 16) = v5;
    v10 = a2[2];
    *(_QWORD *)(v4 + 24) = v8;
    *(_QWORD *)(v4 + 32) = v7;
    *(_QWORD *)(v4 + 40) = v10;
    *(_QWORD *)(v4 + 48) = v6;
    if ( v4 == a1 || v9 == (__int64 *)v4 || *v9 != a1 )
    {
      _list_add_valid_or_report(v4, v9);
      return 0;
    }
    else
    {
      v11 = 0;
      *(_QWORD *)(a1 + 8) = v4;
      *(_QWORD *)v4 = a1;
      *(_QWORD *)(v4 + 8) = v9;
      *v9 = v4;
    }
  }
  else
  {
    return (unsigned int)-12;
  }
  return v11;
}
