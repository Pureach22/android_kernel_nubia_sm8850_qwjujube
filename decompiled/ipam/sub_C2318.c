__int64 __fastcall sub_C2318(__int64 a1, __int64 a2)
{
  __int64 v2; // x12

  if ( (v2 & 0x400000000000LL) != 0 )
    JUMPOUT(0xBEA28);
  return ipa3_reset_flt(a1, a2);
}
