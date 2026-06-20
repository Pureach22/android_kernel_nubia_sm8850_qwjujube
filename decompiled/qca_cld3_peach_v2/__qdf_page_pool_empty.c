bool __fastcall _qdf_page_pool_empty(__int64 a1)
{
  _BOOL4 v1; // w20

  if ( *(_DWORD *)(a1 + 256) )
  {
    return 0;
  }
  else
  {
    raw_spin_lock(a1 + 1416);
    if ( *(_DWORD *)(a1 + 1472) )
      v1 = *(_QWORD *)(*(_QWORD *)(a1 + 1480) + 8LL * *(int *)(a1 + 1408)) == 0;
    else
      v1 = 1;
    raw_spin_unlock(a1 + 1416);
  }
  return v1;
}
