__int64 __fastcall wlan_reg_is_chan_disabled_and_not_nol(__int64 a1)
{
  return reg_is_chan_disabled_and_not_nol(a1) & 1;
}
