__int64 __fastcall wlan_crypto_get_key_type(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 32)) != 0 )
    return *(unsigned int *)(v1 + 8);
  else
    return 17;
}
