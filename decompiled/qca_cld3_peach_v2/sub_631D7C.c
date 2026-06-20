__int64 __fastcall sub_631D7C(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x638D50);
  return cfg_tdls_get_uapsd_mask(a1, a2);
}
