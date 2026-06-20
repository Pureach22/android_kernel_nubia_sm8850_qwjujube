__int64 __fastcall enable_8960(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w20
  __int64 v7; // x0
  int v8; // w8
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  v9 = 0;
  result = regmap_read(v4, 13856, &v9);
  if ( !(_DWORD)result )
  {
    if ( a2 <= 5 )
      v6 = 8 * (1LL << a2);
    else
      v6 = 15872;
    if ( (v6 & ~v9) != 0 )
    {
      result = regmap_write(*(_QWORD *)(a1 + 16), 13856, v9 | 2);
      if ( !(_DWORD)result )
      {
        v7 = *(_QWORD *)(a1 + 16);
        if ( *(_DWORD *)(a1 + 8) <= 1u )
          v8 = 16777217;
        else
          v8 = 67108865;
        v9 |= v8 | v6 | 0x40000;
        result = regmap_write(v7, 13856, v9);
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
