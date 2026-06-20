__int64 __fastcall sub_12CC08(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        long double a9)
{
  __int64 v9; // x12
  __int128 v10; // q23

  *(_OWORD *)(v9 + 512) = v10;
  *(long double *)(v9 + 528) = a9;
  return sde_connector_property_is_dirty(a1, a2);
}
