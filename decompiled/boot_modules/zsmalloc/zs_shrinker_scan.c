__int64 __fastcall zs_shrinker_scan(__int64 a1)
{
  __int64 result; // x0

  result = zs_compact(*(_QWORD *)(a1 + 88));
  if ( !result )
    return -1;
  return result;
}
