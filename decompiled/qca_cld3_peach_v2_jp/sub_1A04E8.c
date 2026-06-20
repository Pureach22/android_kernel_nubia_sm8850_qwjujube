__int64 __fastcall sub_1A04E8(__int64 _X0, __int64 a2, __int64 a3, __int64 a4, char _W4)
{
  __asm { LDSMAXB         W0, W4, [X17] }
  return wlan_crypto_peer_has_auth_mode(_X0);
}
