__int64 __fastcall hdd_translate_wapi_to_csr_auth_type(_DWORD *a1)
{
  if ( *a1 == ccp_wapi_oui01 )
    return 12;
  if ( *a1 == ccp_wapi_oui02 )
    return 13;
  return 255;
}
