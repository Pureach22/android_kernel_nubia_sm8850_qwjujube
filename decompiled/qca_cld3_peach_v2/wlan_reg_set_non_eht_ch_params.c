__int64 __fastcall wlan_reg_set_non_eht_ch_params(__int64 result, char a2)
{
  if ( result )
    *(_BYTE *)(result + 16) = a2 & 1;
  return result;
}
