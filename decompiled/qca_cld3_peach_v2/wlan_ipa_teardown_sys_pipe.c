_BYTE *__fastcall wlan_ipa_teardown_sys_pipe(_BYTE *result)
{
  if ( result )
  {
    if ( result[12] )
      result[12] = 0;
    if ( result[276] )
      result[276] = 0;
    if ( result[540] )
      result[540] = 0;
    if ( result[804] )
      result[804] = 0;
  }
  return result;
}
