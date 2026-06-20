_DWORD *__fastcall hdd_translate_fils_rsn_to_csr_auth(_DWORD *result, _DWORD *a2)
{
  if ( *result == ccp_rsn_oui_0e )
  {
    *a2 = 18;
  }
  else if ( *result == ccp_rsn_oui_0f )
  {
    *a2 = 19;
  }
  else if ( *result == ccp_rsn_oui_10 )
  {
    *a2 = 20;
  }
  else if ( *result == ccp_rsn_oui_11 )
  {
    *a2 = 21;
  }
  return result;
}
