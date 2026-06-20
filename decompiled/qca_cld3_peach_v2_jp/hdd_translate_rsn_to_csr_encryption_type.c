__int64 __fastcall hdd_translate_rsn_to_csr_encryption_type(_DWORD *a1)
{
  if ( *a1 == ccp_rsn_oui04 )
    return 6;
  if ( *a1 == ccp_rsn_oui09 )
    return 13;
  if ( *a1 == ccp_rsn_oui0a )
    return 14;
  if ( *a1 == ccp_rsn_oui02 )
    return 5;
  if ( *a1 == ccp_rsn_oui00 )
    return 0;
  if ( *a1 == ccp_rsn_oui01 )
    return 1;
  if ( *a1 == ccp_rsn_oui05 )
    return 2;
  return 255;
}
