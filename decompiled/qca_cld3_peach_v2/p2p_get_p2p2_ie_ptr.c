unsigned __int8 *__fastcall p2p_get_p2p2_ie_ptr(unsigned __int8 *a1, unsigned __int16 a2)
{
  return wlan_get_vendor_ie_ptr_from_oui(&unk_A61F2E, 4u, a1, a2);
}
