__int64 __fastcall snd_card_sysfs_store(int a1, int a2, char *s)
{
  sscanf(s, "%d", snd_card_pdata + 96);
  sysfs_notify(snd_card_pdata, 0, "card_state");
  return 0;
}
