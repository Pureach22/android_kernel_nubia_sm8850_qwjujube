bool __fastcall cm_is_rsn_or_8021x_sha256_auth_type(__int64 a1)
{
  return (wlan_crypto_get_param(a1, 7u) & 0x81) != 0;
}
