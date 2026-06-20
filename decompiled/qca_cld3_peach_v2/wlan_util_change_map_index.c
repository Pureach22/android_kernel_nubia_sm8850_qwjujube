__int64 __fastcall wlan_util_change_map_index(__int64 result, unsigned __int8 a2, char a3)
{
  __int64 v3; // x9
  __int64 v4; // x8

  v3 = 1LL << a2;
  v4 = a2 >> 6;
  if ( a3 )
    *(_QWORD *)(result + 8 * v4) |= v3;
  else
    *(_QWORD *)(result + 8 * v4) &= ~v3;
  return result;
}
