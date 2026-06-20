__int64 __fastcall sub_1F00A0(__int64 a1)
{
  __int64 v1; // x10
  __int64 v2; // x13

  return wlan_reg_is_etsi_srd_chan_for_freq(a1, v2 + __ROR8__(v1, 46));
}
