__int64 __fastcall hdd_translate_wpa_to_csr_auth_type(int *a1)
{
  int v1; // w8
  __int64 result; // x0
  unsigned int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v3 = 255;
  if ( v1 == ccp_wpa_oui01 )
  {
    result = 5;
  }
  else if ( *a1 == ccp_wpa_oui02 )
  {
    result = 6;
  }
  else if ( *a1 == ccp_wpa_oui06 )
  {
    result = 14;
  }
  else
  {
    hdd_translate_fils_rsn_to_csr_auth(a1, &v3);
    result = v3;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
