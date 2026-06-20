__int64 __fastcall gdsc_genpd_debug_register(__int64 a1)
{
  __int64 v2; // x19
  void *v3; // x2
  unsigned int one; // w19

  v2 = _kmalloc_cache_noprof(kfree, 3520, 32);
  if ( v2 )
  {
    *(_QWORD *)(v2 + 16) = a1;
    mutex_lock(&gdsc_genpd_debug_lock);
    v3 = gdsc_genpd_debug_list;
    if ( gdsc_genpd_debug_list == (_UNKNOWN *)v2
      || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)gdsc_genpd_debug_list) != &gdsc_genpd_debug_list )
    {
      _list_add_valid_or_report(v2, &gdsc_genpd_debug_list);
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)gdsc_genpd_debug_list) = v2;
      *(_QWORD *)v2 = v3;
      *(_QWORD *)(v2 + 8) = &gdsc_genpd_debug_list;
      gdsc_genpd_debug_list = (_UNKNOWN *)v2;
    }
    if ( genpd_rootdir )
      one = gdsc_genpd_debug_create_one(v2);
    else
      one = 0;
    mutex_unlock(&gdsc_genpd_debug_lock);
  }
  else
  {
    return (unsigned int)-12;
  }
  return one;
}
