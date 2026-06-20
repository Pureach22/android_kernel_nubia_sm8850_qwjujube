__int64 __fastcall wcd939x_update_regmap_cache(__int64 result)
{
  __int64 v1; // x19

  if ( *(_DWORD *)(result + 3176) )
  {
    v1 = result;
    regmap_write(*(_QWORD *)(result + 32), 12329, 165);
    regmap_write(*(_QWORD *)(v1 + 32), 12534, 0);
    regmap_write(*(_QWORD *)(v1 + 32), 12535, 0);
    regmap_write(*(_QWORD *)(v1 + 32), 12536, 68);
    result = regmap_write(*(_QWORD *)(v1 + 32), 12598, 128);
    if ( *(_DWORD *)(v1 + 3176) == 2 )
      return regmap_write(*(_QWORD *)(v1 + 32), 13421, 62);
  }
  return result;
}
