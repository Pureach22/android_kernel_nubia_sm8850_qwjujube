__int64 __fastcall wlan_cm_is_link_switch_disconnect_resp(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 3) >> 4) & 1;
}
