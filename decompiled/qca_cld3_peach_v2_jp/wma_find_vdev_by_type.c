__int64 __fastcall wma_find_vdev_by_type(__int64 a1, int a2)
{
  __int64 v2; // x9
  __int64 result; // x0
  __int64 v5; // x8
  _DWORD *i; // x10

  v2 = *(unsigned __int16 *)(a1 + 162);
  if ( !*(_WORD *)(a1 + 162) )
    return 4294967282LL;
  result = 0;
  v5 = *(_QWORD *)(a1 + 520);
  for ( i = (_DWORD *)(v5 + 164); !v5 || *i != a2; i += 122 )
  {
    if ( v2 == ++result )
      return 4294967282LL;
  }
  return result;
}
