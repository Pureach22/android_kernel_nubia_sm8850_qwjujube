__int64 __fastcall a6xx_gx_is_on(_QWORD *a1)
{
  int is_enabled; // w19
  int v3; // w0

  is_enabled = _clk_is_enabled(a1[1105]);
  if ( a1[1129] )
    v3 = kgsl_genpd_is_enabled(a1[1129]);
  else
    v3 = regulator_is_enabled(a1[1126]) != 0;
  return is_enabled & v3 & 1;
}
