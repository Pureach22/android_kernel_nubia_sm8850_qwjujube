__int64 __fastcall sde_hw_get_limit_conf(__int64 a1, int a2, char a3)
{
  int v3; // w8

  if ( (a3 & 1) != 0 )
    v3 = 176;
  else
    v3 = 192;
  return (unsigned __int8)((unsigned int)sde_reg_read(a1, v3 + (a2 & 0xFFFFFFFC)) >> (8 * (a2 & 3)));
}
