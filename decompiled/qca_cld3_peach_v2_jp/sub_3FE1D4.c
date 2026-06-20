__int64 __fastcall sub_3FE1D4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { SMC             #0x6942 }
  return dot11f_pack_ie_he_cap(a1, a2, a3, a4, a5);
}
