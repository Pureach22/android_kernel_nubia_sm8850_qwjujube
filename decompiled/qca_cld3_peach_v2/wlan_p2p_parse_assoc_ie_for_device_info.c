unsigned __int8 *__fastcall wlan_p2p_parse_assoc_ie_for_device_info(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // x0

  result = nullptr;
  if ( a1 )
  {
    if ( a2 )
      return p2p_parse_assoc_ie_for_device_info(a1, a2);
  }
  return result;
}
