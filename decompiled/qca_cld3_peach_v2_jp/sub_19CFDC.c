__int64 __fastcall sub_19CFDC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { STGP            X5, X22, [X10,#0x88]! }
  return wlan_crypto_decap(a1, a2, a3, a4, a5, _X5);
}
