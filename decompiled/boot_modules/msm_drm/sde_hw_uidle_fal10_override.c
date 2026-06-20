__int64 __fastcall sde_hw_uidle_fal10_override(__int64 a1, char a2)
{
  __int64 v2; // x2
  __int64 result; // x0

  if ( (a2 & 1) != 0 )
    v2 = 2147483649LL;
  else
    v2 = 0;
  result = sde_reg_write(a1, 8, v2, "UIDLE_FAL10_VETO_OVERRIDE");
  __dsb(0xEu);
  return result;
}
