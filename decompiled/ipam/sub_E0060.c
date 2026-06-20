__int64 __fastcall sub_E0060(__int64 a1)
{
  __int64 v1; // x10

  if ( (v1 & 0x8000000000LL) == 0 )
    JUMPOUT(0xD9400);
  return ipa3_nat_mdfy_pdn(a1);
}
