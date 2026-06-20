__int64 __fastcall sub_1378EC(__int64 a1)
{
  int v1; // w13

  if ( (v1 & 0x1000000) != 0 )
    JUMPOUT(0x139668);
  return ipa3_check_wdi_opt_chn_empty(a1);
}
