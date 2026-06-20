__int64 __fastcall ipa_rm_cons_index(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x14 )
    return 0xFFFFFFFFLL;
  else
    return dword_1F6004[a1 - 1];
}
