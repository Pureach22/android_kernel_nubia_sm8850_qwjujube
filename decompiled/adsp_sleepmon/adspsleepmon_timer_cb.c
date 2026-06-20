__int64 adspsleepmon_timer_cb()
{
  LOBYTE(word_A629) = 1;
  return _wake_up(&adspsleepmon_wq, 1, 1, 0);
}
