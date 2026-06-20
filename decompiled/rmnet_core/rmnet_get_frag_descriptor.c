_QWORD *__fastcall rmnet_get_frag_descriptor(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x0
  _QWORD *v4; // x21
  __int64 v5; // x20
  _QWORD *v6; // x8
  __int64 v7; // x9
  _QWORD *v8; // x0

  v2 = *(_QWORD *)(a1 + 2808);
  v3 = raw_spin_lock_irqsave(a1 + 2800);
  v4 = *(_QWORD **)v2;
  v5 = v3;
  if ( *(_QWORD *)v2 == v2 )
  {
    v8 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
    v4 = v8;
    if ( v8 )
    {
      *v8 = v8;
      v8[1] = v8;
      v8[2] = v8 + 2;
      v8[3] = v8 + 2;
      ++*(_DWORD *)(v2 + 16);
    }
  }
  else
  {
    v6 = (_QWORD *)v4[1];
    if ( (_QWORD *)*v6 == v4 && (v7 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
    {
      *(_QWORD *)(v7 + 8) = v6;
      *v6 = v7;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)v2);
    }
    *v4 = v4;
    v4[1] = v4;
  }
  raw_spin_unlock_irqrestore(a1 + 2800, v5);
  return v4;
}
