__int64 __fastcall clk_restore_critical_clocks(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v3; // x21
  __int64 v4; // x19
  unsigned __int64 v5; // x8
  int v6; // w22

  v1 = *(_QWORD *)(a1 + 152);
  result = dev_get_regmap(a1, 0);
  if ( result && *(_QWORD *)(v1 + 24) )
  {
    v3 = *(_QWORD *)(v1 + 16);
    v4 = result;
    v5 = 0;
    v6 = 1;
    do
    {
      result = regmap_update_bits_base(
                 v4,
                 *(unsigned int *)(v3 + 8 * v5),
                 *(unsigned int *)(v3 + 8 * v5 + 4),
                 *(unsigned int *)(v3 + 8 * v5 + 4),
                 0,
                 0,
                 0);
      v5 = v6++;
    }
    while ( *(_QWORD *)(v1 + 24) > v5 );
  }
  return result;
}
