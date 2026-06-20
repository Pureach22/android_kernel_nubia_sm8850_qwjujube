__int64 __fastcall cm_wmi_auth_type_to_crypto_key_mgmt(int a1)
{
  if ( (unsigned int)(a1 - 6) > 0x1A )
    return 2;
  else
    return dword_AEFC28[a1 - 6];
}
