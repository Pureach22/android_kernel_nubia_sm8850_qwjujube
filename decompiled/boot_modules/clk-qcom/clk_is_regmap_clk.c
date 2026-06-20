bool __fastcall clk_is_regmap_clk(_QWORD *a1)
{
  _QWORD *v2; // x9
  _BOOL4 v3; // w20

  if ( a1 )
  {
    raw_spin_lock(&clk_regmap_lock);
    v2 = &clk_regmap_list;
    do
    {
      v2 = (_QWORD *)*v2;
      v3 = v2 != &clk_regmap_list;
    }
    while ( v2 - 12 != a1 && v2 != &clk_regmap_list );
    raw_spin_unlock(&clk_regmap_lock);
  }
  else
  {
    return 0;
  }
  return v3;
}
