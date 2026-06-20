__int64 __fastcall wlan_crypto_rsn_keymgmt_to_suite(unsigned int a1)
{
  if ( a1 > 0x1C )
    return 0xFFFFFFFFLL;
  else
    return dword_AD07B4[a1];
}
