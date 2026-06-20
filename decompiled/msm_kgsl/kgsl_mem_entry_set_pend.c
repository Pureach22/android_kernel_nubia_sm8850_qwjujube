bool __fastcall kgsl_mem_entry_set_pend(__int64 a1)
{
  int v2; // w8
  _BOOL4 v3; // w20

  if ( a1 )
  {
    raw_spin_lock(*(_QWORD *)(a1 + 256) + 32LL);
    v2 = *(_DWORD *)(a1 + 264);
    v3 = v2 == 0;
    if ( !v2 )
      *(_DWORD *)(a1 + 264) = 1;
    raw_spin_unlock(*(_QWORD *)(a1 + 256) + 32LL);
  }
  else
  {
    return 0;
  }
  return v3;
}
