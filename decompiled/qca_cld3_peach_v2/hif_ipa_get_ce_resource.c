__int64 __fastcall hif_ipa_get_ce_resource(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 320);
  if ( *((_DWORD *)v1 - 1) != -1796848263 )
    __break(0x8228u);
  return v1();
}
