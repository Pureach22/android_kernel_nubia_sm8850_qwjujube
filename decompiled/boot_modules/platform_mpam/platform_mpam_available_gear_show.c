__int64 __fastcall platform_mpam_available_gear_show(__int64 a1, __int64 a2)
{
  __int64 v3; // x23
  __int64 v4; // x24
  __int64 v5; // x20

  if ( support_gear_cnt < 1 )
    return 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    ++v4;
    v5 += (int)scnprintf(
                 a2 + v5,
                 4096 - v5,
                 "%d - %s\n",
                 *(_DWORD *)(support_gears + v3),
                 *(const char **)(support_gears + v3 + 8));
    v3 += 16;
  }
  while ( v4 < support_gear_cnt );
  return v5;
}
