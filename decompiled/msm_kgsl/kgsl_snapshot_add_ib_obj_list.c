__int64 __fastcall kgsl_snapshot_add_ib_obj_list(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x2
  _QWORD *v6; // x19
  __int64 v7; // t1
  _QWORD *v8; // x8
  unsigned int v9; // w9

  v4 = (_QWORD *)_kmalloc_cache_noprof(idr_find, 3520, 24);
  if ( v4 )
  {
    v7 = *(_QWORD *)(a1 + 144);
    v6 = (_QWORD *)(a1 + 144);
    v5 = (_QWORD *)v7;
    *v4 = a2;
    v8 = v4 + 1;
    if ( *(_QWORD **)(v7 + 8) != v6 || v8 == v6 || v5 == v8 )
    {
      _list_add_valid_or_report(v4 + 1, v6);
      return 0;
    }
    else
    {
      v9 = 0;
      v5[1] = v8;
      v4[1] = v5;
      v4[2] = v6;
      *v6 = v8;
    }
  }
  else
  {
    return (unsigned int)-12;
  }
  return v9;
}
