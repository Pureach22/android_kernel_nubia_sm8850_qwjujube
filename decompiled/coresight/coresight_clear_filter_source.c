__int64 __fastcall coresight_clear_filter_source(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x10

  v2 = *(_QWORD *)(a1 - 56);
  if ( *(int *)(v2 + 4) >= 1 )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(*(_QWORD *)(v2 + 8) + 8 * v3);
      if ( *(_QWORD *)(v4 + 48) == a2 )
      {
        *(_QWORD *)(v4 + 48) = 0;
        v2 = *(_QWORD *)(a1 - 56);
      }
      ++v3;
    }
    while ( v3 < *(int *)(v2 + 4) );
  }
  return 0;
}
