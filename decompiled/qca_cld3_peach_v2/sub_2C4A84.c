__int64 __fastcall sub_2C4A84(__int64 a1)
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return wlan_sap_disconnect_all_p2p_client(a1);
}
