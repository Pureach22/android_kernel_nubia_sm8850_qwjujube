__int64 __fastcall wlan_mlme_get_p2p_p2p_conc_support(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 23) >> 5) & 1;
}
