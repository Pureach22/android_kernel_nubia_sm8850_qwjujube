__int64 __fastcall lim_acquire_free_pre_auth_node(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x8
  __int64 i; // x9

  v2 = *a2;
  if ( !(_DWORD)v2 )
    return 0;
  for ( i = *((_QWORD *)a2 + 1); (*(_BYTE *)(*(_QWORD *)i + 278LL) & 4) == 0; i += 8 )
  {
    if ( !--v2 )
      return 0;
  }
  *(_BYTE *)(*(_QWORD *)i + 278LL) &= ~4u;
  return *(_QWORD *)i;
}
