__int64 __fastcall wlan_pre_cac_get_status(__int64 a1)
{
  return pre_cac_is_active(a1) & 1;
}
