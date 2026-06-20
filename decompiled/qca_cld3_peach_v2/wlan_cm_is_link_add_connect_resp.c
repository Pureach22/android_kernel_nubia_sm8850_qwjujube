__int64 __fastcall wlan_cm_is_link_add_connect_resp(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 7) >> 5) & 1;
}
