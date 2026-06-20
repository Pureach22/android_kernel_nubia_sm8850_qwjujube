__int64 __fastcall msm_vidc_get_cap_id(__int64 a1, int a2)
{
  __int64 v2; // x9
  unsigned int *i; // x8

  v2 = 196;
  for ( i = (unsigned int *)(a1 + 4488); i[10] != a2; i += 42 )
  {
    if ( !--v2 )
      return 0;
  }
  return *i;
}
