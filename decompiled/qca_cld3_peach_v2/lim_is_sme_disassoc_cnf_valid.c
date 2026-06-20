bool __fastcall lim_is_sme_disassoc_cnf_valid(__int64 a1, __int64 a2)
{
  return (*(_BYTE *)(a2 + 18) & 1) == 0;
}
