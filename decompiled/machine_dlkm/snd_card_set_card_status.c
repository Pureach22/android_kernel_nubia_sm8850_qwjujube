__int64 __fastcall snd_card_set_card_status(int a1)
{
  *(_DWORD *)(snd_card_pdata + 96) = a1;
  return 0;
}
