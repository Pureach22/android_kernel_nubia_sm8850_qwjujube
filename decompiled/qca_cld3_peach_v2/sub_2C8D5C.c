__int64 __fastcall sub_2C8D5C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  if ( (a7 & 0x800000000000000LL) == 0 )
    JUMPOUT(0x2C7A70);
  return mlme_update_tgt_eht_caps_in_cfg();
}
