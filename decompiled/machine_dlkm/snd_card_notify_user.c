__int64 __fastcall snd_card_notify_user(int a1)
{
  __int64 v2; // x8

  v2 = snd_card_pdata;
  *(_DWORD *)(snd_card_pdata + 96) = a1;
  sysfs_notify(v2, 0, "card_state");
  if ( !a1 )
  {
    mutex_lock(&vote_against_sleep_lock);
    vote_against_sleep_cnt = 0;
    mutex_unlock(&vote_against_sleep_lock);
  }
  return 0;
}
