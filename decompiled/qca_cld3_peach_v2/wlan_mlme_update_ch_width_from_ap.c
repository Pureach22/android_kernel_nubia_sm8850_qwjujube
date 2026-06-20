__int64 __fastcall wlan_mlme_update_ch_width_from_ap(__int64 result, char a2)
{
  *(_BYTE *)(result + 24256) = a2;
  return result;
}
