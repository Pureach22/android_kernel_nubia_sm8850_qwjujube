__int64 __fastcall sde_crtc_calc_gcd(__int64 result, unsigned int a2)
{
  if ( a2 )
    return sde_crtc_calc_gcd(a2, (unsigned int)result % a2);
  return result;
}
