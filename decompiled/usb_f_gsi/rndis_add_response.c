__int64 __fastcall rndis_add_response(__int64 a1, unsigned int a2)
{
  __int64 v4; // x20
  __int64 v5; // x2
  __int64 *v6; // x1

  v4 = _kmalloc_noprof(a2 + 32LL, 2080);
  if ( v4 )
  {
    *(_DWORD *)(v4 + 24) = a2;
    *(_DWORD *)(v4 + 28) = 0;
    *(_QWORD *)(v4 + 16) = v4 + 32;
    raw_spin_lock(a1 + 96);
    v5 = a1 + 80;
    v6 = *(__int64 **)(a1 + 88);
    if ( v4 == a1 + 80 || v6 == (__int64 *)v4 || *v6 != v5 )
    {
      _list_add_valid_or_report(v4);
    }
    else
    {
      *(_QWORD *)(a1 + 88) = v4;
      *(_QWORD *)v4 = v5;
      *(_QWORD *)(v4 + 8) = v6;
      *v6 = v4;
    }
    raw_spin_unlock(a1 + 96);
  }
  return v4;
}
