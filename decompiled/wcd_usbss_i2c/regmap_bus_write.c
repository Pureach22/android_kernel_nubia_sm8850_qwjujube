__int64 __fastcall regmap_bus_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  if ( *(_QWORD *)(a1 + 152) )
  {
    if ( a3 <= 1 )
    {
      __break(0x800u);
      return regmap_bus_gather_write(a1, a2);
    }
    if ( a3 < 4 )
      return regmap_bus_gather_write(a1, a2);
    __break(0x800u);
  }
  return 4294967274LL;
}
