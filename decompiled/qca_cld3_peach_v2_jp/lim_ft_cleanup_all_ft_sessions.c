__int64 __fastcall lim_ft_cleanup_all_ft_sessions(__int64 result)
{
  unsigned int v1; // w8
  __int64 v2; // x19
  unsigned __int64 v3; // x20
  __int64 v4; // x21

  v1 = *(unsigned __int16 *)(result + 3992);
  if ( *(_WORD *)(result + 3992) )
  {
    v2 = result;
    v3 = 0;
    v4 = 70;
    do
    {
      if ( *(_BYTE *)(*(_QWORD *)(v2 + 12264) + v4) == 1 )
      {
        result = lim_ft_cleanup();
        v1 = *(unsigned __int16 *)(v2 + 3992);
      }
      ++v3;
      v4 += 10792;
    }
    while ( v3 < v1 );
  }
  return result;
}
