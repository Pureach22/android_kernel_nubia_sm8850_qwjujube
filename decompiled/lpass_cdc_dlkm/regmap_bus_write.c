__int64 __fastcall regmap_bus_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  if ( !*(_QWORD *)(a1 + 152) )
    return 4294967274LL;
  if ( a3 > 1 )
    return regmap_bus_gather_write();
  if ( (unsigned int)__ratelimit(&regmap_bus_write__rs, "regmap_bus_write") )
    dev_err(a1, "%s: count %zd bytes < %d, not supported\n", "regmap_bus_write", a3, 2);
  return 4294967274LL;
}
