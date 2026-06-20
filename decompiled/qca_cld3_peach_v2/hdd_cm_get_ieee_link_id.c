__int64 __fastcall hdd_cm_get_ieee_link_id(__int64 a1, char a2)
{
  __int64 v2; // x8

  v2 = 976;
  if ( (a2 & 1) != 0 )
    v2 = 1672;
  return *(unsigned int *)(a1 + v2);
}
