bool __fastcall swrm_remove_from_group(__int64 a1)
{
  __int64 v1; // x21
  int v3; // w8
  _BOOL4 v4; // w20
  __int64 *i; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    mutex_lock(v1 + 8784);
    v3 = *(_DWORD *)(v1 + 15352);
    v4 = v3 > 1;
    if ( v3 >= 2 )
    {
      for ( i = *(__int64 **)(a1 + 984); i != (__int64 *)(a1 + 984); i = (__int64 *)*i )
      {
        *((_BYTE *)i + 944) = 0;
        *(_BYTE *)(a1 + 8411) = 0;
      }
    }
    mutex_unlock(v1 + 8784);
  }
  else
  {
    return 0;
  }
  return v4;
}
