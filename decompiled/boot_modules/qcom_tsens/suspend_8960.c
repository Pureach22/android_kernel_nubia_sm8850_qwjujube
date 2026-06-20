__int64 __fastcall suspend_8960(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v4; // x2

  v1 = *(_QWORD *)(a1 + 16);
  result = regmap_read(v1, 13860, a1 + 2536);
  if ( !(_DWORD)result )
  {
    result = regmap_read(v1, 13856, a1 + 2540);
    if ( !(_DWORD)result )
    {
      if ( *(_DWORD *)(a1 + 8) <= 1u )
        v4 = 16777217;
      else
        v4 = 67108865;
      return regmap_update_bits_base(v1, 13856, v4, 0, 0, 0, 0);
    }
  }
  return result;
}
