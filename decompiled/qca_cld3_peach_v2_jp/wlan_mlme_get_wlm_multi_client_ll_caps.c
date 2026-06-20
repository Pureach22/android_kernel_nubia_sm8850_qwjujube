__int64 __fastcall wlan_mlme_get_wlm_multi_client_ll_caps(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 24) >> 4) & 1;
}
