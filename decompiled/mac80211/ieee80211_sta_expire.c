__int64 __fastcall ieee80211_sta_expire(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 *v3; // x21
  __int64 v4; // x22
  __int64 v5; // x19
  __int64 v7; // x27
  __int64 v8; // x9
  __int64 *v9; // x8
  char v10; // w11
  unsigned __int64 v11; // x11
  unsigned __int64 v12; // x11
  bool v13; // cf
  __int64 v14; // x9
  __int64 v15; // x8

  v2 = *(_QWORD *)(result + 1616);
  v3 = *(__int64 **)(v2 + 1616);
  v4 = v2 + 1616;
  if ( v3 != (__int64 *)(v2 + 1616) )
  {
    v5 = result;
    do
    {
      v8 = v3[218];
      v9 = v3 + 219;
      if ( v8 )
      {
        v10 = 0;
        do
        {
          v11 = _cpu_possible_mask & (unsigned __int64)(-1LL << v10);
          if ( !v11 )
            break;
          v12 = __clz(__rbit64(v11));
          if ( v9[1] - *(_QWORD *)(_per_cpu_offset[v12] + v8 + 8) < 0 )
            v9 = (__int64 *)(_per_cpu_offset[v12] + v8);
          v13 = v12 >= 0x1F;
          v10 = v12 + 1;
        }
        while ( !v13 );
      }
      v7 = *v3;
      if ( v3[10] == v5 )
      {
        v14 = v3[288];
        v15 = v9[1];
        if ( v14 - v15 >= 0 && v14 != 0 )
          v15 = v3[288];
        if ( a2 - jiffies + v15 < 0 )
        {
          result = _sta_info_destroy_part1(v3);
          if ( (_DWORD)result )
          {
            __break(0x800u);
          }
          else
          {
            synchronize_net(result);
            result = _sta_info_destroy_part2((__int64)v3, 1);
          }
        }
      }
      v3 = (__int64 *)v7;
    }
    while ( v7 != v4 );
  }
  return result;
}
