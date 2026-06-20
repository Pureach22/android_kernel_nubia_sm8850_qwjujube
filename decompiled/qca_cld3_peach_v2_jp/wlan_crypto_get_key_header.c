__int64 __fastcall wlan_crypto_get_key_header(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 32);
  if ( v1 )
    return *(unsigned __int8 *)(v1 + 12);
  else
    return 0;
}
