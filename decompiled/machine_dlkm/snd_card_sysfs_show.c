__int64 __fastcall snd_card_sysfs_show(int a1, int a2, char *s)
{
  return snprintf(s, 0x20u, "%d", *(_DWORD *)(snd_card_pdata + 96));
}
