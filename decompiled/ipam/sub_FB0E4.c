__int64 __fastcall sub_FB0E4(__int64 a1, __int64 a2)
{
  __int64 v2; // x12

  if ( (v2 & 0x400000000000LL) != 0 )
    JUMPOUT(0xF77F4);
  return ipa3_reset_rt(a1, a2);
}
