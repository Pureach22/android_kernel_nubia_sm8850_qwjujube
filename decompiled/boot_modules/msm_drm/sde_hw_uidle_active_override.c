__int64 __fastcall sde_hw_uidle_active_override(__int64 a1, char a2)
{
  __int64 v2; // x2

  if ( (a2 & 1) != 0 )
    v2 = 2147483649LL;
  else
    v2 = 0;
  return sde_reg_write(a1, 12, v2, "UIDLE_QACTIVE_HF_OVERRIDE");
}
