__int64 __fastcall sub_3C2608(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (a2 & 0x2000) == 0 )
    JUMPOUT(0x3C3714);
  return lim_enable_short_preamble(a1, a2, a3, a4);
}
