__int64 __fastcall sub_40DCF0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x10

  if ( (v3 & 0x200000000000000LL) != 0 )
    JUMPOUT(0x410E90);
  return convert_tim(a1, a2, a3);
}
