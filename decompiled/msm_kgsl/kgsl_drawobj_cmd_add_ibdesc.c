__int64 __fastcall kgsl_drawobj_cmd_add_ibdesc(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x20
  __int64 v8; // x0
  char v9; // w10
  __int64 v10; // x2
  __int64 *v11; // x1

  v3 = *a3;
  v4 = a3[3] & 3;
  v5 = 4 * a3[2];
  *((_DWORD *)a3 + 6) = v4;
  if ( (*(_BYTE *)(a2 + 24) & 1) == 0 || v4 != 3 )
  {
    if ( (*(_BYTE *)(a2 + 16) & 6) != 0 )
      return 0;
    v8 = kmem_cache_alloc_noprof(memobjs_cache, 3264);
    if ( !v8 )
      return 4294967284LL;
    v9 = *(_BYTE *)(a2 + 24);
    *(_QWORD *)(v8 + 48) = 0;
    *(_QWORD *)(v8 + 32) = v3;
    *(_QWORD *)(v8 + 40) = v5;
    *(_DWORD *)(v8 + 16) = 0;
    *(_QWORD *)(v8 + 24) = 0;
    *(_QWORD *)(v8 + 56) = 0;
    if ( (v9 & 1) != 0 && (a3[3] & 1) != 0 )
    {
      v10 = a2 + 104;
      v11 = *(__int64 **)(a2 + 112);
      if ( v8 != a2 + 104 && v11 != (__int64 *)v8 && *v11 == v10 )
      {
        *(_QWORD *)(a2 + 112) = v8;
        goto LABEL_19;
      }
    }
    else
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a2 + 8) + 200LL) & 0x10) != 0 && *(_QWORD *)(a2 + 88) == a2 + 88 )
        *(_QWORD *)(v8 + 48) = 2;
      v10 = a2 + 88;
      v11 = *(__int64 **)(a2 + 96);
      if ( v8 != a2 + 88 && v11 != (__int64 *)v8 && *v11 == v10 )
      {
        *(_QWORD *)(a2 + 96) = v8;
LABEL_19:
        *(_QWORD *)v8 = v10;
        *(_QWORD *)(v8 + 8) = v11;
        *v11 = v8;
        return 0;
      }
    }
    _list_add_valid_or_report(v8, v11);
    return 0;
  }
  add_profiling_buffer(a1, a2, v3, v5, 0, 0);
  return 0;
}
