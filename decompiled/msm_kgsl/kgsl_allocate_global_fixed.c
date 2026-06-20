__int64 __fastcall kgsl_allocate_global_fixed(_QWORD *a1, const char *a2, __int64 a3)
{
  __int64 v6; // x20
  int inited; // w0
  int v8; // w22
  _QWORD *v9; // x0
  _QWORD *v10; // x2
  _QWORD *v11; // x1

  v6 = _kmalloc_cache_noprof(mutex_unlock, 3520, 232);
  if ( !v6 )
    return -12;
  inited = kgsl_memdesc_init_fixed(a1, a1[1396], a2, v6);
  if ( inited )
  {
    v8 = inited;
    kfree(v6);
    return v8;
  }
  else
  {
    v9 = (_QWORD *)(v6 + 216);
    *(_DWORD *)(v6 + 48) = 2;
    v10 = a1 + 1639;
    v11 = (_QWORD *)a1[1640];
    *(_QWORD *)(v6 + 208) = a3;
    if ( (_QWORD *)(v6 + 216) == a1 + 1639 || v11 == v9 || (_QWORD *)*v11 != v10 )
    {
      _list_add_valid_or_report(v9, v11);
    }
    else
    {
      a1[1640] = v9;
      *(_QWORD *)(v6 + 216) = v10;
      *(_QWORD *)(v6 + 224) = v11;
      *v11 = v9;
    }
    kgsl_mmu_map_global((__int64)a1);
  }
  return v6;
}
