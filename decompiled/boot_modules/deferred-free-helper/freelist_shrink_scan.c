unsigned __int64 __fastcall freelist_shrink_scan(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x19
  __int64 v4; // x0

  if ( !*(_QWORD *)(a2 + 8) )
    return 0;
  v3 = 0;
  do
  {
    if ( v3 >= *(_QWORD *)(a2 + 8) )
      break;
    v4 = free_one_item(1);
    v3 += v4;
  }
  while ( v4 );
  return v3;
}
