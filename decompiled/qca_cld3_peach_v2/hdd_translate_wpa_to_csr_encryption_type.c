__int64 __fastcall hdd_translate_wpa_to_csr_encryption_type(_DWORD *a1)
{
  if ( *a1 == ccp_wpa_oui04 )
    return 6;
  if ( *a1 == ccp_wpa_oui02 )
    return 5;
  if ( *a1 == ccp_wpa_oui00 )
    return 0;
  if ( *a1 == ccp_wpa_oui01 )
    return 1;
  if ( *a1 == ccp_wpa_oui05 )
    return 2;
  return 255;
}
