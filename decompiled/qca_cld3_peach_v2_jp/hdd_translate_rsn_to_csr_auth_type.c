__int64 __fastcall hdd_translate_rsn_to_csr_auth_type(int *a1)
{
  int v1; // w8
  __int64 result; // x0
  unsigned int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v4 = 255;
  if ( v1 == ccp_rsn_oui01 )
  {
    result = 8;
  }
  else if ( *a1 == ccp_rsn_oui02 )
  {
    result = 9;
  }
  else if ( *a1 == ccp_rsn_oui04 )
  {
    result = 11;
  }
  else if ( *a1 == ccp_rsn_oui03 )
  {
    result = 10;
  }
  else if ( *a1 == ccp_rsn_oui06 )
  {
    result = 15;
  }
  else if ( *a1 == ccp_rsn_oui07 )
  {
    result = 16;
  }
  else if ( *a1 == ccp_rsn_oui08 )
  {
    result = 17;
  }
  else if ( *a1 == ccp_rsn_oui_18 )
  {
    result = 23;
  }
  else if ( *a1 == ccp_rsn_oui_12 )
  {
    result = 22;
  }
  else if ( *a1 == ccp_rsn_oui_0b )
  {
    result = 24;
  }
  else if ( *a1 == ccp_rsn_oui_0c )
  {
    result = 25;
  }
  else if ( *a1 == ccp_rsn_oui_0d )
  {
    result = 28;
  }
  else if ( *a1 == 26898256 )
  {
    result = 26;
  }
  else
  {
    hdd_translate_fils_rsn_to_csr_auth();
    hdd_translate_sae_rsn_to_csr_auth(a1, &v4);
    result = v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
