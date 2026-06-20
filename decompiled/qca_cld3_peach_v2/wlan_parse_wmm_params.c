__int64 __fastcall wlan_parse_wmm_params(unsigned __int8 *a1, unsigned __int16 a2, __int64 a3)
{
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0

  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&algn_B08DAB, 5u, a1, a2);
  if ( vendor_ie_ptr_from_oui )
    return 16
         * (unsigned int)((unsigned int)dot11f_unpack_ie_wmm_params(
                                          0,
                                          vendor_ie_ptr_from_oui + 7,
                                          vendor_ie_ptr_from_oui[1] - 5,
                                          a3) != 0);
  else
    return 4;
}
