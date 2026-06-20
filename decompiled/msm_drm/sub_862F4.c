__int64 __fastcall sub_862F4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w12

  if ( (v4 & 0x40000) != 0 )
    JUMPOUT(0x874AC);
  return dp_lphw_hpd_get(a1, a2, a3, a4);
}
