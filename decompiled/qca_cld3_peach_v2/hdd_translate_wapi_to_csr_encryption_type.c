__int64 __fastcall hdd_translate_wapi_to_csr_encryption_type(int *a1)
{
  int v1; // w10
  __int64 result; // x0

  v1 = *a1;
  result = 7;
  if ( v1 != ccp_wapi_oui01 )
  {
    if ( *a1 == ccp_wapi_oui02 )
      return 7;
    else
      return 255;
  }
  return result;
}
