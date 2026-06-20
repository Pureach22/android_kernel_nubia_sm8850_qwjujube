bool __fastcall lim_check_he_80_mcs11_supp(__int64 a1, __int64 a2)
{
  return ((*(unsigned __int16 *)(a2 + 20) >> (2 * *(_BYTE *)(a1 + 8635) - 2)) & 3) == 2
      || ((*(unsigned __int16 *)(a2 + 22) >> (2 * *(_BYTE *)(a1 + 8635) - 2)) & 3) == 2;
}
