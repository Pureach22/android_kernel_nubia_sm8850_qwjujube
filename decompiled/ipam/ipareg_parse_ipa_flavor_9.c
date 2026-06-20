void __fastcall ipareg_parse_ipa_flavor_9(__int64 a1, __int64 a2, int a3)
{
  *(_DWORD *)a2 = 0;
  *(_WORD *)a2 = a3;
  *(_BYTE *)(a2 + 2) = BYTE2(a3);
}
